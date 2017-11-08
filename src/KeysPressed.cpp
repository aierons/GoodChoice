#include "KeysPressed.hpp"

KeysPressed::KeysPressed() {
  keyCodes = vector<SDL_Keycode>();
}

void KeysPressed::addKeyCode(SDL_Keycode kc) {
  if (!hasKeyCode(kc)) {
    keyCodes.push_back(kc);
  }
}

void KeysPressed::removeKeyCode(SDL_Keycode kc) {
  if (hasKeyCode(kc)) {
    keyCodes.erase(keyCodes.begin() + getKeyCodeIdx(kc));
  }
}

bool KeysPressed::hasKeyCode(SDL_Keycode kc) {
  bool foundKey = false;

  for (int i = 0; !foundKey && i < keyCodes.size(); i++) {
    if (keyCodes[i] == kc) {
      foundKey = true;
    }
  }

  return foundKey;
}

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

vector<SDL_Keycode> KeysPressed::getKeyCodes() {
  return keyCodes;
}