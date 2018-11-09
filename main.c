#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structs ainda sem uso*/
typedef struct tabela_t
{
	char nome[20+1];
	int linha;
	int coluna;
	char tamanho[50+1][50+1];
	unsigned int chave_p;
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
void nova_linha(); // adiciona uma nova linha na tabela escolhida
void editar_valores(); // modifica os valores coluna a coluna dado o numero da chave primaria

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
			listar_tab();
			break;
		case 3:
			//nova_linha();
			break;
		case 4:
			//editar_valores();
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
	/*printf("3 - Criar nova linha na tabela;\n");
	printf("4 - Editar os valores de uma tabela;\n");
	printf("5 - Criar nova coluna na tabela;\n");
	printf("6 - Listar todos os dados de uma tabela;\n");
	printf("7 - Pesquisar valor em uma tabela;\n");
	printf("8 - Apagar valor de uma tabela;\n");
	printf("9 - Apagar uma tabela;\n");
	printf("0 - Encerrar o programa.\n");*/
	puts("");
}

void criar_tab()
{
	/*funcao sem fazer uso das structs no momento*/
	FILE *tabela;
	FILE *BD_tabelas;
	char nome_tabela[20+1];
	char nome_tab[20+1];
	char chave_p[20];
	int cont_chave = 0;
	int i, j;

	/*guarda a tabela criada no arquivo que servirá como banco de dados dos nomes das tabelas*/
	BD_tabelas = fopen("tabelasSGBD.txt", "a+");
	//fprintf(BD_tabelas, "%s\n", nome_tabela);

	printf("Informe um nome para a tabela a ser criada: ");
	scanf("%s", nome_tabela);
	
	/*verifica no banco de tabelas se o nome fornecido já existe*/
	while(fscanf(BD_tabelas, "%s", nome_tab) != EOF)
	{
		if(strcmp(nome_tab, nome_tabela) == 0) //se a tabela já existe, encerra o programa e informa ao usuario
		{
			printf("Essa tabela já existe\nInforme outro nome, por favor.\n");
			exit(1);
		}
	}
	
	/*se já nao existir uma tabela com o nome fornecido, entao a nova tabela é adicionada ao banco de tabelas*/
	fprintf(BD_tabelas, "%s\n", nome_tabela);

	tabela = fopen(nome_tabela, "w+");

	if(tabela == NULL)
	{
		/*em caso de erro na alocação*/
		printf("Erro na abertura do arquivo!\n"); 
	}
	else
	{
		/*recebe a chave primaria*/
		printf("Digite o nome da chave primaria: ");
		scanf("%s", chave_p);
	
		/*imprime uma tabela simples no arquivo 'tabela', para saber se o programa funciona*/
		fprintf(tabela, "%s\t| nome1\t| nome2\t| nome3\t|\n", chave_p);
		for(i = 0; i < 5; i++)
		{
			cont_chave++;
			fprintf(tabela, " %d\t| %d\t| %d\t| %d\t|\n", cont_chave, 45, 67, 78);
		}

	}
	
	/*fecha os arquivos abertos anteriormente*/
	fclose(tabela);
	fclose(BD_tabelas);
}

void listar_tab()
{
	FILE *BD_tabelas;
	char nome_tab[20];
	
	printf("Tabelas Existentes:\n\n");

	/*acessa o arquivo com a lista de todas as tabelas que já foram criadas*/
	BD_tabelas = fopen("tabelasSGBD.txt", "r+");
	
	/*enquanto o arquivo nao terminar de ser lido, imprime os nomes das tabelas existentes*/
	while(fscanf(BD_tabelas, "%s", nome_tab) != EOF)
	{
		printf("%s\n", nome_tab);
	}
	
	/*fecha o arquivo aberto anteriormente*/
	fclose(BD_tabelas);
}
