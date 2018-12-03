#include "Header.h"

void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture)
{
	Case **matrix = NULL;
	matrix = ((Case**)malloc(NB_CASE_X * sizeof(Case)));
	int i;
	for (i = 0; i < NB_CASE_X; i++)
	{
		matrix[i] = (Case*)malloc(NB_CASE_Y * sizeof(Case));
	}
	initMatrix(matrix);
	static SDL_Rect dest_fenetre = { 0, 0, L_FENETRE, H_FENETRE };
	static SDL_Rect dest_airejeu = { 20, 20, CASE_SIZE*NB_CASE_X,  CASE_SIZE * (NB_CASE_Y - 1) };
	static SDL_Rect dest_image = { CASE_SIZE*NB_CASE_X / 2, CASE_SIZE*(NB_CASE_Y - 1) / 2, CASE_SIZE, CASE_SIZE };
	SDL_Rect dest_case = { matrix[3][1].x, matrix[1][1].y , CASE_SIZE, CASE_SIZE };
	/****************On efface la scene **************************/
	SDL_RenderClear(rendu);

	/****************On dessine la scene ************************/
	// d'abord le fond
	SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
	SDL_RenderFillRect(rendu, &dest_fenetre);

	// ensuite l'aire de jeu sous la forme d'un rectangle noir de 5 par 8 cases
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &dest_airejeu);
	SDL_SetRenderDrawColor(rendu, 0, 255, 0, 0);
	SDL_RenderFillRect(rendu, &dest_case);
	// avec peut-être à l'interieur des images
	SDL_RenderCopy(rendu, texture, NULL, &dest_image);

	/****************On presente la scene ************************/
	SDL_RenderPresent(rendu);  //ensuite on affiche la nouvelle
}

void initMatrix(Case **matmat)
{
	matmat = ((Case**)malloc(NB_CASE_X * sizeof(Case)));
	int i;
	for (i = 0; i < NB_CASE_X; i++)
	{
		matmat[i] = (Case*)malloc(NB_CASE_Y * sizeof(Case));
	}
	int cntX, cntY;
	for (cntY = 0; cntY < NB_CASE_Y; cntY++)
	{
		for (cntX = 0; cntX < NB_CASE_X; cntX++)
		{
			matmat[cntX][cntY].x = cntX * CASE_SIZE;
			matmat[cntX][cntY].y = (cntY+1) * CASE_SIZE;
			matmat[cntX][cntY].val = 0;
		}
	}
}
