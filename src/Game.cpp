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
#include "InvincibleEnemy.hpp"
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
vector<InvincibleEnemy> invincibles;
SDL_Texture * background = NULL;


//for testing
bool pressed = false;

vector<Level> levels;
int levelCount;
const int maxLevels = 5;
const int bulletMax = 5;

/*
 * This constructor will initialize the Player, KeyPressed, and platforms
 */
Game::Game() {
    keys = new KeysPressed();
    levelCount = 0;
    
    for (int i = 0; i <= maxLevels; i++) {
        levels.push_back(Level());
        levels[i].platforms = vector<Platform>();
        levels[i].pBullets = vector<PlatformBullet>();
        levels[i].eBullets = vector<EnemyBullet>();
        levels[i].normalEnemies = vector<NormalEnemy>();
        levels[i].flyingenemies = vector<FlyingEnemy>();
        levels[i].cloneEnemies = vector<CloneEnemy>();
        levels[i].invincibles = vector<InvincibleEnemy>();
    }
    player = new Player();
    
    levels[0].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
    levels[0].platforms.push_back(Platform(Vector(300, 150), Vector(400, 180)));
    levels[0].platforms.push_back(Platform(Vector(400, 250), Vector(500, 300)));
    levels[0].platforms.push_back(Platform(Vector(100, 375), Vector(270, 400)));
    
    levels[0].platforms.push_back(Platform(Vector(600, 100), Vector(650, 220), false));
    levels[0].normalEnemies.push_back(NormalEnemy(Vector(levels[0].platforms[0].getStartX(), levels[0].platforms[0].getEndY() +10), Vector(levels[0].platforms[0].getEndX(), levels[0].platforms[0].getEndY())));
    levels[0].normalEnemies.push_back(NormalEnemy(Vector(levels[0].platforms[3].getStartX(), levels[0].platforms[3].getEndY() +10), Vector(levels[0].platforms[3].getEndX(), levels[0].platforms[3].getEndY())));
    
    //test invincibles (delete after )
    levels[0].invincibles.push_back(InvincibleEnemy(Vector(levels[0].platforms[3].getStartX(), levels[0].platforms[3].getEndY() +10), Vector(levels[0].platforms[3].getEndX(), levels[0].platforms[3].getEndY())));

    
    levels[0].goal = new Goal(Vector(250, 500));
    
    // Level 2
    levels[1].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
    levels[1].platforms.push_back(Platform(Vector(450, 170), Vector(650, 220)));
    levels[1].platforms.push_back(Platform(Vector(50, 170), Vector(250, 220)));
    levels[1].platforms.push_back(Platform(Vector(450, 420), Vector(650, 470)));
    levels[1].platforms.push_back(Platform(Vector(50, 420), Vector(250, 470)));
    levels[1].platforms.push_back(Platform(Vector(250, 290), Vector(450, 340), false));
    
    vector<Platform> p = levels[1].platforms;
    
    levels[1].normalEnemies.push_back(NormalEnemy(p[0], Vector(p[0].getStartX(), p[0].getEndY()), RIGHT));
    levels[1].normalEnemies.push_back(NormalEnemy(p[3], Vector(p[3].getStartX() + 100, p[3].getEndY()), RIGHT));
    levels[1].normalEnemies.push_back(NormalEnemy(p[4], Vector(p[4].getStartX() + 60, p[4].getEndY()), RIGHT));
    
    
    levels[1].flyingenemies.push_back(FlyingEnemy(Vector(220, 300)));
    levels[1].cloneEnemies.push_back(CloneEnemy(p[1], Vector(p[1].getStartX(), p[1].getEndY()), RIGHT));
    levels[1].cloneEnemies.push_back(CloneEnemy(p[2], Vector(p[2].getEndX(), p[2].getEndY()), LEFT));
    
    levels[1].goal = new Goal(Vector(550, 500));
    
    //Level 3
    levels[2].platforms.push_back(Platform(Vector(50, 20), Vector(550, 90)));
    
    levels[2].platforms.push_back(Platform(Vector(40, 120), Vector(70, 150)));
    levels[2].platforms.push_back(Platform(Vector(40, 220), Vector(70, 250)));
    levels[2].platforms.push_back(Platform(Vector(40, 320), Vector(70, 350)));
    levels[2].platforms.push_back(Platform(Vector(40, 420), Vector(70, 450)));
    
    levels[2].platforms.push_back(Platform(Vector(70, 420), Vector(170, 440)));
    
    levels[2].platforms.push_back(Platform(Vector(100, 220), Vector(200, 240)));
    levels[2].cloneEnemies.push_back(CloneEnemy(levels[2].platforms[5], Vector(120, 240), true));
    
    levels[2].platforms.push_back(Platform(Vector(420, 120), Vector(520, 140), false));
    levels[2].platforms.push_back(Platform(Vector(420, 220), Vector(520, 240), false));
    levels[2].platforms.push_back(Platform(Vector(420, 320), Vector(520, 340), false));
    levels[2].platforms.push_back(Platform(Vector(420, 420), Vector(520, 440), false));
    
    levels[2].normalEnemies.push_back(NormalEnemy(Vector(50, 450), Vector(70, 450)));
    
    levels[2].flyingenemies.push_back(FlyingEnemy(Vector(50, 450)));
    levels[2].flyingenemies.push_back(FlyingEnemy(Vector(450, 450)));
    
    levels[2].goal = new Goal(Vector(50, 500));

	//level 4
	levels[3].platforms.push_back(Platform(Vector(150, 50), Vector(350, 90)));
	levels[3].platforms.push_back(Platform(Vector(50, 150), Vector(250, 190)));
	levels[3].platforms.push_back(Platform(Vector(250, 290), Vector(320, 330)));
	levels[3].platforms.push_back(Platform(Vector(470, 390), Vector(670, 450)));

	levels[3].platforms.push_back(Platform(Vector(50, 290), Vector(220, 330), false));
	levels[3].platforms.push_back(Platform(Vector(250, 420), Vector(350, 440), false));

	levels[3].normalEnemies.push_back(NormalEnemy(levels[3].platforms[1], Vector(50, 200), true));

	levels[3].invincibles.push_back(InvincibleEnemy(levels[3].platforms[1], Vector(250, 200), false));
	levels[3].invincibles.push_back(InvincibleEnemy(levels[3].platforms[2], Vector(250, 340), true));

	levels[3].goal = new Goal(Vector(600, 550));

	//level 5

	levels[4].platforms.push_back(Platform(Vector(100, 50), Vector(600, 100)));

	levels[4].platforms.push_back(Platform(Vector(250, 430), Vector(450, 460)));
	levels[4].platforms.push_back(Platform(Vector(500, 430), Vector(650, 460)));
	levels[4].platforms.push_back(Platform(Vector(50, 430), Vector(200, 460)));

	levels[4].normalEnemies.push_back(NormalEnemy(levels[4].platforms[0], Vector(100, 100), true));
	levels[4].normalEnemies.push_back(NormalEnemy(levels[4].platforms[0], Vector(600, 100), false));
	levels[4].cloneEnemies.push_back(CloneEnemy(levels[4].platforms[0], Vector(150, 100), true));
	levels[4].cloneEnemies.push_back(CloneEnemy(levels[4].platforms[0], Vector(550, 100), false));
	levels[4].invincibles.push_back(InvincibleEnemy(levels[4].platforms[0], Vector(200, 100), false));
	levels[4].invincibles.push_back(InvincibleEnemy(levels[4].platforms[0], Vector(500, 100), true));

	levels[4].invincibles.push_back(InvincibleEnemy(levels[4].platforms[1], Vector(350, 470), true));
	levels[4].cloneEnemies.push_back(CloneEnemy(levels[4].platforms[2], Vector(650, 470), false));
	levels[4].normalEnemies.push_back(NormalEnemy(levels[4].platforms[3], Vector(50, 470), true));

	levels[4].platforms.push_back(Platform(Vector(350, 200), Vector(575, 230), false));
	levels[4].platforms.push_back(Platform(Vector(125, 200), Vector(300, 230), false));
	levels[4].platforms.push_back(Platform(Vector(350, 270), Vector(575, 300), false));
	levels[4].platforms.push_back(Platform(Vector(125, 270), Vector(300, 300), false));

	levels[4].goal = new Goal(Vector(700, 550));

	//Level 6 / Win Screen
	levels[5].platforms.push_back(Platform(Vector(90, 50), Vector(130, 280)));
	levels[5].platforms.push_back(Platform(Vector(190, 50), Vector(230, 280)));
	levels[5].platforms.push_back(Platform(Vector(290, 50), Vector(330, 280)));
	levels[5].platforms.push_back(Platform(Vector(90, 50), Vector(330, 100)));

	levels[5].platforms.push_back(Platform(Vector(390, 50), Vector(430, 230)));
	levels[5].platforms.push_back(Platform(Vector(390, 230), Vector(430, 280)));

	levels[5].platforms.push_back(Platform(Vector(490, 50), Vector(530, 280)));
	levels[5].platforms.push_back(Platform(Vector(600, 50), Vector(640, 280)));
	levels[5].platforms.push_back(Platform(Vector(490, 230), Vector(640, 280)));

	levels[5].goal = new Goal(Vector(1000, 1000));

    load();
}

