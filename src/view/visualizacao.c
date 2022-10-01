#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define RESP 50
#define RESP_CHARS 50

struct Sizes{
    int resp;
} Sizes_default = { 50 };

int menu(char msg[], char resp[RESP][RESP]) {
    // loop infinito para sair apenas quando o usuário entrar uma opção válida
    while(0 == 0) {
        // Escreve a mensagem
        size_t size = strlen(msg);
        for(int i = 0; i < size; i++) {
            printf("%c", msg[i]);
        }
        printf("\n");

        int numeroDeOpcoes;
        char entrada = 0;

        // Imprime as possíveis respostas do usuário
        for(int i = 0; i < Sizes_default.resp -1; i++) {
            if(resp[i][0] == '\0') {
                numeroDeOpcoes = i;
                break;
            }
            
            printf("%d - ", i+1);

            for(int j = 0; j <= Sizes_default.resp; j++) {

                if(resp[i][j] == '\0') break;

                printf("%c", resp[i][j]);

            }

            printf("\n");
        }

        // Lê a entrada do usuário
        printf("Escolha uma opção: ");
        scanf("%c", &entrada);
        
        system("clear");
        
        int opcao = (int)entrada - 48;
        if(opcao <= numeroDeOpcoes && opcao > 0) {
            return opcao;
        }
    }
}

// int main() {

//     char msg[] = { 'T', 'e', 's', 't', 'i', 'n', 'g', ' ', 'v', 'i', 'e', 'w', '.', ' ', 'P', 'r', 'e', 's', 's', ' ', 's', 'o', 'm', 'e', ' ', 'n', 'u', 'm', 'b', 'e', 'r', '\t', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', '1', ' ', 'a', 'n', 'd', ' ', '5', '0', ' ', 't', 'o', ' ', 's', 't', 'o', 'p', '.', '\0' };
//     // *msg = *"Testing view. Press some number between 1 and 50 to stop.";
//     // *msg = { 'T', 'e', 's', 't', 'i', 'n', 'g', '\t', 'v', 'i', 'e', 'w', '.', '\t', 'P', 'r', 'e', 's', 's', '\t', 's', 'o', 'm', 'e', '\t', 'n', 'u', 'm', 'b', 'e', 'r', '\t', 'b', 'e', 't', 'w', 'e', 'e', 'n', '\t', '1', '\t', 'a', 'n', 'd', '\t', '5', '0', '\t', 't', 'o', '\t', 's', 't', 'o', 'p', '.' }
    
//     // char resp[Sizes_default.resp][Sizes_default.resp];

//     // for(int i = 0; i < Sizes_default.resp; i++) {
//     //     for(int j = 0; j < Sizes_default.resp; j++) {
//     //         resp[i][j] = i+j;
//     //     }
//     // }

//     int len = 50;
    
//     char resp[RESP][RESP_CHARS] = {
//                 { 'P', 'e', 'r', 'g', 'u', 'n', 't', 'a', ' ', '1', '\0' },
//                 { 'P', 'e', 'r', 'g', 'u', 'n', 't', 'a', ' ', '2', '\0' },
//                 { 'P', 'e', 'r', 'g', 'u', 'n', 't', 'a', ' ', '3', '\0' }
//     };

//     menu(msg, resp);
//     return 0;
// }
