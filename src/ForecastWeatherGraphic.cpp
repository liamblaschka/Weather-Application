#include "WeatherGraphic.h"
#include "ForecastWeatherGraphic.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

// default constructor
ForecastWeatherGraphic::ForecastWeatherGraphic():WeatherGraphic() {}

// constructor
ForecastWeatherGraphic::ForecastWeatherGraphic(Font& font, Vector2f position, std::string day):WeatherGraphic(font, position) {
    // sets the day text graphic
    day_text.setFont(font);
    day_text.setString(day);
    day_text.setCharacterSize(25);
    day_text.setPosition(position.x - 70, position.y + 10);

    // sets the graphic of the temperature text (max and min temps)
    temperature_text.setFont(font);
    String degree_symbol(Uint32(176));
    temperature_text.setCharacterSize(23);
    temperature_text.setPosition(position.x + 65, position.y + 11);

    // sets the rain chance graphic
    rain_chance_text.setFont(font);
    rain_chance_text.setCharacterSize(23);
    rain_chance_text.setPosition(position.x + 280, position.y + 11);
    // modified image from source: https://www.flaticon.com/free-icon/raindrop_223476
    rain_drop_texture.loadFromFile("../../assets/rain_drop_icon.png");
    rain_drop_texture.setSmooth(true);
}

// sets the icon associated with the icon id
void ForecastWeatherGraphic::set_icon(std::string icon_id) {
    WeatherGraphic::set_icon(icon_id); // runs same function from base class to set icon
    icon.setScale(Vector2f(0.3, 0.3)); // set icon scale
    icon.setPosition(position); // set icon postion
}

// returns the minimum temperature
int ForecastWeatherGraphic::get_min_temperature() {
    return min_temperature;
}

// sets the minimum and maximum temperatures
void ForecastWeatherGraphic::set_temperatures(int min_temperature, int max_temperature) {
    this->min_temperature = min_temperature;
    this->max_temperature = max_temperature;
    String degree_symbol(Uint32(176)); // sets the Uint32 value of the degree symbol
    temperature_text.setString("Min: " + std::to_string(min_temperature) + degree_symbol + "  Max: " + std::to_string(max_temperature) + degree_symbol);
}

// returns the rain chance
int ForecastWeatherGraphic::get_rain_chance() {
    return rain_chance;
}

// sets the rain chance
void ForecastWeatherGraphic::set_rain_chance(int rain_chance) {
    this->rain_chance = rain_chance;

    // if the rain chance is greater than 0, sets the graphic for the rain chance
    if (rain_chance > 0) {
        rain_chance_text.setString(std::to_string(rain_chance) + "%");
        rain_drop_icon = Sprite(rain_drop_texture);
        rain_drop_icon.setScale(Vector2f(0.6, 0.6));
        rain_drop_icon.setPosition(position.x + 255, position.y + 17);
    }
}

// returns the day
std::string ForecastWeatherGraphic::get_day() {
    return day;
}

// sets the day
void ForecastWeatherGraphic::set_day(std::string day) {
    this->day = day;
    day_text.setString(day);
}

// draws the graphic to the window
void ForecastWeatherGraphic::draw(RenderTarget& target, RenderStates states) const {
    target.draw(icon);
    target.draw(day_text);
    target.draw(temperature_text);

    // if the rain chance is greater than 0, draws the rain chance
    if (rain_chance > 0) {
        target.draw(rain_drop_icon);
        target.draw(rain_chance_text);
    }
}