#include "Player.hpp"

Player::Player() {
  position = Vector(300, 250);
  velocity = Vector(0, 0);
  acceleration = Vector(0, 0);
  isFalling = false;
}

void Player::jump() {
  velocity[1] += 1;
  acceleration.setY(2);
}

void Player::updatePosition() {
  position += velocity;
}

void Player::updateVelocity() {
  velocity += acceleration;
}

void Player::updateAcceleration() {
  if (isFalling) {
    acceleration[1] -= .2;
  } else {
    acceleration[1] = 0;
  }
}

bool Player::isColliding(Platform platform) {
  return platform.collides(position);
}

void Player::checkColliding(vector<Platform> platforms) {
  bool collide = false;
  for (int i = 0; !collide && i < platforms.size(); i++) {
    if (isColliding(platforms[i])) {
      collide = true;
      position.setY(platforms[i].getEndY());
    }
  }
  
  isFalling = !collide;
}

void Player::update(KeysPressed * keys, vector<Platform> platforms) {

  if (!keys->hasKeyCode(SDLK_a) && !keys->hasKeyCode(SDLK_d)) {
    idle();
  } else {
    if (keys->hasKeyCode(SDLK_a)) {
      moveLeft();
    }

    if (keys->hasKeyCode(SDLK_d)) {
      moveRight();
    }
  }

  if (keys->hasKeyCode(SDLK_w)) {
    if (!isFalling) {
      isFalling = true;
      jump();
    }
  }

  updatePosition();
  updateVelocity();
  updateAcceleration();

  if (position.getY() > 50) {
    isFalling = true;
  }
  else {
    isFalling = false;
  }

  checkColliding(platforms);

  if (!isFalling) {
    acceleration.setY(0);
    velocity.setY(0);
  }

  cout << "position() == " << position << endl;
  cout << "velocity() == " << velocity << endl;
  cout << "acceleration() == " << acceleration << endl;
  cout << "isFalling() == " << isFalling << endl;
  cout << endl;
}

void Player::moveLeft() {
  velocity[0] = -5;
}

void Player::moveRight() {
  velocity[0] = 5;
}

void Player::idle() {
  velocity[0] = 0;
}

void Player::render(SDL_Renderer * renderer) {
  SDL_Texture * playerTex;
  SDL_Rect destRect;

  playerTex = TextureManager::loadTexture("res/player.png", renderer);
  destRect.w = 23;
  destRect.h = 32;

  destRect.x = position.getX();
  destRect.y = 600 - position.getY();

  SDL_RenderCopy(renderer, playerTex, NULL, &destRect);
}