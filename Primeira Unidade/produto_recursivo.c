#include <stdio.h>

int produto(int x1, int x2) {
    if (x2 == 0) {
        return 0;
    }
    else if(x2 == 1){
        return x1;
    }
    return x1 + produto(x1, x2 - 1);
}

int main() {
    int x1, x2;
    printf("Digite o valor de x1: ");
    scanf("%d", &x1);
    printf("Digite o valor de x2: ");
    scanf("%d", &x2);
    int y = produto(x1, x2);
    printf("O produto de %d e %d e %d\n", x1, x2, y);
    return 0;
}