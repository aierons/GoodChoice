We have currently implemented the player and platforms. The player has been rendered and is now able to run, 
jump and maneuver on platforms and platforms are also rendered. The player can jump onto those without
falling through. 
We still need to implement the enemies and bullets throughout the game. The enemies will be AIs 
throughout the game and we need to implement some form of collide() method if the enemy comes into contact with 
either the player or the bullet. If the player contacts the enemy, the player will immediately lose the game. For collisions,
depending on the type of bullet, the enemy will either be destroyed or the bullet will have no effect. 
We have begun working on the bullets where there are two different types of bullets, REVEAL and DESTROY. The two
kinds of bullets each have their own purposes, where the REVEAL bullet toggles the visibilty for invisble platforms
and the DAMANGE bullet damages an enemy. 
One difficulty we encountered was the installation and setup for SDL since whenever we tried to run the program on certain of our local computers, the program would crash and call up errors and we couldn't fix it properly. 
