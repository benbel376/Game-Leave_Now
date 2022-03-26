#include "constants.h"

void renderPlayer(float playerX, float playerY, float playerA, SDL_Renderer* renderer )
{
    int offset = 20;
    int playerSize = 5;
    float liX = playerX + floor(playerSize/2) + (offset*cos(playerA));
    float liY = playerY + floor(playerSize/2) +(offset*sin(playerA));

    SDL_Rect fillRect = { playerX, playerY, playerSize, playerSize };
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );		
	SDL_RenderFillRect( renderer, &fillRect );

    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderDrawLine( renderer, playerX + floor(playerSize/2), playerY + floor(playerSize/2), liX, liY );
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
        *playerY = *playerY + 5*sin(*playerA);
        *playerX = *playerX + 5*cos(*playerA);
        break;
        case SDLK_DOWN:
        *playerY = *playerY - 5*sin(*playerA);
        *playerX = *playerX - 5*cos(*playerA);
        break;
    }
}