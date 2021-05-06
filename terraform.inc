MAKEFLAGS  	      += --silent
SHELL      	      = /bin/bash
TERRAFORM_VERSION = 0.14.0
TFPLAN = tfplan

ifndef TERRAFORM_FOLDER
	TERRAFORM_FOLDER := ""
endif

ifndef TERRAFORM_ENV
	TERRAFORM_ENV := ""
endif

ifndef REPO_NAME
	REPO_NAME   := $(shell basename $(CURDIR))
	BRANCH_NAME := $(shell git rev-parse --abbrev-ref HEAD)
	COMMIT_SHA  := $(shell git rev-parse --short HEAD)
endif

PROJECT_NAME := ${REPO_NAME}

env := ${BRANCH_NAME}

TF_VAR_env := ${env}
TF_VAR_project_name := ${PROJECT_NAME}

# HELP
# This will output the help for each task
# thanks to https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.PHONY: help

help: ## This help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

terraform-tfsec: ## Execute tfsec in terraform files
	echo "STEP: terraform-tfsec - Execute tfsec in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app tfsec/tfsec . --no-color

terraform-validate: ## Execute terraform validate in terraform files
	echo "STEP: terraform-validate - Execute terraform validate in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app --env-file $(TERRAFORM_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) validate

terraform-clean: ## Remove terraform files untracked in git
	echo "STEP: terraform-clean - Remove terraform files untracked in git"
	cd ./${TERRAFORM_FOLDER}/ && \
	rm -rf ${TFPLAN}

terraform-fmt: ## Execute terraform fmt in terraform files
	echo "STEP: terraform-fmt - Execute terraform fmt in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app hashicorp/terraform:$(TERRAFORM_VERSION) fmt -recursive

terraform-init: ## Execute terraform init in terraform files
	echo "STEP: terraform-init - Execute terraform init in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app hashicorp/terraform:$(TERRAFORM_VERSION) init

terraform-plan: terraform-validate terraform-tfsec ## Execute terraform validate, tfsec and plan in terraform files
	echo "STEP: terraform-plan - Execute terraform validate, tfsec and plan in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app --env-file $(TERRAFORM_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) plan -out ${TFPLAN}

terraform-apply: ## Execute terraform apply in terraform files
	echo "STEP: terraform-apply - Execute terraform apply in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app --env-file $(TERRAFORM_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) apply -auto-approve ${TFPLAN}
	
terraform-destroy: ## Execute terraform destroy in terraform files
	echo "STEP: terraform-destroy - Execute terraform destroy in terraform files"
	docker run --rm -v $$PWD/${TERRAFORM_FOLDER}:/app -w /app --env-file $(TERRAFORM_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) destroy -auto-approve

fmt: terraform-fmt ## alias for terraform fmt
plan: fmt terraform-init terraform-plan ## Execute terraform fmt, init, plan in terraform files
apply: terraform-apply ## alias for terraform apply
destroy: terraform-destroy ## alias for terraform destroy
clean: terraform-clean ## alias for terraform clean
test: plan terraform-apply terraform-destroy ## Execute terraform plan, apply, destroy in terraform files
