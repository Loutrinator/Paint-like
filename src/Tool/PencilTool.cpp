#include "PencilTool.h"

void PencilTool::update(ShapeRegistry &registry, glm::ivec2 cursorPos, CursorState cursorState) {
    if(cursorState == HELD){
        Line line;
        line.pos1 = _lastCursorPos;
        line.pos2 = cursorPos;
        line.color = _context.getColor();

        registry.lines.push_back(line);
    }
    _lastCursorPos = cursorPos;
}

void PencilTool::drawUI() {

}

std::string PencilTool::getName() {
    return "Pencil";
}
