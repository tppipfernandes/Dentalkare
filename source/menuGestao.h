#include <stdio.h>
#include <windows.h>

/**
* \brief menu GESTAO
*
*/
void menuGestao()
{
	int opcao;
	do
	{
		system("cls");
		printf("================ MENU GESTAO ================");
		printf("\n\n\n\t[1] - PESQUISA PACIENTE");
		printf("\n\n\n\t[2] - PESQUISA TRATAMENTO");
		printf("\n\n\n\t[3] - PESQUISA CONSULTA");
		//printf("\n\n\n\t[4] - MOSTRAR TODOS PACIENTES");
		printf("\n\n\n\t[0] - VOLTAR ATRAS");
		printf("\n\n\nESCOLHA OPCAO: ");	scanf("%d", &opcao);
	
		switch(opcao)
		{
			//case 1: searchPaciente(); break;
			//case 2: searchTratamento(); break;
			//case 3: searchConsulta(); break;
			//case 4: showPaciente(); break;
			case 0: return;break;
			default: printf("\n\t\tCODIGO INVALIDO"); getch(); break;
		}
	}while(opcao != 0);
}
