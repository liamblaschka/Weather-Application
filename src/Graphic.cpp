#include "Graphic.h"
#include <SFML/Graphics.hpp>

using namespace sf;

// default constructor
Graphic::Graphic() {}

// constructor
Graphic::Graphic(Font& font, Vector2f position) {
    this->font = font;
    this->position = position;
}

// sets the position
void Graphic::set_position(Vector2f position) {
    this->position = position;
}

// returns the position
Vector2f Graphic::get_postion() {
    return position;
}

// checks if the graphic contains the paramater point, could be mouse point
bool Graphic::contains_point(Vector2f point) {
    return hitbox.contains(point);
}