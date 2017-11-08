#include "Player.hpp"
#include <vector>

Player::Player() {
  position = Vector(250, 50);
  velocity = Vector(0, 0);
  acceleration = Vector(0, 0);
  colliding = false;
}

void Player::jump() {
  velocity[1] += 1;
  acceleration.setY(2);
}

void Player::updatePosition() {
  position += velocity;

  if (position.getY() < 50) {
    position[1] = 50;
  }
}

void Player::updateVelocity() {
  velocity += acceleration;

  if (!isFalling()) {
    velocity[1] = 0;
  }
}

void Player::updateAcceleration() {
  if (isFalling() && !(colliding && acceleration[1] <= 0)) {
    acceleration[1] -= .2;
  } else {
    acceleration[1] = 0;
  }
}

bool Player::isFalling() {
  return position.getY() > 50;
}

void Player::isColliding(std::vector<Platform> platforms) {
	for (Platform p : platforms) {
		if (p.collides(position)) {
			colliding = true;
		}
	}
	colliding = false;
}

void Player::update(KeysPressed * keys) {
  
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
    if (!isFalling()) {
      jump();
    }
  }

  updatePosition();
  updateVelocity();
  updateAcceleration();

  cout << "position() == " << position << endl;
  cout << "velocity() == " << velocity << endl;
  cout << "acceleration() == " << acceleration << endl;
  cout << "isFalling() == " << isFalling() << endl;
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
  SDL_Rect srcRect, destRect;

  playerTex = TextureManager::loadTexture("res/player.png", renderer);
  destRect.w = 23;
  destRect.h = 32;

  destRect.x = position.getX();
  destRect.y = 600 - position.getY();

  SDL_RenderCopy(renderer, playerTex, NULL, &destRect);
}