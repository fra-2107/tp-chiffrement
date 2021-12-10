#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  ALPHA 26
#define CHMAX 1000

char dechiffrement(char c, int k)
{
  char dechcara=0;
  dechcara=c-k;
  if (dechcara<'A')
  {
    dechcara+=ALPHA;
  }
  return dechcara;
}

int main()
{
  char chaine [CHMAX];
  int i=0, cle=0;

  //recuperation de la chaine
  printf("Veuillez entrer le texte chiffré ($+entré pour finir)\n");
  while ((chaine[i]=getchar())!= '$')
  {
    i++;
  }

  //allocation dynamique de la chaine
  char *chaine1 = NULL;
  chaine1 = malloc (strlen(chaine)*sizeof(char));
  strcpy(chaine1, chaine);
  chaine1[i]='\0';
  printf("votre texte chiffré : %s\n", chaine1);

  //recuperation de la clé
  printf("veuillez entrer la clé :\n");
  scanf("%d", &cle);

  //affichage de la chaine dechiffrée
  printf("votre texte dechiffré : ");
  for (int i=0; i<strlen(chaine1); i++)
  {
    if(chaine1[i]>='A'&& chaine1[i]<='Z')
    {
      printf("%c", dechiffrement(chaine1[i], cle));
    }
    else
    {
      printf("%c", chaine1[i]);
    }
  }

  printf("\n");
}
