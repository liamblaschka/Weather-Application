#include "WeatherData.h"
#include "Coordinates.h"
#include  <string>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
using json = nlohmann::json;

// default constructor
WeatherData::WeatherData() {}

// constructor
WeatherData::WeatherData(Coordinates location) {
    this->location = location;
}

// returns the icon id
std::string WeatherData::get_icon_id() {
    return icon_id;
}

// virtual destructor definition to callback to
WeatherData::~WeatherData() {}