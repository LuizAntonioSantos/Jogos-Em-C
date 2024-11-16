#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define NUMERO_DE_TENTATIVAS 5 || Define uma constante

int main(){
    int numSegund = time(0); srand(numSegund);
    int numGrand = rand();
    int numSecret = numGrand % 100; 
    //esse foi o metodo mais louco que já vi para gerar um número aleatorio
    int t = 1, chute = 0, acertou = 0;
    int lvl, numTent = 0;  
    double pontos = 1000;
    
    printf("************\n");
    printf("* Bem-Vindo ao Jogo de Adivinhacao *\n");
    printf("************\n");

    printf("Qual o nivel de dificuldade?\n");
    printf("(1) - Facil | (2) - Medio | (3) - Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &lvl);

    switch (lvl){
      case 1:
        numTent = 20;
      break;

      case 2:
        numTent = 10;
      break;

      case 3:
        numTent = 5;
      break;
      
      default:
        printf("Nivel selecionado nao indentificado. Por favor verifique se digitou o numero corretamente");
      break;
    }

  //Laços de Repetição
  //while ()
    for (int i = 1; i <= numTent; i++){
      printf("\nTentativa %d",t);
      printf("\nQual e o seu chute? ");
      scanf("%d", &chute);
      printf("\nSeu chute foi %d\n", chute);
      
      acertou = (chute == numSecret);

      if (chute < 0){
        printf("Voce nao pode chutar numeros negativos!\n");
        continue;
      }
      
      if (acertou) {
        break; //Ele interrompe o laço for caso acerte o numero secreto  

      } else if (chute > numSecret) {
        printf("O seu chute foi maior que o numero secreto\n");  
      } else {
        printf("O seu chute foi menor que o numero secreto\n");  
      }

      double pontosPerd = abs(chute - numSecret) / 2.0;
      pontos = pontos - pontosPerd;
      
      t++;
    }

    printf("\nFim de Jogo :)");

    if (acertou){
      printf("\nVoce venceu o jogo em %d tentativas", t);    
      printf("\nTotal de pontos: %.1f\n", pontos);
    } else {
      printf("\nVoce perdeu, tente novamente");
      printf("\nO numero secreto era %d", numSecret);
    }
    
  return 0;
}