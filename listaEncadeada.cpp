#include <stdio.h>
#include <stdlib.h>
#include <String.h>

typedef struct fila {
	int valor;
	struct fila *pA;
	struct fila *pD;
}fi;

int _inserir(fi **no,int valor);
int _inserir_primeiro(fi **no,int valor);
void inicializa(fi **pp);
void _remover(fi **pp);

int tamanho=0;
int i = 0;
int z = 0;
int ant = 0;
int* pen = NULL;
int* pfi = NULL;
fila *no;

int main(){

	fi *a;
	inicializa(&a);
	int op,valor=0,rem=0;
	inicializa(&a);
	for(;;){	
		system("cls");
		if(tamanho == 0){
			printf("#   Menu   #\n");
			printf("\n1. Inserir\n2. Remover\n3. Proximo\n4. Anterior\n5. Sair\n\n->");scanf("%i", &op);
		}else{
			printf("#   Menu   #\n");
			printf("\n1. Inserir\n2. Remover\n3. Proximo\n4. Anterior\n5. Sair\nValor:{%d}\n\n->",a->valor);scanf("%i", &op);
		}
		switch (op){
	
		case 1 :
			printf("Qual o valor a ser inserido: \n");
			scanf("%i",&valor);
			if(tamanho == 0){
				_inserir_primeiro(&a,valor);
			}else{
				_inserir(&a,valor);	
			}		
			break;
			
		case 2 :
			_remover(&a);
			break;
		
		case 3 :
			a = a->pD; printf("{%d}\n",a->valor); 
			system("pause");
			break;
			
		case 4 :
			a = a->pA; printf("{%d}\n",a->valor); 
			system("pause");
			break;
			
		case 5 :
			exit(1);
			break;
		}
	}
}

int _inserir_primeiro(fi **pp,int valor){
	
		fila *no = (fila*)malloc(sizeof(fila));
		no->valor = valor;
		no->pA = no;
		no->pD = no;
		*pp = no;
		
		tamanho++;
				
}

int _inserir(fi **pp,int valor){

		fila *no = (fila*)malloc(sizeof(fila));
		no->valor = valor;
		no->pD = (*pp)->pD;
		no->pA = *pp;
		(*pp)->pD = no;
		no->pD->pA = no;
		
		*pp = no;
	
}

void _remover(fi **pp){
		fila *no;
		
		(*pp)->pD->pA = (*pp)->pA;
		(*pp)->pA->pD = (*pp)->pD;
		no = (*pp)->pD;
		free(*pp);
		*pp = no;
	
}

void inicializa(fi **pp){
   *pp = NULL;
}




