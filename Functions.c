#include "Header.h"

/*void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture)
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

	SDL_RenderClear(rendu);



	SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
	SDL_RenderFillRect(rendu, &dest_fenetre);


	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &dest_airejeu);
	SDL_SetRenderDrawColor(rendu, 0, 255, 0, 0);
	SDL_RenderFillRect(rendu, &dest_case);

	SDL_RenderCopy(rendu, texture, NULL, &dest_image);

	SDL_RenderPresent(rendu); 
} */

/* void initMatrix(Case **matmat)
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
} */


void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture)
{
	////Dessine rectangle du fond
	//SDL_Rect rfond;
	//rfond.x = NB_CASE_Y * CASE_SIZE;
	//rfond.y = (NB_CASE_X - 1) * CASE_SIZE;

	//SDL_SetRenderDrawColor(rendu, 100, 100, 100, 255);
	//SDL_RenderFillRect(rendu, &rfond);

	
	
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
	SDL_RenderCopy(rendu, texture, NULL, &dest_image);


	/****************On presente la scene ************************/
	SDL_RenderPresent(rendu);  //ensuite on affiche la nouvelle
}




Case initMatrice()
{
	int i, j;
	for (i = 0; i < NB_CASE_X; i++)
	{
		for (j = 0; j < NB_CASE_Y; j++)
		{ 
			matrice[i][j].valeur = rand(% 2);	matrice[i][j].x = CASE_SIZE * j;	matrice[i][j].y = CASE_SIZE * (i + 1);
		} 
	} 
	return **matrice;
}

void dessineCase(int lig, int col, SDL_Renderer *rendu, SDL_Texture *texture)
{
	SDL_Rect r;
	r.w = CASE_SIZE; r.h = CASE_SIZE;
	r.x = matrice[col][lig].x + 20;
	r.y = matrice[col][lig].y + 20;

	SDL_Texture * IMG_LoadTexture(SDL_Renderer *rendu, const char *case_1);
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

