#include <stdio.h>
#include <windows.h>

#define N 100

typedef struct
{
	int id_tratamento;
	char tipo_tratamento[N];
	float custo_tratamento;
	char data_validade;
}tratamentos;

/**
* \brief adicionar novo TRATAMENTO
*
*/
void addTratamento()
{
	system("cls");
	//char nome[100], morada[100], email[100];
	//int idade;
	
	printf("\n\n\tADICIONAR TRATAMENTO");
	
	//printf("\nTIPO TRATAMENTO: "); //scanf("%c", &nome);
	
	printf("\n\n\nTRATAMENTO ADICIONADO!");
	
	//getch();
}
/**
* \brief remover TRATAMENTO
*
*/
int removeTratamento()
{
	system("cls");
	//char nome[100];
	//int idade;
	
	printf("\n\n\tREMOVER TRATAMENTO");
	
	//printf("Insira o no do tratamento: ");	//scanf("%c", &nome);
	
	printf("\n\n\TRATAMENTO REMOVIDO!");
	
	//getch();
}
/**
* \brief modificar TRATAMENTO existente
*
*/
int modifyTratamento()
{
	system("cls");
	//char nome[100];
	//int idade;
	
	printf("\n\n\tMODIFICAR TRATAMENTO");
	
	printf("\nINSIRA O No DO TRATAMENTO PARA MODIFICAR: "); //scanf("%c", &nome);
	
	printf("\n\n\TRATAMENTO MODIFICADO!");
	
	//getch();
}
/**
* \brief mostrar todos os TRATAMENTOS
*
*/
int showTratamento()
{
	system("cls");
	//char nome[100], morada[100], email[100];
	//int idade;
	
	printf("\n\n\tMOSTRAR TODOS OS TRATAMENTOS");
	
	printf("====================================================\n");
	printf("A/c no.      NAME           Type  Balance\n");
	printf("====================================================\n");

	//getch();
}
/**
* \brief menu TRATAMENTO
*
*/
void menuTratamentos()
{
	int opcao;
	do
	{
		system("cls");
		printf("================ MENU TRATAMENTOS ================");
		printf("\n\n\n\t[1] - ADICIONAR TRATAMENTO");
		printf("\n\n\n\t[2] - REMOVER TRATAMENTO");
		printf("\n\n\n\t[3] - MODIFICAR TRATAMENTO");
		printf("\n\n\n\t[4] - MOSTRAR TODOS TRATAMENTOS");
		printf("\n\n\n\t[0] - VOLTAR ATRAS");
		printf("\n\n\nESCOLHA OPCAO: ");	scanf("%d", &opcao);
	
		switch(opcao)
		{
			case 1: addTratamento(); break;
			case 2: removeTratamento(); break;
			case 3: modifyTratamento(); break;
			case 4: showTratamento(); break;
			case 0: return;break;
			default: printf("\n\t\tCODIGO INVALIDO"); getch(); break;
		}
	}while(opcao != 0);
}
