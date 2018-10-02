#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Inserir(int x);
void Remover();
void Exibir();
int pe=0;
int ps=0;
int qtd=0;
int fila[5];

int main(){

	int entrada=0;
	int op=0;
	
	for(;;){
		system("cls");
		printf("\nOpcoes: \n");
		printf("1 - Inserir\n2 - Remover\n3 - Exibir\n4 - Sair\n");
		scanf("%i",&op);
		if(op == 1){
			printf("%i",qtd);
			if(qtd == 5){
				printf("\nFila lotada!\n");
				system("pause");
			}else{
				printf("Qual o valor a ser inserido na fila: \n");
				scanf("%i",&entrada);
				Inserir(entrada);
			}
		}else if(op == 2){
			if(qtd == 0){
				printf("\nNao ha ninguem na fila!\n");
				system("pause");
			}else{
				Remover();	
			}
		}else if(op == 3){
			Exibir();
		}else if(op == 4){
			break;
		}else{
			printf("\nComando inválido\n");
		}
	}
}

int Inserir(int x){

	if(qtd < 5 && pe == 5){//
			
		pe = 0;
		fila[pe] = x;//
		pe++;
		qtd++;//
		return 1;
			
	}else if(qtd < 5){
			
		fila[pe] = x;
		pe++;
		qtd++;
		return 1;		
	}
}

void Remover(){
	if(ps == 5 && qtd > 0){
			ps = 0;
			fila[ps] = NULL;
			ps++;
			qtd--;
	}else if(ps < 5){
						
			fila[ps] = NULL;
			ps++;
			qtd--;
		
	}
}

void Exibir(){
	for(int i=0;i<5;i++){
		printf("Fila: [%i]\n",fila[i]);
	}
	system("pause");
}

