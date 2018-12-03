#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#define L_FENETRE 500
#define H_FENETRE 460

#define CASE_SIZE 50 
#define NB_CASE_X	5
#define NB_CASE_Y	9

#define BOULE_SIZE 20

//STRUCTURES :
typedef struct { int x; int y; int val; } Case;

//FONCTIONS :
void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture);
void initMatrix(Case** matmat);
void dessineCase();
void dessineMatrice(Case* Matrix);
//VARIABLES :

