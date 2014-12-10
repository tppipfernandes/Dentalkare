/* !
* \ file
* \ brief Projeto Modulo Tematico LTIC 2014/2015 "menuPaciente.h"
* \ details "menuPaciente.h" implementa o menu Paciente
* \ author Susana Estevao (a48584)
* \ date 9 dez 2014
* \ bug sem erros detetados
* \ version 0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define N 50 	//Numero maximo de Registos 
#define pacienteName "pacientes.txt"
/**
* estrututa para trabalhar a data de nascimento
*/
typedef struct
{
	int dia;
	int mes;
	int ano;
}data;
/**
* estrututa para armazenar os dados de um PACIENTE
*/
typedef struct
{
	int id; /**< id - inteiro com o numero de identificacao do PACIENTE */	
	char nome[N]; /**< nome - string com o nome do PACIENTE */
	data nascimento; /**< data - string para a data de nascimento do PACIENTE */
	char morada[N]; /**< morada - string com a morada do PACIENTE */
	char email[N]; /**< email - string com o email do PACIENTE */
	int telemovel; /**< telemovel - inteiro com o telemovel do PACIENTE */
	int idade; /**< idade - inteiro com a idade do PACIENTE */ 
	int estado; /**< estado - inteiro com o estado do PACIENTE */
}paciente;
/** define um tipo como sendo um lista de paciente */
typedef paciente listaPaciente[N];
listaPaciente p;
/**
* \brief Funcao que inicializa a estrutura de dados paciente
* \ param void
*/
int initPaciente(listaPaciente p) // funcao para inicializar a estrutura de dados
{
    int i;
    for (i=0; i<N; i++)
    {
         p[i].id=0;
         p[i].estado=0;
    }
    return 0;
}
/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "pacientes.txt"
* \param p : listaPaciente
* \return void
*/
void lerPaciente(listaPaciente p)
{
	FILE *filePaciente=fopen(pacienteName,"r+");
	int i;
	if(filePaciente==NULL)
	{
		printf("\nErro ao abrir ficheiro! <Enter para Sair>");
		getch(); return;
	}
	for(i=0; i<N; i++)
	{
		fscanf(filePaciente,"%d\n", &p[i].id);
		fscanf(filePaciente," %[^\n]s%*c", p[i].nome);	     	
		fscanf(filePaciente," %[^\n]s%*c", p[i].morada);
		fscanf(filePaciente," %[^\n]s%*c", p[i].email);
		fscanf(filePaciente,"%d\n", &p[i].telemovel);
		fscanf(filePaciente,"%d-%d-%d\n", &p[i].nascimento.ano, &p[i].nascimento.mes, &p[i].nascimento.dia);
		fscanf(filePaciente,"%d\n", &p[i].idade);
		fscanf(filePaciente,"%d\n\n", &p[i].estado);	
	}
	//fread(p, sizeof(paciente), N, filePaciente);
	fclose(filePaciente);
	printf("\nFicheiro Carregado com sucesso! <Enter para Continuar>"); getch();
}
/**
* \brief Funcao que gravar a estrutura de dados no ficheiro "pacientes.txt"
* \param p : listaPaciente
* \return void
*/
void gravarPaciente(listaPaciente p)
{
	FILE *filePaciente=fopen(pacienteName,"w+");
	int i;
	if(filePaciente==NULL)
	{
		printf("\nErro ao gravar ficheiro! <enter para sair>");
		getch(); return;
	}
	for(i=0; i<N; i++)
	{
		if(p[i].estado==1)
		{
			fprintf(filePaciente,"%d\n%s\n%s\n%s\n%9d\n%d-%d-%d\n%d\n%d\n\n",
			p[i].id, p[i].nome, p[i].morada, p[i].email, p[i].telemovel, p[i].nascimento.ano, p[i].nascimento.mes, p[i].nascimento.dia, p[i].idade, p[i].estado);
		}
	}
	//fwrite(p, sizeof(paciente), N, filePaciente);
	fclose(filePaciente);
	printf("\nFicheiro Gravado com Sucesso! <Enter para Sair>"); getch();
}
/**
* \brief Funcao para mostra todos os PACIENTES gravados em "pacientes.txt"
* \param void
*/
void mostrarPaciente(listaPaciente p)
{
	int i;
	system("cls");
	for(i=0; i<N; i++)
	{
		if(p[i].estado==1)
		{
			printf("Id Paciente: %d\nNome do Paciente: %s\nMorada: %s\nE-mail: %s\nTelemovel: %9d\nData Nascimento: %d-%d-%d\nIdade: %d\nEstado: %d\n\n",
					p[i].id, p[i].nome, p[i].morada, p[i].email, p[i].telemovel, p[i].nascimento.ano, p[i].nascimento.mes, p[i].nascimento.dia, p[i].idade, p[i].estado);
		}
	}
	printf("\nListagem Concluida! <Enter para Continuar>");getch();
}
/**
* \brief Funcao para adicionar um novo PACIENTE
* \param p : listaPaciente
*/
void inserirPaciente(listaPaciente p)
{
	int i=0, opcao;
	int dia_Actual=16, mes_Actual=12, ano_Actual=2014;
	system("cls");
	do //corre ate o ultimo registo(vai para o primeiro indice onde p[i].estado=0)
	{
		i++;
	}while(p[i].estado>0 && p[i].estado<2);
	do
	{
		printf("\nId Paciente: %d", i);
		p[i].id=i;
		printf("\nNome do Paciente: "); gets(p[i].nome);
		printf("Morada: "); gets(p[i].morada);
		printf("E-mail: "); gets(p[i].email);
		printf("Telemovel: "); scanf("%d%*c", &p[i].telemovel);
		printf("Data Nascimento\n");
		printf("Ano <aaaa>: "); scanf("%d%*c", &p[i].nascimento.ano);
		printf("Mes <mm>: "); scanf("%d%*c", &p[i].nascimento.mes);
		printf("Dia <dd>: "); scanf("%d%*c", &p[i].nascimento.dia);
		if ((p[i].nascimento.mes > mes_Actual) || ((p[i].nascimento.mes = mes_Actual) && (p[i].nascimento.dia > dia_Actual)))
			p[i].idade = ano_Actual - p[i].nascimento.ano;
		else 
			p[i].idade = ano_Actual - p[i].nascimento.ano;
	    printf("Idade: %d", p[i].idade);
		p[i].estado=1;
		i++;
		while(p[i].estado>0 && p[i].estado<2)
			i++;
		printf("\n\nPaciente Adicionado com Sucesso!");
		
		printf("\n\nQuer inserir outro paciente [1]-SIM [0]-NAO:  ");	scanf("%d%*c", &opcao);
	}while(opcao==1);
}
/**
* \brief Funcao que altera o registo dos PACIENTES na estrutura de dados
* \param p : listaPaciente
*/
int alterarPaciente(listaPaciente p)
{
	int alt, opcao, op, confere;
	int mesA=12, diaA=3, anoA=2014;
	do
	{
		system("cls");
		printf("\nQual o Id do Paciente para alterar? [0]-SAIR: "); scanf("%d%*c",&alt);
		if(alt==0)	
			break;
		p[alt].id=alt;
		if(alt==p[alt].id)
		{
			printf("\n--------------------------------------------------------");
			printf("\nId Paciente: %d", alt);
			printf("\nNome do Paciente: %s", p[alt].nome);
			printf("\nMorada: %s", p[alt].morada);
			printf("\nE-mail: %s", p[alt].email);
			printf("\nTelemovel: %9d", p[alt].telemovel);
			printf("\nData Nascimento: %d-%d-%d", p[alt].nascimento.ano, p[alt].nascimento.mes, p[alt].nascimento.dia);
			printf("\nIdade: %d", p[alt].idade);
			printf("\nEstado: %d", p[alt].estado);
			printf("\n--------------------------------------------------------");
		}
		else
			printf("\nERRO! Id do Paciente nao existe.");
		printf("\n\nQuer mesmo alterar este Paciente? [1]-SIM [2]-NAO:  "); scanf("%d%*c",&confere);
		if(confere==1)
		{
			printf("\nEditar Paciente ID: [%d]", alt);
			do
			{
				printf("\n\nPretende alterar que campos: ");
				printf("\n[1] - Nome Paciente");
				printf("\n[2] - Morada");
				printf("\n[3] - E-mail");
				printf("\n[4] - Telemovel");
				printf("\n[5] - Data de Nascimento");
				printf("\n[6] - Idade");
				printf("\n[0] - Nenhum");
				printf("\nQual a sua opcao: "); scanf("%d%*c", &opcao);
				if(opcao==1)	
				{	
					printf("\nNome do Paciente: "); gets(p[alt].nome); 
				}
				else
					if(opcao==2)	
					{	
						printf("\nMorada: "); gets(p[alt].morada); 
					}
					else
						if(opcao==3)
						{	
							printf("\nE-mail: "); gets(p[alt].email); 
						}
						else
							if(opcao==4)
							{	
								printf("\nTelemovel: "); scanf("%d%*c", &p[alt].telemovel);
							}
							else
								if(opcao==5)
								{
									printf("\nData Nascimento\n");
									printf("Ano <aaaa>: "); scanf("%d%*c", &p[alt].nascimento.ano);
									printf("Mes <mm>: "); scanf("%d%*c", &p[alt].nascimento.mes);
									printf("Dia <dd>: "); scanf("%d%*c", &p[alt].nascimento.dia);
									if ((p[alt].nascimento.mes > mesA) && (p[alt].nascimento.dia > diaA))
								    	p[alt].idade = anoA - p[alt].nascimento.ano;
								    else 
										p[alt].idade = anoA - p[alt].nascimento.ano;
								    printf("\nIdade: %d", p[alt].idade);
								}
								else
								if(opcao==6)
								{
									printf("\nIdade: "); scanf("%d%*c", &p[alt].idade);
								}
								else
									if(opcao==0) 
									return 0; 									
									else
										printf("\nOpcao Invalida");
			}while(opcao==0 && opcao>0 || opcao<7);
			p[alt].estado=1;
			printf("\n\nPaciente Alterado com Sucesso!");
		}
		else
			if(confere==2)
				break;
		printf("\n\nQuer alterar outro paciente? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &opcao);
	}while(opcao==1);
	getch();
}
/**
* \brief Funcao para eliminar um registo PACIENTE na estrutura de dados
* \param p : listaPaciente
*/
int eliminarPaciente(listaPaciente p)
{
	int eli, opcao, confere;
	do
	{
		system("cls");
		printf("\nQual o ID para eliminar? [0]-SAIR: "); scanf("%d%*c", &eli);
		if(eli==0)	break;
		p[eli].id=eli;
		if(p[eli].id==eli)
		{
			printf("\n--------------------------------------------------------");
			printf("\nId Paciente: %d", eli);
			printf("\nNome do Paciente: %s", p[eli].nome);
			printf("\nMorada: %s", p[eli].morada);
			printf("\nE-mail: %s", p[eli].email);
			printf("\nTelemovel: %9d", p[eli].telemovel);
			printf("\nData Nascimento: %d-%d-%d", p[eli].nascimento.ano, p[eli].nascimento.mes, p[eli].nascimento.dia);
			printf("\nIdade: %d", p[eli].idade);
			printf("\nEstado: %d", p[eli].estado);
			printf("\n--------------------------------------------------------");
			printf("\n\nQuer mesmo eliminar este Paciente? [1]-SIM [2]-NAO:  "); scanf("%d%*c", &confere);
			if(confere==1)
			{
				p[eli].estado=0;
				printf("\nPaciente Eliminado com Sucesso!");
			}
			else
				if(confere==2)
					break;
		}
		else
			printf("\nERRO! Id do Paciente nao existe.");
		printf("\n\nQuer eliminar outro Paciente? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &opcao);
	}while(opcao==1);
}
/**
* \brief Funcao menu PACIENTE
* \param void
*/
void menuPaciente(void)
{
	//listaPaciente p;
	int op;
	initPaciente(p); 
	do
	{
		system("cls");
		printf("\n---------- MENU GESTAO PACIENTE ------------");
		printf("\n\n[1] - Ler Ficheiro");
		printf("\n\n[2] - Gravar Ficheiro");
		printf("\n\n[3] - Inserir Novo Registo");
		printf("\n\n[4] - Alterar Registo");
		printf("\n\n[5] - Eliminar Registo");
		printf("\n\n[6] - Mostrar Todos Registos");
		printf("\n\n[0] - Voltar Menu Principal");
		printf("\n--------------------------------------------");
		printf("\n\nQual Opcao: "); scanf("%d%*c", &op);
		switch(op)
		{
			case 1: lerPaciente(p); break;
			case 2: gravarPaciente(p); break;
			case 3: inserirPaciente(p); break;
			case 4: alterarPaciente(p); break;
			case 5: eliminarPaciente(p); break;
			case 6: mostrarPaciente(p); break;
			case 0: return; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while(op != 0);
	getch();
}
