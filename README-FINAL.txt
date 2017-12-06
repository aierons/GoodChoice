Proposed Features Implemented:
  - Player can move and jump on platforms
  - Player can alternate between different types of bullets
  - Player can shoot enemies with enemy bullets
  - Player can reveal hidden platforms with platform bullets

Class Hierarchy:
  - Main
    - Game
      - TextureManager
      - KeysPressed
      - Level
      - Goal
      - Vector
      - Player
      - Bullet
        - PlatformBullet
        - EnemyBullet
      - Enemy
        - NormalEnemy
        - CloneEnemy
        - InvincibleEnemy


Dynamic Memory Management:
  - When rendering each game object, we always destroy the SDL texture between
    each tick to avoid memory leaks.
  - Each bullet in the list has a lifetime. Once the lifetime reaches 0 or the
    bullet hits a platform or enemy, the bullet removes itself from the list.
  - Enemies in each level are also stored in the list. Once the enemy gets hit by
    a bullet, the enemy is removed from the list.
  - In the destructor of the game, all goal flags and the player, which are created with new, are deleted.
