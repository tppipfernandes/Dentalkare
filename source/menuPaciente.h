/**
* \file
* \brief Projeto Modulo Tematico LTIC 2014/2015 "menuPaciente.h"
* \details "menuPaciente.h" implementa o menu dos PACIENTES
* \date 9 dez 2014
*/
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <string.h>

#define N 50
#define pacienteName "paciente.txt"

/** Estrutura para trabalhar as DATAS */
typedef struct
{	int dia; /**< dia - inteiro com o dia */
	int mes; /**< mes - inteiro com o mes */
	int ano; /**< ano - inteiro com o ano */
}dN;

/** Estrutura para Armazenar os dados dos PACIENTES */
typedef struct
{	int idP; /**< idP - inteiro com o numero de identificacao do PACIENTE */	
	char nome[N]; /**< nome - string com o nome do PACIENTE */
	char apelido[N]; /**< apelido - string com o apelido do PACIENTE */
	char morada[N]; /**< morada - string com a morada do PACIENTE */
	char email[N]; /**< email - string com o email do PACIENTE */
	int telemovel; /**< telemovel - inteiro com o telemovel do PACIENTE */
	dN dNascimento; /**< data - string para a data de nascimento do PACIENTE */
	int idade; /**< idade - inteiro com a idade do PACIENTE */ 
	int estado; /**< estado - inteiro com o estado do PACIENTE */
}paciente;

/** Define um tipo como sendo uma listaPaciente */
typedef paciente listaPaciente[N];

