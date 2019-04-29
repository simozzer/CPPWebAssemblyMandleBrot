#include "mandle.h"

/*
MNDL_FLOAT Mandle::sinLow(MNDL_FLOAT x) {
    if (x < -3.14159265) 
        x += 6.28318531;
    else if (x >  3.14159265) 
        x -= 6.28318531;
    
    if (x < 0) 
        return 1.27323954 * x + .405284735 * x * x;
    else 
        return 1.27323954 * x - 0.405284735 * x * x;
}
*/

Mandle::Mandle(int w, int h) 
{
    width = w;
    height = h;
    bufferSize = w * h * 4;
    scale = 2.5;
    originX = -1.75;
    originY = -1.25;
    alpha = 255;
    maxIterations = 255;
    colorShift = 0.005;
    colorShifted = 0.0;

    opacity = 160;
    buffer = new uint8_t[bufferSize];
}

uint8_t * Mandle::getBuffer()
{
    return &buffer[0];
}

Mandle::~Mandle()
{
    delete buffer;
}

long Mandle::getBufferSize()
{
    return bufferSize;
}

MNDL_FLOAT Mandle::getScale()
{
    return scale;
}

MNDL_FLOAT Mandle::getOriginX()
{
    return originX;
}

MNDL_FLOAT Mandle::getOriginY()
{
    return originY;
}

MNDL_FLOAT Mandle::getCenterX()
{
    return originX + (0.5 * scale);
}

MNDL_FLOAT Mandle::getCenterY()
{
    return originY + (0.5 * scale);
}

MNDL_ITER Mandle::getMaxIterations()
{
    return maxIterations;
}

void Mandle::setOriginX(MNDL_FLOAT ox)
{
    originX = ox;
}

void Mandle::setOriginY(MNDL_FLOAT oy)
{
    originY = oy;
}

void Mandle::setScale(MNDL_FLOAT s)
{
    scale = s;
}

void Mandle::setMaxIterations(MNDL_ITER mi)
{
    maxIterations = mi;
}

void Mandle::setCenterX(MNDL_FLOAT cx)
{
    //TODO::
}

void Mandle::setCenterY(MNDL_FLOAT cy)
{
    //TODO::
}

void Mandle::setAlpha(uint8_t a) 
{
    alpha = a;
}

MNDL_FLOAT Mandle::getXValue(int x)
{
    return originX + ((MNDL_FLOAT)x * scale/width);
}

MNDL_FLOAT Mandle::getYValue(int y)
{
    return originY + ((MNDL_FLOAT)y * scale/height);
}

void Mandle::paint(MNDL_FLOAT oX, MNDL_FLOAT oY, MNDL_FLOAT s)
{
    originX = oX;
    originY = oY;
    scale = s;
    colorShifted += colorShift;
    if (colorShifted >= 1.0) {
        colorShifted = colorShifted - 1.0;
    }
    
    
    for (int y =0; y < height; y++) 
    {
        for (int x =0; x < width; x++) 
        {
            MNDL_FLOAT xReal = getXValue(x);
            MNDL_FLOAT yImaginary = getYValue(y);
            MNDL_ITER iCount = getIterationCount(xReal,yImaginary);
            setColor(x,y,iCount);
        }
    }
}

void Mandle::setColor(int x, int y, int iCount)
{
  double dClr = iCount/maxIterations;

	int offset = 4 * (x + (y * width));

    
    if (dClr == 0) {
        buffer[offset] = 0;
        buffer[offset+1] = 0;
        buffer[offset+2] = 0;
        buffer[offset+3] = opacity;
    } else {
        
        
        dClr = dClr + colorShifted;
        if (dClr > 1) {
            dClr = dClr -1;
        }
        
        uint8_t r =0;
        uint8_t g = 0;
        uint8_t b = 0;
        
        if (dClr <= 0.5) {
            // contains red
            if (dClr <= 0.25) {
                r = dClr * 255 * 4;
            } else {
                r = 255 - (dClr * 255 *4);
            }
        }
        buffer[offset] = r;
        
        if ((dClr >= 0.25) && (dClr <= 0.75)) {
            // contains green
            if (dClr < 0.5) {
                g = (dClr - 0.25) * 255 * 4;
            } else {
                g = 255 - ((dClr - 0.5) * 255 *  4);
            }
        }
        buffer[offset+1] = g;
        
        if (dClr >= 0.5) {
            // contains blue
            if (dClr <= 0.75) {
                b = (dClr - 0.5) * 255 * 4;
            } else {
                b = 255 - ((dClr - 0.75) * 255 * 4);
            }
            buffer[offset+2] = b;
            
        } else {
            buffer[offset+2] = 0;
        }
    // buffer[offset+2] = dClr/512;
        buffer[offset+3] = opacity;
    }
}

MNDL_ITER Mandle::getIterationCount(MNDL_FLOAT oReal, MNDL_FLOAT oImaginary)
{
   
    MNDL_FLOAT zReal = 0;
    MNDL_FLOAT zImaginary = 0;
    MNDL_FLOAT zrsqr = zReal * zReal;
    MNDL_FLOAT zisqr = zImaginary * zImaginary;
    MNDL_ITER iterCount = 0;
    while ((zrsqr + zisqr <= 4.0) && (iterCount < maxIterations))
    {
        zImaginary = zReal * zImaginary;
        zImaginary += zImaginary; // Multiply by two
        zImaginary += oImaginary;
        zReal = zrsqr - zisqr + oReal;
        zrsqr = zReal * zReal;
        zisqr = zImaginary * zImaginary;
        iterCount++;
    }
    
    if (iterCount <= maxIterations)
    {
        return iterCount;
    }
    else
    {
        return 0;
    }
    
}

