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
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }

  
  if( !TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer)){
     return false;
  }

  if( !TheTextureManager::Instance()->load("Assets/backGR.png", "backGR", m_pRenderer)){
     return false;
  }

  if( !TheTextureManager::Instance()->load("Assets/cloud.png", "cloud", m_pRenderer)){
     return false;
  }

  if( !TheTextureManager::Instance()->load("Assets/ball.png", "ball", m_pRenderer)){
     return false;
  }
  if( !TheTextureManager::Instance()->load("Assets/Space.png", "Space", m_pRenderer)){
     return false;
  }

  if( !TheTextureManager::Instance()->load("Assets/Wall.png", "Wall", m_pRenderer)){
     return false;
  }
  
  m_bRunning = true;
  
  return true;
}

void Game::update()
{
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  m_cloudFrame = ((SDL_GetTicks() / 100) % 3);
  //m_ballFrame = ((SDL_GetTicks() / 100) % 3);
  
  if(cloudX <= 0)
    cloudXspeed = 1;
  else if(cloudX + cloudXsize >= 640)
    cloudXspeed = -1;

  cloudX += cloudXspeed;
  cloudY += cloudYspeed;

  if(ballX <= 0)
    ballXspeed = 0.5;
  else if(ballX + ballXsize >= 640)
    ballXspeed = -0.5;
  
  if(ballY <= 0)
    ballYspeed = 0.5;
  else if(ballY + ballYsize >= 480)
    ballYspeed = -0.5;

  ballX += ballXspeed;
  ballY += ballYspeed;

}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  TheTextureManager::Instance()->draw("backGR", 0, 0, resX, resY, 0, m_pRenderer, SDL_FLIP_NONE);

  TheTextureManager::Instance()->draw("cloud", 400, 100, cloudXsize, cloudYsize, cloudAng, m_pRenderer, SDL_FLIP_NONE);

  TheTextureManager::Instance()->drawFrame("cloud", cloudX, cloudY, cloudXsize, cloudYsize, 0, m_currentRow, m_cloudFrame, m_pRenderer, SDL_FLIP_NONE); // png파일이 alpha-png가 아니라 png의 (x, y = 0, 0)기준으로 튕겨져나와 끝까지 도달하지 못한다.
  
  TheTextureManager::Instance()->drawFrame("animate", 100, 300, 128, 82, 0, m_currentRow, m_currentFrame, m_pRenderer, SDL_FLIP_NONE);

  TheTextureManager::Instance()->drawFrame("ball", ballX, ballY, ballXsize, ballYsize, 0, m_currentRow, m_currentFrame % 3, m_pRenderer, SDL_FLIP_NONE); //이것또한 cloud와 마찬가지로 같은 현상이 있다.

  for(int x = 0; x < 19; x++)
  {
    for(int y = 0; y < 19; y++)
    {
      if(miro[x][y] == 0)
      {
        TheTextureManager::Instance()->draw("Space", 640 - (19 - x) * miroTileXsize, 480 - (19 - y) * miroTileYsize, miroTileXsize, miroTileYsize, 0, m_pRenderer, SDL_FLIP_NONE);
      }
      else if(miro[x][y] == 1)
      {
        TheTextureManager::Instance()->draw("Wall", 640 - (19 - x) * miroTileXsize, 480 - (19 - y) * miroTileYsize, miroTileXsize, miroTileYsize, 0, m_pRenderer, SDL_FLIP_NONE);
      }
    }
  }

  cloudAng += cloudAngspeed;

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