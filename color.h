#pragma once

enum class color { RED, ORANGE, YELLOW, GREEN, LIGHT_BLUE, BLUE, VIOLET };
const color colors[7]{ color::RED, color::ORANGE, color::YELLOW, color::GREEN, color::LIGHT_BLUE, color::BLUE, color::VIOLET };

inline std::ostream& operator<<(std::ostream& out, const color& bi) {
    switch (bi) {
    case color::BLUE:
        out << "BLUE";
        break;
    case color::GREEN:
        out << "GREEN";
        break;
    case color::RED:
        out << "RED";
        break;
    case color::ORANGE:
        out << "ORANGE";
        break;
    case color::YELLOW:
        out << "YELLOW";
        break;
    case color::LIGHT_BLUE:
        out << "LIGHT_BLUE";
        break;
    case color::VIOLET:
        out << "VIOLET";
        break;
    }
    return out;
}