/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "paciente.txt"
* \param p : listaPaciente
*/
void lerPaciente(listaPaciente p)
{
	FILE *fPaciente = fopen(pacienteName, "r+");
	int i;
	if(fPaciente==NULL)
	{
		printf("\nErro ao abrir ficheiro!");
		getch(); 
	}
	for(i=0; i<N; i++)
	{
		fscanf(fPaciente, "%d\n", &p[i].idP);
		fscanf(fPaciente, " %[^\n]s%*c", p[i].nome);
		fscanf(fPaciente, " %[^\n]s%*c", p[i].apelido);
		fscanf(fPaciente, " %[^\n]s%*c", p[i].morada);
		fscanf(fPaciente, " %[^\n]s%*c", p[i].email);
		fscanf(fPaciente, "%d\n", &p[i].telemovel);
		fscanf(fPaciente, "%d-%d-%d", &p[i].dNascimento.dia, &p[i].dNascimento.mes, &p[i].dNascimento.ano);
		fscanf(fPaciente, "%d\n", &p[i].idade);
		fscanf(fPaciente, "%d\n", &p[i].estado);
	}
	fclose(fPaciente);
	//printf("\nFicheiro carregado com Sucesso! <enter para continuar>");
}
/**
* \brief Funcao que carrega a estrutura de dados a partir do ficheiro "paciente.txt"
* \param p : listaPaciente
*/
void gravarPaciente(listaPaciente p)
{
	FILE *fPaciente = fopen(pacienteName, "w+");
	int i;
	if(fPaciente==NULL)
	{
		printf("\nErro ao abrir ficheiro! <enter para sair>");
		getch();
	}
	for(i=0; i<N; i++)
	{
		if(p[i].estado==1)
			fprintf(fPaciente, "%d\n%s\n%s\n%s\n%s\n%d\n%d-%d-%d\n%d\n%d\n\n", p[i].idP, p[i].nome, p[i].apelido, p[i].morada, p[i].email, p[i].telemovel, p[i].dNascimento.dia, p[i].dNascimento.mes, p[i].dNascimento.ano, p[i].idade, p[i].estado);
	}
	fclose(fPaciente);
	//printf("\nFicheiro Gravado com Sucesso! <enter para continuar>");
}
/**
* \brief Funcao para listar todos os PACIENTES gravados em "paciente.txt"
* \param p : listaPaciente
*/
int listarPaciente(listaPaciente p)
{
	int i;
	system("cls");
	printf("\n------------------- LISTAR PACIENTES -------------------\n");
	for(i=0; i<N; i++)
	{
		if(p[i].estado==1)
			printf("\nId Paciente: %d\nNome Paciente: %s %s\nMorada Paciente: %s\nE-mail: %s\nTelemovel: %d\nData Nascimento: %d-%d-%d\nIdade: %d\nEstado: %d\n\n",
					p[i].idP, p[i].nome, p[i].apelido, p[i].morada, p[i].email, p[i].telemovel, p[i].dNascimento.dia, p[i].dNascimento.mes, p[i].dNascimento.ano, p[i].idade, p[i].estado);
	}
	printf("\n---------------------------------------------------------\n");
	printf("\nListagem Concluida! <enter para continuar>");
	getch();
}
/**
* \brief Funcao para adicionar um novo PACIENTE
* \param p : listaPaciente
*/
void inserirPaciente(listaPaciente p)
{
	int i=0, op, op2, diaActual=16, mesActual=12, anoActual=2014;
	
	do
	{
		i++;
	}while(p[i].estado>0 && p[i].estado<2);
	do
	{
		system("cls");
		printf("\n[1]-Inserir Paciente ou [0]-Sair? "); scanf("%d%*c", &op2);
		if(op2==0)
			break;
		printf("\n------------------------------------------\n");
		printf("\nIdPaciente: [%d]\n", i);
		p[i].idP=i;
		printf("\nIntroduza o nome e depois o apelido\n");
		printf("Nome: "); gets(p[i].nome); 
		printf("Apelido: "); gets(p[i].apelido);
		printf("Morada Paciente: "); gets(p[i].morada);
		printf("E-mail Paciente: "); gets(p[i].email);
		printf("Telemovel: "); scanf("%d%*c", &p[i].telemovel);
		printf("Data de Nascimento: \n");
		printf("Ano <aaa>: "); scanf("%d%*c", &p[i].dNascimento.ano);
		printf("Mes <mm>: "); scanf("%d%*c", &p[i].dNascimento.mes);
		printf("Dia <dd>: "); scanf("%d%*c", &p[i].dNascimento.dia);
		if((p[i].dNascimento.mes > mesActual) || (p[i].dNascimento.mes == mesActual) && (p[i].dNascimento.dia > diaActual))
			p[i].idade=anoActual-p[i].dNascimento.ano;
		else
			p[i].idade=anoActual-p[i].dNascimento.ano;
		printf("Idade: %d", p[i].idade);
		p[i].estado=1;
		printf("\n------------------------------------------\n");
		i++;
		while(p[i].estado>0 && p[i].estado<2)
			i++;
		printf("\n\nPaciente Adicionado com Sucesso!");
		printf("\n\nQuer inserir outro paciente? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &op);
	}while(op==1);
	getch();
}
/**
* \brief Funcao que alterar um registo dos PACIENTES na estrutura de dados
* \param p : listaPaciente
*/
int alterarPaciente(listaPaciente p)
{
	int alt, op, op2, confere, diaActual=13, mesActual=12, anoActual=2014;
	do
	{
		system("cls");
		printf("\nQual o ID do Paciente para alterar? [0]-SAIR: "); scanf("%d%*c", &alt);
		if(alt==0)
			break;
		p[alt].idP=alt;
		if(alt==p[alt].idP)
		{
			printf("\n-------------------------------------------------------\n");
			printf("Id Paciente: [%d]\n", p[alt].idP);
			printf("Nome Paciente: %s %s\n", p[alt].nome, p[alt].apelido);
			printf("Morada Paciente: %s\n", p[alt].morada);
			printf("E-mail: %s\n", p[alt].email);
			printf("Telemovel: %d\n", p[alt].telemovel);
			printf("Data Nascimento: %d-%d-%d\n", p[alt].dNascimento.dia, p[alt].dNascimento.mes, p[alt].dNascimento.ano);
			printf("Idade: %d\n", p[alt].idade);
			printf("Estado: %d", p[alt].estado);
			printf("\n-------------------------------------------------------\n");
		}
		else
			printf("\nERRO! Id Paciente nao existe.");
		printf("\n\nQuer mesmo alterar este Paciente? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
		if(confere==1)
		{
			printf("\nEditar Paciente ID: [%d]", p[alt].idP);
			do
			{
				printf("\n\nPretende alterar que campos: ");
				printf("\n[1] - Nome");
				printf("\n[2] - Apelido");
				printf("\n[3] - Morada");
				printf("\n[4] - E-mail");
				printf("\n[5] - Telemovel");
				printf("\n[6] - Data de Nascimento");
				printf("\n[7] - Idade");
				printf("\n[0] - Nenhum");
				printf("\nQual a sua opcao: "); scanf("%d%*c", &op);
				switch(op)
				{
					case 1: printf("\nNome: "); gets(p[alt].nome); break;
					case 2: printf("\nApelido: "); gets(p[alt].apelido); break;
					case 3: printf("\nMorada: "); gets(p[alt].morada); break;
					case 4: printf("\nE-mail: "); gets(p[alt].email); break;
					case 5: printf("\nTelemovel: "); scanf("%d%*c", &p[alt].telemovel); break;
					case 6: printf("\nData Nascimento\n");
							printf("Ano <aaaa>: "); scanf("%d%*c", &p[alt].dNascimento.ano);
							printf("Mes <mm>: "); scanf("%d%*c", &p[alt].dNascimento.mes);
							printf("Dia <dd>: "); scanf("%d%*c", &p[alt].dNascimento.dia);
							if((p[alt].dNascimento.mes > mesActual) || (p[alt].dNascimento.mes == mesActual) && (p[alt].dNascimento.dia > diaActual))
						    	p[alt].idade=anoActual-p[alt].dNascimento.ano;
						    else 
								p[alt].idade=anoActual-p[alt].dNascimento.ano;
						    printf("\nIdade: %d", p[alt].idade);
						    break;
					case 7: printf("\nIdade: "); scanf("%d%*c", &p[alt].idade); break;
					case 0: return 0; break;
					default: printf("\nOpcao Invalida"); break;
				}
			}while(op=='1' && op>0 || op<7);
			p[alt].estado=1;
			printf("\n\nPaciente Alterado com Sucesso!");
		}
		else
			break;
		printf("\n------------------------------------------\n");
		printf("\nQuer alterar outro Paciente? [1]-SIM [2]-NAO: "); scanf("%d%*c", &op);
	}while(op2==1);	
	getch();
}
/**
* \brief Funcao para eliminar um registo PACIENTE na estrutura de dados
* \param p : listaPaciente
*/
int eliminarPaciente(listaPaciente p)
{
	int eli, op, confere;
	do
	{
		system("cls");
		printf("\nQual o ID para eliminar? [0]-SAIR: "); scanf("%d%*c", &eli);
		if(eli==0)	
			break;
		p[eli].idP=eli;
		if(p[eli].idP==eli)
		{
			printf("\n----------------------------------------------------------\n");
			printf("\nId Paciente: [%d]", p[eli].idP);
			printf("\nNome do Paciente: %s %s", p[eli].nome, p[eli].apelido);
			printf("\nMorada: %s", p[eli].morada);
			printf("\nE-mail: %s", p[eli].email);
			printf("\nTelemovel: %9d", p[eli].telemovel);
			printf("\nData Nascimento: %d-%d-%d", p[eli].dNascimento.dia, p[eli].dNascimento.mes, p[eli].dNascimento.ano);
			printf("\nIdade: %d", p[eli].idade);
			printf("\nEstado: %d", p[eli].estado);
			printf("\n----------------------------------------------------------\n");
			printf("\n\nQuer eliminar este Paciente? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &confere);
			if(confere==1)
			{
				p[eli].estado=0;
				printf("\nPaciente Eliminado com Sucesso!");
			}
		}
		else
			printf("\nERRO! Id do Paciente nao existe.");
		printf("\n\nQuer eliminar outro Paciente? [1]-SIM [0]-NAO:  "); scanf("%d%*c", &op);
	}while(op==1);
	getch();
}
/**
* \brief Funcao menu PACIENTE
* \param void
*/
void menuPaciente(void)
{
	char op;
	int i;
	listaPaciente p;
	//Inicializar estrutura PACIENTE
    for (i=0; i<N; i++)
    {
         //p[i].idP=0;
         p[i].estado=0;
    }
    lerPaciente(p);
	do
	{
		system("cls");
		printf("\n-------------------- MENU GESTAO PACIENTE ------------------");
		printf("\n\n	[1] - Inserir Novo Registo");
		printf("\n\n	[2] - Alterar Registo");
		printf("\n\n	[3] - Eliminar Registo");
		printf("\n\n	[4] - Mostrar Todos Registos");
		printf("\n\n	[0] - Voltar Menu Principal");
		printf("\n------------------------------------------------------------");
		printf("\n\nQual Opcao: "); scanf("%s%*c", &op);
		switch(op)
		{
			case '1': inserirPaciente(p); break;
			case '2': alterarPaciente(p); break;
			case '3': eliminarPaciente(p); break;
			case '4': listarPaciente(p); break;
			case '0': gravarPaciente(p); return; break;
			default: printf("\nOpcao Invalida!"); getch(); break;
		}
	}while(op!='0' || op=='a' || op=='A');
	getch();
}
