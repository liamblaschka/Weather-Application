#include "User.h"
#include "Coordinates.h"
#include <string>
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// constructor
User::User() {
    update_location(); // updates the user's location
}

// returns the location string (name)
string User::get_location_string() {
    return location_string;
}

// returns the coordinates (latitude, longitude) of the location
Coordinates User::get_location_coordinates() {
    return location_coordinates;
}

// the code of the following functions (write_memory_callback() and update_location()) largely was sourced, and took contributtion
// from these sources: https://www.youtube.com/watch?v=mJVchgjkgL8, https://www.appsloveworld.com/c/100/2/c-libcurl-get-output-into-a-string
size_t User::write_memory_callback(void *contents, size_t size, size_t nmemb, string *str) { // used in process of storing json API data in string
    size_t real_size = size * nmemb;
    try {
        str->append((char*)contents, real_size);
    } catch (bad_alloc &e) {
        cout << "Memory allocation error." << endl;
        return -1;
    }
    return real_size;
}

// updates the user's location
int User::update_location() {
    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        cout << "HTTP request failed" << endl;
        return -1;
    }
    CURLcode result;
    string data_literal;

    // retreive API data and place in string data_literal
    curl_easy_setopt(curl, CURLOPT_URL, "https://ipinfo.io/json");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data_literal);
    result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        cout << "Error: " << curl_easy_strerror(result) << endl;
        return -1;
    }

    curl_easy_cleanup(curl);

    // set json object data as parsed data of data_literal string
    json data = json::parse(data_literal);

    // access required data, setting to variables
    location_string = data["city"];
    string combined_coords = data["loc"];
    stringstream combined_coords_stream(combined_coords);
    string coordinate;
    int i = 0;
    while (getline(combined_coords_stream, coordinate, ',')) {
        if (i == 0) {
            location_coordinates.x = stod(coordinate);
        } else {
            location_coordinates.y = stod(coordinate);
        }
        i++;
    }

    return 0;
}