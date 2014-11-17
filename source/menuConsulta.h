#include <stdio.h>
#include <windows.h>

typedef struct
{
	int id_Consulta;
	int id_Paciente;
	int id_Tratamento;
	char data;
	char hora;
	float duracao;
	float preco;
}consulta;

/**
* \brief adicionar nova CONSULTA
*
*/
void addConsulta()
{
	system("cls");
	//char nome[100], morada[100], email[100];
	//int idade;
	
	printf("\n\n\tADICIONAR CONSULTA");
	
	
	
	printf("\n\n\CONSULTA ADICIONADO!");
	
	//getch();
}
/**
* \brief remover CONSULTA
*
*/
int removeConsulta()
{
	system("cls");
	char nome[100];
	//int idade;
	
	printf("\n\n\tREMOVER CONSULTA");
	
	
	
	printf("\n\n\CONSULTA REMOVIDO!");
	
	//getch();
}
/**
* \brief modificar CONSULTA existente
*
*/
int modifyConsulta()
{
	system("cls");
	//char nome[100];
	//int idade;
	
	printf("\n\n\tMODIFICAR CONSULTA");
	
	//printf("\nINSIRA O NOME DO PACIENTE PARA MODIFICAR: "); scanf("%c", &nome);
	
	printf("\n\n\CONSULTA MODIFICADO!");
	
	//getch();
}
/**
* \brief mostrar todos os CONSULTA
*
*/
int showConsulta()
{
	system("cls");
	//char nome[100], morada[100], email[100];
	//int idade;
	
	printf("\n\n\tMOSTRAR TODAS AS CONSULTA");
	
	printf("====================================================\n");
	printf("A/c no.      NAME           Type  Balance\n");
	printf("====================================================\n");

	//getch();
}
/**
* \brief menu CONSULTA
*
*/
void menuConsulta()
{
	char opcao;
	do
	{
		system("cls");
		printf("================ MENU CONSULTA ================");
		printf("\n\n\n\t[1] - ADICIONAR CONSULTA");
		printf("\n\n\n\t[2] - REMOVER CONSULTA");
		printf("\n\nn\\t[3] - MODIFICAR CONSULTA");
		printf("\n\n\n\t[4] - MOSTRAR TODAS CONSULTA");
		printf("\n\n\n\t[0] - VOLTAR ATRAS");
		printf("\n\n\nESCOLHA OPCAO: ");	scanf("%c", &opcao);
	
		switch(opcao)
		{
			case '1': addConsulta(); break;
			case '2': removeConsulta(); break;
			case '3': modifyConsulta(); break;
			case '4': showConsulta(); break;
			case '0': return;break;
			default: printf("\n\t\tCODIGO INVALIDO"); getch(); break;
		}
	}while(opcao != '0');
}
