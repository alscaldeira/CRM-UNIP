#include <stdio.h>

int main() {

    int qualnivel, resultado;
    printf("pretende retirar seu dinheiro em quanto tempo?\n");
    printf("(1) ******\n (2) ******\n (3) *****\n (4) *****\n\n");
    printf("Escolha: ");
    scanf("%d", &qualnivel);
     

    switch (qualnivel) {

        case 1:
            resultado = 10;
            break;

         case 2:
            resultado = 20;
            break;

         case 3:
            resultado = 30;
            break;

         case 4:
            resultado = 40;
            break;

    }

    printf("sabe o que esta fazendo?\n");
    printf("(1) ******\n (2) ******\n (3) *****\n (4) *****\n\n");
    printf("Escolha: ");
    scanf("%d", &qualnivel);

    switch (qualnivel) {

        case 1:
            resultado += 10;
            break;

         case 2:
            resultado += 20;
            break;

         case 3:
            resultado += 30;
            break;

         case 4:
            resultado += 40;
            break;

    }

    if(resultado <= 40){
        printf("vc e conservador %d", resultado);

    } else if(resultado <= 60) {
        printf("vc e moderado %d", resultado);

    } else {
        printf("vc e agressivo %d", resultado);

    }
    


}