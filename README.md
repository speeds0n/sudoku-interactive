# Sudoku Interativo
## Linguagem de Programação 1 - DIM0120 - 2020.6

Este projeto consiste em contruir o jogo [Sudoku](https://wikipedia.org/wiki/Sudoku) de forma interativa, executado em modo texto apartir do terminal.

Para compilar o jogo o usuário deve executar o comando 'make all' via terminal dentro do diretório do jogo.
Para executar o jogo o usuário deve executar o comando ./sudoku ou 'make run' dentro do diretório do jogo.

Para remover os arquivos gerados pela compilação o usuário deve executar o comando 'make rl'

## Action Mode
Action Mode é um modo dentro do jogo que trata todos os comandos executados pelo usuário.
A função faz o tratamento da entrada informada pelo usuário.

##### Caso o jogador use o comando 'p'
	Verifica se o usuário digitou o comando da forma correta.
	Salva os valores digitados.
    Verifica se o número é valido na linha coluna e no quadrante atual e exibe uma mensagem correspondente.
    salva o comando e seus valores caso o jogador queria desfazer o comando.

##### Caso o jogador use o comando 'r'
    Verifica se os valores digitados são validos.
    Remove o numero da posição indicada.
    salva o comando e seus valores caso o jogador queria desfazer os comandos.

##### Caso o jogador use o comando 'c'
    verifica se o jogador ainda tem checks sobrando
    Verifica quais numeros estao correto e quais os numeros que estao incorretos

##### Caso o jogador use o comando 'u'
    Desfaz o último comando executado pelo jogador.


###### Projeto disponível [GitHub](https://github.com/speeds0n/sudoku-interactive) e [GitLab](https://projetos.imd.ufrn.br/edsoncassiano0/sudoku-interactive)
###### Author Edson Cassiano, October, 12, 2020
