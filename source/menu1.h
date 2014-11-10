/**
* \brief
*
*/
void funcao1(){
	// ...
	char c = lechar();
}


/**
* \brief
*
*/
void menu1(){
int op;
	do{
		printf("1 - opção 1...\n");
		printf("2 - opção 2...\n");
		printf("3 - opção 3...\n");
		printf("...\n");
		printf("0 - voltar\n");
	
		scanf("d", op);
	
		switch(op){
			case 1: funcao1() ;break;
			case 2: ;break;
			case 3: ;break;
			case 0: ;break;
		}
	}while( op!=0);
}