void Game::load() {
    if (levelCount > maxLevels) {
        levelCount = maxLevels;
    }
    delete player;
    player = new Player();
    goal = levels[levelCount].goal;
    platforms = levels[levelCount].platforms;
    pBullets = levels[levelCount].pBullets;
    eBullets = levels[levelCount].eBullets;
    normalEnemies = levels[levelCount].normalEnemies;
    flyingenemies = levels[levelCount].flyingenemies;
    cloneEnemies = levels[levelCount].cloneEnemies;
    invincibles = levels[levelCount].invincibles;
    Bullet::count = 0;
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
        delete levels[i].goal;
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
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && Bullet::count <=bulletMax) {
        eBullets.push_back(EnemyBullet(player->position + Vector(7, 14),
                                       Bullet::getInitialVector(player->position + Vector(14, -14),
                                                                Vector(event.button.x, 600 - event.button.y))));
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT && Bullet::count <= bulletMax) {
        pBullets.push_back(PlatformBullet(player->position + Vector(7, 14),
                                          Bullet::getInitialVector(player->position + Vector(14, -14),
                                                                   Vector(event.button.x, 600 - event.button.y))));
    }
    
    //for testing only
    if (keys->hasKeyCode(SDLK_z)) {
        pressed = true;
    }
    if (keys->hasKeyCode(SDLK_x) && pressed) {
        levelCount++;
        load();
        pressed = false;
    }
}


