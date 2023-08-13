#include <stdio.h>

typedef struct data{
    int dia, mes, ano;
}Dia;

int Total_Aulas(Dia dia_hoje, Dia dia_ultimo){
    int DiasdeAula=0, diahoje;
    int meshoje, mesultimo = dia_ultimo.mes;
    int anohoje, anoultimo = dia_ultimo.ano;
    for(anohoje = dia_hoje.ano; anohoje <= anoultimo; anohoje++){
        for(meshoje = dia_hoje.mes; meshoje <= mesultimo; meshoje++){
            for(diahoje = dia_hoje.dia; diahoje <= 30; diahoje++){
                if(diahoje % 7 == 2){
                    DiasdeAula++;
                }
            }
        }
    }
    return (DiasdeAula);
}

int main(){
    Dia dia_hoje = {7, 8, 2023};
    Dia dia_ultimo = {20, 11, 2023};
    int total = Total_Aulas(dia_hoje, dia_ultimo);
    printf("\nTivemos %d aulas", total);
    return(0);
}
