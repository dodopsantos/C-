#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Inserir(int x);
void Remover();
void Exibir();
void Exibir_idosos();

int nEntrada=0, pEntrada=0;
int nSaida=0, pSaida=0;
int nQtd=0, pQtd=0;
int fila[5], preferencial[5];

int main(){

	int entrada=0;
	int op=0;
	
	for(;;){
		system("cls");
		printf("\n#    Menu:    #\n\n");
		printf("1. Inserir\n2. Remover\n3. Exibir fila normal\n4. Exibir fila preferencial\n5. Sair\n");scanf("%i",&op);
		printf("N:[%i] P:[%i]\n",nQtd,pQtd);
		
		switch(op){
					
		case 1 :
			printf("Qual sua idade: \n");scanf("%i",&entrada);
			Inserir(entrada);
			break;
			
		case 2 :
			Remover();
			break;
			
		case 3 :
			Exibir();
			break;
			
		case 4:
			Exibir_idosos();
			break;
			
		case 5 :
			exit(1);
			break;
		}
	}
}

int Inserir(int x){

	if(x < 60){
		if(nQtd == 5){
				printf("\nFila lotada!\n");
				system("pause");
		}if(nQtd < 5 && nEntrada == 5){
			
			nEntrada = 0;
			fila[nEntrada] = x;
			nEntrada++;
			nQtd++;
			return 1;
			
		}else if(nQtd < 5){
			
			fila[nEntrada] = x;
			nEntrada++;
			nQtd++;
			return 1;		
		}
	}else{
		if(pQtd == 5){
				printf("\nFila lotada!\n");
				system("pause");
		}if(pQtd < 5 && pEntrada == 5){
			
			pEntrada = 0;
			preferencial[pEntrada] = x;
			pEntrada++;
			pQtd++;
			return 1;
			
		}else if(pQtd < 5){
			
			preferencial[pEntrada] = x;
			pEntrada++;
			pQtd++;
			return 1;		
		}
	}
	
}

void Remover(){
	if(nQtd == 0 && pQtd == 0){
		printf("\nVazia!\n");
		system("pause");			
	}else{
		if( pQtd < 1 ){
			if(nSaida == 5 && nQtd > 0){
				nSaida = 0;
				printf("%i removido da fila normal!\n",fila[nSaida]);
				fila[nSaida] = NULL;
				nSaida++;
				nQtd--;
				system("pause");
				
			}else if(nSaida < 5){	
				printf("%i removido da fila normal!\n",fila[nSaida]);				
				fila[nSaida] = NULL;
				nSaida++;
				nQtd--;
				system("pause");
			}
		}else{
		
			if(pSaida == 5 && pQtd > 0){
				pSaida = 0;
				printf("%i removido da fila preferencial!\n",preferencial[pSaida]);
				preferencial[pSaida] = NULL;
				pSaida++;
				pQtd--;
				system("pause");
			}else if(pSaida < 5){		
				printf("%i removido da fila preferencial!\n",preferencial[pSaida]);			
				preferencial[pSaida] = NULL;
				pSaida++;
				pQtd--;
				system("pause");
			}
		}	
	}
}

void Exibir(){
	for(int i=0;i<5;i++){
		printf("Fila: [%i]\n",fila[i]);
	}
	system("pause");
}

void Exibir_idosos(){
	for(int i=0;i<5;i++){
			printf("Preferencial: [%i]\n",preferencial[i]);	
	}
	system("pause");
}
