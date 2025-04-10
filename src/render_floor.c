#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * renderFloor - Render the floor texture on the bottom half of the screen.
 * @renderer: Pointer to the SDL renderer.
 */
void renderFloor(SDL_Renderer *renderer)
{
	SDL_Rect dst = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_Rect src = {0, 0, floorTexWidth, floorTexHeight};
	SDL_RenderCopy(renderer, floorTexture, &src, &dst);
}
