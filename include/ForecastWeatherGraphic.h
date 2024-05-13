#pragma once
#include "Graphic.h"
#include "WeatherGraphic.h"
#include <string>
#include <SFML/Graphics.hpp>

// represents the graphic of the forecast weather data
class ForecastWeatherGraphic : public WeatherGraphic {
    private:
        int min_temperature;
        int max_temperature;
        int rain_chance;
        std::string day;
        sf::Text rain_chance_text;
        sf::Texture rain_drop_texture;
        sf::Sprite rain_drop_icon;
        sf::Text day_text;
    public:
        // constructors
        ForecastWeatherGraphic();
        ForecastWeatherGraphic(sf::Font& font, sf::Vector2f position, std::string day);

        // sets the icon according to the paramater icon_id
        void set_icon(std::string icon_id) override;

        // returns the minimum temperature
        int get_min_temperature();

        // sets the minimum and maximum temperatures of the graphic to those in the paramaters
        void set_temperatures(int min_temperature, int max_temperature);

        // returns the rain chance
        int get_rain_chance();

        // sets the rain chance of the graphic to the inputted paramater
        void set_rain_chance(int rain_chance);

        // returns the day the forecast weather graphic is displaying
        std::string get_day();

        // sets the day of the graphic with the paramater
        void set_day(std::string day);

        // draws the graphic onto the window
        void draw(sf::RenderTarget&, sf::RenderStates states) const override;
};