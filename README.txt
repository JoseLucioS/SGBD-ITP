# SGBD-ITP

 Aluno: José Lúcio da Silva Júnior
 Endereço para o GitHub: https://github.com/JoseLucioS/SGBD-ITP

 O sistema foi desenvolvido na linguagem C de programação, utilizando-se do editor de texto VIM e num computador Ubuntu. Dessa maneira, a forma de compilar o programa é através de: "gcc main.c" no terminal de comandos. Em seguida, executando-se o comando "./a.out"  no terminal de comandos. Nenhuma biblioteca externa foi utilizada.

 Funcionalidades implementadas:

 - Criar tabela - 
  O programa é capaz de criar uma tabela em arquivo, solicitando antes, o número de colunas, o nome e o tipo da coluna a ser criada.

 - Listar tabelas - 
  O programa imprime a lista com todas as tabelas criadas até o momento.
  As tabelas são guardadas num arquivo que serve unicamente para armazená-las.

 - Criar nova linha - 
  Nova linha é impressa no arquivo-tabela fornecido pelo usuário. O usuário precisa digitar os valores a serem impressos um por um.

 - Listar todos os dados de uma tabela - 
  O comando lê o arquivo-tabela fornecido até o final, e imprime na tela linha por linha.

 - Apagar tabela - 
  Dado o nome da tabela a ser apagada, o programa busca pela tabela e a deleta do banco de dados, fazendo uso de uma estratégia de copiar todos os nomes das tabelas que são diferentes da que foi fornecida para um novo arquivo, apagando o antigo arquivo e renomeando o novo arquivo.
 - Encerrar programa - 
  Caso o usuário não deseje fazer nada, pode-se digitar o comando parar encerrar a execução do programa.

 Funcionalidades não implementadas: 
 - Editar os valores de uma tabela
 - Criar uma nova coluna na tabela
 - Pesquisar valores em uma tabela
 - Apagar valor de uma tabela

 Extras:
 - Repositório online para armazenamento e documentação do código (GitHub), pois além de ser uma sugestão do nosso professor, é também uma alternativa relevante para se trabalhar em grupo ou quando se usa mais de um console para desenvolver o projeto. 

 O que poderia ser mudado:
  A parte principal que poderia ser mudada seria o acréscimo das demais funções, que deixaram de ser implementadas devido ao tempo relativamente curto para a dar conta das outras disciplinas do curso e da implementação. Ademais, o uso de structs e alocação dinâmica otimizariam muito o projeto, usando somente a memória necessária, sem desperdicíos.
  Outro ponto interessante seria a utilização de nomes mais adequados para as variáveis, para melhorar a compreensão do código. Além disso, alguns erros e falhas precisam ser corrigidos no programa, pois alguns compiladores rodam o código e outros não.
