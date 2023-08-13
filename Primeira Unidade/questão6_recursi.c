#include <stdio.h>

int recursivo(int num, int invert){
    if(num == 0){
        return invert;
    }
    invert = invert * 10 + num % 10;
    return (recursivo(num/10, invert));
}

int main(){
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    int invert = recursivo(num, 0);
    printf("Numero invertido: %d", invert);
    return (0);
}
