#ifndef __Game__
#define __Game__

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "vector"

class Game {
  public:
  Game() {}
  ~Game() {}

  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();

  private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  bool m_bRunning;

  
  // GameObject m_go;
  // Player m_player;

  // SDL_Texture* m_pTexture;
  // SDL_Rect m_sourceRectangle;
  // SDL_Rect m_destinationRectangle;
  // ㄴ원본/대상 상자 관련 맴버 변수 선언

  //TextureManager m_textureManager;
  int m_currentFrame;

  private:
  std::vector<GameObject*> m_gameObjects;
  
};

#endif