#include <stdio.h>
#include <stddef.h>

int main(){

    int dependentes, numerodependentes;

    printf("Possui dependestes?\n");
    printf("1 -- Sim\n");
    printf("2 -- Nao\n");
    printf("Digite uma opcao: ");
    scanf("%d", &dependentes);

    if(dependentes ==  1){
        printf("Quantos dependestes? ");
        scanf("%d", &numerodependentes);
    } else {
        numerodependentes = NULL;
    }

    printf("\n\n\n %d %d", dependentes, numerodependentes);
}