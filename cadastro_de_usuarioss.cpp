#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int cadastrar() //Função responsavel por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF para cadastro: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo "file"
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, ","); // salva o valor da variavel(No caso adicionamos uma , depois da informação coletada)
	fclose(file); // fecha o arquivo
	
	printf("Digite o NOME para cadastro: "); //coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file,nome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, ","); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o SOBRENOME para cadastro: "); //coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, sobrenome); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o CARGO para cadastro: "); //coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file, cargo); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause"); //pausa o sistema até o usuário apertar alguma tecla
	
	
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
		printf("CPF não cadastrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("Estas são as informações do usuário: ");
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
		printf("CPF deletado, ou não se encontra no sistema!.\n");
		system("pause");
	}
	
	
 }



int main()
{
	int opcao=0; //definindo variáveis 
	int laco;
	
	for(laco=1; laco=1;)
	{
	
	
	    system("cls");
	    
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf("############################################## CADASTRO DE USUARIOS EBAC ##############################################\n\n");
        
		printf("Escolha uma das opções:\n\n"); //inicio do menu
        printf("1- Cadastro de usuários\n");
        printf("2- Consulta de usuários\n");
        printf("3- Deletar usuários\n\n");    
        printf("Opção: "); //fim do menu
    
        scanf("%d", &opcao); //armazenamento da escolha do usuário
    
        system("cls"); //responsável por limpar a tela
        
        switch(opcao) //inicio da seleção de menus
        {
        	case 1:
            cadastrar(); //chamada de funções 
            break;
            
            case 2:
            consultar(); //chamada de funções
            break;
            
            case 3:
            deletar(); //chamada de funções
            break;   
			
            default:
            printf("Esta opção não está disponível!\n");
            system("pause");
            break;
          
	    } //fim da seleção
    
   }
}
