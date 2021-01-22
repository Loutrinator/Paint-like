#ifndef PENCILTOOL_H
#define PENCILTOOL_H


#include "ITool.h"

class PencilTool : public ITool{
public:
    using ITool::ITool;

    void update(ShapeRegistry& registry, glm::ivec2 cursorPos, CursorState cursorState) override;
    void drawUI() override;
    std::string getName() override;

private:
    glm::ivec2 _lastCursorPos;
};


#endif //PENCILTOOL_H
