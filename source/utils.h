#define MAX_NAME_LEN 50

typedef char NOME[MAX_NAME_LEN];

char lechar(){
	char c;
	scanf("%c", &c);
	return c;
}

void lerStringComEspacos(NOME &nome){
	strupr(nome);
	scanf("%[^\n]s",nome);
}

