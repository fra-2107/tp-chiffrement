#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII 65

int CalculerCle(char cara)
{
  int vale= 'E'-ASCII;
  int cle;
  printf("%d\n",cara-ASCII);
  printf("%d\n",vale);
  cle= vale - (cara-ASCII);
  printf("La clé est : %d\n",cle);
  return cle;
}

int main()
{
  char lettrefrequente = 'H';
  CalculerCle(lettrefrequente);
  return 0;
}
