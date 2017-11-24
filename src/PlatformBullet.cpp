#include "PlatformBullet.h"
#include "Platform.hpp"


bool PlatformBullet::collidesWithPlatform(Platform p) {
	if (p.collides(position)) {
		if (p.isVisible()) {
			p.show();
		}
		return true;
	}
	return false;
}
