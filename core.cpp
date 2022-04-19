#include "core.h"

std::optional<QPointF> getRoundedPos(QPointF originalPos)
{
    auto pos = originalPos;
    pos.setX(round(pos.x() / 100) * 100);
    pos.setY(round(pos.y() / 100) * 100);
    if ((originalPos - pos).manhattanLength() > 40)
        return {};
    return pos;
}
