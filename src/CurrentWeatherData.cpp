#include "WeatherData.h"
#include "CurrentWeatherData.h"
#include <math.h>
#include <nlohmann/json.hpp>
#include "Coordinates.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using json = nlohmann::json;

// default constructor
CurrentWeatherData::CurrentWeatherData():WeatherData() {}

// constructor
CurrentWeatherData::CurrentWeatherData(Coordinates location, Font& font, Vector2f position):WeatherData(location) {
    // sets the graphic
    graphic = CurrentWeatherGraphic(font, position);
}

// returns the temperature
int CurrentWeatherData::get_temperature() {
    return temperature;
}

// sets the temperature
void CurrentWeatherData::set_temperature(int temperature) {
    this->temperature = temperature;
}

// updates the weather data and graphic using relevant json data from data returned by the API
void CurrentWeatherData::update_data(json data) {
    icon_id = data["weather"][0]["icon"];
    temperature = round(float(data["temp"]));
    graphic.set_icon(icon_id);
    graphic.set_temperature(temperature);
}

// draws the graphic onto the window
void CurrentWeatherData::draw(RenderTarget& target, RenderStates states) const {
    target.draw(graphic);
}