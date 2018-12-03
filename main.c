#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_tabelas.h"

int main()
{
	int comando;
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
