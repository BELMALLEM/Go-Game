#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include "constant.h"
#include "jeu.h"
#include <time.h>



// Cette fct est la responsable du jeu
void jouer_joueur(SDL_Surface *ecran)
{
/*=================================les variables=======================================*/ 
  int ok=1,x=0,y=0,valeur,capturee=0,noir_capturee=0,blanc_capturee=0;
  SDL_Surface *Choix[2], *TableauDeJeu=IMG_Load("goban.png");// les surfaces
  int ChoixActuel=blanc;// le choix du joueur
  SDL_Rect PositionDeChoix, position_annonce;// Les positions
  SDL_Event event;
  int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR]; // declaration de la carte
  
/*=====================================================================================*/
    
for(int i=0;i<10;i++) 
{ 
   for(int j=0;j<10;j++)
      carte[i][j]=vide;
}//vidage de la carte


Choix[0]=IMG_Load("noir1.png");
Choix[1]=IMG_Load("blanc1.png");
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));
PositionDeChoix.x=0;
PositionDeChoix.y=0;
SDL_BlitSurface(TableauDeJeu,NULL,ecran,&PositionDeChoix);




while(ok)
{ SDL_WaitEvent(&event);
  switch(event.type)
   {
     case SDL_QUIT:
          ok=0;options(ecran);
          break;
 
     case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          { 
             case SDLK_ESCAPE:
                 {ok=0;options(ecran);
                  break;}

          }

          
/*================== le travaille de la souris ===============================*/  
     case SDL_MOUSEBUTTONDOWN:
         { 
            if(event.button.button == SDL_BUTTON_LEFT)
             {  
                      x=event.button.x/70;
                      y=event.button.y/70;
                  
                      
                 
/*======================== poser les jetons =====================================*/                          
                 if(carte[x][y]==vide)
                  { if(ChoixActuel==noir) 
                      ChoixActuel=blanc;
                   else if(ChoixActuel==blanc)
                      ChoixActuel=noir;
                     carte[x][y]=ChoixActuel;
                     PositionDeChoix.x=x*70;
                     PositionDeChoix.y=y*70;
                 
                  if(carte[x][y]==noir)
                   {
                    PositionDeChoix.x-=9;
                    PositionDeChoix.y-=8;
                    SDL_BlitSurface(Choix[0],NULL,ecran,&PositionDeChoix);
                    SDL_Flip(TableauDeJeu);

                    if(revenir_initial(carte,x,y,10)==0)
                         {carte[x][y]=vide;vidage(ecran,x,y,position_annonce);ChoixActuel=blanc;}
                   }
         /*======================================================*/        
                  if(carte[x][y]==blanc)
                   {
                    PositionDeChoix.x-=1;
                    PositionDeChoix.y+=1;
                    SDL_BlitSurface(Choix[1],NULL,ecran,&PositionDeChoix);
                    SDL_Flip(TableauDeJeu);

                    if(revenir_initial(carte,x,y,10)==0)
                          {carte[x][y]=vide;vidage(ecran,x,y,position_annonce);ChoixActuel=noir;}
                    
                   }
           capture(ecran,carte,x,y,10,ChoixActuel);
           
            
/*===================================================================*/  

                
                } /* vide*/
      
            }// BUTTON_LEFT 
                   
                  SDL_Flip(TableauDeJeu);
   
         if(event.button.button == SDL_BUTTON_RIGHT)
            {
              x=event.button.x/70;
              y=event.button.y/70;            
              carte[x][y]=vide;
             vidage(ecran,x,y,PositionDeChoix);
             SDL_Flip(TableauDeJeu);
             if(ChoixActuel==noir) ChoixActuel=blanc;
             if(ChoixActuel==blanc) ChoixActuel=noir;
            }// BUTTON_RIGHT
        
     break;
 printf("\n");
    }//case sdl_mousebutton
     
  }//switch
 
    
    SDL_Flip(ecran);
 
}//while

    SDL_FreeSurface(Choix[0]);
    SDL_FreeSurface(Choix[1]);
    SDL_FreeSurface(TableauDeJeu);
    


}// main


/*0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000*/


// Cette fct est la responsable du jeu avec pc

