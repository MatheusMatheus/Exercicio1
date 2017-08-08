
// Em sistemas Windows usar cls
// Em sistemas Linux usar clear
#define CLRSCR "clear"

#define FALSE 0
#define TRUE 1

#define INTEIRO "%d"
#define FLOAT "%f"
#define DOUBLE "%lf"
#define STRING "%s"

void getch() {
    printf("\nPressione qualquer tecla para continuar...");
    getc(stdin);
    getc(stdin);
    fflush(stdin);
}
