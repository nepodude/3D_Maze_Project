#include <stdio.h>
#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * loadWallTexture - Load the wall texture from "wall.bmp".
 * @renderer: Pointer to the SDL renderer.
 *
 * If "wall.bmp" is missing, a fallback 64x64 grey texture is generated.
 */
void loadWallTexture(SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	surface = SDL_LoadBMP("wall.bmp");
	if (!surface)
	{
		printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		printf("wall.bmp not found. Generating fallback texture.\n");
		texWidth = 64;
		texHeight = 64;
		surface = SDL_CreateRGBSurface(0, texWidth, texHeight, 32,
			0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
		if (!surface)
		{
			printf("SDL_CreateRGBSurface Error: %s\n", SDL_GetError());
			return;
		}
		SDL_FillRect(surface, NULL,
			SDL_MapRGBA(surface->format, 150, 150, 150, 255));
	}
	else
	{
		texWidth = surface->w;
		texHeight = surface->h;
	}
	wallTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

/*
 * loadCeilingTexture - Load the ceiling texture from "ceiling.bmp".
 * @renderer: Pointer to the SDL renderer.
 *
 * If "ceiling.bmp" is missing, a fallback 64x64 light-blue texture is generated.
 */
void loadCeilingTexture(SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	surface = SDL_LoadBMP("ceiling.bmp");
	if (!surface)
	{
		printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		printf("ceiling.bmp not found. Generating fallback texture.\n");
		ceilingTexWidth = 64;
		ceilingTexHeight = 64;
		surface = SDL_CreateRGBSurface(0, ceilingTexWidth, ceilingTexHeight, 32,
			0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
		if (!surface)
		{
			printf("SDL_CreateRGBSurface Error: %s\n", SDL_GetError());
			return;
		}
		SDL_FillRect(surface, NULL,
			SDL_MapRGBA(surface->format, 100, 100, 255, 255));
	}
	else
	{
		ceilingTexWidth = surface->w;
		ceilingTexHeight = surface->h;
	}
	ceilingTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

/*
 * loadFloorTexture - Load the floor texture from "floor.bmp".
 * @renderer: Pointer to the SDL renderer.
 *
 * If "floor.bmp" is missing, a fallback 64x64 green texture is generated.
 */
void loadFloorTexture(SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	surface = SDL_LoadBMP("floor.bmp");
	if (!surface)
	{
		printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		printf("floor.bmp not found. Generating fallback texture.\n");
		floorTexWidth = 64;
		floorTexHeight = 64;
		surface = SDL_CreateRGBSurface(0, floorTexWidth, floorTexHeight, 32,
			0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
		if (!surface)
		{
			printf("SDL_CreateRGBSurface Error: %s\n", SDL_GetError());
			return;
		}
		SDL_FillRect(surface, NULL,
			SDL_MapRGBA(surface->format, 50, 205, 50, 255));
	}
	else
	{
		floorTexWidth = surface->w;
		floorTexHeight = surface->h;
	}
	floorTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

/*
 * loadWeaponTexture - Load the weapon texture from "weapon.bmp".
 * @renderer: Pointer to the SDL renderer.
 *
 * If "weapon.bmp" is missing, a fallback 64x64 red texture is generated.
 */
void loadWeaponTexture(SDL_Renderer *renderer)
{
	SDL_Surface *surface;
	surface = SDL_LoadBMP("weapon.bmp");
	if (!surface)
	{
		printf("SDL_LoadBMP Error: %s\n", SDL_GetError());
		printf("weapon.bmp not found. Generating fallback texture.\n");
		weaponTexWidth = 64;
		weaponTexHeight = 64;
		surface = SDL_CreateRGBSurface(0, weaponTexWidth, weaponTexHeight, 32,
			0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
		if (!surface)
		{
			printf("SDL_CreateRGBSurface Error: %s\n", SDL_GetError());
			return;
		}
		SDL_FillRect(surface, NULL,
			SDL_MapRGBA(surface->format, 255, 0, 0, 255));
	}
	else
	{
		weaponTexWidth = surface->w;
		weaponTexHeight = surface->h;
	}
	weaponTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}
