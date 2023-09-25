#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define lista 32

typedef struct contatos{
    char nome[100];
    char email[60];
    int telefone;
}Contatos;

struct Hash {
    int chave;
    char livre;
    Contatos *contatos;
};

int funcaoHash2(int key){
    return key % 32;
}

int funcao_hashing(int key) {
    int sum = 0;
    while (key > 0){
        sum += key % 10;
        key /= 10;
    }
    return funcaoHash2(sum);
}


void mostrar_hash(struct Hash tabela[]) {
    FILE*arq=fopen("Contatos.txt","r");
    fprintf(arq,"LISTA DE CONTATOS:\n");
    if(arq==NULL){
        printf("ERRO AO ABRIR O ARQUIVO\n");
        exit (1);
    }
    for (int i = 0; i < lista; i++) {
        if (tabela[i].contatos != NULL && tabela[i].contatos->telefone != 0) {
            fprintf(arq, "\nNome: %s\n", tabela[i].contatos->nome);
            fprintf(arq, "Email: %s\n", tabela[i].contatos->email);
            fprintf(arq, "Telefone: %d\n", tabela[i].contatos->telefone);
        }
    }
    fclose(arq);
}


void inserir(struct Hash tabela[], int num) {
    int index = funcao_hashing(num);
    int key = index;
    while (key <= lista && tabela[index].livre != 'L' && tabela[index].livre != 'R') {
        index = (index + key) % lista;
        key = key + 1;
    }
    if (key <= lista) {
        tabela[index].chave = num;
        tabela[index].livre = 'O';
    }
    else {
        printf("Tabela cheia ou em loop\n");
    }
}

int buscar_Contato(struct Hash tabela[], int num) {
    int index = funcao_hashing(num);
    int key = 1;
    while (key <= lista && tabela[index].livre != 'L' && tabela[index].chave != num) {
        index = (index + key) % lista;
        key = key + 1;
    }
    if (tabela[index].chave == num && tabela[index].livre != 'R') {
        return index;
    }
    else {
        return lista;
    }
}

void remover(struct Hash tabela[], int num) {
    int posicao = buscar(tabela, num);
    if (posicao < lista) {
        tabela[posicao].livre = 'R';
    }
    else {
        printf("Elemento não está presente\n");
    }
}

void buscar(struct Hash tabela[], int num){
    int c;
    printf("Digite o numero que deseja buscar");
    scanf("%d", &c);
    size_t key = funcao_hashing(c);
    struct Hash *novo;
    int key_inicio = key;
    while(1){
        if(tabela[key].contatos->telefone == c){
        novo = tabela[key];
        return novo;
        }
        key++;
        if(key_inicio == key){
            break;
        }

        if(key > lista){
            key = key%lista;
            key_inicio = key;
        }
    }

}

Contatos *add_contato(){
    Contatos *novo_contato = (Contatos*)malloc(sizeof(Contatos));
    if (novo_contato==NULL){
        printf("Erro ao alocar memória para o novo contato.\n");
        exit (1);
    }
    printf("Digite o nome: ");
    scanf("%s",novo_contato->nome);
    printf("Digite o E-mail: ");
    scanf("%s",novo_contato->email);
    printf("Digite o telefone: ");
    scanf("%d",&novo_contato->telefone);
    return(novo_contato);
}

void listarContatos(Contatos **tabela){
    printf("\nLista de Contatos:\n\n");
    for (int i = 0; i < 32; i++) {
        if (tabela[i]->telefone != 0){
            printf("\nNome: %s\n", tabela[i]->nome);
            printf("Email: %s\n", tabela[i]->email);
            printf("Telefone: %d\n", tabela[i]->telefone);
        }
    }
}

int main() {
    struct Hash tabela[lista];
    Contatos* contat;
    unsigned int saida =0;
    int num, i, op;
    for (i = 0; i < lista; i++) {
        tabela[i].livre = 'L';
    }
    do {
        printf("\nMENU DE OPÇÕES\n");
        printf("\n1-Adicionar contato\n");
        printf("\n2-Excluir elemento\n");
        printf("\n3-Listar Contatos\n");
        printf("\n4-Buscar contato\n");
        printf("\n5-Exportar contato\n");
        printf("\n6-Sair\n");
        printf("\nDigite sua opção: ");
        scanf("%d", &op);
        if (op < 1 || op > 6) {
            printf("Opção Inválida\n");
        }
        else {
            switch (op) {
            case 1:
                printf("\n ADICIONAR CONTATO\n");
                num=add_contato(tabela);
                inserir(tabela, num);
                break;
            case 2: 
                printf("\n EXCLUIR CONTATO \n");
                printf("Digite o Contato a ser excluido: %d",&num);
                remover(tabela, num);
                break;
            case 3:
                printf("\n LISTAR CONTATOS");
                listarContatos(tabela);
                break;
            case 4:
                printf("\n BUSCAR CONTATO");
                printf("Digite o contato que deseja encontrar: %d", &num);
                buscar(tabela,num);
                break;
            case 5:
                printf("\nEXPORTAR CONTATOS\n");
                mostrar_hash(tabela);
                break;
            case 6:
                printf("\n=================================\n");
                printf("              SAIR               \n");
                printf("=================================\n");
                saida = 1;
                printf("\n");
                break;
            default:
                break;
            }
        }
        getch();
    } while (op != 6);
    return 0;
}
