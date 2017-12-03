#include "Player.hpp"

/*
 * Constructor for player.
 */
Player::Player() {
  position = Vector(300, 250);
  velocity = Vector(0, 0);
  acceleration = Vector(0, 0);
  isFalling = false;
}

/*
 * Makes the player "jump" by setting its vertical velocity to 1 and
 * its vertical acceleration to 2.
 */
void Player::jump() {
  velocity[1] += 1;
  acceleration.setY(1.2);
}

/*
 * Updates the position based on its velocity
 */
void Player::updatePosition() {
  position += velocity;
}

/*
 * Updates the velocity based on its acceleration
 */
void Player::updateVelocity() {
  velocity += acceleration;
}

/*
 * Constantly updates vertical acceleration due to "gravity" when the player is
 * falling.
 */
void Player::updateAcceleration() {
  if (isFalling) {
    acceleration[1] -= .1;
  } else {
    acceleration[1] = 0;
  }
}

/*
 * Checks if the players position intersects the given platform.
 */
bool Player::isColliding(Platform platform) {
  return platform.collides(position) && platform.isVisible();
}
/*
* Checks if the players position intersects the given goal.
*/
bool Player::isColliding(Goal goal) {
	return goal.collides(position);
}

/*
 * Updates player's isFalling state based on collision of any platform
 */
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

/*
 * Updates the state of the player given key presses and platforms
 */
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

  //cout << "position() == " << position << endl;
  //cout << "velocity() == " << velocity << endl;
  //cout << "acceleration() == " << acceleration << endl;
  //cout << "isFalling() == " << isFalling << endl;
  //cout << endl;
}

/*
 * Moves the player left by setting its horizontal velocity to -5
 */
void Player::moveLeft() {
  velocity[0] = -5;
}

/*
* Moves the player right by setting its horizontal velocity to 5
*/
void Player::moveRight() {
  velocity[0] = 5;
}

/*
 * Sets player's horizontal velocity to 0
 */
void Player::idle() {
  velocity[0] = 0;
}

/*
 * Renders the player onto the given renderer
 */
void Player::render(SDL_Renderer * renderer) {
  SDL_Texture * playerTex;
  SDL_Rect destRect;

  playerTex = TextureManager::loadTexture("res/player.png", renderer);
  destRect.w = 23;
  destRect.h = 32;

  destRect.x = position.getX();
  destRect.y = 600 - position.getY();

  SDL_RenderCopy(renderer, playerTex, NULL, &destRect);
  SDL_DestroyTexture(playerTex);
}