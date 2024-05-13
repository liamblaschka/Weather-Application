#pragma once
#include "WeatherData.h"
#include "CurrentWeatherGraphic.h"
#include "Coordinates.h"
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

// class represents the current weather data
class CurrentWeatherData : public WeatherData {
    private:
        int temperature;
        CurrentWeatherGraphic graphic;
    public:
        // constructors
        CurrentWeatherData();
        CurrentWeatherData(Coordinates location, sf::Font& font, sf::Vector2f position);

        // returns the temperature
        int get_temperature() override;

        // sets the temperature
        void set_temperature(int temperature) override;

        // updates the weather data from the relevant json data inputted into paramater
        void update_data(nlohmann::json data) override;

        // draws the graphic for the current weather data to the window
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // virtual destrcutor as is used with polymorphism
        ~CurrentWeatherData() {}
};