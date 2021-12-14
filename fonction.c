#include "cesar.h"

//fonction de chiffrement : 
char Chiffrement(char lettre, int cle)
{
  //Chaine qui correspond au caractère chiffré.
  char LettreChiffree = 0;

  //Chiffrement du mot :
  if(lettre>='a' && lettre <='z')
  {
    //mise en majuscule des lettres minuscules (pour faciliter le traitement).
    lettre = toupper(lettre);
    LettreChiffree = lettre + cle;
    //on retranche 26 pour rester dans l'alphabet de le pas arriver dans les caractères spéciaux.
    if (LettreChiffree >'Z')
      {
        LettreChiffree = LettreChiffree - ALPHA;
      }
    //remise en minuscule des lettres minuscule.
    LettreChiffree = tolower(LettreChiffree);
  }
  else if (lettre>='A' && lettre <='Z')
  {
    LettreChiffree = lettre + cle;
    //on retranche 26 pour rester dans l'alphabet de le pas arriver dans les caractères spéciaux.
    if (LettreChiffree >'Z')
      {
        LettreChiffree = LettreChiffree - ALPHA;
      }
  }

  //retour du caractère chiffré.
  return LettreChiffree;
}

//fonction de déchiffrement :
char dechiffrement(char c, int k)
{
  //chaine qui correspond au caractère dechiffré.
  char dechcara=0;

  //dechiffrement du mot:
  if(c>='a' && c <='z')
  {
    //mise en majuscule des lettres minuscules (pour faciliter le traitement).
    c = toupper(c);
    dechcara = c - k;
    //on ajoute 26 pour rester dans l'alphabet de le pas arriver dans les caractères spéciaux.
    if (dechcara <'A')
      {
        dechcara = dechcara + ALPHA;
      }
      //remise en minuscule des lettres minuscule.
    dechcara = tolower(dechcara);
  }
  else if (c>='A' && c <='Z')
  {
    dechcara = c - k;
    //on ajoute 26 pour rester dans l'alphabet de le pas arriver dans les caractères spéciaux.
    if (dechcara < 'A')
      {
        dechcara = dechcara + ALPHA;
      }
  }
  //retour du caractère déchiffré.
  return dechcara;
}

//fonction de recherche de la lettre la plus présente dans le texte chiffré :
int lettreMax(char *chaine)
{
  int tab[ALPHA]={0};
  int a=strlen(chaine), m=0, p=0;

  //creation d'un tableau avec 26 valeurs correspondants aux lettres de l'alphabet.
  for (int i=0; i<a; i++)
  {
    //incrementation du rang correspondant au caractère.
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

//focntion de calcul de la clé de déchiffrement :
int CalculerCle(char cara)
{
  int vale= 'E'-'A';
  int cle;
  cle= (cara-'A') - vale;

  printf("La cle est : %d\n",cle);
  return cle;
}
