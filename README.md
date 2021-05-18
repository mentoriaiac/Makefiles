# Makefiles

Este projeto tem como objetivo fornecer um Makefile base para ser importado no inicio dos Makefiles de implementação e templates da organização [Mentoria IaC](https://github.com/mentoriaiac).

A proposta é que este Makefile tenha os targets padrão para todo tipo de implementação recorrente como pipelines de [Terraform](https://www.terraform.io/), [Ansible](https://www.ansible.com/), [Docker](https://www.docker.com/), [Kubernetes](https://kubernetes.io/pt/).

## Como utilizar o template

### Arquivo .env

Este arquivo contém informações essenciais para o funcionamento do projeto e devem ser preenchidas pelo usuário deste repositório:

|   Variável         |  Obrigatório   |  _Default_        | Descrição     |
|    :---:           |     :---:      |     :---:         | :---          |
| INCLUDE_MAKEFILE   |   Não          |   `terraform.inc` | Nome do arquivo `.inc` do Makefile de uma tecnologia que será utilizada, por exemplo, `terraform.inc`. |
| REMOTE_REPOSITORY  |   Não          |   `https://raw.githubusercontent.com/mentoriaiac/Makefiles/main` | Caminho para o _raw content_ do repositório do Github que contém o arquivo do item anterior. Na maior parte das vezes, será o caminho deste próprio repositório: `https://raw.githubusercontent.com/mentoriaiac/Makefiles/main`. |
| TARGET_FOLDER      |   Não          |   ""              | Diretório alvo dos comandos executados pelo Makefile. Caso não seja informado, será usado o diretório raiz deste projeto. |
| TARGET_ENV         |   Não          |   `.target.env`   | Arquivo que permite separar as variáveis de ambiente específicas de uma tecnologia. |



### Executar comandos make

Começar utilizando os comandos `make` ou `make help`, para conhecer os comandos disponíveis para o Makefile de tal tecnologia.


### Tecnologias disponíveis

- [Terraform](./examples/terraform)
  



