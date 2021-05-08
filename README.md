# Makefiles

Este projeto tem como objetivo fornecer um Makefile base para ser importado no inicio dos Makefiles de implementação e templates da organização [Mentoria IaC](https://github.com/mentoriaiac).

A proposta é que este Makefile tenha os targets padrão para todo tipo de implementação recorrente como pipelines de [Terraform](https://www.terraform.io/), [Ansible](https://www.ansible.com/), [Docker](https://www.docker.com/), [Kubernetes](https://kubernetes.io/pt/).

## Como utilizar o template

### Arquivo .env

Este arquivo contém informações essenciais para o funcionamento do projeto e devem ser preenchidas pelo usuário deste repositório:

|   Variável         |  Obrigatório   | Descrição     |
|    :---:           |     :---:      | :---          |
| INCLUDE_MAKEFILE   |   Sim          | Nome do arquivo `.inc` do Makefile de uma tecnologia que será utilizada, por exemplo, `terraform.inc`. |
| REMOTE_REPOSITORY  |   Sim          | Caminho para o _raw content_ do repositório do Github que contém o arquivo do item anterior. Na maior parte das vezes, será o caminho deste próprio repositório: `https://raw.githubusercontent.com/mentoriaiac/Makefiles/main`. |
| TARGET_FOLDER      |   Não          | Diretório alvo dos comandos executados pelo Makefile. Caso não seja informado, será usado o diretório raiz deste projeto. |
| TARGET_ENV         |   Não          | Arquivo que permite separar as variáveis de ambiente específicas de uma tecnologia. Se não informado, será usado o arquivo `.env`. |



### Executar comandos make

Começar utilizando os comandos `make` ou `make help`, para conhecer os comandos disponíveis para o Makefile de tal tecnologia.

Por exemplo:

```sh
> make help
help                           This help
terraform-tfsec                Execute tfsec in terraform files
terraform-validate             Execute terraform validate in terraform files
terraform-clean                Remove terraform files untracked in git
terraform-fmt                  Execute terraform fmt in terraform files
terraform-init                 Execute terraform init in terraform files
terraform-plan                 Execute terraform validate, tfsec and plan in terraform files
terraform-apply                Execute terraform apply in terraform files
terraform-destroy              Execute terraform destroy in terraform files
fmt                            alias for terraform fmt
plan                           Execute terraform fmt, init, plan in terraform files
apply                          alias for terraform apply
destroy                        alias for terraform destroy
clean                          alias for terraform clean
test                           Execute terraform plan, apply, destroy in terraform files
```

