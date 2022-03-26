#include "constants.h"

int calculateIndex(float cpx, float cpy, int box, int max)
{
	
	int dpx = floor(cpx/(box+1));
	int dpy = floor(cpy/(box+1));
	int index = (max*dpy) + dpx;
	return index;
}

void renderPlayer(float playerX, float playerY, float playerA, SDL_Renderer* renderer )
{
    int offset = 6;
    int liX = (int)(playerX + floor(PLAYER_SIZE/2) + (offset*cos(playerA)));
    int liY = (int)playerY + floor(PLAYER_SIZE/2) +(offset*sin(playerA));
    int px = (int)playerX;
    int py = (int)playerY;

    SDL_Rect fillRect = { px, py, PLAYER_SIZE, PLAYER_SIZE };
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );		
	SDL_RenderFillRect( renderer, &fillRect );

    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderDrawLine( renderer, px + floor(PLAYER_SIZE/2), py + floor(PLAYER_SIZE/2), liX, liY );
}

void movePlayer(SDL_Event e, float * playerX, float * playerY, float * playerA){
    //Select surfaces based on key press
    switch( e.key.keysym.sym )
    {
        case SDLK_LEFT:
        *playerA = *playerA - (0.05*PI);
        if(*playerA <= 0){
            *playerA = *playerA + (2*PI);
        }
        break;
        case SDLK_RIGHT:
        *playerA = *playerA + (0.05*PI);
        if(*playerA >= 2*PI){
            *playerA = *playerA-(2*PI);
        }
        break;
        case SDLK_UP:
        *playerY = *playerY + 10*sin(*playerA);
        *playerX = *playerX + 10*cos(*playerA);
        if(map[calculateIndex(*playerX, *playerY, BLOCK_SIZE, COLUMN_NUM)] != 0)
        {
            *playerY = *playerY - 5*sin(*playerA);
            *playerX = *playerX - 5*cos(*playerA);
        }
        *playerY = *playerY - 10*sin(*playerA);
        *playerX = *playerX - 10*cos(*playerA);

        *playerY = *playerY + 5*sin(*playerA);
        *playerX = *playerX + 5*cos(*playerA);
        break;

        case SDLK_DOWN:

        *playerY = *playerY - 10*sin(*playerA);
        *playerX = *playerX - 10*cos(*playerA);
        if(map[calculateIndex(*playerX, *playerY, BLOCK_SIZE, COLUMN_NUM)] != 0)
        {
            *playerY = *playerY + 5*sin(*playerA);
            *playerX = *playerX + 5*cos(*playerA);
        }
        *playerY = *playerY + 10*sin(*playerA);
        *playerX = *playerX + 10*cos(*playerA);

        *playerY = *playerY - 5*sin(*playerA);
        *playerX = *playerX - 5*cos(*playerA);
        
        break;
    }
}

