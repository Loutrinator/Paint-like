#ifndef SETTINGS_H
#define SETTINGS_H

#include <imgui.h>

enum DrawMode{
    POINT, LINE, POLYGON, PAINTER
};

class Settings {
public:
    Settings();
    DrawMode getDrawMode();
    float* getColor();
    void changeColor();

private:
    float* _currentColor;
    DrawMode _drawMode;
};

#endif //SETTINGS_H
