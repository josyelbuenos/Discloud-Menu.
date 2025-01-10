# DISCLOUD Menu - Gerenciamento de Aplicações e Backups

#### Este repositório contém uma ferramenta de linha de comando desenvolvida em C++ para gerenciamento de aplicações na [Discloud](https://github.com/discloud) utilizando o sistema de [Discloud CLI](https://github.com/discloud/cli). A ferramenta oferece um menu interativo para que o usuário possa realizar diversas operações em aplicações hospedadas, como:

- ***Visualizar informações do usuário***
- ***Fazer upload de aplicações***
- ***Acessar o terminal da aplicação***
- ***Gerenciar as aplicações (iniciar, parar, reiniciar, status, etc.)***
- ***Realizar backups***
- ***Excluir aplicações***

#### A ferramenta também permite um submenu para gerenciamento avançado, onde o usuário pode controlar os aplicativos, visualizar logs, entre outras opções.

## Principais funcionalidades:

Interface interativa com cores e formatação para facilitar a navegação
Suporte para UTF-8 para garantir compatibilidade com diferentes caracteres
Uso de ANSI escape codes para exibição colorida no terminal
Este projeto é ideal para administradores e usuários que precisam gerenciar suas aplicações no Discloud de maneira prática e eficiente.

## Você pode acessar a versão mais recente do executável ![AQUI](https://github.com/josyelbuenos/Discloud-Menu./releases/).

## Compilação

Você pode compilar o código utilizando o `g++` ou qualquer outro compilador que suporte C++.

Para compilar o arquivo `menu.cpp` com `g++`, use o seguinte comando:

```bash
g++ menu.cpp -o discloud_menu
```
Este comando gerará um executável chamado discloud_menu.

## License

[MIT](https://github.com/josyelbuenos/Discloud-Menu./blob/main/LICENSE)

## Autores

- [@josyelbuenos](https://www.github.com/josyelbuenos)
