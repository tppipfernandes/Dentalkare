#include <stdio.h>
#include "utils.h"
#include "menu1.h"


/* Ol�* */


/**
* \brief
*
*/
void menu2(){
int op;
	do{
		printf("1 - op��o 1...\n");
		printf("2 - op��o 2...\n");
		printf("3 - op��o 3...\n");
		printf("...\n");
		printf("0 - voltar\n");
	
		scanf("d", op);
	
		switch(op){
			case 1: ;break;
			case 2: ;break;
			case 3: ;break;
			case 0: ;break;
		}
	}while( op!=0);
}




/**
* \brief
*
*/
void menu3(){
	int op;
	do{
		printf("1 - op��o 1...\n");
		printf("2 - op��o 2...\n");
		printf("3 - op��o 3...\n");
		printf("...\n");
		printf("0 - voltar\n");
	
		scanf("d", op);
	
		switch(op){
			case 1: ;break;
			case 2: ;break;
			case 3: ;break;
			case 0: ;break;
		}
	}while( op!=0);
}



/**
* \brief
*
*/
void mainmenu(){
	int op;
	do{
		printf("1 - op��o 1...\n");
		printf("2 - op��o 2...\n");
		printf("3 - op��o 3...\n");
		printf("...\n");
		printf("0 - voltar\n");
	
		scanf("%d", &op);
	
		switch(op){
			case 1: menu1();break;
			case 2: menu2();break;
			case 3: menu3();break;
			case 0: return ;break;
		}
	}while( op != 0);
}


int main (){
		NOME n;
		printf("nome=");
		lerStringComEspacos(n);
		printf("Ola %s\n\n",n);
		mainmenu();
		printf("bye");
}
