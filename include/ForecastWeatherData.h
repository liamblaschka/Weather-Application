#pragma once
#include "WeatherData.h"
#include "ForecastWeatherGraphic.h"
#include "Coordinates.h"
#include <string>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

// represents the forecast weather data
class ForecastWeatherData : public WeatherData {
    private:
        int max_temperature;
        int min_temperature;
        int rain_chance;
        std::string day;
        ForecastWeatherGraphic graphic;
    public:
        // constructors
        ForecastWeatherData();
        ForecastWeatherData(Coordinates location, std::string day, sf::Font& font, sf::Vector2f position);

        // returns the rain chance
        int get_rain_chance() override;

        // sets the rain chance to the paramater value
        void set_rain_chance(int rain_chance) override;

        // returns the maximum temperature
        int get_max_temperature() override;

        // sets the maximum temperature to paramater value
        void set_max_temperature(int max_temperature) override;

        // returns the minimum temperature
        int get_min_temperature() override;

        // sets the minimum temperature to paramater value 
        void set_min_temperature(int min_temperature) override;

        // returns the day for the forecasted data as a string
        std::string get_day() override;

        // sets the day of the data using paramater string
        void set_day(std::string day) override;

        // updates the data using the relevant json data of the data sourced from the API
        void update_data(nlohmann::json data) override;

        // draws the graphic of the forecast data to the window
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // virtual destructor
        ~ForecastWeatherData() {}
};