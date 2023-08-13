#include <stdio.h>

int NaoRecursivo(int num) {
    int inver = 0;

    while (num > 0) {
        inver = inver * 10 + num % 10;
        num = num / 10;
    }

    return inver;
}

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    int inver = NaoRecursivo(num);
    printf("Numero invertido: %d\n", inver);
    
    return 0;
}
