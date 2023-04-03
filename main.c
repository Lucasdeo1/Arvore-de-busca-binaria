#include <stdio.h>
#include <stdlib.h>
//Lucas Deodato
typedef struct Arvore{
	int inf; 
	struct arvore *esq; 
	struct arvore *dir; 
}arvore;

arvore*cria(){
	return NULL;
}

arvore*inserir( arvore*a, int v ){
	if ( a == NULL ){
		a = ( arvore* ) malloc( sizeof ( arvore ) );
		a->inf = v;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if( v <a->inf ){
		a->esq = inserir( a->esq, v );
	}
	else {
		a->dir = inserir( a->dir, v );
	}
	return a;
}

void mostra( arvore*a ){ // preordem
	if ( a != NULL ) {
		printf(" %d ", a->inf);
		mostra( a->dir );
		mostra( a->esq );
	}
}

void emordem( arvore*a ){
	if ( a != NULL ){
		emordem( a->dir );
		printf(" %d ", a->inf);
		emordem( a->esq );
	}
}

void posordem( arvore*a ){
	if ( a!=NULL ) { 
		posordem( a->dir );
		posordem( a->esq );
		printf(" %d ", a->inf);
	}
}

arvore*remove( arvore*a, int v ){
	if( a == NULL ){
        return NULL;
    }
    else{
        if( a->inf >v ){
            a->esq = remove ( a->esq, v );
        }
        else if ( a->inf < v ){
            a->dir = remove ( a->dir, v );
        }
        else{
            if( ( a->esq == NULL ) && ( a->dir == NULL ) ) { 
                free ( a );
                a=NULL;
            }
            else if( a->dir == NULL ) {
                arvore *aux = a;
                a = a -> esq;
                free ( aux );
            }
            else if( a->esq == NULL ) {
                arvore *aux = a;
                a = a -> dir;
                free ( aux );
            }
            else{
                arvore*aux = a->esq;
                while( aux->dir != NULL ){
                    aux = aux->dir;
                }
                a->inf = aux->inf;
                aux->inf = v;
                a->esq = remove( a->esq, v );
            }
        }
    }
    return a;
}

void liberaarvore ( arvore*a ){
	if( a!=NULL ) {
		liberaarvore ( a->esq );
		liberaarvore ( a->dir );
		free( a );
	}
}

int quantosnos( arvore*a ){
	if ( a == NULL ){
		return 0;
	}else {
		return 1 + quantosnos( a->dir ) + quantosnos( a->esq );
	}
}

int busca( arvore*a, int v ){
	if( a == NULL ) { 
		return 0;
	}else {
		if( v == a->inf ) {
			return 1;
		}else {
			printf("não existe na arvore!");
			return 2;
		}
	}
}

int main() {
	
	arvore*a;
	a = cria();
	int op,x,quant;
	while ( op!= 5 ){
		printf("\n-------------------\n");
		printf("1-inserir:\n");
		printf("2-mostrar em preordem:\n");
		printf("3-mostrar em ordem:\n");
		printf("4-mostrar em posordem:\n");
		printf("5-busca:\n");
		printf("6-remover um valor:\n");
		printf("7- total de nos:\n");
		printf("8- sair:\n");		
		printf("ESCOLHA:");
		scanf("%d", &op);
		printf("\n-------------------\n");
		
		switch ( op ){
		case 1:
			printf("insira um valor:");
			scanf("%d", &x);
			a = inserir( a, x );
			break;
		case 2:
			printf("imprimindo os valores em pre ordem...\n");
			mostra( a );
			break;
		case 3:
		
			printf("imprimindo os valores em ordem...\n");
			emordem( a );
			break;
		case 4:
			printf("imprimindo os valores em pos ordem...\n");
			posordem( a );
			break;
		case 5:
			printf("digite um valor para saber se existe na arvore:");
			scanf("%d",&x);
			if( busca( a, x ) == 0 ){
				printf("Não foi inserido nenhum dado na arvore.");
			}else if( busca( a, x ) == 1){
				printf("Esse valor foi encontrado na arvore.");
			}else {
				printf("não existe esse valor na arvore.");
			}
			break;
		case 6:
			printf("digite um valor que deseje remver:");
			scanf("%d",&x);
			a = remove( a, x );
			break;
		case 7:
			quant =  quantosnos( a );
			printf("%d",quant);
			break;
		case 8:
			liberaarvore( a );
			printf("Arvore de busca binaria destuida!");
			return 0;
			break;
		}	
	}
}
