#include <stdio.h>
#include <stdlib.h>

#define lista 32

typedef struct contatos{
    char nome[100];
    char email[60];
    int telefone;
}Contatos;

struct hash {
    int chave;
    char livre;
    Contatos *contatos;
};

int funcaoHash2(int key) {
    float A = 0.6180339887; 
    float valorHash = key * A;
    valorHash = valorHash - (int)valorHash;
    unsigned int indice = (unsigned int)(lista * valorHash);
    return indice;
}

int funcao_hashing(int key) {
    int sum = 0;
    while (key > 0){
        sum += key % 10;
        key /= 10;
    }
    int index = funcaoHash2(sum%lista);
    return index;
}


void mostrar_hash(struct hash *tabela) {
    FILE*arq=fopen("Contatos.txt","w");
    fprintf(arq,"LISTA DE CONTATOS:\n");
    if(arq==NULL){
        printf("ERRO AO ABRIR O ARQUIVO\n");
        exit (1);
    }
    for (int i = 0; i < lista; i++) {
        if (tabela[i].contatos != NULL && tabela->livre != 'R'){
            fprintf(arq, "\nNome: %s\n", tabela[i].contatos->nome);
            fprintf(arq, "Email: %s\n", tabela[i].contatos->email);
            fprintf(arq, "Telefone: %d\n", tabela[i].contatos->telefone);
        }
    }
    fclose(arq);
}

void limpaTabela(struct hash *tabela){
    int i;
    for(i=0; i < lista; i++){
        tabela[i].contatos = NULL;
    }
}


void inserir(struct hash *tabela, Contatos *contat) {
    int index = funcao_hashing(contat->telefone);
    while(tabela[index].livre != 'L' && tabela[index].livre !='R'){
        index = (index+1)%lista;
    }
    tabela[index].contatos = contat;
    tabela[index].livre = 'O';
    tabela[index].chave = contat->telefone;
    printf("Contato adicionado na tabela Hash!\n");
}

int buscar_Contato(struct hash *tabela, int num) {
    int index = funcao_hashing(num);
    int key = 1;
    while (key <= lista && tabela[index].livre != 'O' && tabela[index].chave != num) {
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

void remover(struct hash *tabela, int num) {
    int posicao = buscar_Contato(tabela, num);
    if (posicao < lista) {
        tabela[posicao].livre = 'R';
    }
    else {
        printf("Contato não está presente\n");
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
    
    printf("Contato adicionado com sucesso!\n");
    return(novo_contato);
}

void listarContatos(struct hash *tabela){
    printf("\nLista de Contatos:\n\n");
    for (int i = 0; i < 32; i++){
        if (tabela[i].contatos != NULL && tabela->livre != 'R'){
            printf("\nNome: %s\n", tabela[i].contatos->nome);
            printf("Email: %s\n", tabela[i].contatos->email);
            printf("Telefone: %d\n", tabela[i].contatos->telefone);
        }
    }
}

int main() {
    struct hash tabela[lista];
    Contatos* contat;
    int num, i, op;
    limpaTabela(tabela);
    for (i = 0; i < lista; i++) {
        tabela[i].livre = 'L';
    }
    while(1){
        printf("\nMENU DE OPÇÕES\n");
        printf("\n1-Adicionar Contato\n");
        printf("\n2-Excluir Contato\n");
        printf("\n3-Listar Contatos\n");
        printf("\n4-Buscar Contato\n");
        printf("\n5-Exportar Contato\n");
        printf("\n6-Sair\n");
        printf("\nDigite sua opção: ");
        scanf("%d", &op);
        if (op < 1 || op > 6) {
            printf("Opção Inválida\n");
        }
        else {
            switch (op) {
                case 1:
                    printf("\n====================\n");
                    printf("\n  ADICIONAR CONTATO\n");
                    printf("\n====================\n");
                    contat = add_contato();
                    inserir(tabela, contat);
                    break;
                case 2: 
                    printf("\n====================\n");
                    printf("\n  EXCLUIR CONTATO \n");
                    printf("\n====================\n");
                    printf("Digite o Contato a ser excluido: ");
                    scanf("%d", &num);
                    remover(tabela, num);
                    break;
                case 3:
                    printf("\n====================\n");
                    printf("\n  LISTAR CONTATOS\n");
                    printf("\n====================\n");
                    listarContatos(tabela);
                    break;
                case 4:
                    printf("\n====================\n");
                    printf("\n  BUSCAR CONTATO\n");
                    printf("\n====================\n");
                    printf("Digite o contato que deseja encontrar: ");
                    scanf("%d", &num);
                    int pos = buscar_Contato(tabela, num);
                    printf("Nome: %s\nEmail: %s\nTelefone: %d", tabela[pos].contatos->nome, tabela[pos].contatos->email, tabela[pos].contatos->telefone);
                    break;
                case 5:
                    printf("\n====================\n");
                    printf("\n  EXPORTAR CONTATOS  \n");
                    printf("\n====================\n");
                    mostrar_hash(tabela);
                    break;
                case 6:
                    printf("\n====================\n");
                    printf("          SAIR \n");
                    printf("\n====================\n");
                    exit(0);
                    printf("\n");
                    break;
                default:
                    printf("Opção invalida!\n");
                    break;
            }
        }
    }
    return 0;
}
