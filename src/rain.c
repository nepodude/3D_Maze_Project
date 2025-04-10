#include <SDL2/SDL.h>
#include <stdlib.h>
#include "raycasting.h"

/* Structure for a raindrop */
typedef struct s_raindrop
{
    float x;
    float y;
    float speed;
} t_raindrop;

/* Array of raindrops */
t_raindrop raindrops[NUM_RAINDROPS];

/*
 * initRain - Initialize rain particles with random positions
 * and speeds.
 */
void initRain(void)
{
    int i;
    for (i = 0; i < NUM_RAINDROPS; i++)
    {
        raindrops[i].x = (float)(rand() % SCREEN_WIDTH);
        raindrops[i].y = (float)(rand() % SCREEN_HEIGHT);
        raindrops[i].speed = 2.0f + (rand() % 3); /* Speeds 2 to 4 */
    }
}

/*
 * updateRain - Update the positions of the raindrops.
 * Each raindrop moves downward; if it passes the bottom,
 * it is reset to the top.
 */
void updateRain(void)
{
    int i;
    for (i = 0; i < NUM_RAINDROPS; i++)
    {
        raindrops[i].y += raindrops[i].speed;
        if (raindrops[i].y > SCREEN_HEIGHT)
            raindrops[i].y = 0;
    }
}

/*
 * renderRain - Render the raindrops on the screen.
 * @renderer: Pointer to the SDL renderer.
 */
void renderRain(SDL_Renderer *renderer)
{
    int i;
    SDL_SetRenderDrawColor(renderer, 200, 200, 255, 200);
    for (i = 0; i < NUM_RAINDROPS; i++)
    {
        SDL_RenderDrawLine(renderer,
                           (int)raindrops[i].x,
                           (int)raindrops[i].y,
                           (int)raindrops[i].x,
                           (int)raindrops[i].y + 5);
    }
}
