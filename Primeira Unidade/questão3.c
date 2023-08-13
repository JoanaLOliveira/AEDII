#include <stdio.h>
#include <math.h>
void triplo_pitagorico(int x){
    for(int cateto1 = 1; cateto1 <=x; cateto1++){
        for(int cateto2 = 1; cateto2 <=x; cateto2++){
            float hip = sqrt((cateto1 * cateto1) + ((cateto2 * cateto2)));
            if(hip == (int)hip){
                printf("(%d) (%d) (%1.f)\n", cateto1, cateto2, hip);
            }
        }
    }
}

int main(){
    int x;
    printf("Digite um valor inteiro a ser usado como parametro: ");
    scanf("%d", &x);
    triplo_pitagorico(x);
    return (0);
}
