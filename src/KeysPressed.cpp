#include "KeysPressed.hpp"

/*
 * Constructor that initializes keyCodes to an empty vector
 */
KeysPressed::KeysPressed() {
  keyCodes = vector<SDL_Keycode>();
}

/*
 * Pushes back the given key code into the keyCodes vector if the vector does not
 * have it already.
 */
void KeysPressed::addKeyCode(SDL_Keycode kc) {
  if (!hasKeyCode(kc)) {
    keyCodes.push_back(kc);
  }
}

/*
 * Removes the given key code if it is in the vector.
 */
void KeysPressed::removeKeyCode(SDL_Keycode kc) {
  if (hasKeyCode(kc)) {
    keyCodes.erase(keyCodes.begin() + getKeyCodeIdx(kc));
  }
}

/*
 * Checks if keyCodes contains the given key code;
 */
bool KeysPressed::hasKeyCode(SDL_Keycode kc) {
  bool foundKey = false;

  for (int i = 0; !foundKey && i < keyCodes.size(); i++) {
    if (keyCodes[i] == kc) {
      foundKey = true;
    }
  }

  return foundKey;
}

/*
 * Gets the index of the key code in the list. If the vector
 * does not contain the given key code, -1 is returned.
 */
int KeysPressed::getKeyCodeIdx(SDL_Keycode kc) {
  bool foundKey = false;
  int idx = -1;

  for (int i = 0; !foundKey && i < keyCodes.size(); i++) {
    if (keyCodes[i] == kc) {
      foundKey = true;
      idx = i;
    }
  }

  return idx;
}

/*
 * Getter for keyCodes
 */
vector<SDL_Keycode> KeysPressed::getKeyCodes() {
  return keyCodes;
}