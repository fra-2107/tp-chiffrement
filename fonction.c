#include "cesar.h"

char Chiffrement(char lettre, int cle)
{
  //Chaine qui correspond au mot chiffré
  char LettreChiffree = 0;

  //Chiffrement du mot
  if(lettre>='a' && lettre <='z')
  {
    lettre = toupper(lettre);
    LettreChiffree = lettre + cle;
    if (LettreChiffree >'Z')
      {
        LettreChiffree = LettreChiffree - ALPHA;
      }
    LettreChiffree = tolower(LettreChiffre);
  }
  else if (lettre>='A' && lettre <='Z')
  {
    LettreChiffree = lettre + cle;
    if (LettreChiffree >'Z')
      {
        LettreChiffree = LettreChiffree - ALPHA;
      }
  }

  //Affichage du mot chiffré
  return LettreChiffree;
}

char dechiffrement(char c, int k)
{
  //caractere dechiffré
  char caractereDechiffre=0;

  //dechiffrement du caractere
  caractereDechiffre=c-k;
  if (caractereDechiffre<'A' || (caractereDechiffre<'a' && caractereDechiffre>'z'))
  {
    caractereDechiffre+=ALPHA;
  }

  //retour du caractere dechiffré
  return caractereDechiffre;
}

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
  return m+'A';

}

int CalculerCle(char cara)
{
  int vale= 'E'-'A';
  int cle;
  cle= (cara-'A') - vale;
  printf("La clé est : %d\n",cle);
  return cle;
}
