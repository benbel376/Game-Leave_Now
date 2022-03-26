#ifndef RESOURCES
#define RESOURCES

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include "map.cpp"
#include "player.cpp"

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//it renders the map out of an array.
void renderMap(int * mapArray, int mX, int mY, int blockSize, SDL_Renderer* renderer);

//it renders the player on the screen
void renderPlayer(int playerPosX, int playerPosY, int playerSize, int offset, SDL_Renderer* renderer );
#endif