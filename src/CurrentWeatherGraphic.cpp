#include "Graphic.h"
#include "WeatherGraphic.h"
#include "CurrentWeatherGraphic.h"
#include <SFML/Graphics.hpp>

using namespace sf;

// default constructor
CurrentWeatherGraphic::CurrentWeatherGraphic():WeatherGraphic() {}

// constructor
CurrentWeatherGraphic::CurrentWeatherGraphic(Font& font, Vector2f position):WeatherGraphic(font, position) {
    // sets the font, size and position of the temperature text
    temperature_text.setFont(font);
    temperature_text.setCharacterSize(45);
    temperature_text.setPosition(Vector2f(position.x + 180, position.y + 60));
}

// sets the graphic icon using the icon id
void CurrentWeatherGraphic::set_icon(std::string icon_id) {
    WeatherGraphic::set_icon(icon_id); // runs the same function of the base class to set icon
    icon.setPosition(position); // sets positon of icon
}

// returns the temperature
int CurrentWeatherGraphic::get_temperature() {
    return temperature;
}

// sets the temperature variable, and updates the graphic
void CurrentWeatherGraphic::set_temperature(int temperature) {
    this->temperature = temperature;
    temperature_text.setString(std::to_string(temperature) + String(Uint32(176)));
}

// sets the postion variable and position of the graphic in the window
void CurrentWeatherGraphic::set_position(Vector2f position) {
    this->position = position;
    icon.setPosition(position);
    temperature_text.setPosition(Vector2f(position.x + 180, position.y + 60));
}

// draws the graphic to the window
void CurrentWeatherGraphic::draw(RenderTarget& target, RenderStates states) const {
    target.draw(icon);
    target.draw(temperature_text);
}