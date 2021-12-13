#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET 26
#define CH_MAX 1000

char Chiffrement(char lettre, int cle)
{
  //Chaine qui correspond au mot chiffré
  char LettreChiffre = 0;

  //Chiffrement du mot
  if(lettre>='a' && lettre <='z')
  {
    lettre = toupper(lettre);
    LettreChiffre = lettre + cle;
    if (LettreChiffre >'Z')
      {
        LettreChiffre = LettreChiffre - ALPHABET;
      }
    LettreChiffre = tolower(LettreChiffre);
  }
  else if (lettre>='A' && lettre <='Z')
  {
    LettreChiffre = lettre + cle;
    if (LettreChiffre >'Z')
      {
        LettreChiffre = LettreChiffre - ALPHABET;
      }
  }

  //Affichage du mot chiffré
  return LettreChiffre;
}

int main()
{
  char phrase[CH_MAX];
  int cle;
  int i = 0;

  printf("Entrez une phrase : ");
  while ((phrase[i] = getchar()) != '$')
  {
    i++;
  }
  printf("Entrez clé : ");
  scanf("%d", &cle);

  char *phrase1 = NULL;
  phrase1 = malloc(strlen(phrase)*sizeof(char));
  strcpy(phrase1, phrase);
  phrase1[i] = '\0';

  printf("votre phrase : %s\n", phrase1);

  printf("Texte chiffré : ");
  for (i = 0; i < strlen(phrase1); i++)
  {
    if (phrase1[i] >= 'A' && phrase1[i] <= 'Z' || phrase1[i] >= 'a' && phrase1[i] <= 'z')
    {
      printf("%c", Chiffrement(phrase1[i], cle));
    }
    else
    {
      printf("%c", phrase[i]);
    }
  }
  printf("\n");
  return 0;
}
