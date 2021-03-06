#include <stdio.h>
#include "game.h"
#include "engine.h"

Texture backgroundImage;
AnimatedTexture ball;


void init()
{
	PolishEngine_LoadTexture(&backgroundImage, "res/images/bg.png", 0, 0);
	PolishEngine_LoadAnimatedTexture(&ball, "res/data/ball.json", 0, 0);

}

void update(double deltaTime)
{
	if (PolishEngine_GetKey("w"))
	{
		ball.x += 3 * (deltaTime * FPS);
	}
}

void render()
{
	PolishEngine_Blit(&backgroundImage);
	ball.scale = 2;
	PolishEngine_BlitAnimatedTexture(&ball, "bigBall");
}

void cleanup()
{
	SDL_DestroyTexture(backgroundImage.texture);
	SDL_DestroyTexture(ball.texture);
	printf("cleaned up game!\n");
}
