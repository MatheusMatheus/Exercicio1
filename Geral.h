
// Em sistemas Windows usar cls
// Em sistemas Linux usar clear
#define CLRSCR "cls"

#define PAUSAR "read -n1"

#define FALSE 0
#define TRUE 1

#define INTEIRO "%d"
#define FLOAT "%f"
#define DOUBLE "%lf"
#define STRING "%s"

void getch() {
    getchar();
    fflush(stdin);
}
