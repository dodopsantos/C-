#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
	int valor;
	struct arvore *pE;
	struct arvore *pD;
	struct arvore *pC;
}B;

int inserir(B **pp,int valor);
int inserir_primeiro(B **pp,int valor);
void inicializa(B **pp);

void remover(B **pp);
void semF(B **pp);
void esqF(B **pp);
void dirF(B **pp);
void doisF(B **pp);

void EmOrdem(B **pp);
void PreOrdem(B **pp);
void PosOrdem(B **pp);

int profundidade (B **pp);
int balanceamantoE (B **pp);
int balanceamentoD (B **pp);

int tamanho = 0, temp = 0, raiz = 0, profun = 0, balE = 0, balD = 0, balanco = 0;

int main(){
	int op = 0, x = 0, navi = 0;
	B *a;
	B *nav;
	inicializa(&a);
	
	for(;;){
		
		system("cls");
		if(tamanho == 0){
			printf("#    Menu    #\n");
			printf("\n1. Inserir\n7. Sair\n\n->");scanf("%i",&op);
			if(op != 1 && op != 7){
				printf("Escolha uma opcao valida!\n");
				system("pause");
				main();
			}
			
		}else{
			printf("#    Menu    #\n");
			printf("\n1. Inserir\n2. Navegar\n3. Pre-ordem\n4. Em-ordem\n5. Pos-ordem\n6. Profundidade\n7. Balanceamento\n8. Sair\nValor: {%d}\n\n->",nav->valor);
			scanf("%i",&op);		
		}
		
		switch(op){
		
		case 1 :
			printf("Valor a ser inserido: \n");scanf("%i",&x);
			if(tamanho == 0){
				inserir_primeiro(&nav,x);
			}else{
				inserir(&nav,x);	
			}	
			break;
			
		case 2 :
			for(;;){
				
				system("cls");
				printf("#    Menu    #\n");
				printf("\n1. Cima\n2. Direita\n3. Esquerda\n4. Remover\n5. Menu\n Valor: {%d}\n\n->",nav->valor);scanf("%i",&navi);
				if(navi == 1){
					
					if(nav->pC == NULL){	
							printf("Elemento ja na raiz");
							system("pause");		
						}else{	
						nav = nav->pC;
					}
					
				}else if(navi == 2){
					
					if(nav->pD == NULL){
						
						printf("Ultima elemento da folha para a direita");
						system("pause");
					}else{
						nav = nav->pD;
					}
					 
				}else if(navi == 3){
					
					if(nav->pE == NULL){
						
						printf("Ultima elemento da folha para a esquerda");
						system("pause");
					}else{
						nav = nav->pE;
					}	 
				}else if (navi == 4){
					
					remover(&nav);
				}else if (navi == 5){
					while(nav->pC != NULL){
						
						nav = nav->pC;
					}
					break;
				}
			}
			
			break;
		
		case 3 :
			
			PreOrdem(&nav);
			system("pause");
			break;
			
		case 4 :
			
			EmOrdem(&nav);
			system("pause");
			break;
		case 5 :
			
			PosOrdem(&nav);
			system("pause");
			break;
		case 6 :
			
			while(nav->pC != NULL){
				nav = nav->pC;
			}
			profun = profundidade(&nav);
			
			printf("Tamanho: %i\n",(profun - 1));
			system("pause");
			break;
		case 7 :
			
			balD = balanceamentoD(&nav);
			balE = balanceamantoE(&nav);
			printf("\nEsquerda: %i\n",(balE - 1));
			printf("\nDireita: %i\n",(balD - 1));
			balanco = balE - balD;
				if(balanco == 0 || balanco == 1 || balanco == -1){
					printf("Arvore Balanceada\n");
				}else{
					printf("Arvore Desbalanceada\n");
				}
			system("pause");
			break;
		case 8 :
			
			exit(1);
			break;
		}
	}
}

void inicializa(B **pp){
   *pp = NULL;
}

int inserir_primeiro(B **pp,int valor){
	
	arvore *no = (arvore*)malloc(sizeof(arvore));
	no->valor = valor;
	no->pE = NULL;
	no->pD = NULL;
	no->pC = NULL;
	*pp = no;
	raiz = valor;
	tamanho++;		
		
}

int inserir(B **pp,int valor){
	
	arvore *no = (arvore*)malloc(sizeof(arvore));
	B *nav;
	B *temp;
	nav = *pp;
	no->valor = valor;
	
	if(nav->valor > no->valor){
				
		if(nav->pE == NULL){
				temp = nav;
				no->pC = temp;
				no->pE = NULL;
				no->pD = NULL;
				nav->pE = no;	
						
		}else{
			while(nav->valor > no->valor && nav->pE != NULL){
				nav = nav->pE;
			}
					
			if(nav->valor > no->valor){
				temp = nav;
				no->pC = temp;
				no->pE = NULL;
				no->pD = NULL;
				nav->pE = no;
				
			}else{
				temp = nav;
				no->pC = temp;
				no->pE = NULL;
				no->pD = NULL;
				nav->pD = no;
			}
		}
			
	}else if(nav->valor < no->valor){
				
		if(nav->pD == NULL){
				temp = nav;
				no->pC = temp;
				no->pE = NULL;
				no->pD = NULL;
				nav->pD = no;	
						
		}else{
			while(nav->valor < no->valor && nav->pD != NULL){
				nav = nav->pD;
			}
					
			if(nav->valor < no->valor){
				temp = nav;
				no->pC = temp;
				no->pE = NULL;
				no->pD = NULL;
				nav->pD = no;
				
			}else{
				temp = nav;
				no->pC = temp;
				no->pE = NULL;
				no->pD = NULL;
				nav->pE = no;
			}
		}
	}
	tamanho++;
}

