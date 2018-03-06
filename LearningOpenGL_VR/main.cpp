#define WIN64_LEAN_AND_MEAN
#include <Windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int)
{
	Game* game = Game::Instance();

	game->Init();

	while (game->Frame());

	game->Shutdown();
    return 0;
}