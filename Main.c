// Síntese: Implementação de programa de computador que realize um CRUD. 
// Autor  : Matheus dos Santos Rodrigues
// Data   : 08/08/2017

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
	struct tProduto produtos[TAMANHO];
	struct tProduto produto;
	int opcao;
	int qtdProduto = 0;
	char titulo[50];

	do {
		system(CLRSCR);
		sprintf(titulo, "\n%s\n%s\n%s\n%s\n%s\n%s\n%s: ", "1 - Incluir", "2 - Listar", "3 - Alterar", "4 - Pesquisar", "5 - Excluir", "6 - Sair", "Opcao");
		opcao = lerIntLimite(titulo, 1, 6);		
		
		switch(opcao) {
			case 1:
				if (qtdProduto < TAMANHO)
					incluir(qtdProduto++, produtos);
				else {
					printf("Nao e possivel inserir mais produtos");
					getch();
				}
				break;
				
			case 2:
				listar(qtdProduto, produtos);
				getch();
				break;

			case 3:
				alterar(qtdProduto, produtos);
				break;
			
			case 4:
				produto = pesquisarProduto(qtdProduto, produtos);
				if(qtdProduto > 0)
					mostrarProduto(&produto);
				break;
				
			case 5:
				if(excluir(qtdProduto, produtos) == TRUE)
					qtdProduto--;
				break;

			case 6:
				printf("Programa finalizado!\n");
				break;
		}
	} while (opcao != 6);
}
