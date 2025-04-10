#include <SDL2/SDL.h>
#include "raycasting.h"

/*
 * renderWeapon - Render the weapon texture at the bottom center.
 * @renderer: Pointer to the SDL renderer.
 *
 * The weapon is drawn scaled (adjust the scale factor as needed).
 */
void renderWeapon(SDL_Renderer *renderer)
{
	SDL_Rect src, dst;
	float scale = 2.0; /* Adjust scale factor for desired size */

	/* Use entire weapon texture as source */
	src.x = 0;
	src.y = 0;
	src.w = weaponTexWidth;
	src.h = weaponTexHeight;
	/* Destination: bottom center of the screen */
	dst.w = (int)(weaponTexWidth * scale);
	dst.h = (int)(weaponTexHeight * scale);
	dst.x = (SCREEN_WIDTH - dst.w) / 2;
	dst.y = SCREEN_HEIGHT - dst.h;

	SDL_RenderCopy(renderer, weaponTexture, &src, &dst);
}
