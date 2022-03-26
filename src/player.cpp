

void renderPlayer(int playerPosX, int playerPosY, int playerSize, int offset, int liX, int liY, SDL_Renderer* renderer )
{
    SDL_Rect fillRect = { playerPosX, playerPosY, playerSize, playerSize };
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );		
	SDL_RenderFillRect( renderer, &fillRect );

    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
	SDL_RenderDrawLine( renderer, playerPosX + offset, playerPosY + offset, liX, liY );
}

void movePlayer(SDL_Event e, int * playerX, int * playerY){
    //Select surfaces based on key press
    switch( e.key.keysym.sym )
    {
        case SDLK_LEFT:
        *playerX = *playerX - 5;
        break;
        case SDLK_RIGHT:
        *playerX = *playerX + 5;
        break;
        case SDLK_UP:
        *playerY = *playerY - 5;
        break;
        case SDLK_DOWN:
        *playerY = *playerY + 5;
        break;
    }
}