#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Bullet.h"
#include "PlatformBullet.h"
#include "EnemyBullet.h"
#include "NormalEnemy.hpp"
#include "FlyingEnemy.hpp"
#include "CloneEnemy.h"
#include "Level.h"

#include <vector>

SDL_Event Game::event;
Player *player;
KeysPressed * keys;

Goal * goal;
vector<Platform> platforms;
vector<PlatformBullet> pBullets;
vector<EnemyBullet> eBullets;
vector<NormalEnemy> normalEnemies;
vector<FlyingEnemy> flyingenemies;
vector<CloneEnemy> cloneEnemies;

vector<Level> levels;
int levelCount;

/*
 * This constructor will initialize the Player, KeyPressed, and platforms
 */
Game::Game() {
	keys = new KeysPressed();
	levelCount = 0;
	levels.push_back(Level());
	levels.push_back(Level());
    player = new Player();
    levels[0].platforms = vector<Platform>();
	levels[0].pBullets = vector<PlatformBullet>();
	levels[0].eBullets = vector<EnemyBullet>();
	levels[0].normalEnemies = vector<NormalEnemy>();
	levels[0].flyingenemies = vector<FlyingEnemy>();
	levels[0].cloneEnemies = vector<CloneEnemy>();

	levels[0].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
	levels[0].platforms.push_back(Platform(Vector(300, 150), Vector(400, 180)));
	levels[0].platforms.push_back(Platform(Vector(400, 250), Vector(500, 300)));
	levels[0].platforms.push_back(Platform(Vector(100, 375), Vector(270, 400)));
    
	levels[0].platforms.push_back(Platform(Vector(600, 100), Vector(650, 220), false));
    for (Platform p : levels[0].platforms) {
        if (p.isVisible()) {
			levels[0].normalEnemies.push_back(NormalEnemy(Vector(p.getStartX(), p.getEndY()), Vector(p.getEndX(), p.getEndY())));
        }
    }
<<<<<<< HEAD
	levels[0].goal = new Goal(Vector(250, 500));

	levels[1].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
	levels[1].flyingenemies.push_back(FlyingEnemy(Vector(300, 150), Vector(400, 180)));
	levels[1].cloneEnemies.push_back(CloneEnemy(levels[0].platforms[0], Vector(levels[0].platforms[0].getStartX(), levels[0].platforms[0].getEndY()), RIGHT));

=======
    
	levels[0].flyingenemies.push_back(FlyingEnemy(Vector(300, 150), Vector(400, 180)));
	levels[0].goal = new Goal(Vector(250, 500));

	levels[1].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
>>>>>>> origin/master
	levels[1].goal = new Goal(Vector(550, 500));

	load();
}

void Game::load() {
	player = new Player();
	goal = levels[levelCount].goal;
	platforms = levels[levelCount].platforms;
	pBullets = levels[levelCount].pBullets;
	eBullets = levels[levelCount].eBullets;
	normalEnemies = levels[levelCount].normalEnemies;
	flyingenemies = levels[levelCount].flyingenemies;
	cloneEnemies = levels[levelCount].cloneEnemies;

}
void Game::reset() {
	load();
    /*player = new Player();
    keys = new KeysPressed();
    platforms = vector<Platform>();
    pBullets = vector<PlatformBullet>();
    eBullets = vector<EnemyBullet>();

    //testing platform bullet
    //pBullets.push_back(PlatformBullet(Vector(300, 200), Vector(10, 0)));

    platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
    platforms.push_back(Platform(Vector(300, 150), Vector(400, 180)));
    platforms.push_back(Platform(Vector(400, 250), Vector(500, 300)));
    platforms.push_back(Platform(Vector(100, 375), Vector(270, 400)));

    //testing invisible platform
    platforms.push_back(Platform(Vector(600, 100), Vector(650, 220), false));*/
}

/*
 * This destructor will delete the pointers to player and keys;
 */
Game::~Game() {
    delete player;
    delete keys;
	for (int i = 0; i < levels.size(); i++) {
		//if there is a level without a goal this will cause an issue
		delete levels[0].goal;
		//this might cause an issue ---- if so, try doing begin + i. I don't know if erase slides stuff over or not
		levels.erase(levels.begin());
	}
}

/*
 * Initializes the game by creating a window and renderer.
 */
void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized..." << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window) {
            std::cout << "Window Created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }
}

/*
 * Handles user input such as keyboard, mouse, and quitting
 */
void Game::handleEvents() {
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            keys->addKeyCode(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            keys->removeKeyCode(event.key.keysym.sym);
        default:
            break;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        eBullets.push_back(EnemyBullet(player->position + Vector(7, 14),
                                       Bullet::getInitialVector(player->position + Vector(14, -14),
                                                                Vector(event.button.x, 600 - event.button.y))));
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
        pBullets.push_back(PlatformBullet(player->position + Vector(7, 14),
                                          Bullet::getInitialVector(player->position + Vector(14, -14),
                                                                   Vector(event.button.x, 600 - event.button.y))));
    }
}
/*
* checks if any of the bullets collide wiht the enemy
* eraise the enemy from the vector if it is hit
*/
bool Game::ifEnemyGotHIt(int enemyIndex) {
	vector<int> toDelete;
	bool gotHit = false;
	for (int k = 0; k < eBullets.size(); k++) {
		EnemyBullet bullet = eBullets.at(k);
		if (normalEnemies[enemyIndex].collides(bullet.getPosition())) {
			toDelete.push_back(k);
			gotHit = true;
		}
	}

	for (int i : toDelete) {
		eBullets.erase(eBullets.begin() + i);
	}
	return gotHit;
}

