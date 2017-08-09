
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

void stringNull(char *str) {
	int i;
	for(i = 0; i < *str; i++) {
		str[i] = NULL;
	}
}

