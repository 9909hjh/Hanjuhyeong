// 10월 15일 <상속, 다형성> 부분 실습 완료. 20181289 한주형
//10월 22일 <추상, 유일객체> 부분 실습 진행 완료. 
//11월 3일 <Vector2D> 부분 실습 진행 완료
//11월 5일 <물리, 키 입력> 부분 실습 완료.
//11월 12알 <마우스 압력> 부분 실습 완료.

#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
//Game* g_game = 0;

int main(int argc, char* argv[])
{
  if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
  {
    Uint32 frameStart, frameTime;
    while (TheGame::Instance()->running())
  {
    frameStart = SDL_GetTicks();
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
    frameTime = SDL_GetTicks() - frameStart;
    if(frameTime < DELAY_TIME)
    {
      SDL_Delay((int)(DELAY_TIME - frameTime));
    }
    //SDL_Delay(10); // 상속부분 실습.
  }
  } else {
    std::cout << "game init failure" << SDL_GetError() << "\n";
    return -1;
  }
  TheInputHandler::Instance()->clean();
  return 0;
}