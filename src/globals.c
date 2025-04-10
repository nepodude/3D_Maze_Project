#include "raycasting.h"

int map[MAP_HEIGHT][MAP_WIDTH];
float playerX = 3.5;
float playerY = 3.5;
float playerAngle = 1.0;
SDL_Texture *wallTexture = NULL;
SDL_Texture *ceilingTexture = NULL;
SDL_Texture *floorTexture = NULL;
SDL_Texture *weaponTexture = NULL;
int texWidth = 0;
int texHeight = 0;
int ceilingTexWidth = 0;
int ceilingTexHeight = 0;
int floorTexWidth = 0;
int floorTexHeight = 0;
int weaponTexWidth = 0;
int weaponTexHeight = 0;
int rainOn = 0; /* Rain is initially off */
