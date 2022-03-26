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

//it converts a position on the map to an index for the map array
int calculateIndex(float cpx, float cpy, int box, int max);

//it renders the map out of an array.
void renderMap(int * mapArray, int mX, int mY, int blockSize, SDL_Renderer* renderer);

//it renders the player on the screen
void renderPlayer(float playerX, float playerY, float playerA, SDL_Renderer* renderer );

//it changes the x and y position of the player and its orientation
void movePlayer(SDL_Event e, float * playerX, float * playerY, float * playerA);


#endif