void PreOrdem(B **pp){		

   B *pNavegar;
   pNavegar = *pp;
   
   if(pNavegar != NULL){
   		printf("\n%i", pNavegar->valor);
        PreOrdem(&pNavegar->pE);
        PreOrdem(&pNavegar->pD);
    }
}

void EmOrdem(B **pp){
	
	B *pNavegar;
	pNavegar=*pp;
	
    if(pNavegar != NULL){
        EmOrdem(&pNavegar->pE);
        printf("\n%i", pNavegar->valor);
        EmOrdem(&pNavegar->pD);
    }
}

void PosOrdem(B **pp){
	
	B *pNavegar;
	pNavegar = *pp;
	
	if(pNavegar != NULL){
		PosOrdem(&pNavegar->pE);
		PosOrdem(&pNavegar->pD);
		printf("\n%i", pNavegar->valor);
	}
}

int profundidade (B **pp) {
	
	B *pNavegar;
	pNavegar = *pp;
	int profE, profD;
	
   if (pNavegar == NULL){
		return 0;
   }else{
   	
   		profE = profundidade (&pNavegar->pE);
      	profD = profundidade (&pNavegar->pD);
      	
	    if (profE < profD){

	    	return profD + 1;
	    	
		}
	    else{

	    	return profE + 1;
		}
   }
}

int balanceamantoE (B **pp){
	
	B *pNavegar;
	pNavegar = *pp;
	int balanceE;
	
   if (pNavegar == NULL){
		return 0;
   }else{
   	
   		balanceE = balanceamantoE (&pNavegar->pE);
      	
	    return balanceE + 1;
   }
}

int balanceamentoD (B **pp){
	
	B *pNavegar;
	pNavegar = *pp;
	int balanceD;
	
   if (pNavegar == NULL){
		return 0;
   }else{
   	
   		balanceD = balanceamentoD (&pNavegar->pD);
      	
	    return balanceD + 1;
   }
}

void remover(B **pp){
	void semF(B **pp);
	void esqF(B **pp);
	void dirF(B **pp);
	void doisF(B **pp);
	B *pNavegar;
	pNavegar = *pp;
	
	if(pNavegar->pD == NULL && pNavegar->pE == NULL){
		semF(pp);
	}else if(pNavegar->pD == NULL && pNavegar->pE != NULL ){
		esqF(pp);
	}else if(pNavegar->pD != NULL && pNavegar->pE == NULL){
		dirF(pp);
	}else if(pNavegar->pD != NULL && pNavegar->pE != NULL){
		doisF(pp);		
	}
	
	*pp = pNavegar;
	
	}

void semF(B **pp){
	
	B *pNavegar;
	pNavegar = *pp;
	
	if(pNavegar->pC != NULL){
		pNavegar = pNavegar->pC;
		pNavegar->pD = NULL;
		pNavegar->pE = NULL;
			
	}else{
		//type=1;
	}
	
	*pp = pNavegar;
	
}

void esqF(B **pp){
	void remover(B **pp);
	B *pNavegar;
	pNavegar =*pp;
	int aux=0;
	
	pNavegar = pNavegar->pE;
	aux = pNavegar->valor;
	pNavegar = pNavegar->pC;
	pNavegar->valor = aux;
	pNavegar = pNavegar->pE;
	
	*pp = pNavegar;
	remover(pp);
}

void dirF(B **pp){
	void remover(B **pp);
	B *pNavegar;
	pNavegar =*pp;
	int aux=0;
	
	pNavegar = pNavegar->pD;
	aux = pNavegar->valor;
	pNavegar = pNavegar->pC;
	pNavegar->valor = aux;
	pNavegar = pNavegar->pD;
	
	
	*pp = pNavegar;
	remover(pp);
}

void doisF(B **pp){
	void remover(B **pp);
	B *pNavegar;
	B *raiz;
	B *dois;
	pNavegar = *pp;
	raiz = *pp;
	dois = *pp;
	int aux;
	while(raiz->pC != NULL){
			raiz = raiz->pC;
	}
		
	if(pNavegar->valor < raiz->valor){
		dois = dois->pE;
		
		while(dois->pD!=NULL){
			dois = dois->pD;
		}
	
		pNavegar->valor = dois->valor;
		pNavegar = pNavegar->pE;
	
		while(pNavegar->pD != NULL){
			pNavegar = pNavegar->pD;
		}
	}else{
		dois = dois->pD;
		
		while(dois->pE != NULL){
			dois = dois->pE;
		}
		 
		pNavegar->valor = dois->valor;
		pNavegar = pNavegar->pD;
		
		while(pNavegar->pE != NULL){
			pNavegar = pNavegar->pE;
		}
	}	
	
	*pp = pNavegar;
	remover(pp);	
}



