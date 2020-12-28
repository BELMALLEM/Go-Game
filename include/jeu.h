#include <SDL/SDL.h>
#include<SDL_image.h>
#include <SDL/SDL_ttf.h>

void jouer_joueur(SDL_Surface *ecran);
void jouer_computer(SDL_Surface *ecran);
void capture(SDL_Surface *tableaudejeu,int carte[10][10],int i,int j,int taille,int choixactuel);
void capturer_2(SDL_Surface *tableaudejeu,int carte[10][10],int size ,int i,int j ,int choix_contraire);
void vidage(SDL_Surface *tableaudejeu,int x, int y, SDL_Rect position);
int liberte(int carte[10][10],int i,int j,int size);
int revenir_initial(int carte[10][10],int i,int j, int taille);
int random_position(int min,int max);

char player(SDL_Surface *ecran, int x, int y);
int combien_de_boules(int (*carte)[10],int choix);
int score(int carte[10][10], int taille,int qui_est_capturee);