void Game::updateEnemies(){
    updateNormalEnemies();
    if (!cloneEnemies.empty()) {
        updateCloneEnemies();
    }
    
    for (int i = 0; i < flyingenemies.size(); i++){
        flyingenemies[i].update(*player);
        
        if (flyingenemies[i].collides(player->position)){
            reset();
        }
        else {
            for (int k = 0; k < eBullets.size(); k++) {
                EnemyBullet bullet = eBullets.at(k);
                if (flyingenemies[i].collides(bullet.getPosition())) {
                    flyingenemies.erase(flyingenemies.begin() + i);
                    eBullets.erase(eBullets.begin() + k);
                    k--;
                    Bullet::count--;
                    break;
                }
            }
        }
    }
    
}

void Game::updateBullets(){
    for (int count = 0; count < pBullets.size(); count++) {
        pBullets[count].updatePosition();
        bool exists = true;
        if (!pBullets[count].isAlive()) {
            pBullets.erase(pBullets.begin() + count);
            Bullet::count--;
            exists = false;
        }
        for (int i = 0; i < platforms.size() && exists; i++) {
            if (pBullets[count].collidesWithPlatform(platforms[i])) {
                pBullets.erase(pBullets.begin() + count);
                Bullet::count--;
                exists = false;
            }
        }
    }
    for (int count = 0; count < eBullets.size(); count++) {
        eBullets[count].updatePosition();
        bool exists = true;
        if (!eBullets[count].isAlive()) {
            eBullets.erase(eBullets.begin() + count);
            Bullet::count--;
            exists = false;
        }
        for (int i = 0; i < platforms.size() && exists; i++) {
            if (eBullets[count].collidesWithPlatform(platforms[i])) {
                eBullets.erase(eBullets.begin() + count);
                Bullet::count--;
                exists = false;
            }
        }
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
            //toDelete.push_back(k);
            eBullets.erase(eBullets.begin() + k);
            k--;
            Bullet::count--;
            gotHit = true;
        }
    }
    //    for (int i : toDelete) {
    //        eBullets.erase(eBullets.begin() + i);
    //    }
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
    for (int i = 0; i < normalEnemies.size(); i++) {
        if (this->ifEnemyGotHIt(i)) {
            normalEnemies.erase(normalEnemies.begin() + i);
        }
        else {
            normalEnemies[i].update(*player);
            this->ifPlayerDies(i);
        }
    }
}

void Game::updateCloneEnemies() {
    for (int i = 0; i < cloneEnemies.size(); i++) {
        if (cloneEnemies[i].collides(player->position)) {
            reset();
        }
        cloneEnemies[i].update(*player);
        this->ifHitClone(i);
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
                Bullet::count--;
            }
        }
    }
    
    for (int j = 0; j < eBullets.size(); j++) {
        EnemyBullet b = eBullets.at(j);
        if (cloneEnemies[enemyIndex].collides(b.getPosition())) {
            cloneEnemies.erase(cloneEnemies.begin() + enemyIndex);
            eBullets.erase(eBullets.begin() + j);
            Bullet::count--;
            break;
        }
    }
}

/*
 * Updates the state of the game.
 */
void Game::update() {
    if (player->position.getY() < 0) {
        reset();
    }
    player->update(keys, platforms);
    updateEnemies();

    for (int i = 0; i < invincibles.size(); i++) {
        if (invincibles[i].collides(player->position)) {
            reset();
        }
        invincibles[i].update(*player);
    }
    updateBullets();
    if (keys->hasKeyCode(SDLK_ESCAPE)) {
        reset();
    }
    if (player->isColliding(*goal)) {
        levelCount++;
        load();
    }
}

void Game::render_background(SDL_Renderer * renderer) {
    SDL_Rect destRect;
    if (background == NULL){
        background = TextureManager::loadTexture("res/bg.png", renderer);
    }
    destRect.w = 800;
    destRect.h = 600;
    
    destRect.x = 0;
    destRect.y = 0;
    
    SDL_RenderCopy(renderer, background, NULL, &destRect);
    //DON'T Destroy Texture otherwise it has to reload it
}


/*
 * Renders all given game objects
 */
void Game::render() {
    SDL_RenderClear(renderer);
    render_background(renderer);
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
    for (InvincibleEnemy em : invincibles) {
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
