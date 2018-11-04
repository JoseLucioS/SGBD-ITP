#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tabela_t
{
	char nome[20+1];
	int linha;
	int coluna;
	char tamanho[50+1][50+1];
	
}Tabela;

typedef struct coluna_t
{
	char *nome_coluna;
	char *conteudo_col;
	unsigned int chave;
}Coluna;

void comandos(); // imprime os comandos na tela
void criar_tab(); // cria um arquivo com uma tabela 
void listar_tab(); // lista todos os arquivos-tabela

int main()
{
	int comando;
	FILE *p_arquivo;

	comandos();
	
	printf("Digite um comando: ");
	scanf("%d", &comando);
	
	/*verifica quais os comandos fornecidos*/
	switch(comando)
	{
		case 1:
			criar_tab();
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
	puts("");
}

void criar_tab()
{
	/*funcao sem fazer uso das structs no momento*/
	FILE *tabela;
	char nome_tabela[20+1];
	char tipo[] = ".txt";
	char chave_p[20];
	int i, j;

	printf("informe um nome para a tabela a ser criada: ");
	scanf("%s", nome_tabela);
	strcat(nome_tabela, tipo);
	
	tabela = fopen(nome_tabela, "w+");
	if(tabela == NULL)
	{
		/*em caso de erro na alocação*/
		printf("erro na abertura do arquivo!\n"); 
	}
	else
	{
		/*recebe a chave primaria, mas ainda sem qualquer uso*/
		printf("digite o nome da chave primaria: ");
		scanf("%s", chave_p);
		
		/*imprime uma tabela simples no arquivo 'tabela', para saber se o programa funciona*/
		fprintf(tabela, "nome1 | nome2 | nome3 |\n");
		for(i = 0; i < 5; i++)
		{
			for(j = 0; j < 3; j++)
			{
				fprintf(tabela, "%d     | %d     | %d     |\n", 1, 2, 3);
			}
			printf("\n");
		}

	}
	fclose(tabela);
}

