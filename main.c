#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enum tipos = {};

typedef struct chave_primaria
{
	char *nome;
	unsigned int contador;
}Chave_P;

typedef struct coluna_t
{
	char *nome_coluna;
	char *tipo_coluna;
}Coluna;

typedef struct tabela_t
{
	char nome[20+1];
	int linhas;
	int colunas;
//	char tamanho[50+1][50+1];
	Coluna ptr_col[50];
	Chave_P chave_pri;
}Tabela;

void comandos(); // imprime os comandos na tela
void criar_tabela(); // cria um arquivo com uma tabela 
void listar_tabela(); // lista todos os arquivos-tabela
void nova_linha(); // adiciona uma nova linha na tabela escolhida
void editar_valores(); // modifica os valores coluna a coluna dado o numero da chave primaria
void listar_dados_tabela(); // lista todos os dados da tabela
void apagar_tabela(); // apaga a tabela com o nome fornecido

int main()
{
	int comando;
	FILE *p_arquivo;
	Tabela *ptr_tabela;

	ptr_tabela = malloc(sizeof(Tabela)*1);
	
	printf("----------------------------------------------------- SGBD - ITP --------------------------------------------------------\n");

	comandos();
	
	printf("Digite um comando: ");
	scanf("%d", &comando);
	
	/*verifica quais os comandos fornecidos*/
	switch(comando)
	{
		case 1:
			criar_tabela();
			break;
		case 2:
			listar_tabela();
			break;
		case 3:
			nova_linha();
			break;
		case 4:
			//editar_valores();
			break;
		case 6:
			listar_dados_tabela();
			break;
		case 9:
			apagar_tabela();
				break;
		case 0:
			printf("fim do programa\n");
			break;
		default:
			printf("Comando inválido! Tente novamente.\n"); // caso o comando recebido nao esteja entre 0 e 9
	}

	free(ptr_tabela);

	return 0;
}

void comandos()
{
	/*menu de comandos*/
	printf("Lista de Comandos:\n");
	printf("1 - Criar uma tabela;\n");
	printf("2 - Listar todas as tabelas;\n");
	printf("3 - Criar nova linha na tabela;\n");
	/*printf("4 - Editar os valores de uma tabela;\n");
	printf("5 - Criar nova coluna na tabela;\n");*/
	printf("6 - Listar todos os dados de uma tabela;\n");
	/*printf("7 - Pesquisar valor em uma tabela;\n");
	printf("8 - Apagar valor de uma tabela;\n");*/
	printf("9 - Apagar uma tabela;\n");
	printf("0 - Encerrar o programa.\n");
	puts("");
}

void criar_tabela()
{
	FILE *tabela;
	FILE *BD_tabelas;
	char nome_tabela[20+1];
	char nome_tab[20+1];
	char chave_p[20];
	int cont_chave = 0;
	int n_colunas;
	int i, j;
	char *nome_coluna, *tipo_coluna;

	/*Abre o arquivo banco de dados com os nomes das tabelas existentes*/
	BD_tabelas = fopen("tabelasSGBD.txt", "a+");
	//fprintf(BD_tabelas, "%s\n", nome_tabela);

	printf("Informe um nome para a tabela a ser criada: ");
	scanf("%s", nome_tabela);

	/*verifica no banco de tabelas se o nome fornecido já existe*/
	while(fscanf(BD_tabelas, "%s", nome_tab) != EOF)
	{
		if(strcmp(nome_tab, nome_tabela) == 0) //se a tabela já existe, encerra o programa e informa ao usuario
		{
			printf("Essa tabela já existe\nTente novamente com outro nome, por favor.\n");
			exit(1);
		}
	}
	
	/*se nao existir uma tabela com o nome fornecido, entao a nova tabela é adicionada ao banco de tabelas*/
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
		
		/*recebe o numero de colunas*/
		printf("quantas colunas terá a nova tabela?: ");
		scanf("%d", &n_colunas);
		
		char coluns[n_colunas][20];
		char tipo_coluns[n_colunas][10];

		fprintf(tabela, "| %s |", chave_p);
		
		for(i = 0; i < n_colunas; i++)			
		{
			printf("informe o nome da coluna:\n");
			scanf("%s", coluns[i]);  

			printf("tipo da coluna:\n");	
			scanf("%s", tipo_coluns[i]);
			
		}
		
		for(i = 0; i < n_colunas; i++)
		{
			fprintf(tabela, " %s (%s) |", coluns[i], tipo_coluns[i]);
		}
	
	}
	
	/*fecha os arquivos abertos anteriormente*/
	fclose(tabela);
	fclose(BD_tabelas);
}

void listar_tabela()
{
	FILE *BD_tabelas;
	char nome_tab[20];
	
	printf("Tabelas Existentes:\n");

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

void nova_linha()
{
	char *nome_tabela;
	char *valor_coluna;
	char *nome_tab;
	int quant_valores, i;
	unsigned int chave_pri;
	FILE *tabela;
	FILE *BD_tabelas;

	printf("qual a tabela?: ");	
	scanf("%s", nome_tabela);

	printf("quantos valores serão informados?: ");
	scanf("%d", &quant_valores);

	printf("valor da chave primaria: ");
	scanf("%u", &chave_pri);

	/*abre a tabela informada*/
	tabela = fopen(nome_tabela, "a+");

	if(tabela == NULL)
	{
		printf("Erro na abertura do arquivo\n");
	}
	else
	{
		fprintf(tabela, "\n| %u |", chave_pri);

		for(i = 0; i < quant_valores; i++)
		{
			printf("valor da coluna: ");
			scanf("%s", valor_coluna);

			fprintf(tabela, " %s |", valor_coluna);
		}
	}
	fclose(tabela);
}

void listar_dados_tabela()
{
	char *nome;
	char linha[1024];
	FILE *tabela;

	printf("nome da tabela: ");
	scanf("%s", nome);

	tabela = fopen(nome, "r");

	if(tabela == NULL)
	{
		printf("Impossivel abrir a tabela\n");
	}
	else
	{
		while(fgets(linha, sizeof(linha), tabela) != NULL)
		{
			printf("%s", linha);
		}
	}
	fclose(tabela);
}

void apagar_tabela()
{
	char *nome;
	char *nome_aux;
	char linha[20], *tabela;
	FILE *arquivo_inicial, *arquivo_post;

	printf("informe o nome da tabela: ");
	scanf("%s", nome);

	//abre o arquivo de tabelas salvas no modo leitura
	arquivo_inicial = fopen("tabelasSGBD.txt", "r");
	
	//abre um arquivo auxiliar para receber os nomes das tabelas, com exceçao daquele que se quer apagar
	arquivo_post = fopen("tabelasSGBD", "w");

	while((fgets(linha, sizeof(linha), arquivo_inicial)) != NULL)
	{
		tabela = strtok(linha, "");
		if(strcmp(tabela, nome) != 0) //verifica se o nome na tabela é igual ao nome da tabela que se quer apagar
		{
			fprintf(arquivo_post, "%s\n", tabela); // se os nomes forem diferentes, copia-se a string 'tabela' para o novo arquivo
		}
	}
	
	/*fecha os arquivos abertos inicialmente*/
	fclose(arquivo_post);
	fclose(arquivo_inicial);
	remove("tabelasSGBD.txt"); //apaga o antigo arquivo que lista as tabelas existentes
	rename("tabelasSGBD", "tabelasSGBD.txt"); // muda o nome do novo arquivo para o nome padrao 'tabelasSGBD.txt'
}
