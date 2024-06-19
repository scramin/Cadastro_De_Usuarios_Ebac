#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int cadastrar() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF para cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo "file"
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, ","); // salva o valor da variavel(No caso adicionamos uma , depois da informa��o coletada)
	fclose(file); // fecha o arquivo
	
	printf("Digite o NOME para cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, ","); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o SOBRENOME para cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, sobrenome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o CARGO para cadastro: "); //coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, cargo); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); //pausa o sistema at� o usu�rio apertar alguma tecla
	
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("Estas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF para deletar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	remove(cpf);
	
	if(file == NULL)
	{
		printf("CPF deletado, ou n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
 }



int main()
{
	int opcao=0; //definindo vari�veis 
	int laco;
	
	for(laco=1; laco=1;)
	{
	
	
	    system("cls");
	    
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf("############################################## CADASTRO DE USUARIOS EBAC ##############################################\n\n");
        
		printf("Escolha uma das op��es:\n\n"); //inicio do menu
        printf("1- Cadastro de usu�rios\n");
        printf("2- Consulta de usu�rios\n");
        printf("3- Deletar usu�rios\n\n");    
        printf("Op��o: "); //fim do menu
    
        scanf("%d", &opcao); //armazenamento da escolha do usu�rio
    
        system("cls"); //respons�vel por limpar a tela
        
        switch(opcao) //inicio da sele��o de menus
        {
        	case 1:
            cadastrar(); //chamada de fun��es 
            break;
            
            case 2:
            consultar(); //chamada de fun��es
            break;
            
            case 3:
            deletar(); //chamada de fun��es
            break;   
			
            default:
            printf("Esta op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
          
	    } //fim da sele��o
    
   }
}
