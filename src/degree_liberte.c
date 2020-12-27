#include <stdlib.h>
#include <stdio.h>
#include "constant.h"

// Cette fct calcul le nombre de degree de liberte apres chaque coup
int liberte(int carte[10][10],int i,int j,int size)
{
 int free=0,valeur=carte[i][j];
 if(i<size-1)
  {printf(" [d] ");
   if(carte[i+1][j]==vide)
     {
       free++;
       carte[i+1][j]=possible;
     }
   else if( carte[i+1][j]==valeur)
     {
       carte[i][j]=plein;
       free+=liberte(carte,i+1,j,size);
     }
   
  }

 if(j<size-1)
  {printf(" [b] ");
   if(carte[i][j+1]==vide)
     { 
       free++;
       carte[i][j+1]=possible;
     }
   else if(carte[i][j+1]==valeur)
     {
       carte[i][j]=plein;
       free+=liberte(carte,i,j+1,size);
     }
    
  }

 if(i>0)
  {printf(" [g] ");
   if(carte[i-1][j]==vide)
     { 
       free++;
       carte[i-1][j]=possible;
     }
   else if(carte[i-1][j]==valeur)
     {
       carte[i][j]=plein;
       free+=liberte(carte,i-1,j,size);
     
     }
  
  }

if(j>0)
  {printf(" [h] ");
   if(carte[i][j-1]==vide)
     {
       free++;
      carte[i][j-1]=possible;
     }
   else if(carte[i][j-1]==valeur)
     {
      carte[i][j]=plein;
       free+=liberte(carte,i,j-1,size);
     }
  
  }
 
 return free;
}
 

// cette fct donne le degree de liberte est libere ce que la precedente a ruiné
int revenir_initial(int carte[10][10],int i,int j, int taille)
{ int free,valeur=carte[i][j];
  free=liberte(carte,i,j,taille);
  for(int k=0;k<taille;k++){
     for(int l=0;l<taille;l++){
         if( carte[k][l]==possible)
             carte[k][l]=vide;
         if( carte[k][l]== plein)
             carte[k][l]=valeur;
       }    
     }
return free;
}

