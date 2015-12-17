#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 100

typedef struct no{
    int numero;
    char nome[TAM];
    struct no *nseg;
} No;

No* insereNaLista(No *lista, No *novoNo){
	No *cabeca=lista;
    No *auxiliar;
	//caso a lista esteja vazia ainda:
	if(lista==NULL) return novoNo;
	//caso o primeiro elemento seja maior 
	//que o que vamos inserir
	if(lista->numero > novoNo->numero){
		novoNo->nseg=lista;
		return novoNo;
		}
    while(lista!=NULL){
    auxiliar=lista;
      lista=lista->nseg;
        //inserir no fim da lista
        if(auxiliar->nseg==NULL){
            auxiliar->nseg=novoNo;
            return cabeca; //retorna a cabeça
        }
        //inserir no meio da lista
      if(lista->numero >= novoNo->numero){
        auxiliar->nseg=novoNo;
        novoNo->nseg=lista;
        return cabeca;
      }
    }
	return cabeca;
}

No* removeDaLista(int numero, No *lista){
    No *cabeca=lista;
    No *auxiliar;

    //lista vazia
    if(lista==NULL) return lista;

    //caso seja o primeiro a remover
    if(lista->numero==numero){
        cabeca=lista->nseg;
        free(lista);
        return cabeca;
    }

    while(lista!=NULL){
    auxiliar=lista;
    lista=lista->nseg;
    //remove o ultimo elemento
    if(auxiliar->nseg==NULL){
            free(auxiliar);
            return cabeca; //retorna a cabeça
        }

        //remove o ultimo
      if(lista->numero == numero){
        auxiliar->nseg=lista->nseg;
        free(lista);
        return cabeca;
      }
    }
    return cabeca;
}

No* criaNo(char *nome,int numero,No *lista){
    No *novoNo;
    novoNo =(No *) malloc(sizeof(No));
    novoNo->nseg=NULL;
    novoNo->numero=numero;
    strcpy(novoNo->nome,nome);
    lista=insereNaLista(lista, novoNo);
    return lista;
}

void imprimeLista(No *lista){
	while(lista!=NULL){
		printf("Numero: %d",lista->numero);
		printf("\tNome: ");
		puts(lista->nome);
	    lista=lista->nseg;
	}
}


int main(){
    int menu=1;
    int numeroAluno;
    char nome[TAM];
    No *lista=NULL;

    while(menu!=0){
        printf("1 - Inserir Aluno\n");
        printf("2 - Remover Aluno\n");
        printf("3 - Mostrar lista Dos Alunos\n");
        printf("4 - Sair\n");

        scanf("%d",&menu);

        if(menu==1){
        	printf("Nome: ");
        	scanf("%s",nome);
        	printf("Numero: ");
        	scanf("%d",&numeroAluno);
        	printf("\n");
        	lista=criaNo(nome,numeroAluno,lista);
        }

        if(menu==2){
            printf("Numero do aluno a remover: \n");
            scanf("%d",&numeroAluno);
            lista=removeDaLista(numeroAluno,lista);
        }

        if(menu==3) imprimeLista(lista);

        if(menu==4) menu=0;

    }
    return 0;
}