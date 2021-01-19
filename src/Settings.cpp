#include "Settings.h"

Settings::Settings() : _currentColor(new float[]{1.0, 0.0, 0.0}), _drawMode(POINT) {

}

DrawMode Settings::getDrawMode() {
    return _drawMode;
}

float* Settings::getColor() {
    return _currentColor;
}

void Settings::changeColor() {
    ImGui::ColorEdit3("Change color", _currentColor);
}