void jouer_computer(SDL_Surface *ecran)
{
/*=================================les variables=======================================*/
  int ok=1,x=0,y=0,valeur,capturee=0,noir_capturee=0,blanc_capturee=0; 
  SDL_Surface *Choix[2], *TableauDeJeu=IMG_Load("goban.png");// les surfaces
  int ChoixActuel=blanc;// le choix du joueur
  SDL_Rect PositionDeChoix, position_annonce;// Les positions
  SDL_Event event;
  int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR]; // declaration de la carte
  int score_blanc=0,score_noir=0;
  
/*=====================================================================================*/
    
for(int i=0;i<10;i++) 
{ 
   for(int j=0;j<10;j++)
      carte[i][j]=vide;
}//vidage de la carte


Choix[0]=IMG_Load("noir1.png");
Choix[1]=IMG_Load("blanc1.png");
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,255));
PositionDeChoix.x=0;
PositionDeChoix.y=0;
SDL_BlitSurface(TableauDeJeu,NULL,ecran,&PositionDeChoix);
srand(time(0));
 

while(ok)
{ 

  

/*================== le travaille de la souris ===============================*/ 
switch(ChoixActuel)
{
case noir:
{                    
 printf("computer play");
                      x=(rand()%9)+1;
                      y=(rand()%9)+1;
                      while(carte[x][y]!=vide)
                       {x=(rand()%9)+1;
                        y=(rand()%9)+1;}
                  printf("x=%d y=%d",x,y);SDL_Delay(500);
/*======================== poser les jetons =====================================*/                          
                 if(carte[x][y]==vide)
                  { 
                      ChoixActuel=blanc;
                   
                     carte[x][y]=ChoixActuel;
                     PositionDeChoix.x=x*70;
                     PositionDeChoix.y=y*70;
                 
                  if(carte[x][y]==blanc)
                   {
                    SDL_BlitSurface(Choix[1],NULL,ecran,&PositionDeChoix);
                    SDL_Flip(TableauDeJeu);

                    if(revenir_initial(carte,x,y,10)==0)
                         {carte[x][y]=vide;vidage(ecran,x,y,position_annonce);ChoixActuel=noir;}
                   }

                }
                      
                capture(ecran,carte,x,y,10,ChoixActuel);
                
                 
 break;
}

case blanc:
{
 SDL_WaitEvent(&event);
  switch(event.type)
   {
     case SDL_QUIT:
     {    ok=0;
          options(ecran);
          break;
    }
  
    case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
          {  
                 case SDLK_ESCAPE:
                  {ok=0;options(ecran);
                  break;}    
          }
    case SDL_MOUSEBUTTONDOWN:
         { 
            if(event.button.button == SDL_BUTTON_LEFT)
             {  
                      x=event.button.x/70;
                      y=event.button.y/70;
                  
                     
/*======================== poser les jetons =====================================*/                          
                 if(carte[x][y]==vide)
                  {   ChoixActuel=noir;

                     carte[x][y]=ChoixActuel;
                     PositionDeChoix.x=x*70;
                     PositionDeChoix.y=y*70;
                 
                  if(carte[x][y]==noir)
                   {
                    PositionDeChoix.x-=9;
                    PositionDeChoix.y-=8;
                    SDL_BlitSurface(Choix[0],NULL,ecran,&PositionDeChoix);
                    SDL_Flip(TableauDeJeu);

                    if(revenir_initial(carte,x,y,10)==0)
                         {carte[x][y]=vide;vidage(ecran,x,y,position_annonce);ChoixActuel=blanc;}
                   }
         /*======================================================*/        
                capture(ecran,carte,x,y,10,ChoixActuel);
                
                 
/*===================================================================*/  

                
                } /* vide*/
      
            }// BUTTON_LEFT 
                

               
        
                  SDL_Flip(TableauDeJeu);
   
         if(event.button.button == SDL_BUTTON_RIGHT)
            {
              x=event.button.x/70;
              y=event.button.y/70;            
              carte[x][y]=vide;
             vidage(ecran,x,y,PositionDeChoix);
             SDL_Flip(TableauDeJeu);
             if(ChoixActuel==noir) ChoixActuel=blanc;
             if(ChoixActuel==blanc) ChoixActuel=noir;
            }// BUTTON_RIGHT
        
     break;
 printf("\n");
    }//case sdl_mousebutton
     
  }//switch
break;
 }
 
  
}
    SDL_Flip(ecran);
 
}//while

    SDL_FreeSurface(Choix[0]);
    SDL_FreeSurface(Choix[1]);
    SDL_FreeSurface(TableauDeJeu);
    


}// main



