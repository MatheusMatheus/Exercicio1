#include "Util.c"

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
	lerString(produto[posicao].descricao, "\nInsira a descricao do produto: ", "\nErro ao ler String");
}

void listar(int qtdProdutos, struct tProduto *produto) {
	int i;
	system(CLRSCR);
	if(qtdProdutos == 0) {
		printf("\nNao ha produtos cadastrados...");
	} else {
		printf("\nLista de produtos...");
		printf("\n%-10.10s%-10.10s%-20.20s\n", "Codigo", "Preco", "Descricao");
		for(i = 0; i < qtdProdutos; i++) {
			printf("%-10d%-10.2f%-20.20s\n", produto[i].codigo, produto[i].preco, produto[i].descricao);
		}	
	}
}

void alterar(int qtdProdutos, struct tProduto *produtos) {
	int codigo, indice;
	printf("Alterando dados...");
	if(qtdProdutos > 0) {
		codigo = pesquisarCodigo(qtdProdutos, produtos);
		indice = pesquisarIndice(qtdProdutos, codigo, produtos);
		if(indice != INT_MIN) 
			alteraProduto(produtos, indice);
		else {
			system(CLRSCR);
			printf("\nProduto nao encontrado...");
			getch();	
		}
	} else {
		system(CLRSCR);
		printf("\nNao ha produtos cadastrados...");
		getch();
	}
}

void alteraProduto(struct tProduto *produto, int indice) {
	char titulo[150];
	int flag = FALSE;
	organizaTitulo(titulo, &produto[indice]);
	int alterar = lerIntLimite(titulo, 1, 4);   

	switch(alterar) {
		case 1:
			produto[indice].preco = lerFloat("Insira o novo preco do produto: ");
			flag = TRUE;
			break;
		
		case 2:
			lerString(produto[indice].descricao, "\nInsira a nova descricao do produto: ", "\nErro ao ler String");
			flag = TRUE;
			break;
		
		case 3:
			produto[indice].preco = lerFloat("Insira o novo preco do produto: ");
			lerString(produto[indice].descricao, "\nInsira a nova descricao do produto: ", "\nErro ao ler String");
			flag = TRUE;
			break;
		
		case 4:
			break;
	}
   
    if(flag == TRUE) {
    	printf("Alteracao realizada com sucesso!");
    	getch();
	}
}

int pesquisarIndice(int qtdProdutos, int codigo, struct tProduto *produtos) {
	int i = INT_MIN;
	for(i = 0; i < qtdProdutos; i++)
		if(codigo == produtos[i].codigo){
			break;
		}
	return i;
}

int pesquisarCodigo(int qtdProdutos, struct tProduto *produtos) {
	int codigo, prodExiste = FALSE;
	while(prodExiste == FALSE && qtdProdutos > 0) {
        listar(qtdProdutos, produtos);
		codigo = lerInt("\nSelecione um produto por seu codigo: ");
		prodExiste = validaCodigo(qtdProdutos, codigo, produtos);
		if(prodExiste == FALSE) {
			printf("O produto selecionado nao existe\nTente novamente\n");
			getch();				
		}
	}
	return codigo;
}

struct tProduto pesquisarProduto(int qtdProdutos, struct tProduto *produtos) {
	int indice;
	int codigo;
	if(qtdProdutos > 0) {
		codigo = pesquisarCodigo(qtdProdutos, produtos);
		indice = pesquisarIndice(qtdProdutos, codigo, produtos);
		return produtos[indice];
	} else {
		system(CLRSCR);
		printf("Nao ha produtos cadastrados");
		getch();
		return;
	}
	
}

void mostrarProduto(struct tProduto *produto) {
	printf("\n%-10.10s%-10.10s%-20.20s\n", "Codigo", "Preco", "Descricao");	
	printf("%-10d%-10.2f%-20.20s\n", produto->codigo, produto->preco, produto->descricao);
	getch();
}

int excluir(int qtdProduto, struct tProduto *produtos) {
	int i, codigo, indice, confirma;
	struct tProduto temp;
	char titulo[100];
	
	if(qtdProduto > 0) {
		codigo = pesquisarCodigo(qtdProduto, produtos);
		sprintf(titulo, "Confirmar exlusao do produto %d?\n%s\n%s: ", codigo, "1 - Sim\n2 - Nao", "Opcao");
		confirma = lerIntLimite(titulo, 1, 2);
		if(confirma == TRUE) {
			indice = pesquisarIndice(qtdProduto, codigo, produtos);
			for (i = indice; i < (qtdProduto)-1; i++)
				produtos[i] = produtos[i+1];
	
			produtos[i].codigo = 0;
			stringNull(produtos[i].descricao);
			produtos[i].preco = 0;	
				
			printf("\nProduto %d excluido com sucesso!", codigo);
			getch();
			return TRUE;
		} else {
			return FALSE;
		}
	} else {
		system(CLRSCR);
		printf("Nao ha produtos cadastrados");
		getch();
		return FALSE;
	}
}


