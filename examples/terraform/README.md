# Terraform

Exemplos para utilização do Makefile para Terraform.

## Requisitos

| Name | Version |
|------|---------|
| GNU Make | >= 4.2.1 |
| Docker | >= 20.10.6 |

# Makefiles

A implementação do Makefiles para Terraform está contida no arquivo `terraform.inc`. Esta implementação utiliza containeres Docker para execução dos comandos, referenciando a imagem `hashicorp/terraform:0.14.0`.

## Opções de _backend_

O Terraform trabalha com [_backend_](https://www.terraform.io/docs/language/settings/backends/index.html) local ou remoto. Foram disponibilizados alguns exemplos de como utilizar o Makefile, de acordo com o _backend_ escolhido:

- [Terraform com _backend_ local](./local-backend)
- [Terraform com _backend_ na GCP](./google-backend)