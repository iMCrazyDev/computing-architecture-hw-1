#pragma once

enum class color { RED, ORANGE, YELLOW, GREEN, LIGHT_BLUE, BLUE, VIOLET };
const color colors[7]{ color::RED, color::ORANGE, color::YELLOW, color::GREEN, color::LIGHT_BLUE, color::BLUE, color::VIOLET };

inline std::string getColor(const color& bi) {
    switch (bi) {
    case color::BLUE:
        return "BLUE";
        break;
    case color::GREEN:
        return "GREEN";
        break;
    case color::RED:
        return "RED";
        break;
    case color::ORANGE:
        return "ORANGE";
        break;
    case color::YELLOW:
        return "YELLOW";
        break;
    case color::LIGHT_BLUE:
        return "LIGHT_BLUE";
        break;
    case color::VIOLET:
        return "VIOLET";
        break;
    }
    return "";
}