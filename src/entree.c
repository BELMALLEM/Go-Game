#include <time.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "jeu.h"
#include <math.h>

int random_position(int min,int max)
{ return (rand()%(max - min)) + min + 1;  }

void entree(SDL_Surface *ecran)
{ SDL_Surface *entree=IMG_Load("play_or_exit.png");
  SDL_Event event;
  SDL_Rect position;position.x=0;position.y=0;
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));
  SDL_BlitSurface(entree,NULL,ecran,&position);int ok=1;printf(" entree ");
while(ok)
{  
  SDL_WaitEvent(&event);
  switch(event.type)
   {
     case SDL_QUIT:
          ok=0;
          break;
 
     case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {  
             case SDLK_KP1:
                  {options(ecran);
                  break;}
       
             case SDLK_KP2:
                  {ok=0;
                  break;}
 
             case SDLK_ESCAPE:
                  ok=0;
                  break;

             
          }

}
SDL_Flip(ecran);
}
SDL_FreeSurface(entree);
}

void options(SDL_Surface *ecran)
{SDL_Surface *options=IMG_Load("options.png");int ok=1;
  SDL_Event event;
  SDL_Rect position;position.x=0;position.y=0;
 SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));printf(" options  ");
  SDL_BlitSurface(options,NULL,ecran,&position);
while(ok)
{  
  SDL_WaitEvent(&event);
  switch(event.type)
   {
     case SDL_QUIT:
          {ok=0;entree(ecran);}
          break;
 
     case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {  
             case SDLK_KP1:
                  jouer_joueur(ecran);
                  break;
       
             case SDLK_KP2:
                  jouer_computer(ecran);
                  break;
 
             case SDLK_ESCAPE:
                  {ok=0;
                  entree(ecran);
                  break;}
         
          } 

}
SDL_Flip(ecran);
 
}
SDL_FreeSurface(options);
}
