#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "Geral.h"
#include "Main.h"
#include "Leitura.c"
#include "DAO.c"

#define TAMANHO 20

int main(void){
	int opcao, qtdProduto = 0;
	char titulo[50];
	
	struct tProduto produtos[TAMANHO];
	do {
		system(CLRSCR);
		sprintf(titulo, "\n%s\n%s\n%s\n%s\n%s\n%s: ", "1 - Incluir", "2 - Listar", "3 - Alterar", "4 - Pesquisar", "5 - Sair", "Opcao");
		opcao = lerIntLimite(titulo, 1, 5);		
		
		switch(opcao) {
			case 1:
				incluir(qtdProduto++, produtos);
				break;
				
			case 2:
				listar(qtdProduto, produtos);
				getch();
				break;

			case 3:
				alterar(qtdProduto, produtos);
				break;
			
			case 4:
				pesquisarCodigo(qtdProduto, produtos);
				break;

			case 5:
				printf("Programa finalizado!\n");
				break;
				
			default:
				printf("\n\nOpcao invalida, escolha novamente");
				getch();
		}
	} while (opcao != 5 && qtdProduto < TAMANHO);
}
