#include "raycasting.h"
#include <SDL2/SDL.h>

/*
 * renderScene - Render the complete scene.
 * @renderer: Pointer to the SDL renderer.
 *
 * Renders the ceiling, floor, walls, weapon, and if rain is enabled,
 * the rain overlay.
 */
void renderScene(SDL_Renderer *renderer)
{
    renderCeiling(renderer);
    renderFloor(renderer);
    renderWalls(renderer);
    renderWeapon(renderer);
    if (rainOn)
        renderRain(renderer);
}
