#include "Header.h"

int main(int argc, char** argv)
{
	SDL_Window *mainFenetre = NULL;
	SDL_Renderer *rendu = NULL;
	SDL_Event event;
	SDL_Texture *texture;

	int quit = 0;
	/*********************Démarrage de la SDL ***********************/
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
	{
		printf("\nImpossible d initialiser SDL :  %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*********************Création de la Fenetre principale ***********************/
	mainFenetre = SDL_CreateWindow("Mon Super Programme", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, L_FENETRE, H_FENETRE, SDL_WINDOW_SHOWN);             // flags - see below
	if (mainFenetre == NULL)
	{
		printf("\nImpossible de creer la fenetre :  %s\n", SDL_GetError());         exit(EXIT_FAILURE);
	}

	rendu = SDL_CreateRenderer(mainFenetre, -1, SDL_RENDERER_ACCELERATED);
	if (rendu == NULL)
	{
		printf("\nImpossible de creer le rendu :  %s\n", SDL_GetError());         exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(rendu, 0, 0, 220, 255); //la fenêtre est bleue

	/********************* Chargement des fichiers images pour la création des textures ***********/
	texture = IMG_LoadTexture(rendu, "./images/ellesExistent.jpg");
	if (texture == NULL)
	{
		printf("\nProbleme sur la texture\n");         exit(EXIT_FAILURE);
	}


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

