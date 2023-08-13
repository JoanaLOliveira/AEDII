#include <stdio.h>

void ascii(){
    for(int i = 0 ; i <= 127 ; i++){
        if(i % 10 == 0){
            printf("\n");
        }
        printf("%3d: '%c'   ", i, i);
    }
}

int main(){
    ascii();
    return (0);
}
