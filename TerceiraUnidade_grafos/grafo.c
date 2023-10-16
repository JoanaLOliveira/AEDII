#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vertice{
    int id, new_id;
    char nome[100];
    struct Adjacencia* adjacente;
}Vertice;

typedef struct adjacencia {
    struct Vertice* vertice;
    struct Adjacencia* proximo; // Próximo elemento na lista de adjacência
} Adjacencia;

typedef struct aresta {
    int idOrig;
    int idDest;
} Aresta;

typedef struct grafo {
    Vertice* vertices;
    Aresta* arestas;
    int numVertices;
    int numArestas;
} Grafo;

Adjacencia* cria_adjacencia() {
    Adjacencia* newAdjacencia = (Adjacencia*)malloc(sizeof(Adjacencia));
    if (newAdjacencia == NULL) {
        printf("Erro na alocação de memória para a adjacência\n");
        exit(1);  // Ou trate o erro de outra forma
    }
    newAdjacencia->vertice = NULL;
    newAdjacencia->proximo = NULL;
    return newAdjacencia;
}




int buscar_politico(Vertice* vertice){
    FILE* politico_nome = fopen("politico_nome.csv","r");
    if(politico_nome == NULL){
        printf("\nErro na abertura do arquivo!");
        exit(1);
    }
    char linha[256];
    if (fgets(linha, sizeof(linha), politico_nome) == NULL) {
        printf("Erro ao ler cabeçalho do arquivo.");
        fclose(politico_nome);
        return -1;
    }
    while (fgets(linha, sizeof(linha), politico_nome)) {
        if (sscanf(linha, "%d;%99[^;];%d", &vertice->new_id, vertice->nome, &vertice->id) == 3) {
            printf("Dado encontrado: new_id=%d, nome=%s, id=%d\n", vertice->new_id, vertice->nome, vertice->id);
            break;
        }
    }
    fclose(politico_nome);
    return vertice->new_id;
}

void buscar_amigos(int id, int new_id, Grafo* grafo) {
    FILE* politico_amigos = fopen("politicos_amigos.csv", "r");
    if (politico_amigos == NULL) {
        printf("\nErro na abertura do arquivo 'politicos_amigos.csv'\n");
        return;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), politico_amigos)) {
        int idOrig, idDest;
        if (sscanf(linha, "%d;%d", &idOrig, &idDest) == 2) {
            if (idOrig == id && idDest != id) {
                for (int i = 0; i < grafo->numVertices; i++) {
                    if (grafo->vertices[i].id == idDest) {
                        Adjacencia* novaAdjacencia = cria_adjacencia(&grafo->vertices[i]);
                        novaAdjacencia->proximo = grafo->vertices[id].adjacente;
                        grafo->vertices[id].adjacente = novaAdjacencia;
                        printf("%s é amigo de %s (ID: %d)\n", grafo->vertices[i].nome, grafo->vertices[id].nome, id);
                        break;
                    }
                }
            }
        }
    }
    fclose(politico_amigos);
}

int main(){
    Vertice vertice;
    unsigned int id, new_id;
    Grafo meuGrafo;
    meuGrafo.numVertices = 3;
    meuGrafo.numArestas = 2;
    meuGrafo.vertices = (Vertice*)malloc(meuGrafo.numVertices * sizeof(Vertice));
    meuGrafo.arestas = (Aresta*)malloc(meuGrafo.numArestas * sizeof(Aresta));
    
    printf("Digite o id do politico que deseja buscar: ");
    scanf("%d", &id);
    new_id = buscar_politico(vertice);
    printf("Digite o id que deseja buscar atraves do id ja fornecido: ");
    scanf("%d", &id);
    buscar_amigos(id, new_id, &meuGrafo);

    free(meuGrafo.vertices);
    free(meuGrafo.arestas);
    return (0);
}
