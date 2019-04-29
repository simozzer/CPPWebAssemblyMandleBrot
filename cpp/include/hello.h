#ifndef HELLO_H
#define HELLO_H

#include <vector>
#include "mandle.h"

extern "C" {
    int new_mandle(int w, int h);
    uint8_t * getBuffer(int mandleInstance);
    void paint(int mandleInstance, MNDL_FLOAT oX, MNDL_FLOAT oY, MNDL_FLOAT s);
    MNDL_FLOAT getOriginX(int mandleInstance);
    MNDL_FLOAT getOriginY(int mandleInstance);
    MNDL_FLOAT getCenterX(int mandleInstance);
    MNDL_FLOAT getCenterY(int mandleInstance);
    MNDL_ITER getMaxIterations(int mandleInstance);
    void setMaxIterations(int mandleInstance, MNDL_ITER max);
    MNDL_FLOAT getScale(int mandleInstance);
    MNDL_FLOAT getXValue(int mandleInstance, int pixelX);
    MNDL_FLOAT getYValue(int mandleInstance, int pixelY);
    int main();
    
    
}


#endif
