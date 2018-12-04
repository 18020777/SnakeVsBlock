#include "Header.h"

extern Case matrice[NB_CASE_Y][NB_CASE_X];

void initMat(void)
{
	int i, j;
	for (i = 0; i < NB_CASE_Y; i++)
	{
		for (j = 0; j < NB_CASE_X; j++)
		{
			matrice[i][j].y =i * CASE_SIZE;
			matrice[i][j].x = j * CASE_SIZE;
			matrice[i][j].valeur = 0;
		}
	}
}
//-------------------------------------------------------------
void dessineCase(int j, int i, SDL_Renderer*rendu, SDL_Texture*texture)
{

	SDL_Rect r_case;
	r_case.x = matrice[i][j].x;
	r_case.y = matrice[i][j].y;
	r_case.h = CASE_SIZE;
	r_case.w = CASE_SIZE;
	//SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
	texture = IMG_LoadTexture(rendu, "./images/case_1.png");
	SDL_RenderCopy(rendu, texture, NULL, &r_case);
	//SDL_RenderFillRect(rendu, &r_case);
}

//----------------------------------------------------------------------------
void dessineMat(SDL_Renderer *rendu, SDL_Texture *texture)
{
	int i, j;
	for (i = 0; i < NB_CASE_Y; i++)
	{
		for (j = 0; j < NB_CASE_X; j++)
		{
			if (matrice[i][j].valeur == 1)
			{
				dessineCase(j,i,rendu,texture);
			}		
		}
	}
}

//--------------------------------------------------------------------------

//-------------------------------------------------------------

void dessineScene(SDL_Renderer *rendu, SDL_Texture *texture)
{
	static SDL_Rect dest_fenetre = { 0, 0, L_FENETRE, H_FENETRE };
	static SDL_Rect dest_airejeu = { 0, 0, CASE_SIZE*NB_CASE_X,  CASE_SIZE * (NB_CASE_Y - 1) };
	static SDL_Rect dest_image = { CASE_SIZE*NB_CASE_X / 2, CASE_SIZE*(NB_CASE_Y - 1) / 2, CASE_SIZE, CASE_SIZE };
	/****************On efface la scene **************************/
	SDL_RenderClear(rendu);

	/****************On dessine la scene ************************/
	// d'abord le fond
	//SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
	SDL_RenderFillRect(rendu, &dest_fenetre);

	// ensuite l'aire de jeu sous la forme d'un rectangle noir de 5 par 8 cases
	SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
	SDL_RenderFillRect(rendu, &dest_airejeu);

	// avec peut-être à l'interieur des images
	dessineMat(rendu, texture);
	SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
	SDL_RenderCopy(rendu, texture, NULL, &dest_image);


	/****************On presente la scene ************************/
	

}

void scrollMat(void)
{
	int i, j;
	for (i = 0; i < NB_CASE_Y-1; i++)
	{
		for (j = 0; j < NB_CASE_X; j++)
		{
			matrice[i][j].y++;
			if (matrice[i][j].y > 390)
			{
				matrice[i][j].y = -50;
				matrice[i][j].valeur = rand() % 4;
			}
		}
	}
	
	
}
