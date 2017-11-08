#ifndef KeysPressed_hpp
#define KeysPressed_hpp
#include <vector>
#include "SDL.h"
using namespace std;

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