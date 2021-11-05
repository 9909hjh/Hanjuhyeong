#include "Player.h"
#include "InputHandler.h"

// void Player:: load(int x, int y, int width, int height, std::string  textureID)
// {
//   GameObject::load(x, y, width, height, textureID);
// }
//void Player::draw()
// {
//   GameObject::draw(pRenderer));
// }
// void Player::update()
// {
//   m_x -= 1;
// }

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  // SDLGameObject::update();
  //m_position.setX(m_position.getX() + 1);
  handleInput();
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  //m_velocity.setX(1);
  SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput()
{
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
  {
    m_velocity.setX(2);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
  {
    m_velocity.setX(-2);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
  {
    m_velocity.setY(-2);
  }
  if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
  {
    m_velocity.setY(2);
  }
}

// #include "SDL.h"

// class InputHandler {
// public:
//   ~InputHandler() {}
//   static InputHandler* Instance() {
//     if(s_pInstance == 0){
//       s_pInstance = new InputHandler();
//     }
//     return s_pInstance;
//   }
//   bool isKeyDown(SDL_Scancode key);
//   void update();
//   void clean() {}

// private:
//   InputHandler() {}
//   static InputHandler* s_pInstance;
//   const Uint8* m_keystates;
// };
// typedef InputHandler TheInputHandler;