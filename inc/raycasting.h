#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>

/* Screen and map constants */
#define SCREEN_WIDTH 1300
#define SCREEN_HEIGHT 700
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define FOV 60.0
#define NUM_RAYS SCREEN_WIDTH

/* Rain constants */
#define NUM_RAINDROPS 1000

/* Global variable declarations */
extern int map[MAP_HEIGHT][MAP_WIDTH];
extern float playerX;
extern float playerY;
extern float playerAngle;
extern SDL_Texture *wallTexture;
extern SDL_Texture *ceilingTexture;
extern SDL_Texture *floorTexture;
extern SDL_Texture *weaponTexture;
extern int texWidth;
extern int texHeight;
extern int ceilingTexWidth;
extern int ceilingTexHeight;
extern int floorTexWidth;
extern int floorTexHeight;
extern int weaponTexWidth;
extern int weaponTexHeight;
extern int rainOn;  /* 0: off, 1: on */

/* Function prototypes */
int loadMapFromFile(const char *filePath);
void loadWallTexture(SDL_Renderer *renderer);
void loadCeilingTexture(SDL_Renderer *renderer);
void loadFloorTexture(SDL_Renderer *renderer);
void loadWeaponTexture(SDL_Renderer *renderer);
void renderCeiling(SDL_Renderer *renderer);
void renderFloor(SDL_Renderer *renderer);
void processRay(int i, SDL_Rect *srcRect, SDL_Rect *destRect);
void renderWalls(SDL_Renderer *renderer);
void renderWeapon(SDL_Renderer *renderer);
void renderScene(SDL_Renderer *renderer);

/* Rain functions */
void initRain(void);
void updateRain(void);
void renderRain(SDL_Renderer *renderer);

#endif /* RAYCASTING_H */
