#include <stdio.h>
#include <time.h>
#include <math.h>

int main(){
    clock_t start = clock();
    for(size_t i=0; i<1000;i++){
        for(size_t j=0; j<1000;j++){
            for(size_t k=0; k<1000;k++){
                if(j==999){
                    printf("Marcador: %d\n",i);
                }
            }
        }
    }

    clock_t end = clock();
    printf("Tempo de execução: %f\n", (double)(end-start)/CLOCKS_PER_SEC);

}