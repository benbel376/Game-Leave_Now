

// header file containing all other libraries and constants.
#include "resources.h"


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

void close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() ){printf( "Failed to initialize!\n" );}
	else
	{
		//Main loop flag
		bool quit = false;
		//Event handler
		SDL_Event e;
		int playerX = 160;
		int playerY = 160;
		int playerS = 5;
		int offset = 2;
		int liX = playerX+10;
		int liY = playerY + offset;
		//While application is running: main game loop.
		while( !quit )
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
				//User requests quit
				if( e.type == SDL_QUIT ){quit = true;}
				else if( e.type == SDL_KEYDOWN )
				{
					movePlayer(e, &playerX, &playerY);
					liX = playerX+10;
					liY = playerY + offset;
				}
			}
			//Clear screen
			SDL_SetRenderDrawColor( gRenderer, 0x33, 0x33, 0x33, 0xFF );
			SDL_RenderClear( gRenderer );

			//drawMap on the screen
			renderMap(map, COLUMN_NUM, ROW_NUM, BLOCK_SIZE, gRenderer);

			//draw player on the map
			renderPlayer(playerX, playerY, playerS, offset, liX, liY, gRenderer );

			//Update screen
			SDL_RenderPresent( gRenderer );
			
		}
		
	}

	//Free resources and close SDL
	close();

	return 0;
}