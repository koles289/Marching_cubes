#include "Mouse.h"

void Mouse::onLeftButton(int x, int y) {
	if (x > 400) { xx = -30; }
	else { xx = 30; }

	if (y > 400) { yy = -30; }
	else { yy = 30; }
	ynew =(yold - yy);
	xnew =(xold - xx);
}

void Mouse::onRightButton(int x, int y) {
	znew = zold + 45;
}



void Mouse::setXx(int xx) {
	Mouse::xx = xx;
}


void Mouse::setXold(int xold) {
	Mouse::xold = xold;
}


void Mouse::setYy(int yy) {
	Mouse::yy = yy;
}


void Mouse::setYold(int yold) {
	Mouse::yold = yold;
}


void Mouse::setZz() {
	Mouse::zz = zz+20;
}


void Mouse::setZold(int zold) {
	Mouse::zold = zold;
}

void Mouse::setState(State state)
{
	Mouse::state = state;
}

/*void Mouse::setState(Mouse::State state) {
	Mouse::state = state;
}*/

int Mouse::getXnew() const {
	return xnew;
}

int Mouse::getYnew() const {
	return ynew;
}

int Mouse::getZnew() const {
	return znew;
}

Mouse::State Mouse::getState() const
{
	return State();
}
