Estudos de C — Low Level Programming

Repositório dedicado ao estudo prático da linguagem C, com foco em programação de baixo nível, sistemas Linux e interação direta com os recursos do sistema operacional.

O objetivo é compreender não apenas como escrever código em C, mas também o que acontece por trás das operações: manipulação de arquivos, chamadas de sistema, gerenciamento de memória, permissões e interação com o ambiente Unix.

Objetivos

* Aprofundar os fundamentos da linguagem C.
* Compreender a interação entre programas e o sistema operacional Linux.
* Explorar bibliotecas padrão, interfaces POSIX e chamadas de sistema.
* Trabalhar com arquivos, descritores, permissões e metadados.
* Desenvolver maior domínio sobre memória, buffers e recursos do sistema.
* Construir uma base sólida em programação de baixo nível.

Conteúdos estudados

C e programação de sistemas

* Estruturas, ponteiros e manipulação de memória.
* Argumentos de linha de comando.
* Tratamento de erros com errno.
* Diagnóstico de erros com strerror().
* Manipulação de buffers e leitura de dados.

Arquivos e interfaces POSIX

* Abertura e leitura de arquivos com open() e read().
* Fechamento de descritores com close().
* Consulta de metadados com stat() e fstat().
* Manipulação e interpretação de permissões de arquivos.
* Constantes e flags de acesso, como O_RDONLY.
* Tratamento de erros em operações de entrada e saída.

Linux e sistemas Unix

* Interfaces entre aplicações e o sistema operacional.
* Descritores de arquivos e operações de baixo nível.
* Comportamento de chamadas de sistema.
* Compilação e execução de programas C em ambiente Linux.

O conteúdo é incremental: os tópicos são explorados conforme os estudos avançam.

Compilação e execução

Para compilar um programa utilizando GCC:

gcc programa.c -o programa

Para compilar com o Clang:
clang programa.c -o programa 

Executar o programa:

./programa

Quando o programa recebe um caminho de arquivo como argumento:

./programa arquivo.txt

Os comandos e argumentos dependem de cada exercício.

Ambiente de desenvolvimento

* Linguagem: C
* Compilador: GCC e Clang
* Sistema operacional: Linux
* Área de estudo: Low-level programming, sistemas Unix e interfaces POSIX

Progresso

Este repositório acompanha minha evolução prática em C, reunindo exercícios, experimentos e implementações desenvolvidos durante os estudos.

A proposta é aprender explorando o funcionamento real das operações, investigando erros e entendendo os mecanismos envolvidos em cada implementação.

Mais do que apenas aprender a sintaxe da linguagem, o foco é desenvolver uma compreensão mais profunda de como o software interage com o sistema operacional.

⸻

Autor: Blitk

Repositório — Estudos de C Low Level
