MAKEFLAGS  	+= --silent
SHELL      	 = /bin/bash

ifndef TERRAFORM_FOLDER
	TERRAFORM_FOLDER := ""
endif

REPO_NAME := ${BITBUCKET_REPO_SLUG}
BRANCH_NAME  := ${BITBUCKET_BRANCH}
COMMIT_SHA   := $(shell echo ${BITBUCKET_COMMIT}| head -c 7)

ifndef BITBUCKET_REPO_SLUG
	REPO_NAME   			:= $(shell basename $(CURDIR))
	BRANCH_NAME   			:= $(shell git rev-parse --abbrev-ref HEAD)
	COMMIT_SHA   			:= $(shell git rev-parse --short HEAD)
endif

PROJECT_NAME := $(shell echo ${REPO_NAME}| sed 's/eks-//')

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
	cd ./${TERRAFORM_FOLDER}/ && \
	tfsec . --no-color

terraform-generate-backend:  ## Generate file backend.tf
	echo "STEP: terraform-generate-backend - Generate file backend.tf"
	cd ./${TERRAFORM_FOLDER}/ && \
	echo -e "terraform {\nbackend "s3" {}\n}" > backend.tf && \
	terraform fmt

terraform-validate: ## Execute terraform validate in terraform files
	echo "STEP: terraform-validate - Execute terraform validate in terraform files"
	cd ./${TERRAFORM_FOLDER}/ && \
	terraform validate

terraform-clean: ## Remove terraform files untracked in git
	echo "STEP: terraform-clean - Remove terraform files untracked in git"
	cd ./${TERRAFORM_FOLDER}/ && \
	rm -rf .terraform/ && \
	rm -rf .terraform.* && \
	rm -rf backend.tf && \
	rm -rf *.tfstate* && \
	rm -rf .terraform.lock.hcl && \
	rm -rf tf.plan

terraform-fmt: ## Execute terraform fmt in terraform files
	echo "STEP: terraform-fmt - Execute terraform fmt in terraform files"
	terraform fmt -recursive

terraform-init: terraform-generate-backend ## Execute terraform init in terraform files
	echo "STEP: terraform-init - Execute terraform init in terraform files"
	cd ./${TERRAFORM_FOLDER}/ && \
	terraform init \
	-backend-config="key=${PROJECT_NAME}/terraform.tfstate" \
	-backend-config="region=${AWS_REGION}" \
	-backend-config="bucket=${BUCKET_NAME}" 

terraform-plan: terraform-validate terraform-tfsec ## Execute terraform validate, tfsec and plan in terraform files
	echo "STEP: terraform-plan - Execute terraform validate, tfsec and plan in terraform files"
	cd ./${TERRAFORM_FOLDER}/ && \
	terraform plan -var-file=global.vars -out tf.plan

terraform-apply: ## Execute terraform apply in terraform files
	echo "STEP: terraform-apply - Execute terraform apply in terraform files"
	cd ./${TERRAFORM_FOLDER}/ && \
	terraform apply -auto-approve tf.plan
	
terraform-destroy: ## Execute terraform destroy in terraform files
	echo "STEP: terraform-destroy - Execute terraform destroy in terraform files"
	cd ./${TERRAFORM_FOLDER}/ && \
	terraform destroy -auto-approve -var-file=global.vars

fmt: terraform-fmt ## alias for terraform fmt
plan: fmt terraform-init terraform-plan ## Execute terraform fmt, init, plan in terraform files
apply: terraform-apply ## alias for terraform apply
destroy: terraform-destroy ## alias for terraform destroy
clean: terraform-clean ## alias for terraform clean
test: plan terraform-apply terraform-destroy ## Execute terraform plan, apply, destroy in terraform files
