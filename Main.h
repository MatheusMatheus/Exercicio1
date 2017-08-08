#include "Struct.h"
void incluir(int posicao, struct tProduto *produto);
void listar(int qtdProdutos, struct tProduto *produto);
void alterar(int qtdProdutos, struct tProduto *produtos);
int validaCodigo(int qtdProdutos, int codigo, struct tProduto *produtos);
int pesquisarIndice(int qtdProdutos, int codigo, struct tProduto *produtos);
int pesquisarCodigo(int qtdProdutos, struct tProduto *produtos) ;
void alteraProduto(struct tProduto *produto, int indice) ;
void organizaTitulo(char *titulo, struct tProduto *produto);
