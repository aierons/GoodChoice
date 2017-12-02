#include "Game.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Bullet.h"
#include "PlatformBullet.h"
#include "EnemyBullet.h"
#include "NormalEnemy.hpp"
#include "FlyingEnemy.hpp"
#include "Level.h"

#include <vector>

SDL_Event Game::event;
Player *player;
KeysPressed * keys;

vector<Platform> platforms;
vector<PlatformBullet> pBullets;
vector<EnemyBullet> eBullets;
vector<NormalEnemy> enemies;
vector<FlyingEnemy> flyingenemies;

vector<Level> levels;
int levelCount;

/*
 * This constructor will initialize the Player, KeyPressed, and platforms
 */
Game::Game() {
	keys = new KeysPressed();
	levelCount = 0;
	levels.push_back(Level());
    player = new Player();
    levels[0].platforms = vector<Platform>();
	levels[0].pBullets = vector<PlatformBullet>();
	levels[0].eBullets = vector<EnemyBullet>();
	levels[0].enemies = vector<NormalEnemy>();
	levels[0].flyingenemies = vector<FlyingEnemy>();

	levels[0].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
	levels[0].platforms.push_back(Platform(Vector(300, 150), Vector(400, 180)));
	levels[0].platforms.push_back(Platform(Vector(400, 250), Vector(500, 300)));
	levels[0].platforms.push_back(Platform(Vector(100, 375), Vector(270, 400)));
    
	levels[0].platforms.push_back(Platform(Vector(600, 100), Vector(650, 220), false));
    for (Platform p : levels[0].platforms) {
        if (p.isVisible()) {
			levels[0].enemies.push_back(NormalEnemy(Vector(p.getStartX(), p.getEndY()), Vector(p.getEndX(), p.getEndY())));
        }
    }
    
	levels[0].flyingenemies.push_back(FlyingEnemy(Vector(300, 150), Vector(400, 180)));

	load();
}

void Game::load() {
	player = new Player();
	platforms = levels[levelCount].platforms;
	pBullets = levels[levelCount].pBullets;
	eBullets = levels[levelCount].eBullets;
	enemies = levels[levelCount].enemies;
	flyingenemies = levels[levelCount].flyingenemies;
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
 * Updates the state of the game.
 */
void Game::update() {
    player->update(keys, platforms);
    //fly->update();
//    for (Enemy em : enemies) {
//        enemies[i].update(platforms);
//
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].update(*player);
        for (int k = 0; k < eBullets.size(); k++){
            EnemyBullet b = eBullets.at(k);
            if(enemies[i].collides(b.getPosition())){
                enemies.erase(enemies.begin() + i);
                
            }
        }
        if (enemies[i].collides(player->position)){
            reset();
        }
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
}

/*
 * Renders all given game objects
 */
void Game::render() {
    SDL_RenderClear(renderer);
    player->render(renderer);
    //fly->render(renderer, flyingEnemyImagePath);
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


    for (Enemy em : enemies) {
        em.render(renderer);
    }

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
