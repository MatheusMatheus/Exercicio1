#include "Struct.h"
void incluir(int posicao, struct tProduto *produto);
void listar(int qtdProdutos, struct tProduto *produto);
void alterar(int qtdProdutos, struct tProduto *produtos);
int validaCodigo(int qtdProdutos, int codigo, struct tProduto *produtos);
struct tProduto *pesquisar(int qtdProdutos, int codigo, struct tProduto *produtos);
void alteraProduto(struct tProduto *produto);
