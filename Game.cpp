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
        SDL_SetRenderDrawColor(m_pRenderer, 100, 100, 0, 255);
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }

  //m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
  if( !TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer)){
     return false;
  }
  m_bRunning = true;
  
  return true;
}

void Game::update()
{
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  //컴퓨터가 보여주는 이미지 속도
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  // m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
  // m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

  TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
  TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

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