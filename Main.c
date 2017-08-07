#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Geral.h"
#include "Main.h"
#include "Leitura.c"

#define TAMANHO 20

int main(void){
	int opcao, qtdProduto = 0;
	char titulo[50];
	
	struct tProduto produtos[TAMANHO];
	do {
		system(CLRSCR);
		sprintf(titulo, "\n%s\n%s\n%s\n%s\n%s: ", "1 - Incluir", "2 - Listar", "3 - Alterar", "4 - Sair", "Opcao");
		opcao = lerIntLimite(titulo, 1, 4);		
		
		switch(opcao) {
			case 1:
				incluir(qtdProduto++, produtos);
				break;
				
			case 2:
				listar(qtdProduto, produtos);
				break;

			case 3:
				alterar(qtdProduto, produtos);
				break;
			
			case 4:
				printf("Programa finalizado!\n");
				break;
				
			default:
				printf("\n\nOpcao invalida, escolha novamente");
				getch();
		}
	} while (opcao != 4 && qtdProduto < TAMANHO);
}

void incluir(int posicao, struct tProduto *produto) {
	system(CLRSCR);
	printf("Incluir produto...\n");
	int codigoValido;
	do {
		produto[posicao].codigo = lerInt("Insira o codigo do produto: ");
		codigoValido = validaCodigo(posicao, produto[posicao].codigo, produto);
		if(codigoValido == TRUE) {
			printf("Codigo ja existente\nTente novamente\n");
		}
	} while(codigoValido == TRUE);

	produto[posicao].preco = lerFloat("Insira o preco do produto: ");
	lerString(produto[posicao].descricao, "Insira a descricao do produto: ", "\nErro ao ler String");
}

void listar(int qtdProdutos, struct tProduto *produto) {
	int i;
	system(CLRSCR);
	if(qtdProdutos == 0) {
		printf("\nNao ha produtos cadastrados...");
	} else {
		printf("Lista de produtos...");
		printf("\n%-10.10s%-10.10s%-20.20s\n", "Codigo", "Preco", "Descricao");
		for(i = 0; i < qtdProdutos; i++) {
			printf("%-10d%-10.2f%-20.20s\n", produto[i].codigo, produto[i].preco, produto[i].descricao);
		}	
		getch();
	}
}

void alterar(int qtdProdutos, struct tProduto *produtos) {
	int produto;
	printf("Alterando dados...");
	listar(qtdProdutos, produtos);	
	if(qtdProdutos > 0) {
		produto = lerInt("\nSelecione um produto por seu código\n");
	}

}

// Retorna TRUE se encontrar - Retorna FALSE se não encontrar
int validaCodigo(int qtdProdutos, int codigo, struct tProduto *produtos) {
	int i;
	system(CLRSCR);
	for(i = 0; i < qtdProdutos; i++) {
		if (produtos[i].codigo == codigo) {
			return TRUE;
		}
	}
	return FALSE;
}

