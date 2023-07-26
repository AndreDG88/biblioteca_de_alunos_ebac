#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int cadastrar() // Func�o respons�vel por cadastrar os alunos
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	printf("Acessando o Registro de Nomes\n");
	
	// in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char curso[40];
	// Fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF do aluno que ser� cadastrado: ");
	scanf("%s",cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" refere-se a escrever
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" refere-se a alterar
	fprintf(file,", Nome:");
	fclose(file);
	
	printf("Digite o nome do aluno a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Sobrenome:");
	fclose(file);
	
	printf("Digite agora o sobrenome do aluno: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", Curso:");
	fclose(file);
	
	printf("Qual � o curso do aluno:");
	scanf("%s",curso);
	
	file = fopen(arquivo, "a");
	fprintf(file,curso);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	printf("Acessando a Consulta de Registros\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do aluno a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{ 
	    printf("Aluno n�o encontrado, verifique se o CPF esta correto.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas s�o as informa��es do Aluno: ");
		printf("%s",conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	system("pause");
}

int apagar()
{
	printf("Acessando o Descarte de Registros\n");
	
	char cpf[40];
	
	printf("Digite o CPF do aluno que ter� o registro apagado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file != NULL)
	{
		remove(cpf);
		printf("Registro do aluno apagado com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("Aluno n�o encontrado, verifique se o CPF esta correto.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int loop_menu=1;
	
	for(loop_menu=1;loop_menu=1;)
	{
		
		system("cls"); // respons�vel por limpar a tela

	
	     setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	     printf("### Biblioteca de Alunos da EBAC ###\n\n"); // Iniciando o menu
	     printf("Escolha a op��o desejada do menu:\n\n");
	     printf("\t1 - Cadastrar Aluno\n");
	     printf("\t2 - Consultar Registro\n");
	     printf("\t3 - Apagar Registro\n\n"); // Fim do menu
	     printf("Esse software � de uso exclusivo dos membros da EBAC. Desenvolvido por: Andr� Soares\n\n");
	     printf("Qual op��o voc� deseja?:");
	
	     scanf("%d", &opcao); // Armazenamento da op��o do usu�rio
	
	     system("cls");
	     
	     switch(opcao)
	     {
	     	case 1: // In�cio da �rea de Sele��o
	     	cadastrar(); // chamada de fun��es
	        break;
	        
	        case 2:
	        consultar();
		    break;
		    
		    case 3:
		    apagar();
		    break;
		    
		    default:
		    printf("Op��o inv�lida, favor tentar novamente\n");
		    system("pause");
		    break;
		    
		 }// Fim da �rea de sele��o
	
	}
}
