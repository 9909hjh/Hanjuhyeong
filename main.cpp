// 10월 15일 <상속, 다형성> 부분 실습 완료. 20181289 한주형
//10월 22일 <추상, 유일객체> 부분 실습 징행 완료. 

#include "Game.h"

//Game* g_game = 0;

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
  {
    while (TheGame::Instance()->running())
  {
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
    SDL_Delay(10); // 상속부분 실습.
  }
  } else {
    std::cout << "game init failure" << SDL_GetError() << "\n";
    return -1;
  }
  TheGame::Instance()->clean();
  return 0;
}