//색을 랜덤하게 바꾸기
//5번 반복하면 빠져나가기

#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags);

void Random();
void render();


int main(int argc, char* argv[])
{
  if(init("Breaking Up HelloSDL",
  SDL_WINDOWPOS_CENTERED,
  SDL_WINDOWPOS_CENTERED,
  640, 480, //해상도 비율 1280, 720을 하면 약간 깨진다.
  SDL_WINDOW_SHOWN))
  {
    g_bRunning = true;
  }
  else{
    return 1;
  }

  int a = 0;
  while (g_bRunning)
  {
  //   SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 100, 255); //화면을 blue로 바꿈
  // SDL_RenderClear(g_pRenderer);
  // SDL_RenderPresent(g_pRenderer);

    Random();
    render();
    a++;
    if(a == 5) //5번 반복하면 빠져나오기
      break;
  }
  
  
  SDL_Quit();
  return 0;
}


bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title,
  xpos, ypos,
  height, width, flags);
  

  if(g_pWindow != 0)
  {
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
  }
}

else
{
  return false;
}

SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

return true;
}

void Random() //화면 색을 렌덤으로 바꾸기
{
  SDL_SetRenderDrawColor(g_pRenderer, rand() % 255, rand() % 255,rand() % 255, 255);
  SDL_Delay(1500);
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}


// #include <SDL.h>

// SDL_Window* g_pWindow = 0;
// SDL_Renderer* g_pRenderer = 0;

// int main(int argc, char* args[])
// {
//   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
//   {
//     g_pWindow = SDL_CreateWindow("Seeting up SDL", SDL_WINDOWPOS_CENTERED,
//     SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

//     if(g_pWindow != 0)
//     {
//       g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
//     }
//   }
//   else
//   {
//     return 1;
//   }

//   SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 100, 255); //화면을 blue로 바꿈
//   SDL_RenderClear(g_pRenderer);
//   SDL_RenderPresent(g_pRenderer);

//   SDL_Delay(5000);
//   SDL_Quit();

//   return 0;
// }