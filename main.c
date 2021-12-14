#include "cesar.h"

int main(int argc, char  *argv[])
{
  //mode "chiffrement" :
  if (strcmp(argv[1],"-c")==0)
  {
    char phrase[CHMAX];
    int cle;
    int i = 0;

    //récupération de la chaine à chiffrer.
    printf("Entrez une phrase ($+enter pour arreter): ");
    while ((phrase[i] = getchar()) != '$')
    {
      i++;
    }

    //allocation dynamique d'une chaine.
    char *phrase1 = NULL;
    phrase1 = malloc(strlen(phrase)*sizeof(char));
    strcpy(phrase1, phrase);
    phrase1[i] = '\0';
    
    //récupération de la clé de chiffrement.
    printf("Entrez une cle : ");
    scanf("%d", &cle);

    //chiffrement du texte.
    printf("Texte chiffre : ");
    for (i = 0; i < strlen(phrase1); i++)
    {
      //chiffrement des lettres uniquement.
      if ((phrase1[i] >= 'A' && phrase1[i] <= 'Z' )|| (phrase1[i] >= 'a' && phrase1[i] <= 'z'))
      {
        printf("%c", Chiffrement(phrase1[i], cle));
      }
      //réaffichage des caractères speciaux non chiffrés. 
      else
      {
        printf("%c", phrase[i]);
      }
    }

    //liberation de la mémoire.
    free (phrase1);
    printf("\n");
  }

  //mode "déchiffrement" :
  else if (strcmp(argv[1],"-d")==0)
  {
    char chaine[CHMAX];
    int i=0, cle=0;

    //récupération de la chaine à déchiffrer.
    printf("Veuillez entrer le texte chiffre ($+enter pour finir) : ");
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

    //recuperation de la clé de déchiffrement.
    printf("veuillez entrer la cle : ");
    scanf("%d", &cle);

    //affichage de la chaine dechiffrée.
    printf("votre texte dechiffre : ");
    for (int i=0; i<strlen(chaine1); i++)
    {
      //déchiffrement des lettres uniquement.
      if((chaine1[i] >= 'A' && chaine1[i] <= 'Z' )|| (chaine1[i] >= 'a' && chaine1[i] <= 'z'))
      {
        printf("%c", dechiffrement(chaine1[i], cle));
      }
      //réaffichage des caractères spéciaux.
      else
      {
        printf("%c", chaine1[i]);
      }
    }

    //liberation de la mémoire.
    free (chaine1);
    printf("\n");
  }

  //mode "automatique" :
  else if (strcmp(argv[1],"-a")==0)
  {
    char chaine [CHMAX];
    int i=0;

    //récuperation de la chaine chiffrée.
    printf("Veuillez entrer le texte ($+enter pour finir) :");
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

    //recherche de la clé de déchiffrement.
    cleAuto=CalculerCle(x);

    i=0;

    printf("votre texte chiffree : %s\n", chaine1);

    //affichage de la chaine dechiffrée.
    printf("votre texte dechiffree : ");
    for (int i=0; i<strlen(chaine1); i++)
    {
      //déchiffrement des lettres uniquement.
      if ((chaine1[i]>= 'A' && chaine1[i]<='Z')||(chaine1[i]>= 'a' && chaine1[i]<='z'))
      {
        printf("%c", dechiffrement(chaine1[i], cleAuto));
      }
      //réaffichage des caractères spéciaux.
      else 
      {
        printf("%c", chaine1[i]);
      }
    }

    //libération de la mémoire.
    free (chaine1);
    printf("\n");
  }

  return 0;
}
