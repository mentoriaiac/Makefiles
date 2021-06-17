# Terraform

Exemplos para utilização do Makefile para Terraform.

## Requisitos

| Name | Version |
|------|---------|
| GNU Make | >= 4.2.1 |
| Docker | >= 20.10.6 |

## Makefiles

A implementação do Makefiles para Terraform está contida no arquivo `[terraform.inc](../../terraform.inc)`. Esta implementação utiliza containeres Docker para execução dos comandos, como imagem padrão utilizamos a `hashicorp/terraform:1.0.0`.

### Variáveis customizáveis

Para implementar variáveis de ambiente customizáveis você pode utilizar criar um arquivo chamado `.terraform.env` e informar o nome dele na variável *TARGET_ENV* do arquivo [.env](./.env).

No arquivo makefile [terraform.inc](../../terraform.inc) temos algumas variáveis pre-implementadas que podem ser customizadas.

| Variável | Descrição | _Default_ |
| :---: | :--- | :--- |
| TERRAFORM_VERSION | Versão do terraform utilizada para executar o projeto  | v1.0.0 |
| TFPLAN | Nome do arquivo que será gerado com o plano de execução do terraform  | tfplan |

## Opções de _backend_

O Terraform trabalha com [_backend_](https://www.terraform.io/docs/language/settings/backends/index.html) local ou remoto. Foram disponibilizados alguns exemplos de como utilizar o Makefile, de acordo com o _backend_ escolhido:

- [Terraform com _backend_ local](./local-backend)
- [Terraform com _backend_ na GCP](./google-backend)