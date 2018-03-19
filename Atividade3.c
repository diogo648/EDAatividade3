#include <stdlib.h>
#include <stdio.h>
#include<string.h>



typedef struct tno no;

struct tno{

	int ra;
	char nomeAluno[50];
	float nota;
	struct tno *prox;
};


no *insereAluno(int ra, char nomeAluno[50], float nota){

no *aux = (no *) malloc(sizeof(no));

aux->ra = ra;
strcpy(aux->nomeAluno,nomeAluno);
aux->nota = nota;
aux-> prox = NULL;

return aux;


}

no *insereOrdenado(no *lista, no *novaLista)
{
	no *temp = NULL, *temp1 = lista;

	if (temp1 == NULL)
	{
		lista = novaLista;//Se a lista está vazia, os novos dados são a lista
	}
	else
	{
		while (temp1 != NULL && novaLista->ra > temp1->ra)//Encontra a posição correta na lista
		{
			temp = temp1;
			temp1 = temp1->prox;
		}

		if (temp == NULL)//Insere na posição correta
		{
			novaLista->prox = lista;
			lista = novaLista;
		}
		else
		{
			novaLista->prox = temp1;
			temp->prox = novaLista;
		}
	}

	return lista;//Retorna a lista ordenada
}



void exibeDados(no *dadosAlunos){

while(dadosAlunos)
{

	printf("Aluno: %s ..... RA: %d ..... Nota: %f \n",dadosAlunos->nomeAluno,dadosAlunos->ra,dadosAlunos->nota);

	dadosAlunos = dadosAlunos -> prox;
}

}



int main(){


int opcao=0;
int ra;
char nomeAluno[50];
float nota;

no *alunos= NULL, *aux;


no *lista=NULL; //Lista vazia

	while(opcao!= -1)
	{
		printf("\n MENU \n");
		printf("1. Inserir o cadastro de um aluno \n");
		printf("2. Buscar aluno por RA \n");
		printf("3. Buscar aluno por Nome \n");
		printf("4. Exibir dados de todos os alunos cadastrados \n");
		printf("5. Sair \n");
		scanf("%d",&opcao);


		
		if(opcao == 1)
		{

			printf("Digite o RA do aluno:");
			scanf("%d",&ra);
			__fpurge(stdin);

			printf("Digite o nome do aluno:");
			gets(nomeAluno);

			printf("Digite a nota do aluno:");
			scanf("%f",&nota);
			__fpurge(stdin);			
			
			//Insere Aluno
			aux = insereAluno(ra,nomeAluno,nota);

			if(aux == NULL){

				return -1;
			}

			alunos = insereOrdenado(alunos,aux);
		}

		if(opcao == 2)
		{

			printf("Digite o RA do aluno:");
			scanf("%d",&ra);
		}
		
		if(opcao == 3)
		{
			printf("Digite o nome do aluno:");
		}

		if(opcao == 4)
		{
			exibeDados(alunos);
		}

		if(opcao == 5)
		{
			opcao = -1;
		}


	}




}

