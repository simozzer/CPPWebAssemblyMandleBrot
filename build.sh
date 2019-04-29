rm build/ -rf
mkdir build
cd build
em++ ../cpp/src/hello.cpp ../cpp/src/mandle.cpp -I ../cpp/include/ -std=c++11 -g -O3 -s EXPORTED_FUNCTIONS="[_new_mandle,_getBuffer,_paint,_getCenterX,_getCenterY,_getOriginX,_getOriginY,_getMaxIterations,_setMaxIterations,_getScale,_getXValue,_getYValue]" -s WASM=1 -o hello.js
mv hello.js ../web/gen/
mv hello.wasm ../web/gen/
mv hello.wasm.map ../web/gen
mv hello.wast ../web/gen
