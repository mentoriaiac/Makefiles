# Terraform

Exemplos para utilização do Makefile para Terraform.

## Requisitos

| Name | Version |
|------|---------|
| GNU Make | >= 4.2.1 |
| Docker | >= 20.10.6 |

# Makefiles

A implementação do Makefiles para Terraform está contida no arquivo `terraform.inc`. Esta implementação utiliza containeres Docker para execução dos comandos, referenciando a imagem `hashicorp/terraform:0.14.0`.

## Como utilizar o template

### Configrando _backend_

O Terraform trabalha com [_backend_](https://www.terraform.io/docs/language/settings/_backend_s/index.html) local ou remoto.

Para configurar um **_backend_ remoto**, foi disponibilizado um comando adicional para determinadas clouds.

- Terraform com _backend_ na GCP (depende das configuração de um .target.env_):

```sh
> make terraform-generate-backend-gcs
```

### Configurando o arquivo .target.env

Este arquivo deve conter as variáveis de ambiente geralmente utilizadas pelo Terraform para interagir com as clouds (Google Cloud, AWS, Azure, etc.):


- Terraform com backend na GCP

|   Variável                      |  Obrigatório   |  _Default_        | Descrição     |
|    :---:                        |     :---:      |     :---:         | :---          |
| BUCKET_NAME                     |   Sim          |                   | Nome do bucket na Google Cloud Storage. O bucket informado na deve existir na GCP. |
| GOOGLE_APPLICATION_CREDENTIALS  |   Sim          |                   | Caminho local para o arquivo de credenciais da GCP no formato JSON.  |


### Executando o Terraform

Começar utilizando os comandos `make` ou `make help`, para conhecer os comandos disponíveis para o Terraform.

Por exemplo:

```sh
> make help
help                           This help
terraform-tfsec                Execute tfsec in terraform files
terraform-validate             Execute terraform validate in terraform files
terraform-clean                Remove terraform files untracked in git
terraform-fmt                  Execute terraform fmt in terraform files
terraform-generate-backend-gcs Generate file backend.tf
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

