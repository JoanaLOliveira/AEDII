#include <stdio.h>
#include <time.h>

void tempo(int n){
    for(size_t i=0; i<n; i++){
        for(size_t j=0; j<n; j++){
            for(size_t k=0; k<n; k++){
                if(j==99){
                    printf("Marcador: %ld\n", i);
                }
            }
        }
    }
}

int main(){
    double soma = 0; 
    for(int i=0;i<10; i++){
        clock_t start = clock();
        tempo(100);
        clock_t end = clock();
        soma += (double) (end - start);         
    }
    printf("Tempo: %f\n", soma/(10*CLOCKS_PER_SEC)); 
    return(0);
}