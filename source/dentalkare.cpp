#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <fstream> //inclui a biblioteca fstream, para usar o ofstream e ifstream
#include "utils.h"
#include "menuPaciente.h"
#include "menuTratamentos.h"
#include "menuConsulta.h"
#include "menuGestao.h"

/**
* \brief GOTOXY definir coluna e linha
*
*/
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}                 // Nota: No Turbo-C esta funcao ja esta incluida 

/**
* \brief menu PRINCIPAL
*
*/
/*
void mainmenu()
{	
	system("cls");
	system("color f0");
	NOME n;
	printf("NOME: ");
	lerStringComEspacos(n);
	printf("BEM VINDO AO DENTALKARE, %s\n\n",n);
	int opcao;	
	do{
		printf("\n\t\tMENU PRINCIPAL");
		printf("\n\n\t[1] - PACIENTE\n");
		printf("\n\n\t[2] - TRATAMENTOS\n");
		printf("\n\n\t[3] - CONSULTA\n");
		printf("\n\n\t[4] - GESTAO\n");
		printf("\n\n\t[0] - TERMINAR\n\n");
		printf("\n\nESCOLHA OPCAO: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1: menuPaciente();break;
			case 2: menuTratamentos(); break;
			case 3: menuConsulta();break;
			case 4: menuGestao();break;
			case 0: return ;break;
		}
	}while(opcao != 0);
}
*/

int main ()
{
	system("color f0");
	NOME n;
	printf("NOME: ");
	lerStringComEspacos(n);
	printf("\n\n================ BEM VINDO AO DENTALKARE, %s ================\n\n",n);
	getch();
	//mainmenu();
	
	int opcao;	
	do{
		system("cls");
		printf("================ MENU PRINCIPAL ================");
		printf("\n\n\n\t[1] - PACIENTE\n");
		printf("\n\n\n\t[2] - TRATAMENTOS\n");
		printf("\n\n\n\t[3] - CONSULTA\n");
		printf("\n\n\n\t[4] - GESTAO\n");
		printf("\n\n\n\t[0] - TERMINAR\n\n");
		printf("\n\n\nESCOLHA OPCAO: ");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case 1: menuPaciente();break;
			case 2: menuTratamentos(); break;
			case 3: menuConsulta();break;
			case 4: menuGestao();break;
			case 0: exit (1);break;
		}
	}while(opcao != 0);
	
	printf("\n\n\n\tPROGRAMA FINALIZADO!\n\n\t MUITO OBRIGADO POR TER USADO ESTE PROGRAMA");
	printf("\n\n\nQUALQUER TECLA PARA TERMINAR."); //getch();
}

