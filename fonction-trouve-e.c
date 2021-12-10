#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  ALPHA 26
#define CHMAX 1000


int lettreMax(char *chaine)
{
  int tab[ALPHA]={0};
  int a=strlen(chaine), m=0, p=0;

  //creation d'un tableau avec 26 valeurs correspondants aux lettres de l'alphabet.
  for (int i=0; i<a; i++)
  {
    tab[chaine[i]-'A']++;
  }

  //parcours du tableau pour trouver la plus grande valeur.
  for (int i=0; i<ALPHA; i++)
  {
    if (tab[i] >= p)
    {
      p=tab[i];
      m=i;
    }
  }

//retour de la lettre la plus commune dans la chaine saisie.
return m+65;

}

int main()
{
  char chaine [CHMAX];
  int i=0;

  //recuperation de la chaine.
  printf("Veuillez entrer le texte ($+entré pour finir)\n");
  while ((chaine[i]=getchar())!= '$')
  {
    i++;
  }

    //allocation dynamique d'une chaine.
  char *chaine1 = NULL;
  chaine1 = malloc (strlen(chaine)*sizeof(char));
  strcpy(chaine1, chaine);
  chaine1[i]='\0';

  //affichage de la lettre la plus commune dans la chaine saisie.
  printf("la lettre la plus commune est le %c\n", lettreMax(chaine1));
}
