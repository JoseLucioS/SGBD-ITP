#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void comandos(); // imprime os comandos na tela
void criar_tab(); // cria um arquivo com uma tabela 
void listar_tab(); // lista todos os arquivos-tabela

int main()
{
	int comando;
	comandos();
	printf("Digite um comando: ");
	scanf("%d", &comando);
	
	/*verifica quais os comandos fornecidos*/
	switch(comando)
	{
		case 1:
			//criar_tab();
			break;
		case 2:
			//listar_tab();
			break;
		default:
			printf("Comando inválido! Tente novamente.\n");// caso o comando recebido nao esteja entre 0 e 9
	}

	return 0;
}

void comandos()
{
	/*menu de comandos*/
	printf("Lista de Comandos:\n");
	printf("1 - Criar uma tabela;\n");
	printf("2 - Listar todas as tabelas;\n");
	printf("3 - Criar nova linha na tabela;\n");
	printf("4 - Editar os valores de uma tabela;\n");
	printf("5 - Criar nova coluna na tabela;\n");
	printf("6 - Listar todos os dados de uma tabela;\n");
	printf("7 - Pesquisar valor em uma tabela;\n");
	printf("8 - Apagar valor de uma tabela;\n");
	printf("9 - Apagar uma tabela;\n");
	printf("0 - Encerrar o programa.\n");
}

