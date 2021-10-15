// 10월 15일 <상속, 다형성> 부분 실습 완료. 20181289 한주형


#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
  g_game = new Game();
  g_game->init("Game Class", 100, 100, 640, 480, 0);
  while (g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10); // 상속부분 실습.
  }

  g_game->clean();
  return 0;
}