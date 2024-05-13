#include "WeatherData.h"
#include "ForecastWeatherData.h"
#include "Coordinates.h"
#include <string>
#include <math.h>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using json = nlohmann::json;

// default constructor
ForecastWeatherData::ForecastWeatherData():WeatherData() {}

// constructor
ForecastWeatherData::ForecastWeatherData(Coordinates location, std::string day, Font& font, Vector2f position):WeatherData(location) {
    this->day = day;
    graphic = ForecastWeatherGraphic(font, position, day);
}

// returns the rain chance
int ForecastWeatherData::get_rain_chance() {
    return rain_chance;
}

// sets the rain chance
void ForecastWeatherData::set_rain_chance(int rain_chance){
    this->rain_chance = rain_chance;
    graphic.set_rain_chance(rain_chance);
}

// returns the maximum temperature
int ForecastWeatherData::get_max_temperature() {
    return max_temperature;
}

// sets the maximum temperature
void ForecastWeatherData::set_max_temperature(int max_temperature) {
    this->max_temperature = max_temperature;
    graphic.set_temperatures(min_temperature, max_temperature);
}

// returns the minimum temperature
int ForecastWeatherData::get_min_temperature() {
    return min_temperature;
}

// sets the minimum temperature
void ForecastWeatherData::set_min_temperature(int min_temperature) {
    this->min_temperature = min_temperature;
    graphic.set_temperatures(min_temperature, max_temperature);
}

// returns the day
std::string ForecastWeatherData::get_day() {
    return day;
}

// sets the day
void ForecastWeatherData::set_day(std::string day) {
    this->day = day;
    graphic.set_day(day);
}

// updates the data using the relevant json data
void ForecastWeatherData::update_data(json data) {
    // reads from json data
    icon_id = data["weather"][0]["icon"];
    max_temperature = round(float(data["temp"]["max"]));
    min_temperature = round(float(data["temp"]["min"]));
    rain_chance = float(data["pop"]) * 100;

    // sets the values to the graphics
    graphic.set_icon(icon_id);
    graphic.set_temperatures(min_temperature, max_temperature);
    graphic.set_rain_chance(rain_chance);
}

// draws the graphic onto the window
void ForecastWeatherData::draw(RenderTarget& target, RenderStates states) const {
    target.draw(graphic);
}