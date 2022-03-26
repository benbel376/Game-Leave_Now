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


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//map dimension constants
const int COLUMN_NUM = 50;
const int ROW_NUM = 30;
const int BLOCK_SIZE = 20;

//Screen dimension constants
const int SCREEN_WIDTH = 1550;
const int SCREEN_HEIGHT = 630;

//math constants
const double PI = 3.141592653589793238;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//it renders the map out of an array.
void renderMap(int * mapArray, int mY, int mX);



#endif