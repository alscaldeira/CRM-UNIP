#include "stdio.h"

int menu(char msg[], char resp[][6]) {
    
    // loop infinito para sair apenas quando o usuário entrar uma opção válida
    while(0 == 0) {
    
        // Escreve a mensagem
        printf("%s\n", msg);

        // Resgata o número de opções
        int opcoes = sizeof(resp);

        printf("%d ---- %lu\n", opcoes, sizeof(resp[0]));
        int entrada;

        for(int i = 0; i < opcoes; i++) {
            printf("%d - ", i+1);
            for(int j = 0; j <= sizeof(resp[i]); j++) {
                printf("%c", resp[i][j]);
            }
            printf("\n");
        }

        scanf("%d", &entrada);

        if(entrada <= opcoes && entrada > 0) {
            return entrada;
        }

    }
}

int main() {

    char msg[4] = "Test";
    char resp[3][6] = { "Resp 1",
                        "Resp 2",
                        "Resp 3"
                      };
    
    menu(msg, resp);
    return 0;
}
