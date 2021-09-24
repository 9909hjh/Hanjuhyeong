#include "Game.h"
#include "SDL_image.h"

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) 
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow != 0) {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
      if(m_pWindow != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }

  m_bRunning = true;

  //SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/rider.bmp");
  //SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/animate.bmp");
  // SDL_Surface* pTempSurface = IMG_Load("Assets/animate.png");
  SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

  SDL_FreeSurface(pTempSurface);

  // SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

  m_sourceRectangle.w = 128;
  m_sourceRectangle.h = 82;

  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  m_destinationRectangle.x = 50;
  m_destinationRectangle.y = 100;
  

  return true;
}

void Game::update()
{
  m_sourceRectangle.x = 128 * ((SDL_GetTicks() / 10) % 6);
  //컴퓨터가 보여주는 이미지 속도

  if(m_destinationRectangle.x < 300 || m_destinationRectangle.y < 300)
  {
    m_destinationRectangle.x++;
    m_destinationRectangle.y++;
  }
  else {
    m_destinationRectangle.x = 0;
    m_destinationRectangle.y = 0;
  }

}

//키보드로 움직이에 하고 싶은데 입력을 받는 형식으로
//하면 (만약 w를 눌러 위로 움직이면 메모리에 w가 계속쌓여서 메모리 낭비가 될것이다.) 비효율적으로 되기 떄문에 그걸 어떻게 하면 좋을까...

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  
  SDL_RenderPresent(m_pRenderer);
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}