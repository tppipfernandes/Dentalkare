/* !
* \ file
* \ brief Projeto Modulo Tematico LTIC 2014/2015 "menuGestao.h"
* \ details "menuGestao.h" implementa o menu Gestao da Clinica
* \ author Susana Estevao (a48584)
* \ date 9 dez 2014
* \ bug sem erros detetados
* \ version 0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/**
* \brief Funcao para pesquisa de Pacientes
*/
/*pesquisaP()
{
	int op;
	do
	{
		printf("\n------ MENU PESQUISA PACIENTE -------");
		printf("\n[1] - Pesquisar Pacientes por Idade");
		printf("\n[2] - Pesquisar Pacientes por Nome");
		printf("\n[3] - Media de Idades");
		printf("\n[4] - ");
		printf("\n[0] - Voltar Atras");
		switch(op)
		{
			case 1: printf("\n----- PESQUISA POR IDADES -------"); 
					printf("\nQual a idade do Paciente?: "); scanf("%d%*c", &idade);
					for (i=1; i<N; i++)
			    	{
			        	if (idade==p[i].idade && p[i].estado>0)
			         		printf("\nId Paciente: %d\nNome Paciente: %s\nIdade: %d\n\n",
			         				p[i].id, p[i].nome, p[i].idade);
			    	}
					break;
			case 2: printf("\n----- PESQUISA POR NOME -------"); 
					printf("\nQual o nome do Paciente?: "); scanf("%s%*c", &nome);
					for (i=1; i<N; i++)
			    	{
			        	if (nome==p[i].nome && p[i].estado>0)
			         		printf("\nId Paciente: %d\nNome Paciente: %s\n\n",
			         				p[i].id, p[i].nome);
			    	}
					break;
			case 3: printf("\n----- MEDIA DE IDADES -------"); 
					for (i=1; i<N; i++) 			//percorre pacientes
			        {
		                 idades=idades+p[i].idade; 	//soma idades dos pacientes
		                 pa++; 						//incrementa numero de pacientes
			        }
				    media=idade/pa; 			//calcula a media
			    	printf("\nA Media de idades do %.2f", media);
					break;
			case 4: 
			case 0: return; break;
			default: printf("\nOpcao Invalida!"); break;	
		}
	}while(op==0);
}*/
/**
* \brief Funcao para pesquisa de Tratamentos
*/
/*pesquisaT()
{
	int op;
	do
	{
		printf("\n------ MENU PESQUISA TRATAMENTO -------");
		printf("\n[1] - Pesquisar Tratamento pelo Tipo");
		printf("\n[2] - Media de Preco de Tratamento");
		printf("\n[3] - ");
		printf("\n[0] - Voltar Atras");
		switch(op)
		{
			case 1: 
			case 2: 
			case 3: 
			case 0: return; break;
			default: printf("\nOpcao Invalida!"); break;	
		}
	}while(op==0);
}*/
/**
* \brief Funcao para pesquisa de Consultas
*/
/*pesquisaC()
{
	int op;
	do
	{
		printf("\n------ MENU PESQUISA CONSULTA -------");
		printf("\n[1] - Pesquisar Consulta por Datas");
		printf("\n[2] - Pesquisar Consulta por Horas");
		printf("\n[3] - ");
		printf("\n[0] - Voltar Atras");
		switch(op)
		{
			case 1:
			case 2: 
			case 3: 
			case 4: 
			case 0: return; break;
			default: printf("\nOpcao Invalida!"); break;	
		}
	}while(op==0);
}*/
/**
* \brief Funcao para mostrar menu de GESTAO
* \param void
* \return void
*/
void menuGestao(void)
{
	int op;
	do
	{
		system("cls");
		printf("\n------------ MENU GESTAO CLINICA ---------------");
		printf("\n\n[1] - Pesquisa de Paciente");
		printf("\n\n[2] - Pesquisa de Tratamento");
		printf("\n\n[3] - Pesquisa de Consulta");
		printf("\n\n[0] - Voltar Menu Principal");
		printf("\n-------------------------------------------------");
		printf("\n\nQual a opcao: ");	scanf("%d%*c", &op);
		switch(op)
		{
			//case 1: pesquisaP(); break;
			//case 2: pesquisaT(); break;
			//case 3: pesquisaC(); break;
			default: printf("\nOpcao Invalida!"); getch(); break;
			//case 0: return 0; break;
		}
	}while(op!=0);
	getch();
}
