#pragma once
#include "WeatherData.h"
#include "CurrentWeatherData.h"
#include "ForecastWeatherData.h"
#include "Coordinates.h"

class WeatherDataSet : public sf::Drawable {
    private:
        WeatherData** weather_data_list;
        int count;
        std::string week_days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        Coordinates location;
    public:
        WeatherDataSet(Coordinates location, sf::Font& font);
        void add_weather_data(WeatherData* data);
        void remove_weather_data(int index);
        int get_count();
        static std::size_t write_memory_callback(void *contents, std::size_t size, std::size_t nmemb, std::string *str);
        int update_data();
        void set_location(Coordinates location);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        ~WeatherDataSet();
};