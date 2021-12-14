#include "cesar.h"

int main(int argc, char  *argv[])
{
  if (strcmp(argv[1],"-c")==0)
  {
    char phrase[CHMAX];
    int cle;
    int i = 0;
    //recuperation de la chaine et de la clé.
    printf("Entrez une phrase ($+enter pour arreter): ");
    while ((phrase[i] = getchar()) != '$')
    {
      i++;
    }
    printf("Entrez une cle : ");
    scanf("%d", &cle);

    //allocation dynamique d'une chaine.
    char *phrase1 = NULL;
    phrase1 = malloc(strlen(phrase)*sizeof(char));
    strcpy(phrase1, phrase);
    phrase1[i] = '\0';

    //chiffrement du texte.
    printf("Texte chiffre : ");
    for (i = 0; i < strlen(phrase1); i++)
    {
      if ((phrase1[i] >= 'A' && phrase1[i] <= 'Z' )|| (phrase1[i] >= 'a' && phrase1[i] <= 'z'))
      {
        printf("%c", Chiffrement(phrase1[i], cle));
      }
      else
      {
        printf("%c", phrase[i]);
      }
    }
    free (phrase1);
    printf("\n");
  }

  else if (strcmp(argv[1],"-d")==0)
  {
    char chaine[CHMAX];
    int i=0, cle=0;

    //recuperation de la chaine.
    printf("Veuillez entrer le texte chiffre ($+enter pour finir)\n");
    while ((chaine[i]=getchar())!= '$')
    {
      i++;
    }

    //allocation dynamique d'une chaine.
    char *chaine1 = NULL;
    chaine1 = malloc (strlen(chaine)*sizeof(char));
    strcpy(chaine1, chaine);
    chaine1[i]='\0';
    printf("votre texte chiffre : %s\n", chaine1);

    //recuperation de la clé
    printf("veuillez entrer la cle :\n");
    scanf("%d", &cle);

    //affichage de la chaine dechiffrée.
    printf("votre texte dechiffre : ");
    for (int i=0; i<strlen(chaine1); i++)
    {
      //verifiaction pour ne changer que les lettres majuscules.
      if((chaine1[i] >= 'A' && chaine1[i] <= 'Z' )|| (chaine1[i] >= 'a' && chaine1[i] <= 'z'))
      {
        printf("%c", dechiffrement(chaine1[i], cle));
      }
      else
      {
        printf("%c", chaine1[i]);
      }
    }
    printf("\n");
    free (chaine1);

  }

  else if (strcmp(argv[1],"-a")==0)
  {
    char chaine [CHMAX];
    int i=0;

    //recuperation de la chaine.
    printf("Veuillez entrer le texte ($+enter pour finir)\n");
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
    char x=lettreMax(chaine1);
    printf("la lettre la plus commune est le %c\n", x);

    int cleAuto=0;

    //recherche de la clé
    cleAuto=CalculerCle(x);

    i=0;

    printf("votre texte chiffree : %s\n", chaine1);

    //affichage de la chaine dechiffrée.
    printf("votre texte dechiffree : ");
    for (int i=0; i<strlen(chaine1); i++)
    {
      if ((chaine1[i]>= 'A' && chaine1[i]<='Z')||(chaine1[i]>= 'a' && chaine1[i]<='z'))
      {
        printf("%c", dechiffrement(chaine1[i], cleAuto));
      }
      else 
      {
        printf("%c", chaine1[i]);
      }
    }
    printf("\n");
    free (chaine1);
  }

  return 0;
}
