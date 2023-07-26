#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int cadastrar() // Funcão responsável por cadastrar os alunos
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	printf("Acessando o Registro de Nomes\n");
	
	// início da criação de variáveis/strings
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cpf[40];
	char curso[40];
	// Fim da criação de variáveis/strings
	
	printf("Digite o CPF do aluno que será cadastrado: ");
	scanf("%s",cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
	
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
	
	printf("Qual é o curso do aluno:");
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
	    printf("Aluno não encontrado, verifique se o CPF esta correto.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações do Aluno: ");
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
	
	printf("Digite o CPF do aluno que terá o registro apagado: ");
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
		printf("Aluno não encontrado, verifique se o CPF esta correto.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int loop_menu=1;
	
	for(loop_menu=1;loop_menu=1;)
	{
		
		system("cls"); // responsável por limpar a tela

	
	     setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	     printf("### Biblioteca de Alunos da EBAC ###\n\n"); // Iniciando o menu
	     printf("Escolha a opção desejada do menu:\n\n");
	     printf("\t1 - Cadastrar Aluno\n");
	     printf("\t2 - Consultar Registro\n");
	     printf("\t3 - Apagar Registro\n\n"); // Fim do menu
	     printf("Esse software é de uso exclusivo dos membros da EBAC. Desenvolvido por: André Soares\n\n");
	     printf("Qual opção você deseja?:");
	
	     scanf("%d", &opcao); // Armazenamento da opção do usuário
	
	     system("cls");
	     
	     switch(opcao)
	     {
	     	case 1: // Início da área de Seleção
	     	cadastrar(); // chamada de funções
	        break;
	        
	        case 2:
	        consultar();
		    break;
		    
		    case 3:
		    apagar();
		    break;
		    
		    default:
		    printf("Opção inválida, favor tentar novamente\n");
		    system("pause");
		    break;
		    
		 }// Fim da área de seleção
	
	}
}
