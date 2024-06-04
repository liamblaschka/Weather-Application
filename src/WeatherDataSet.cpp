#include "WeatherData.h"
#include "CurrentWeatherData.h"
#include "ForecastWeatherData.h"
#include "WeatherDataSet.h"
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Coordinates.h"
#include <fstream>
#include <iostream>

using namespace sf;
using json = nlohmann::json;

// constructor
WeatherDataSet::WeatherDataSet(Coordinates location, Font& font) {
    this->location = location;

    // sets weather data objects of array, determines the current day of the week, and also,
    // the following days of the week
    time_t current_time = time(0);
    struct tm* local_time = localtime(&current_time);
    int current_day_index = local_time->tm_wday;

    count = 8;
    weather_data_list = new WeatherData*[count];

    weather_data_list[0] = new CurrentWeatherData(location, font, Vector2f(85, 20));
    weather_data_list[1] = new ForecastWeatherData(location, "Today", font, Vector2f(80, 190));
    for (int i = 2; i < 8; i++) {
        weather_data_list[i] = new ForecastWeatherData(location, week_days[(current_day_index + i - 1) % 7], font, Vector2f(80, 190 + ((i - 1) * 50)));
    }
}

// adds a weather data object by reference
void WeatherDataSet::add_weather_data(WeatherData* data) {
    if (count < 8) {
        weather_data_list[count] = data;
    }
}

// removed a weather data object
void WeatherDataSet::remove_weather_data(int index) {
    if (count > index) {
        delete weather_data_list[index];
        count--;

        for (int i = index; i < count; i++) {
            weather_data_list[i] = weather_data_list[i + 1];
        }
    }
}

// returns the number of weather data objects in the weather data list
int WeatherDataSet::get_count() {
    return count;
}

// sets the location of the weather data
void WeatherDataSet::set_location(Coordinates location) {
    this->location = location;
}

size_t WeatherDataSet::write_memory_callback(void *contents, size_t size, size_t nmemb, std::string *str) { // used in storing json data returned by API as string
    size_t real_size = size * nmemb;
    try {
        str->append((char*)contents, real_size);
    } catch (std::bad_alloc &e) {
        std::cout << "Memory allocation error." << std::endl;
        return -1;
    }
    return real_size;
}

int WeatherDataSet::update_data() {
    // determines the current day of the week, and the following days of teh week
    time_t current_time = time(0);
    struct tm* local_time = localtime(&current_time);
    int current_day_index = local_time->tm_wday;
    if (local_time->tm_wday != current_day_index) {
        for (int i = 2; i < 8; i++) {
            weather_data_list[i]->set_day(week_days[(current_day_index + i - 1) % 7]);
        }
    }

    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        std::cout << "HTTP request failed" << std::endl;
        return -1;
    }
    CURLcode result;
    std::string data_literal;

    // retreives API data from OpenWeatherMap API, and stores it in string data_literal
    std::string url = "api.openweathermap.org/data/2.5/onecall?lat=" + std::to_string(location.x) + "&lon="
                    + std::to_string(location.y) + "&exclude=hourly,minutely&units=metric&appid=103423645f4a2cd6fd178dc0d3da0097";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data_literal);
    result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        std::cout << "Error: " << curl_easy_strerror(result) << std::endl;
        return -1;
    }

    curl_easy_cleanup(curl);

    // parses the json data in the string data_literal to json object data
    json data = json::parse(data_literal);

    // updates the current weather data with the relevant data from the json data retreived from API
    weather_data_list[0]->update_data(data["current"]);

    // updates the forecast weather data with the relevant "daily" data
    // from  the json data retreived from the API
    for (int i = 1; i < count; i++) {
        weather_data_list[i]->update_data(data["daily"][i - 1]);
    }

    // write prettified JSON to another file
    std::ofstream o("pretty.json");
    o << std::setw(4) << data << std::endl;
    o.close();

    return 0;
}

// draws graphic for each of the weather data objects in the weather data list to the window
void WeatherDataSet::draw(RenderTarget& target, RenderStates states) const {
    for (int i = 0; i < count; i++) {
        target.draw(*weather_data_list[i]);
    }
}

// destructor to free dynamically allocated memory
WeatherDataSet::~WeatherDataSet() {
    // free memory allocated for each weather data object of the list
    for (int i = 0; i < count; i++) {
        delete weather_data_list[i];
    }

    // free memory allocated to the weather_data_list
    delete[] weather_data_list;
}