//Projeto Modulo Tematico LTIC 2014/15
//DentalKare - Software Gestao para Clinica Dentaria
//"dentalkare"

/**
* \file
* \brief Projeto Modulo Tematico LTIC 2014/2015 "dentalkare.c"
* \details "dentalkare.c" implementa o menu Principal
* \date 9 dez 2014
*/
#include <stdio.h>
#include <cstdlib>
#include <conio.h>

#include "menuPaciente.h"
#include "menuTratamento.h"
#include "menuConsulta.h"
#include "menuGestao.h"

/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "paciente.txt"
* \param p : listaPaciente
*/
int main(void)
{
	system("color 2");
	printf("\n\n");
	printf("\n	-------------------------------------------------------");
	printf("\n	-------------------------------------------------------");
	printf("\n	---------------                         ---------------");
	printf("\n	---------------        BEM VINDO        ---------------");
	printf("\n	---------------                         ---------------");
	printf("\n	---------------                         ---------------");
	printf("\n	---------------           A             ---------------");
	printf("\n	---------------                         ---------------");
	printf("\n	---------------                         ---------------");
	printf("\n	---------------        DENTALKARE       ---------------");
	printf("\n	---------------                         ---------------");
	printf("\n	-------------------------------------------------------");
	printf("\n	-------------------------------------------------------\n");
	getch();
	
	char op;
	do
	{
		system("cls");
		printf("\n---------------   MENU PRINCIPAL   ---------------");
		printf("\n\n	[1] - Menu Pacientes");
		printf("\n\n	[2] - Menu Tratamentos");
		printf("\n\n	[3] - Menu Consulta");
		printf("\n\n	[4] - Menu Gestao");
		printf("\n\n	[0] - Terminar Programa");
		printf("\n--------------------------------------------------");
		printf("\n\nQual Opcao: ");	scanf("%s%*c", &op);
		switch(op)
		{
			case '1': menuPaciente(); break;
			case '2': menuTratamento(); break;
			case '3': menuConsulta(); break;
			case '4': menuGestao(); break;
			case '0': printf("\n--------------------------------------------------\n");
					printf("\n\t	PROGRAMA FINALIZADO!	");
    				printf("\n\nObrigado por utilizar este programa! <Enter para Continuar>");
					exit(1); break;
			default: printf("\nOpcao Invalida"); getch(); break;
		}
	}while(op!='0' || op=='a' || op=='A');
	getch();
}
