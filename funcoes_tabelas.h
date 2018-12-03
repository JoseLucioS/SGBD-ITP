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

