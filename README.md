# Makefiles

Este projeto tem como objetivo fornecer um Makefile base para ser importado no inicio dos Makefiles de implementação e templates da organização [Mentoria IaC](https://github.com/mentoriaiac).

A proposta é que este Makefile tenha os targets padrão para todo tipo de implementação recorrente como pipelines de [Terraform](https://www.terraform.io/), [Ansible](https://www.ansible.com/), [Docker](https://www.docker.com/), [Kubernetes](https://kubernetes.io/pt/).

## Requisitos

| Name | Version |
|------|---------|
| GNU Make | >= 4.2.1 |

## Como utilizar o template

### Arquivo .env

Este arquivo contém informações essenciais para o funcionamento do projeto e devem ser preenchidas pelo usuário deste repositório:

|   Variável         | Descrição     | Obrigatório   |  _Default_         |
|    :---:           | :---          |     :---:      |     :---          |
| INCLUDE_MAKEFILE   | Nome do arquivo `.inc` do Makefile de uma tecnologia que será utilizada, por exemplo, `terraform.inc`. **Deve ser alterado**, pois o arquivo padrão apenas informa como utilizar o projeto. |   Sim          |   `how-to-use.inc` |
| VERSION_MAKEFILE   | Versão do template Makefile que será utilizado. **Não utilizar `main`.**  |   Sim          |   `main`           |
| REMOTE_REPOSITORY  | Caminho para do repositório do Github que contém os arquivos Makefile base. Recomenda-se usar o valor padrão. |   Não          |   `https://raw.githubusercontent.com/mentoriaiac/Makefiles/${VERSION_MAKEFILE}/${INCLUDE_MAKEFILE}` |
| TARGET_FOLDER      | Diretório alvo dos comandos executados pelo Makefile. Caso não seja informado, será usado o diretório raiz deste projeto. |   Não          |   ""               |
| TARGET_ENV         | Arquivo que permite separar as variáveis de ambiente específicas de uma tecnologia. |   Não          |   `.target.env`    |

### Executar comandos _make_

Começar utilizando os comandos `make` ou `make help`, para conhecer os comandos disponíveis para o Makefile de tal tecnologia.

### Tecnologias disponíveis

- [Terraform](./examples/terraform)
