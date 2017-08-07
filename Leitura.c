#include "Leitura.h"


int lerInt(char *titulo) {
	int ret;
	int  num;
	do {
		printf("%s", titulo);
		fflush(stdin);		
		ret = scanf("%d", &num);
		if(ret != 1) {
			printf("%s", "Erro ao ler numero");
		}
	}while(ret != 1);
	return num;
}


int lerIntLimite(char *titulo, int min, int max) {
	int num;
	char aux[80];
	do {
		system(CLRSCR);
		num = lerInt(titulo);
		if (num < min || num > max) {
			sprintf(aux, "\nO numero deve estar entre %d e %d.", min, max);
			printf("%s", aux);
			getch();
		}
	} while(num < min || num > max);
	return num;
}

float lerFloatLimite(char *titulo, float min, float max) {
	float num;
	char aux[80];
	do {
		system(CLRSCR);
		num = lerFloat(titulo);
		if (num < min || num > max) {
			sprintf(aux, "\nO numero deve estar entre %f e %f.", min, max);
			printf("%s", aux);
			getchar();getchar();
		}
	} while(num < min || num > max);
	return num;
}

float lerFloat(char *titulo) {
	int ret;
	float num;
	do {
		printf("%s", titulo);
		fflush(stdin);
		ret = scanf("%f", &num);
		fflush(stdin);
		if(ret != 1) {
			printf("%s", "Erro ao ler numero");
		}
	}while(ret != 1);
	return num;
}

void lerString(char *str, char *titulo, char*msgErro) {
	do {

		system(CLRSCR);
		printf("%s", titulo);
		fflush(stdin);
		if(fgets(str, 30, stdin) != NULL) {
			validaString(str);
		} 
		if (strlen(str) == 0){
			system(CLRSCR);
			printf("%s", msgErro);
			
		}
	}while(strlen(str) == 0);
}

void validaString(char *str) {
	if(str[strlen(str) -1] == '\n')
		str[strlen(str) -1] = '\0';
}

