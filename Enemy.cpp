#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
  SDLGameObject::draw();
}
void Enemy::update()
{
  // m_y += 1;
  // m_x += 1;
  //SDLGameObject::update();//이것은
  //m_position.setX(m_position.getX() + 1);
  //m_position.setY(m_position.getY() + 1); 와 같습니다.
  m_currentFrame = ((SDL_GetTicks() / 100) % 6);
  m_acceleration.setX(1);
  SDLGameObject::update();
}

void Enemy::clean() {}