#pragma once
#include "Coordinates.h"
#include <string>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

// represents a common interface for weather data, (is base class of ForecastWeatherData and CurrentWeatherData),
// is also an abstract function
class WeatherData : public sf::Drawable {
    protected:
        std::string icon_id;
        Coordinates location;

    public:
        // constructors
        WeatherData();
        WeatherData(Coordinates location);

        // returns the icon id as a string, the icons for the graphic have different ids provided by the API
        std::string get_icon_id();

        // updates the weather data from the inputted relevant data of the data sourced by the API, pure virtual function
        virtual void update_data(nlohmann::json data) = 0;

        // virtual function to return temperature, here it returns 0
        virtual int get_temperature() { return 0; }

        // virtual function to set the temperature to paramater value, here is empty 
        virtual void set_temperature(int temperature) {}

        // virtual function to return the rain chance, here it returns 0
        virtual int get_rain_chance() { return 0; }

        // virtual function to set the rain chance to paramater value, here it is empty
        virtual void set_rain_chance(int rain_chance) {}

        // virtual function to return the maximum temperature, here it returns 0
        virtual int get_max_temperature() { return 0; }

        // virtual function to set the maximum temperature to the paramater value, here is empty
        virtual void set_max_temperature(int max_temperature) {}

        // virtual function to return the minimum temperature, here it returns 0
        virtual int get_min_temperature() { return 0; }

        // virtual function to set the minimum temperature to the paramater value, here it is empty
        virtual void set_min_temperature(int min_temperature) {}

        // virtual function to return the day of the (forecast) weather data, here returns empty string
        virtual std::string get_day() { return ""; }

        // virtual function to set the day to paramater value, here it is empty
        virtual void set_day(std::string day) {}

        // virtual function to draw the weather data's graphic onto the window (pure virtual function)
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        // virtual destructor as this class is used for polymorphism
        virtual ~WeatherData() = 0;
};