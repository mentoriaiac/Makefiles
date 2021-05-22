MAKEFLAGS  	      += --silent
SHELL      	      = /bin/bash

# HELP
# This will output the help for each task
# thanks to https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.PHONY: help

help: ## This help
	@echo "********* Makefiles *********"
	@echo ""
	@echo "Este projeto tem como objetivo fornecer um Makefile base para ser importado na implementação e templates da organização Mentoria IaC."
	@echo "A proposta é que este Makefile tenha os targets padrão para todo tipo de implementação recorrente como pipelines de Terraform, Ansible, Docker, Kubernetes, etc."
	@echo ""
	@echo "Para escolher uma implementação de Tecnologia, informar ao arquivo .env as seguintes informações:"
	@echo ""
	@echo "  - INCLUDE_MAKEFILE : Nome do arquivo '*.inc' do Makefile de uma tecnologia que será utilizada, por exemplo, terraform.inc."
	@echo "  - VERSION_MAKEFILE : Versão do template Makefile que será utilizado. Não utilizar main."
	@echo "  - REMOTE_REPOSITORY : Caminho para do repositório do Github que contém os arquivos Makefile base. Recomenda-se usar o valor default https://raw.githubusercontent.com/mentoriaiac/Makefiles/."
	@echo "  - TARGET_FOLDER : Diretório alvo dos comandos executados pelo Makefile. Caso não seja informado, será usado o diretório raiz deste projeto."
	@echo "  - TARGET_ENV : Arquivo que permite separar as variáveis de ambiente específicas de uma tecnologia."
	@echo ""
	@echo "Mais informações em https://github.com/mentoriaiac/Makefiles/blob/main/README.md"
	@echo ""


