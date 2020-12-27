#include <stdio.h>
#include "jeu.h"
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "constant.h"
#include <stdlib.h>




// assistante du capture
void capturer_2(SDL_Surface *ecran,int carte[10][10],int size ,int i,int j ,int choix_contraire) 

{    int x=i,y=j;
        
        SDL_Rect position;
        carte[i][j]=vide;
        vidage(ecran,x,y,position);
        SDL_Flip(ecran);
     	
	if ( i < size-1 ) {				
                if ( carte[i+1][j] == choix_contraire ) {carte[i+1][j]=0;	
                        capturer_2(ecran,carte,size,i+1,j,choix_contraire) ;
                }
        }
	if ( j < size-1 ) {				
                if ( carte[i][j+1] == choix_contraire ) {carte[i][j+1]=0;
                        capturer_2(ecran,carte,size,i,j+1,choix_contraire) ;
                }
        }
	if ( i > 0 ) {
                if ( carte[i-1][j] == choix_contraire ) {carte[i-1][j]=0;	
                        capturer_2(ecran,carte,size,i-1,j,choix_contraire) ;
                }
        }
	if ( j > 0 ) {
                if ( carte[i][j-1] == choix_contraire ) {carte[i][j-1]=0;	
                        capturer_2(ecran,carte,size,i,j-1,choix_contraire) ;
                }
        }
	
}



// la fonction principale de la capture 
void capture(SDL_Surface *ecran,int carte[10][10],int i,int j,int taille,int choixactuel)
{int valeur; 
   
  if(i < taille-1)
    {if( (carte[i+1][j]!=vide) && (carte[i+1][j]!=choixactuel))
       {printf("on entre en droite == ");
         if( revenir_initial(carte,i+1,j,10) ==0)
            {printf("apres droite ");capturer_2(ecran,carte,taille,i+1,j,carte[i+1][j]);}
     
       }
    }

    if(j < taille-1)
    {if( (carte[i][j+1]!=vide) && (carte[i][j+1]!=choixactuel))
       {printf("on entre en bas == ");
         if( revenir_initial(carte,i,j+1,taille)==0)
            {printf("apres bas ");capturer_2(ecran,carte,taille,i,j+1,carte[i][j+1]);}
    
       }
    }


    if(i > 0)
    {if( (carte[i-1][j]!=vide) && (carte[i-1][j]!=choixactuel))
       {printf("on entre en gauche == ");
        if( revenir_initial(carte,i-1,j,taille)==0)
            {printf("apres gauche ");capturer_2(ecran,carte,taille,i-1,j,carte[i-1][j]);}
     
       }
    }


    if(j > 0)
    {if( (carte[i][j-1]!=vide) && (carte[i][j-1]!=choixactuel))
       {printf(" on entre en haut == ");
        if( revenir_initial(carte,i,j-1,taille)==0)
            {printf("apres haut ");capturer_2(ecran,carte,taille,i,j-1,carte[i][j-1]);}
  
       }
    }

  
}


