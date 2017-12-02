//
//  NormalEnemy.hpp
//  testing
//
//  Created by Wesley Jiang on 12/1/17.
//  Copyright © 2017 Wesley Jiang. All rights reserved.
//
#pragma once
#ifndef NormalEnemy_hpp
#define NormalEnemy_hpp
#include "Enemy.h"

class NormalEnemy : public Enemy {
public:
    NormalEnemy(Vector start, Vector end);
    virtual void render(SDL_Renderer * renderer);
    virtual void updatePosition(Player player);
    virtual void update(Player player);
};


#endif /* NormalEnemy_hpp */