/*
* checks if any of the enemies are touching the player, if they are reset the game
*/
void Game::ifPlayerDies(int enemyIndex) {
	if (normalEnemies[enemyIndex].collides(player->position)) {
		reset();
	}
}

/*
* checks if any of the enemies are touching the player, if they are reset the game
*/
void Game::updateNormalEnemies() {
	// first check if there is anything to delete to prevent changing the size of the array during iterating throught for loop
	vector<int> toDelete;
	for (int i = 0; i < normalEnemies.size(); i++) {
		if (ifEnemyGotHIt(i)) {
			toDelete.push_back(i);
		}
	}
	for (int i : toDelete) {
		normalEnemies.erase(normalEnemies.begin() + i);
	}

	for (int i = 0; i < normalEnemies.size(); i++) {
		normalEnemies[i].update(*player);
		ifPlayerDies(i);
	}
}

void Game::updateCloneEnemies() {
	for (int i = 0; i < cloneEnemies.size(); i++) {
		cloneEnemies[i].update(*player);
		ifHitClone(i);
	}
}

void Game::ifHitClone(int enemyIndex) {
	if (!cloneEnemies[enemyIndex].hasCloned) {
		for (int k = 0; k < pBullets.size(); k++) {
			PlatformBullet b = pBullets.at(k);
			if (cloneEnemies[enemyIndex].collides(b.getPosition())) {
				cloneEnemies.push_back(CloneEnemy(cloneEnemies[enemyIndex].platform, cloneEnemies[enemyIndex].getPostion(), !cloneEnemies[enemyIndex].facingRight()));
				cloneEnemies[enemyIndex].hasCloned = true;
				cloneEnemies[enemyIndex + 1].hasCloned = true;
				pBullets.erase(pBullets.begin() + k);
			}
		}
	}

	for (int j = 0; j < eBullets.size(); j++) {
		EnemyBullet b = eBullets.at(j);
		if (cloneEnemies[enemyIndex].collides(b.getPosition())) {
			cloneEnemies.erase(cloneEnemies.begin() + enemyIndex);
			pBullets.erase(pBullets.begin() + j);
			break;
		}
	}
}

/*
 * Updates the state of the game.
 */
void Game::update() {
    player->update(keys, platforms);
	updateNormalEnemies();
	if (!cloneEnemies.empty()) {
		updateCloneEnemies();
	}
    
    for (int i  = 0; i < flyingenemies.size(); i++){
        flyingenemies[i].update(*player);
    }
    

    for (int count = 0; count < pBullets.size(); count++) {
        pBullets[count].updatePosition();
        bool exists = true;
        if (!pBullets[count].isAlive()) {
            pBullets.erase(pBullets.begin() + count);
            exists = false;
        }
        for (int i = 0; i < platforms.size() && exists; i++) {
            if (pBullets[count].collidesWithPlatform(platforms[i])) {
                pBullets.erase(pBullets.begin() + count);
                exists = false;
            }
        }
    }
    for (int count = 0; count < eBullets.size(); count++) {
        eBullets[count].updatePosition();
        bool exists = true;
        if (!eBullets[count].isAlive()) {
            eBullets.erase(eBullets.begin() + count);
            exists = false;
        }
        for (int i = 0; i < platforms.size() && exists; i++) {
            if (eBullets[count].collidesWithPlatform(platforms[i])) {
                eBullets.erase(eBullets.begin() + count);
                exists = false;
            }
        }
    }

    if (keys->hasKeyCode(SDLK_ESCAPE)) {
        reset();
    }

	if (player->isColliding(*goal)) {
		levelCount++;
		load();
	}
}

/*
 * Renders all given game objects
 */
void Game::render() {
    SDL_RenderClear(renderer);
    player->render(renderer);

    for (Platform platform : platforms) {
        if (platform.isVisible()) { platform.render(renderer); }
    }

    for (int count = 0; count < pBullets.size(); count++) {
        pBullets[count].render(renderer);
    }

    for (int count = 0; count < eBullets.size(); count++) {
        eBullets[count].render(renderer);
    }
    
    for (FlyingEnemy em : flyingenemies) {
        em.render(renderer);
    }


    for (Enemy em : normalEnemies) {
        em.render(renderer);
    }
	for (CloneEnemy em : cloneEnemies) {
		em.render(renderer);
	}
	goal->render(renderer);

	goal->render(renderer);

    SDL_RenderPresent(renderer);
}

/*
 * Cleans up the game by destroying the window and renderer.
 */
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}

/*
 * Getter for isRunning, which determines if the game is running.
 */
bool Game::running() {
    return isRunning;
}

/*void Game::shoot() {
	SDL_PollEvent(&event);
	if (event.key == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
		position = player.position;
		alive = true;
		updatePosition();
		render();
	}
}*/
