#ifndef MANDLE_H
#define MANDLE_H

#include <stdint.h>
#include <math.h>

#define MNDL_FLOAT double
#define MNDL_ITER uint32_t

class Mandle {

public:
	Mandle(int w, int h);
    ~Mandle();
	
    uint8_t * getBuffer();
    long getBufferSize();
    MNDL_FLOAT getScale();
    MNDL_FLOAT getOriginX();
    MNDL_FLOAT getOriginY();
    MNDL_FLOAT getCenterX();
    MNDL_FLOAT getCenterY();
    MNDL_ITER getMaxIterations();
    void setOriginX(MNDL_FLOAT ox);
    void setOriginY(MNDL_FLOAT oy);
    void setScale(MNDL_FLOAT s);
    void setMaxIterations(MNDL_ITER mi);
    void setCenterX(MNDL_FLOAT cx);
    void setCenterY(MNDL_FLOAT cy);
    void paint(MNDL_FLOAT oX, MNDL_FLOAT oY, MNDL_FLOAT s);
    void setAlpha(uint8_t alpha);
    MNDL_FLOAT getXValue(int x);
    MNDL_FLOAT getYValue(int y);
private:
    uint8_t * buffer;
    long bufferSize;
    int width;
    int height;
    uint8_t alpha;
    uint8_t opacity;
    MNDL_FLOAT colorShift;
    MNDL_FLOAT colorShifted;
    MNDL_FLOAT originX;
    MNDL_FLOAT originY;
    MNDL_FLOAT scale;
    MNDL_FLOAT maxIterations;
    MNDL_ITER getIterationCount(MNDL_FLOAT oReal, MNDL_FLOAT oImaginary);
    void setColor(int x, int y, int iCount);
};


#endif
