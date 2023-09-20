#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define TITULO_OPCAO1 " Adicionar Contato "
#define TITULO_OPCAO2 " Remover Contato "
#define TITULO_OPCAO3 " Listar Contatos "
#define TITULO_OPCAO4 " Buscar Contato "
#define TITULO_OPCAO5 " Exportar Contatos "
#define TITULO_OPCAO6 " Sair "

#define N_OPCOES 6
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'

typedef struct contatos{
    char nome[100];
    char email[60];
    int telefone;
}Contatos;

int LeOpcao();

void ApresentaMenu(int nItens, int menorOpcao, ...);

Contatos *add_contato();

void insereHash(Contatos **tabelaHash, Contatos *c);

int funcaoHash(int key);

int funcaoHash2(int key);

void exclui_contato(Contatos *tabela);

int main (void){
    unsigned char op;
    unsigned int saida = 0;
    Contatos *novo = (Contatos*)malloc(sizeof(Contatos));
    Contatos *tabelaHash[31];
    printf("\n=================================\n");
    printf("              MENU               \n");
    printf("=================================\n");
    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                    TITULO_OPCAO1, TITULO_OPCAO2,
                    TITULO_OPCAO3, TITULO_OPCAO4,TITULO_OPCAO5, TITULO_OPCAO6);
            
        op = LeOpcao();
        switch(op) {
            case 1:
                printf("\n=================================\n");
                printf("         Adicionar Contato         \n");
                printf("=================================\n");
                printf("\n");
                novo = add_contato();
                insereHash(*tabelaHash, novo);
                printf("\n");
                break;
                
            case 2:  
                printf("\n=================================\n");                   
                printf("         Excluir Contato           \n");
                printf("=================================\n");
                printf("\n");
                //exclui_contato(tabelaHash);
                printf("\n");
                break;

            case 3:       
                printf("\n=================================\n");            
                printf("         Listar Contatos           \n");
                printf("=================================\n");
                printf("\n");
                 
                printf("\n");
                break;
                    
            case 4:
                printf("\n=================================\n");
                printf("           Buscar Contato          \n");
                printf("=================================\n");
                printf("\n");
                
                printf("\n");
                
                printf("\n");
                break;

            case 5:
                printf("\n=================================\n");
                printf("         Exportar Contatos         \n");     
                printf("=================================\n");   
                
                printf("\n");
                
                printf("\n");
                break;

            case 6:
                
                printf("\n=================================\n");
                printf("              Sair               \n");
                printf("=================================\n");
                saida = 1;
                printf("\n");
                break;

            default:
                printf("Opcao invalida");
                return 1;
        }
            
    }while(!saida);

    return 0;
}

void LimpaBuffer(void) {
    int valorLido; /* valorLido deve ser int! */
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int LeOpcao() {
    int r, ret2, n1, letra;
    r = 0;
    while (r != 1){
        printf("\nDigite sua opcao: ");
        ret2 = scanf("%d", &n1);
        if (n1 >= 1 && n1 <= 6){
            r = ret2;
        }
        if (r == 0){
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre 1 e 6. \n");
        }
        letra = 0;
        while (letra != '\n'){
            letra = getchar();
        }
        printf("\n");
    }
    return n1;
}

void ApresentaMenu(int nItens, int menorOpcao, ...){
    int i;
    va_list argumentos;
    va_start(argumentos, menorOpcao);
    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);
}

Contatos *add_contato(){
    Contatos *novo_contato = (Contatos*)malloc(sizeof(Contatos));
    
    printf("Digite o nome");
    scanf(" %s", novo_contato->nome);
    printf("Digite o E-mail");
    scanf(" %s", novo_contato->email);
    printf("Digite o telefone");
    scanf("%d", &novo_contato->telefone);
    
    /* FILE *arq = fopen("Contatos.txt", "a");
    if(arq == NULL){
		printf("Erro ao abrir o arquivo\n");
		exit(1);
	}
	fprintf(arq, "Nome: %s\nE-mail: %s\nTelefone:%i\n\n", novo_contato->nome, novo_contato->email, novo_contato->telefone);
	printf("\nDados adicionados no arquivo!\n");
    fclose(arq);*/
    return(novo_contato);
}

void insereHash(Contatos **tabelaHash, Contatos *c){
    int index = funcaoHash(c->telefone);
    int key_inicio = index;
    while(1){
        if(tabelaHash[index]->telefone == 0){
            tabelaHash[index] = c;
            break;
        }
        index++;
        if(key_inicio == index){
            break;
        }
        if(index > 32){
            index = index % 32;
            key_inicio = index;
        }
    }
}

int funcaoHash(int key) {
    int sum = 0;
    while (key > 0){
        sum += key % 10;
        key /= 10;
    }
    return funcaoHash2(sum % 32);
}

int funcaoHash2(int key){
    return key % 32;
}
