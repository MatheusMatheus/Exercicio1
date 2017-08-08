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
	}
}

void alteraProduto(struct tProduto *produto, int indice) {
	char titulo[150];
	organizaTitulo(titulo, produto);
	int alterar = lerIntLimite(titulo, 1, 4); 
    if(alterar == 1) {
        produto[indice].preco = lerFloat("Insira o novo preco do produto: ");
    } else if (alterar == 2) {
        lerString(produto[indice].descricao, "\nInsira a nova descricao do produto: ", "\nErro ao ler String");
    } else if(alterar == 3) {
        produto[indice].preco = lerFloat("Insira o novo preco do produto: ");
        lerString(produto[indice].descricao, "\nInsira a nova descricao do produto: ", "\nErro ao ler String");       
    }

    // switch(alterar) {
    //     case 1:
    //         produto[indice].preco = lerFloat("Insira o novo preco do produto: ");
    //         break;
        
    //     case 2:
    //         lerString(produto[indice].descricao, "\nInsira a nova descricao do produto: ", "\nErro ao ler String");
    //         break;

    //     case 3:
    //         produto[indice].preco = lerFloat("Insira o novo preco do produto: ");
    //         lerString(produto[indice].descricao, "\nInsira a nova descricao do produto: ", "\nErro ao ler String");
    //         break;

    //     case 4:
    //         break;
    // }
}

int pesquisarIndice(int qtdProdutos, int codigo, struct tProduto *produtos) {
	int i = INT_MIN;
	for(i = 0; i < qtdProdutos; i++) {
		if(codigo == produtos[i].codigo) {
			break;
		}
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

// Retorna TRUE se encontrar - Retorna FALSE se nao encontrar
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

void organizaTitulo(char *titulo, struct tProduto *produto) {
	sprintf(titulo, "%-20.20s%d\n%-20.20s%.2f\n%-20.20s%s ", "Codigo", produto->codigo, "Preco", produto->preco, "Descricao", produto->descricao);
	strcat(titulo, "\n\n\n1 - Alterar preco\n2 - Alterar descricao\n3 - Alterar ambos\n4 - Voltar\nOpcao: ");
}