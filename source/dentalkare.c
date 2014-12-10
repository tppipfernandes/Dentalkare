// Projeto Modulo Tematico LTIC 2014/15
// DentalKare - Software Gestao para Clinica Dentaria
// "dentalkare"

/* !
* \ file
* \ brief Projeto Modulo Tematico LTIC 2014/2015 "dentalkare.c"
* \ details "dentalkare.c" implementa o menu Principal
* \ author Susana Estevao (a48584)
* \ date 9 dez 2014
* \ bug sem erros detetados
* \ version 0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menuPaciente.h"
#include "menuTratamento.h"
#include "menuConsulta.h"
#include "menuGestao.h"
/**
* \brief Funcao mostrar menu PRINCIPAL
* \param void
* \return int
*/
int main (void)
{
	listaPaciente p;
	listaTratamento t;
	listaConsulta c;
	
	system("color f0");
	/*printf("\n-----------------------------------------");
	printf("\n----------  BEM VINDO   -----------------");
	printf("\n----------              -----------------");
	printf("\n----------              -----------------");
	printf("\n----------     A        -----------------");
	printf("\n----------              -----------------");
	printf("\n----------              -----------------");
	printf("\n----------  DENTALKARE  -----------------");
	printf("\n-----------------------------------------\n");
	getch();*/
	
	int op;
	do
	{
		system("cls");
		printf("\n---------- MENU PRINCIPAL ------------");
		printf("\n\n[1] - Menu Pacientes");
		printf("\n\n[2] - Menu Tratamentos");
		printf("\n\n[3] - Menu Consulta");
		printf("\n\n[4] - Menu Gestao");
		printf("\n\n[0] - Terminar Programa");
		printf("\n--------------------------------------");
		printf("\n\nQual Opcao: ");	scanf("%d%*c", &op);
		switch(op)
		{
			case 1: menuPaciente(); break;
			case 2: menuTratamento(); break;
			case 3: menuConsulta(c, p, t); break;
			//case 3: menuConsulta(); break;
			case 4: menuGestao(); break;
			case 0: 
					printf("\n--------------------------------------");
					printf("\n\tPROGRAMA FINALIZADO!");
    				printf("\n\nObrigado por utilizar este programa! <Enter para Continuar>");
					exit(1); break;
			default: printf("\nOpcao Invalida"); getch(); break;
		}
	}while(op!=0);
	getch();
}

