#include "stdio.h"
#include "stdlib.h"

#include "./../view/logo.c"
#include "./login.c"

#include "./../view/visualizacao.c"
#include "locale.h"

int main() {

    setlocale(LC_ALL, "Portuguese_Brasil");

    logo();

    char resp[RESP][RESP_CHARS] = {
        { 'L', 'o', 'g', 'i', 'n', '\0' },
        { 'C', 'a', 'd', 'a', 's', 't', 'r', 'o', '\0' },
        { 'S', 'a', 'i', 'r', '\0' }
    };

    int entrada = menu("Bem-vindo.", resp);

    switch (entrada) {
        case 1:
            login();
            break;

        case 2:
            //cadastro();
            break;

        case 3:
            printf("Obrigado volte sempre!");
            return 0;
    }

    return 0;
}