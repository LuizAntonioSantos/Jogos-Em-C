#include <stdio.h>
#include <string.h>

int main(){
    char palavraSecret[20], chutes[26];
    sprintf(palavraSecret, "MELANCIA");
    int acertou = 0,enforcou = 0, tentativas = 0;
    
    do {
        // strlen vai contar o numero de letras no array até encontrar o final [/0]
        for (int i = 0; i < strlen(palavraSecret); i++){
            int achou = 0;

            for (int j = 0; j < tentativas; j++){
                if (chutes[j] == palavraSecret[i]){
                    achou = 1;
                    break;
                } 
            }
            
            if (achou){
                printf("%c ", palavraSecret[i]);   
            } else {
                printf("_ ");   
            }
        }
        printf("\n");

        char chute;
        printf("Qual letra?\n");
        scanf (" %c", &chute); 

        chutes[tentativas] = chute;
        tentativas++;

    } while (!acertou && !enforcou);
    
    return 0;
}