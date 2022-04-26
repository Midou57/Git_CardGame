#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include <algorithm>
#include <vector>
#include <deque>


#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080


#define reserve 150

//fonctions

SDL_Texture * loadTexture(const char * file, SDL_Renderer * renderer)
{
	SDL_Texture * texture = IMG_LoadTexture(renderer, file);
	if(!texture)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[!] Unable to create texture: %s\n", SDL_GetError());
		return NULL;
	}

	return texture;
}

void cleanUp(SDL_Window * window, SDL_Renderer * renderer)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	IMG_Quit();
	SDL_Quit();
}




int main(int argc, char** argv){

    

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return 1;
    }



    SDL_Window * window = SDL_CreateWindow("Memory", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
													 SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(!window)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
	
		IMG_Quit();
		SDL_Quit();
		return EXIT_FAILURE;
	}

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(!renderer)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
		
		IMG_Quit();
		SDL_DestroyWindow(window);
		SDL_Quit();
		return EXIT_FAILURE;
	}

    SDL_Texture * background = loadTexture("../Images/background.png", renderer);
	if(!background)
	{
		cleanUp(window, renderer);
		return EXIT_FAILURE;
	}

    SDL_Color white = {255, 255, 255, 0xFF};



    
    
 


    

    return 0;
}