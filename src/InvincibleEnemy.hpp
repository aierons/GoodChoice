//
//  InvincibleEnemy.hpp
//  works
//
//  Created by Wesley Jiang on 12/5/17.
//  Copyright © 2017 Wesley Jiang. All rights reserved.
//
#pragma once
#ifndef InvincibleEnemy_hpp
#define InvincibleEnemy_hpp
#include "Enemy.h"
class InvincibleEnemy : public Enemy {
public:
    InvincibleEnemy(Vector start, Vector end);
    InvincibleEnemy(Platform p, Vector spawn, bool d);
    virtual void render(SDL_Renderer * renderer);
    virtual void updatePosition(Player player);
    virtual void update(Player player);
};

#endif /* InvincibleEnemy_hpp */
