#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define N 3

void init(char plateau[N][N]){
  int i;
  int j;
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
    plateau[i][j] = '_';
    }
  }
}

void affiche(char plateau[N][N]){
  int i = 0;
  int j;
  while (i < N){
    for (j = 0; j < N; j++){
      printf("[ %c ]\t", plateau[i][j]);
    }
    printf("\n");
    i++;
  }
}

int choisir_menu12q(){
  int i;
  printf("Choisir entre les trois propositions suivantes :\n");
  printf("1. Partie a deux joueurs\n");
  printf("2. Partie contre l'ordinateur\n");
  printf("3. Quitter\n");

  scanf("%d", &i);

  if (i == 1){
    printf("Option choisie : Partie a deux joueur\n");
  }else if (i == 2){
    printf("Option choisie : Partie contre l'ordinateur\n");
  }else if (i == 3){
    printf("Option choisie : Quitter\n");
  }
  return i;
}

void jouer(char plateau[N][N], int joueur){
   int i;
   int j;
   printf("choississez vos coordonnees\nLignes 0 1 2\nColonnes 0 1 2\n");
   scanf("%d", &i);
   scanf("%d", &j);

  while (i > N || j > N || plateau[i][j] != '_'){
    printf("Cette case est deja prise ! Veuillez choisir d'autres coordonnees\n");
    scanf("%d", &i);
    scanf("%d", &j);
    }

  printf("--------------------------\n");
  if (joueur == 0){
    plateau[i][j] = 'X';
  }
  if (joueur == 1){
    plateau[i][j] = 'O';
  }

}

void joueurOrdinateur(char plateau[N][N]){
  int ligne = rand() % N;
  int colonne = rand() % N;

 while (plateau[ligne][colonne] != '_'){
    ligne = rand() % N;
    colonne = rand() % N;
    }
  plateau[ligne][colonne] = 'O';
}

int partie_gagnee(char plateau[N][N]){
  int i = 0;
  int colonne = 0;
  int ligne_gauche = 0;
  int colonne_gauche = 0;
  int ligne_droite = 0;
  int colonne_droite = N - 1;

  while (i < N){                                                                                                                                  //ligne
    int j = 0;
    while (j != N - 1 && plateau[i][j] == plateau[i][j + 1] && plateau[i][j] != '_'){
      j++;
    }
    if (j == N - 1){
      return 1;
    }else{
    i++;
  }
}

 while (colonne < N){                                                                                                                              //colonne
  int ligne = 0;
  while (ligne != N - 1 && plateau[ligne][colonne] == plateau[ligne + 1][colonne] && plateau[ligne][colonne] != '_'){
    ligne++;
  }
  if (ligne == N - 1){
    return 1;
  }else{
  colonne++;
  }
}

 while (plateau[ligne_gauche][colonne_gauche] == plateau[ligne_gauche + 1][colonne_gauche + 1] && colonne_gauche != N - 1 && plateau[ligne_gauche][colonne_gauche] != '_'){
  ligne_gauche++;                                                                                                                               //diagonale gauche
  colonne_gauche++;
}
if (colonne_gauche == N - 1){
  return 1;
}

 while(plateau[ligne_droite][colonne_droite] == plateau[ligne_droite + 1][colonne_droite - 1] && colonne_droite != 0 && plateau[ligne_droite][colonne_droite] != '_'){
  ligne_droite++;                                                                                                                                //diagonale droite
  colonne_droite--;
}

if (colonne_droite == 0){
  return 1;
}
return 0;
}

void jouer_a(char plateau[N][N]){
  int coup = 0;
  int choix = choisir_menu12q();
  init(plateau);

  if (choix == 2){
    while (partie_gagnee(plateau) != 1 && coup != N + 1){
    printf("--------------------------\n");
    printf("Au tour du joueur de commencer\n");
    jouer(plateau, 0);
    affiche(plateau);

    if (partie_gagnee(plateau) == 1){
      printf("--------------------------\n");
      printf("Bravo tu as gagne(e)!!\n");

    }else{
    printf("--------------------------\n");
    printf("Au tour de l'ordinateur\n");
    joueurOrdinateur(plateau);
    affiche(plateau);

    if (partie_gagnee(plateau) == 1){
      printf("--------------------------\n");
      printf("L'ordinateur gagne...");
    }else{
      printf("--------------------------\n");
      coup++;
      }
    }
  }
  if (partie_gagnee(plateau) != 1){
    printf("--------------------------\n");
    printf("Pas de gagnant pour cette manche\n");
    }
  }

  if (choix == 1){
    while (coup != N + 5 && partie_gagnee(plateau) != 1){
      if (coup % 2 == 0){
        jouer(plateau, 0);
        affiche(plateau);

        if (partie_gagnee(plateau) == 1){
          printf("--------------------------\n");
          printf("Les X gagnent !\n");
        }
      }
      if (coup % 2 != 0){
        jouer(plateau, 1);
        affiche(plateau);

        if (partie_gagnee(plateau) == 1){
          printf("--------------------------\n");
          printf("Les O gagnent !\n");
        }
        printf("--------------------------\n");
        }
        coup++;
      }
    }
  printf("GAME OVER");
}

int main(){

  srand(time(NULL));

  char plateau[N][N];


 jouer_a(plateau);

return 0;
}
