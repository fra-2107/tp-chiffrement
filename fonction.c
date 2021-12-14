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
    LettreChiffree = tolower(LettreChiffree);
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
  char dechcara=0;
  if(c>='a' && c <='z')
  {
    c = toupper(c);
    dechcara = c - k;
    if (dechcara <'A')
      {
        dechcara = dechcara + ALPHA;
      }
    dechcara = tolower(dechcara);
  }
  else if (c>='A' && c <='Z')
  {
    dechcara = c - k;
    if (dechcara < 'A')
      {
        dechcara = dechcara + ALPHA;
      }
  }
  return dechcara;
}

int lettreMax(char *chaine)
{
  int tab[ALPHA]={0};
  int a=strlen(chaine), m=0, p=0;

  //creation d'un tableau avec 26 valeurs correspondants aux lettres de l'alphabet.
  for (int i=0; i<a; i++)
  {
    if (chaine[i]>= 'A' && chaine[i]<='Z')
    {
      tab[chaine[i]-'A']++;
    }
    else if (chaine[i]>= 'a' && chaine[i]<='z')
    {
      tab[chaine[i]-'a']++;
    }
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
  printf("La cle est : %d\n",cle);
  return cle;
}
