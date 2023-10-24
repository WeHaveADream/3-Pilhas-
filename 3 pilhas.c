#include<stdlib.h>
#include<stdio.h>

typedef struct pilhao{

    int valor;

    struct pilhao *anterior;

}pilhao;

typedef struct toppilha
{
    pilhao *topo;
}toppilha;

void criarPilha(toppilha *p){

    p->topo = NULL;

}

int pilhaVazia(toppilha *p){

    if(p->topo == NULL)
        return 1;
    else
        return 0;

}

void empilharElemento(toppilha *p, int valor){

    pilhao *novo = malloc(sizeof(pilhao));

    novo->valor = valor;
    novo->anterior = p->topo;

    p->topo = novo;

    novo=NULL;
    free(novo);

}


void mostrarPilha(toppilha *p){

    if(pilhaVazia(p) == 0){
        pilhao *aux;
        aux = p->topo;


        while (aux != NULL)
        {
            printf("\n %d", aux->valor);

            aux = aux->anterior;
        }
        printf("\n\n");

    }
    else{
        printf("\n===Pilha vazia===\n");
    }
}

void  desempilha(toppilha *p){

    pilhao *aux;
    aux=p->topo;
    p->topo = aux->anterior;
    aux->anterior=NULL;

    free(aux);

}

int menu(){
    int opc;

    printf("\n\n1 - Pilha 1");
    printf("\n2 - Pilha 2");
    printf("\n3 - Pilha 3");
    printf("\n4 - Mostrar todas as pilhas");
    printf("\n5 - Mostrar quantos elementos totais tem as pilhas");
    printf("\n0 - Sair");
    printf("\n-> ");

    fflush(stdin);
    scanf("%d", &opc);

    return opc;
}

int menuPilha(){

    int opc_pilha = 0;

    printf("1- Empilhar\n");
    printf("2- Desempilhar\n");
    printf("3- Mostrar Pilha\n");
    printf("4- Voltar\n");
    printf("-> ");
    fflush(stdin);
    scanf("%d", &opc_pilha);

    return opc_pilha;

}

int main (){

    toppilha *pi1 = malloc(sizeof(pilhao));
    toppilha *pi2 = malloc(sizeof(pilhao));
    toppilha *pi3 = malloc(sizeof(pilhao));
    int opc = 0;
    int opc_pilha = 0;
    int valor = 0;
    int cont_pi1 = 0;
    int cont_pi2 = 0;
    int cont_pi3 = 0;

    criarPilha(pi1);
    criarPilha(pi2);
    criarPilha(pi3);

    do{
        opc = menu();

        switch (opc)
        {
        case 1:
            opc_pilha = menuPilha();

            switch (opc_pilha)
            {
            case 1:
                printf("\nInsira o valor: ");
                fflush(stdin);
                scanf("%d", &valor);

                empilharElemento(pi1, valor);
                cont_pi1++;
                break;

            case 2:
                desempilha(pi1);
                break;

            case 3:
                mostrarPilha(pi1);
                break;

            default:
                break;
            }

            break;

        case 2:
            opc_pilha = menuPilha();

            switch (opc_pilha)
            {
            case 1:
                printf("\nInsira o valor: ");
                fflush(stdin);
                scanf("%d", &valor);

                empilharElemento(pi2, valor);
                cont_pi2++;
                break;

            case 2:
                desempilha(pi2);
                break;

            case 3:
                mostrarPilha(pi2);
                break;

            default:
                break;
            }

            break;
        case 3:
            opc_pilha = menuPilha();

            switch (opc_pilha)
            {
            case 1:
                printf("\nInsira o valor: ");
                fflush(stdin);
                scanf("%d", &valor);

                empilharElemento(pi3, valor);
                cont_pi3++;
                break;

            case 2:
                desempilha(pi3);
                break;

            case 3:
                mostrarPilha(pi3);
                break;
            break;

            default:
                break;
            }

            break;

        case 4:

            printf("\npilha 1 : ");
            mostrarPilha(pi1);

            printf("\n\npilha 2: ");
            mostrarPilha(pi2);

            printf("\n\npilha 3: ");
            mostrarPilha(pi3);


            break;

        case 5:
            printf("\nquantidade de elementos da pilha 1: %d", cont_pi1);
            printf("\nquantidade de elementos da pilha 2: %d", cont_pi2);
            printf("\nquantidade de elementos da pilha 3: %d\n", cont_pi3);

            break;



        }

    }while(opc != 0);

    return 0;
}
