#ifndef KeysPressed_hpp
#define KeysPressed_hpp
#include <vector>
#include "SDL.h"
using namespace std;

/*
 * This class will keep and update a list of SDL key codes
 */
class KeysPressed {
  public:
    KeysPressed();
    void addKeyCode(SDL_Keycode kc);
    void removeKeyCode(SDL_Keycode kc);
    bool hasKeyCode(SDL_Keycode kc);
    int getKeyCodeIdx(SDL_Keycode kc);
    vector<SDL_Keycode> getKeyCodes();
  private:
    vector<SDL_Keycode> keyCodes;
};

#endif