/**********************************************************************/
/*******            Projet d'algo prog struct 2018-2019   *************/
/**********************************************************************/

/*********** 1) Zone des #include ***************************/
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

/************ 2) ci-dessous les #define *********************/
#define L_FENETRE 500
#define H_FENETRE 460

#define CASE_SIZE 50 
#define NB_CASE_X	5
#define NB_CASE_Y	9

#define BOULE_SIZE 20

/********** 3) puis la ou les définitions des structures ***/
struct sCase
{
	int x, y, valeur;								// valeur = 0 (pas de case)  = 1 (présence d'une case)
};
typedef struct sCase Case;


/********** 4) les prototypes des fonctions  ***************/
void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture);
void dessineMat(SDL_Renderer *rendu, SDL_Texture *texture);
void dessineCase(int lig, int col, SDL_Renderer *rendu, SDL_Texture *texture);
void initMatrice(void);

/************et enfin les variables globales************/
Case matrice[NB_CASE_X][NB_CASE_Y];

/***************  La fonction main()    *********************/
int main(int argc, char** argv)
{
	/*********************Déclaration de toutes les variables ***********************/
	SDL_Window *mainFenetre = NULL;
	SDL_Renderer *rendu = NULL;
	SDL_Event event;
	SDL_Texture *texture;

	int quit = 0;

	



	/*********************Démarrage de la SDL ***********************/
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){printf("\nImpossible d initialiser SDL :  %s\n", SDL_GetError());	exit(EXIT_FAILURE);	}

	/*********************Création de la Fenetre principale ***********************/
	mainFenetre = SDL_CreateWindow("Mon Super Programme", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, L_FENETRE, H_FENETRE, SDL_WINDOW_SHOWN);             // flags - see below
	if (mainFenetre == NULL){printf("\nImpossible de creer la fenetre :  %s\n", SDL_GetError());         exit(EXIT_FAILURE);	}	rendu = SDL_CreateRenderer(mainFenetre, -1, SDL_RENDERER_ACCELERATED);
	if (rendu == NULL){	printf("\nImpossible de creer le rendu :  %s\n", SDL_GetError());         exit(EXIT_FAILURE);	}
	SDL_SetRenderDrawColor(rendu, 0, 0, 220, 255); //la fenêtre est bleue


	/********************* Chargement des fichiers images pour la création des textures ***********/
	texture = IMG_LoadTexture(rendu, "./images/case_1.png");
	if (texture == NULL){printf("\nProbleme sur la texture\n");         exit(EXIT_FAILURE);	}


	initMatrice();
	//dessineMat(rendu, texture);

	///********************* La boucle des événements ******************************/
	while (!quit)  //que l'on pourrait écrire quit==0
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT: //clic sur la croix en haut à droite
			quit = 1;
			break;

		case SDL_KEYDOWN:  //enfoncement d'une touche
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:   //la touche echap
				quit = 1; // on quitte
				break;

			case SDLK_LEFT:   //la touche flèche gauche

				break;

			case SDLK_RIGHT:   //la touche flèche gauche

				break;

			case SDLK_d: //la touche d
				printf("on a appuyé sur la touche d\n");
				break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:   //click bouton gauche de la souris
				printf("clic gauche de souris\n");
				break;

			case SDL_BUTTON_RIGHT: // si on clicke droit on quitte
				printf("clic droit de souris\n");
				break;
			}
			event.button.button = 0; // on ré initialise l'événement
			break;
		}
		/********************* Appel de la fonction dessineScene() *********************/
		dessineScene(rendu, texture);
		SDL_Delay(30);  //Attente de 30 ms avant de gérer le prochain événement
	}

	/*********************FIN du programme destruction des textures, du rendu et Fin de la SDL*******************/
	SDL_DestroyTexture(texture); //3) Destruction de la texture
	SDL_DestroyRenderer(rendu);
	SDL_DestroyWindow(mainFenetre);
	SDL_Quit();
	
	return 0;
}


void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture)
{
		
	static SDL_Rect dest_fenetre = { 0, 0, L_FENETRE, H_FENETRE };
	static SDL_Rect dest_airejeu = { 20, 20, CASE_SIZE*NB_CASE_X,  CASE_SIZE * (NB_CASE_Y - 1) };
	static SDL_Rect dest_image = { CASE_SIZE*NB_CASE_X / 2, CASE_SIZE*(NB_CASE_Y - 1) / 2, CASE_SIZE, CASE_SIZE };
	/****************On efface la scene **************************/
	SDL_RenderClear(rendu);

	/****************On dessine la scene ************************/
	// d'abord le fond
	SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
	SDL_RenderFillRect(rendu, &dest_fenetre);

	// ensuite l'aire de jeu sous la forme d'un rectangle noir de 5 par 8 cases
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &dest_airejeu);

	// avec peut-être à l'interieur des images
	dessineMat(rendu, texture);
	SDL_RenderCopy(rendu, texture, NULL, &dest_image);


	/****************On presente la scene ************************/
	SDL_RenderPresent(rendu);  //ensuite on affiche la nouvelle
}




void initMatrice(void)
{
	int i, j;
	for (i = 0; i < NB_CASE_X; i++)
	{
		for (j = 0; j < NB_CASE_Y; j++)
		{ 
			matrice[i][j].valeur = rand()%2;
			matrice[i][j].x = CASE_SIZE * j;
			matrice[i][j].y = CASE_SIZE * (i + 1);
		} 
	} 
	
}

void dessineCase(int lig, int col, SDL_Renderer *rendu, SDL_Texture *texture)
{
	SDL_Rect r;
	r.w = CASE_SIZE; r.h = CASE_SIZE;
	r.x = matrice[col][lig].x + 20;
	r.y = matrice[col][lig].y + 20;

	texture = IMG_LoadTexture(rendu, "./images/case_1.png");
	int SDL_RenderCopy(SDL_Renderer *rendu, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect);
	SDL_RenderCopy(rendu, texture, NULL, &r);
	SDL_RenderFillRect(rendu, &r);
	SDL_RenderPresent(rendu);
}

void dessineMat(SDL_Renderer *rendu, SDL_Texture *texture)
{
	int i, j;
	for (i = 0; i < NB_CASE_X; i++)
	{
		for (j = 0; j < NB_CASE_Y; j++)
		{
			if (matrice[i][j].valeur == 1)
			{
				dessineCase(i, j, rendu, texture);
			}

		}
	}
}


//"./images/case_1.png"
