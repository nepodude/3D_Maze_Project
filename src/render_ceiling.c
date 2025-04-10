#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * renderCeiling - Render the ceiling texture on the top half of the screen.
 * @renderer: Pointer to the SDL renderer.
 */
void renderCeiling(SDL_Renderer *renderer)
{
	SDL_Rect dst = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_Rect src = {0, 0, ceilingTexWidth, ceilingTexHeight};
	SDL_RenderCopy(renderer, ceilingTexture, &src, &dst);
}
