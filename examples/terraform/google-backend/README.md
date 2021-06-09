# Terraform

Exemplos para utilização do Makefile para Terraform.

## Requisitos

| Name | Version |
|------|---------|
| GNU Make | >= 4.2.1 |
| Docker | >= 20.10.6 |

# Makefiles

A implementação do Makefiles para Terraform está contida no arquivo `terraform.inc`. Esta implementação utiliza containeres Docker para execução dos comandos, referenciando a imagem `hashicorp/terraform:0.14.0`.

## Configurando o _backend_ na GCP


### Configurando o arquivo .target.env

Este arquivo deve conter, obrigatoriamente, as variáveis de ambiente (`BUCKET_NAME` e `GOOGLE_APPLICATION_CREDENTIALS`) utilizadas pelo Terraform para interagir com a Google Cloud Platform.

Também podem ser informadas neste arquivo, quantas variáveis forem necessárias para consumo do módulo, no formato `TF_VAR_`, conforme [documentação oficial](https://www.terraform.io/docs/language/values/variables.html#environment-variables).

|   Variável                      |  Obrigatório   |  _Default_        | Descrição     |
|    :---:                        |     :---:      |     :---:         | :---          |
| BUCKET_NAME                     |   Sim          |       n/a         | Nome do bucket na Google Cloud Storage. O bucket informado na deve existir na GCP. |
| GOOGLE_APPLICATION_CREDENTIALS  |   Sim          |       n/a         | Caminho local para o arquivo de credenciais da GCP no formato JSON.  |
| TF_VAR_\<nome>                  |   Não          |       n/a         | Variável de entrada do módulo utilizado.  |

Por exemplo:

```
# Variáveis para backend GCP
BUCKET_NAME=dummy-bucket
GOOGLE_APPLICATION_CREDENTIALS=./dummy-file.json
# Variáveis do módulo
TF_VAR_nome=exemplo
TF_VAR_numero=123
TF_VAR_lista=['item', 'item2']

```

### Criando o arquivo backend.tf

Para configurar um **_backend_ remoto** no Google Cloud Storage (GCS), foi disponibilizado um comando adicional no Makefile.

```sh
> make terraform-generate-backend-gcs
```


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

