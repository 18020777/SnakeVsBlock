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
struct sCase
{
	int x, y, valeur;
};
typedef struct sCase Case;

//FONCTIONS :
void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture);
void initMat(void);
void dessineCase(int lig, int col, SDL_Renderer*rendu, SDL_Texture*texture);
void dessineMat(SDL_Renderer *rendu, SDL_Texture *texture);
void scrollMat(void);

//VARIABLES :

