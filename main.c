#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "constant.h"
#include <SDL_image.h>
#include "jeu.h"




int  main()
{
SDL_Surface *ecran=NULL, *imageDefond=NULL;   
SDL_Rect positionfond;
SDL_Event event;
  
 SDL_Init(SDL_INIT_VIDEO);
  
 ecran=SDL_SetVideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE );
 
  
 SDL_WM_SetCaption("GO",NULL);

 positionfond.x=0;
 positionfond.y=0;
  
  imageDefond=IMG_Load("sans titre.png"); 
  
 int continuer =1;
 
  while(continuer)
{ 
   SDL_WaitEvent(&event);
   switch(event.type)
    {
     case SDL_QUIT :
       continuer=0;
       break;

     case SDL_KEYDOWN:
         switch(event.key.keysym.sym)
         {
            case SDLK_ESCAPE :
                  continuer =0;
            break;

            case SDLK_SPACE :
                entree(ecran);
            break;

         
            
         } 
     break;  
    
    } 
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDL_BlitSurface(imageDefond,NULL,ecran,&positionfond);
    SDL_Flip(ecran);
          
} 
 SDL_FreeSurface(ecran); 
 SDL_FreeSurface(imageDefond);
 SDL_Quit();
 
return EXIT_SUCCESS;




}




