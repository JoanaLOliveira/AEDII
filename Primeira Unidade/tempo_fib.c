#include <stdio.h>
#include <time.h>
#include <math.h>

void soma(int n){
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            for(size_t k=0;k<n;k++){
                if(j==99){
                    printf("Marcador: %d\n",i);
                }
            }   
        }
    }
}

int fib(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}

int main(){
    double soma=0;
    for(int i=0; i<10; i++){
        clock_t start = clock();
        fib(40);
        clock_t end = clock();
        soma+= (double) (end-start);
    }
    printf("Tempo de execucao: %f\n", soma/10*(CLOCKS_PER_SEC));

}