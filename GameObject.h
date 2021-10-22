#pragma once
// #include "SDL.h"
// #include <iostream>
#include "LoaderParams.h"

class GameObject{
public:
  virtual void draw() = 0; //순수 가상함수 선언.
  virtual void update() = 0;
  virtual void clean() = 0;
  virtual ~GameObject() {} //가상 소멸자의 선언.

protected:
  GameObject(const LoaderParams* pParams) {}
};


// class GameObject {
  
// public:
//   virtual void load(int x, int y, int width, int height, std::string textureID);

//   virtual void draw(SDL_Renderer* pRenderer);
//   virtual void update();

//   virtual void clean() {};

// protected:
//   std::string m_textureID;

//   int m_x;
//   int m_y;
//   int m_width;
//   int m_height;

//   int m_currentFrame;
//   int m_currentRow;
// };