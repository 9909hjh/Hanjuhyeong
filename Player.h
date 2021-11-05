#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
  void handleInput();
};


// #include "GameObject.h"

// class Player : public GameObject
// {
// public:
//   void load(int x, int y, int width, int height, std::string textureID);
  
//   void draw(SDL_Renderer* pRenderer);
//   void update();
//   void clean() {};
// };
