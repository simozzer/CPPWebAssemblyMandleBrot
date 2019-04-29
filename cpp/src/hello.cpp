#include "hello.h"


int main() {
	return 0;
}

auto mandles = std::vector<Mandle>();

int new_mandle(int w, int h)
{
    mandles.push_back(Mandle(w,h));
    return mandles.size() -1;
}

uint8_t * getBuffer(int mandleInstance) {
    return mandles[mandleInstance].getBuffer();
}

void paint(int mandleInstance, MNDL_FLOAT oX, MNDL_FLOAT oY, MNDL_FLOAT s)
{
    mandles[mandleInstance].paint(oX, oY, s);
}

MNDL_FLOAT getCenterX(int mandleInstance)
{
    return mandles[mandleInstance].getCenterX();
}

MNDL_FLOAT getCenterY(int mandleInstance)
{
    return mandles[mandleInstance].getCenterY();
}

MNDL_FLOAT getOriginX(int mandleInstance)
{
    return mandles[mandleInstance].getOriginX();
}

MNDL_FLOAT getOriginY(int mandleInstance)
{
    return mandles[mandleInstance].getOriginY();
}

MNDL_ITER getMaxIterations(int mandleInstance)
{
    return mandles[mandleInstance].getMaxIterations();
}

void setMaxIterations(int mandleInstance, MNDL_ITER max)
{
    mandles[mandleInstance].setMaxIterations(max);
}


MNDL_FLOAT getScale(int mandleInstance)
{
    return mandles[mandleInstance].getScale();
}

MNDL_FLOAT getXValue(int mandleInstance, int pixelX)
{
    return mandles[mandleInstance].getXValue(pixelX);
}
    
MNDL_FLOAT getYValue(int mandleInstance, int pixelY)
{
    return mandles[mandleInstance].getYValue(pixelY);
}

//#include <iostream>

/*
int main() {
	Fib fib{};
	std::cout << fib.next() << std::endl;
	std::cout << fib.next() << std::endl;
	std::cout << fib.next() << std::endl;
	std::cout << fib.next() << std::endl;
	std::cout << fib.next() << std::endl;
	return 0;
}
*/
