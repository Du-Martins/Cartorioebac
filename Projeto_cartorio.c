#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando criação do usuario
	scanf("%s", cpf); //%s serve para salvar uma string como registro de cpf 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das sting
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //W de criar o arquivo e signifaca escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"A" de atualização/inserir
	fprintf(file, ","); //Virgula para separar as informações
	fclose(file); //Fechar
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s serve para salvar uma string como registro de nome
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //%s serve para salvar uma string como registro de sobrenome
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	//inicio criação de variaveis/string
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf); //%S porque é uma string
	
	FILE *file;
	file = fopen(cpf, "r"); //R de ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!. \n ");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário deletado com sucesso!. \n");
		system("pause");
	}	
}
int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	system("cls");
		
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	
	printf("\t *** Cartório da EBAC ***\n\n"); //inicio de menu
	printf("Escolha as opções desejadas do menu: \n\n");
	printf("\t1) - Registrar nomes.\n");
	printf("\t2) - Consultar nomes.\n");
	printf("\t3) - Deletar nomes.\n");
	printf("\t4) - Sair do sistema. \n\n");
	printf("Opção: "); // fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	system("cls");
		switch(opcao)//inicio da seleção do menu
	{
		case 1:
		registro();//chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilziar o sistema! Até mais");
		return 0;
		break;
			
		default:
		printf("\t Essa opção não está disponivel!\n"); //fim da selecão
		system("pause");
		break;
			
	}
	

}
}
