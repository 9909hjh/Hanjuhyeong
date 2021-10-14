#include "SDL.h"
#include "TextureManager.h"

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

  private:
    float cloudX = 0;
    float cloudY = 100;
    int cloudXsize = 64;
    int cloudYsize = 64;
    float cloudXspeed = 0.2f;
    float cloudYspeed = 0;
    int cloudAng = 0;
    int cloudAngspeed = 1;

    float ballX = 100;
    float ballY = 100;
    int ballXsize = 64;
    int ballYsize = 64;
    float ballXspeed = 0.5f;
    float ballYspeed = 0.5f;
  
    int m_currentFrame;
    int m_currentRow = 0;
    int m_cloudFrame;
    int m_ballFrame;

    int miro [19][19] =
      {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
      1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
      1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,
      1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
      1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,
      1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
      1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,
      1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,
      1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,
      1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,
      1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
      1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,
      1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,
      1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,
      1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,
      1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,
      1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,
      1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    int miroTileXsize = 10;
    int miroTileYsize = 10;
    
    int resX = 640; //해상도 X축
    int resY = 480; //해상도 Y축

  
};