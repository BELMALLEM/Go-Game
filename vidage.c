#include <SDL/SDL.h>
#include <SDL_image.h>




// la fonction responsable du vidage
void vidage(SDL_Surface *ecran,int x, int y, SDL_Rect position)
{ SDL_Surface *Vide;

 position.x=x*69+4; position.y=y*69+4;printf("vidaaaage    ");
 if(y==0)
   { if(x==0)
       {Vide=IMG_Load("vide_h_g.png");}
    else if(9==x)
       {Vide=IMG_Load("vide_h_d.png");}
    else if(x<9 && x>0)
        {Vide=IMG_Load("vide_h_centre.png");}
   }
 
  else if(y==9)
   { if(x==0)
        {Vide=IMG_Load("vide_b_g.png");}
    else if(x==9)
        {position.x+=1;position.y+=1;
        Vide=IMG_Load("vide_b_d.png");}
    else if(x<9 && x>0)
        {Vide=IMG_Load("vide_b_centre.png");}
   }
 

  else if(y<9 && y>0)
   { if(0==x)
        { Vide=IMG_Load("vide_g_centre.png");}
    else if(9==x)
       {Vide=IMG_Load("vide_d_centre.png");}
    else if(x<9 && x>0)
         {if(x==3 || x==6)
          { if(y==3 || y==6)
           {Vide=IMG_Load("vide_centre_centre.png");}
          
          else{Vide=IMG_Load("vide_centre.png");}
           }
           else{Vide=IMG_Load("vide_centre.png");}
         }//x<9 && x>0
   }// y<9 && y>0
        
        SDL_BlitSurface(Vide,NULL,ecran,&position);
        
        free(Vide);

}

