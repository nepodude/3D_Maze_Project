#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "raycasting.h"

/*
 * main - Entry point of the raycasting program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Expects one argument: the map file path.
 * Initializes SDL, loads the map and textures, initializes rain,
 * and processes input and rendering.
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    int running;
    const float moveSpeed = 0.005f;
    const Uint8 *keystate;

    if (argc < 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return (1);
    }
    if (!loadMapFromFile(argv[1]))
    {
        printf("Error loading map from file.\n");
        return (1);
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return (1);
    }
    window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    loadWallTexture(renderer);
    loadCeilingTexture(renderer);
    loadFloorTexture(renderer);
    loadWeaponTexture(renderer);
    if (!wallTexture || !weaponTexture)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return (1);
    }
    initRain();  /* Initialize rain particles */
    running = 1;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = 0;
            if (event.type == SDL_KEYDOWN)
            {
                /* Toggle rain with R key */
                if (event.key.keysym.sym == SDLK_r)
                    rainOn = !rainOn;
            }
        }
        keystate = SDL_GetKeyboardState(NULL);
        /* Rotation */
        if (keystate[SDL_SCANCODE_LEFT])
            playerAngle -= 0.009;
        if (keystate[SDL_SCANCODE_RIGHT])
            playerAngle += 0.009;
        /* Movement vector */
        {
            float moveX = 0, moveY = 0;
            if (keystate[SDL_SCANCODE_W])
            {
                moveX += cos(playerAngle) * moveSpeed;
                moveY += sin(playerAngle) * moveSpeed;
            }
            if (keystate[SDL_SCANCODE_S])
            {
                moveX -= cos(playerAngle) * moveSpeed;
                moveY -= sin(playerAngle) * moveSpeed;
            }
            if (keystate[SDL_SCANCODE_A])
            {
                moveX += cos(playerAngle - M_PI_2) * moveSpeed;
                moveY += sin(playerAngle - M_PI_2) * moveSpeed;
            }
            if (keystate[SDL_SCANCODE_D])
            {
                moveX += cos(playerAngle + M_PI_2) * moveSpeed;
                moveY += sin(playerAngle + M_PI_2) * moveSpeed;
            }
            if (map[(int)playerY][(int)(playerX + moveX)] == 0)
                playerX += moveX;
            if (map[(int)(playerY + moveY)][(int)playerX] == 0)
                playerY += moveY;
        }
        /* Update rain if enabled */
        if (rainOn)
            updateRain();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        renderScene(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(ceilingTexture);
    SDL_DestroyTexture(floorTexture);
    SDL_DestroyTexture(weaponTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}
