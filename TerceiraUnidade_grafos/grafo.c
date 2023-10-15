#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila{
    Vertice* prox;
    Vertice* ant;
}Fila;

typedef struct vertice{
    int id, new_id;
    char nome[100];
    Fila* lista;
}Vertice;

Vertice* cria_fila(){
    Vertice *v = (Vertice*)malloc(sizeof(Vertice));
    v->prox = NULL;
    v->ant = NULL;
}

int buscar_politico(Vertice* vertice){
    Fila* add =(Fila*)malloc(sizeof(Fila));
    FILE* politico_nome = fopen("politico_nome.csv","r");
    if(politico_nome == NULL){
        printf("\nErro na abertura do arquivo!");
        exit(1);
    }
    fscanf(politico_nome,"%*[^;];%*[^;];%*[^;];%*[^\n]\n");
 
    while(fscanf(politico_nome, "%99[^;];%99[^;];%99[^;];%*[^\n]\n", &vertice->new_id, vertice->nome, &vertice->id) == 3){
        
        printf("Dado encontrado");   
    }
    fclose(politico_nome);
    return vertice->new_id;
}

/* void buscar_amigos(int id, int new_id, Aresta* aresta){
    int aux = buscar_politico(new_id, );
    FILE* politico_amigos = fopen("politicos_amigos.csv", "r");
    if (politico_amigos == NULL){
        printf("\nErro na abertura do arquivo!");
    }

    while(fscanf(politico_amigos, "%99[^;];", &)){

    }
} */

int main(){
    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    unsigned int id, new_id;
    printf("Digite o id do politico que deseja buscar: ");
    scanf("%d", &id);
    new_id = buscar_politico(vertice);
    printf("Digite o id que deseja buscar atraves do id ja fornecido: ");
    scanf("%d", &id);
    //buscar_amigos(id, new_id);
    return (0);
}
