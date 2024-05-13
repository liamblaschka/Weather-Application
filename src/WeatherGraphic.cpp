#include "WeatherGraphic.h"
#include "Graphic.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

// default constructor
WeatherGraphic::WeatherGraphic() {}

// constructor
WeatherGraphic::WeatherGraphic(Font& font, Vector2f position):Graphic(font, position) {
    this->font = font;
    this->position = position;

    // load weather icon texture
    // weather icons source: https://www.npmjs.com/package/weather-underground-icons
    weather_icons.loadFromFile("../../assets/weather_icons.png");
    weather_icons.setSmooth(true);

    icon.setPosition(position); // set icon positoin
}

// return the position of the weather graphic in the window
Vector2f WeatherGraphic::get_position() {
    return position;
}

// sets the position of the weather graphic in the window
void WeatherGraphic::set_position(Vector2f position) {
    this->position = position;
    icon.setPosition(position);
}

// returns the icon id
std::string WeatherGraphic::get_icon_id() {
    return icon_id;
}

// sets the icon of the graphic associated with its id
void WeatherGraphic::set_icon(std::string icon_id) {
    this->icon_id = icon_id;
    if (icon_id == "01d" || icon_id == "01n") {
        // sunny
        icon = Sprite(weather_icons, IntRect(0, 196, 196, 196));
    } else if (icon_id == "02d" || icon_id == "02n") {
        // partly cloudy
        icon = Sprite(weather_icons, IntRect(0, 384, 196, 196));
    } else if (icon_id == "03d" || icon_id == "03n" || icon_id == "04d" || icon_id == "04n") {
        // cloudy
        icon = Sprite(weather_icons, IntRect(196, 196, 196, 196));
    } else if (icon_id == "09d" || icon_id == "09n") {
        // shower rain
        icon = Sprite(weather_icons, IntRect(196, 0, 196, 196));
    } else if (icon_id == "10d" || icon_id == "10n") {
        // rain
        icon = Sprite(weather_icons, IntRect(768, 384, 196, 196));
    } else if (icon_id == "11d" || icon_id == "11n") {
        // thunderstorm
        icon = Sprite(weather_icons, IntRect(768, 0, 196, 196));
    } else if (icon_id == "13d" || icon_id == "13n") {
        // snow
        icon = Sprite(weather_icons, IntRect(196, 576, 196, 196));
    } else if (icon_id == "50d" || icon_id == "50n") {
        // mist
        icon = Sprite(weather_icons, IntRect(768, 196, 196, 196));
    } else {
        // unknown
        icon = Sprite(weather_icons, IntRect(768, 576, 196, 196));
    }
}