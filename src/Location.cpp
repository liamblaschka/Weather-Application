#include "Location.h"
#include "Coordinates.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

// default constructor
Location::Location() {}

// constructor
Location::Location(Font& font, Vector2f position, std::string location, Coordinates coordinates) {
    this->location = location;
    this->coordinates = coordinates;
    this->position = position;

    is_hidden = false;
    text_style = Text::Regular;

    text.setFont(font);
    text.setString(location);
    text.setFillColor(Color::White);
    text.setPosition(position);

    hitbox = text.getGlobalBounds();
}

// return string
std::string Location::get_string() {
    return location;
}

// set the string
void Location::set_string(std::string location) {
    this->location = location;
    text.setString(location);
}

// set the style of the text graphic
void Location::set_style(Uint32 style) {
    text_style = style;
    text.setStyle(style);
    hitbox = text.getGlobalBounds();
}

// return the coordinates of the location (latitiude, longitude)
Coordinates Location::get_coordinates() {
    return coordinates;
}

// set the coordinates of the location
void Location::set_coordinates(Coordinates coordinates) {
    this->coordinates = coordinates;
}

// activates the location graphic
void Location::activate(Uint32 style) {
    this->is_activated = true;
    text.setStyle(text_style | style);
}

// deactivates the location graphic
void Location::deactivate() {
    this->is_activated = false;
    text.setStyle(text_style);
}

// returns the bool for is activated
bool Location::get_is_activated() {
    return is_activated;
}

// sets the position
void Location::set_position(Vector2f position) {
    this->position = position;
    text.setPosition(position);
    hitbox = text.getGlobalBounds();
}

// returns the position
Vector2f Location::get_position() {
    return position;
}

// returns the hitbox, used to determine size of the text graphic
FloatRect Location::get_hitbox() {
    return hitbox;
}

// returns is hidden, is hidden can hide the location graphic instead of deleting it,
// for example if used in a list
bool Location::get_is_hidden() {
    return is_hidden;
}

// sets is hidden
void Location::set_is_hidden(bool is_hidden) {
    this->is_hidden = is_hidden;
}

// draws the location graphic onto the window
void Location::draw(RenderTarget& target, RenderStates states) const {
    target.draw(text);
}