#include <stdio.h>
#include <windows.h>
#include <fstream> //inclui a biblioteca fstream, para usar o ofstream e ifstream

#define N 100

typedef struct
{
	int id_Paciente;
	char nome_Paciente[N];
	char morada[N];
	char email[N];
	int telemovel[9];
	int idade;
	int total_dentes;
}paciente;


/**
* \brief adicionar novo PACIENTE
*
*/
void addPaciente()
{
	system("cls");
	char nome[100], morada[100], email[100];
	int idade;
	
	printf("\n\n\tADICIONAR PACIENTE");
	
	printf("\nNOME PACIENTE: "); scanf("%c", &nome);
	printf("\nIDADE PACIENTE: "); scanf("%d", &idade);
	printf("\nMORADA PACIENTE: "); scanf("%c", &morada);
	printf("\nE-MAIL PACIENTE: "); scanf("%c", &email);
	
	printf("\n\n\nPACIENTE ADICIONADO!");
	//getch();
}

/**
* \brief remover PACIENTE existente
*
*/
int removePaciente()
{
	system("cls");
	char nome[100];
	//int idade;
	
	printf("\n\n\tREMOVER PACIENTE");
	
	printf("Insira nome do paciente: ");	scanf("%c", &nome);
	
	printf("\n\n\nPACIENTE REMOVIDO!");
	
	//getch();
}

/**
* \brief modificar PACIENTE existente
*
*/
int modifyPaciente()
{
	system("cls");
	char nome[100];
	//int idade;
	
	printf("\n\n\tMODIFICAR PACIENTE");
	
	printf("\nINSIRA O NOME DO PACIENTE PARA MODIFICAR: "); scanf("%c", &nome);
	
	printf("\n\n\nPACIENTE MODIFICADO!");
	
	//getch();
}

/**
* \brief mostrar todos os PACIENTES
*
*/
int showPaciente()
{
	system("cls");
	//char nome[100], morada[100], email[100];
	//int idade;
	
	printf("\n\n\tMOSTRAR TODOS OS PACIENTES");
	
	printf("====================================================\n");
	printf("no.      NAME           Type  Balance\n");
	printf("====================================================\n");

	//getch();
}

/**
* \brief menu PACIENTE
*
*/
void menuPaciente()
{
	int opcao;
	do
	{
		system("cls");
		printf("================ MENU PACIENTE ================");
		printf("\n\n\n\t[1] - ADICIONAR PACIENTE");
		printf("\n\n\n\t[2] - REMOVER PACIENTE");
		printf("\n\n\n\t[3] - MODIFICAR PACIENTE");
		printf("\n\n\n\t[4] - MOSTRAR TODOS PACIENTES");
		printf("\n\n\n\t[0] - VOLTAR ATRAS");
		printf("\n\n\nESCOLHA OPCAO: ");	scanf("%d", &opcao);
	
		switch(opcao)
		{
			case 1: addPaciente(); break;
			case 2: removePaciente(); break;
			case 3: modifyPaciente(); break;
			case 4: showPaciente(); break;
			case 0: return;break;
			default: printf("\n\t\tCODIGO INVALIDO"); getch(); break;
		}
	}while(opcao != 0);
}
