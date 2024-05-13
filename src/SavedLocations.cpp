#include "Location.h"
#include "LocationList.h"
#include "SavedLocations.h"
#include "Coordinates.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace sf;

// constructor
SavedLocations::SavedLocations(int size, Font& font):LocationList(size) {
    std::ifstream file("saved_locations.csv"); // opens the saved locations csv

    // if there was a csv file, reads its data and adds the saved locations to locations array
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::string location_string;
            Coordinates location_coordinates;
            std::stringstream line_stream(line);
            std::string column;
            int i = 0;
            while (getline(line_stream, column, ',')) {
                switch (i) {
                    case 0:
                        location_string = column;
                        break;
                    case 1:
                        location_coordinates.x = stod(column);
                        break;
                    case 2:
                        location_coordinates.y = stod(column);
                        break;
                }
                i++;
            }
            locations[count] = Location(font, Vector2f(10, 75 + (35 * count)), location_string, location_coordinates);
            count++;
        }

    // if there was no existing csv file, creates one
    } else {
        std::ofstream file("saved_locations.csv");
        count = 0;
    }
    file.close();

    position_mode = 0;
}

// adds the paramater location to the locations list and the csv file
void SavedLocations::add_location(Location location) {
    if (count < size) {
        // adds to csv
        std::ofstream file("saved_locations.csv", std::ios::app);
        file << location.get_string() << "," << location.get_coordinates().x << "," << location.get_coordinates().y << "\n";
        file.close();
        if (position_mode == 0) {
            location.set_position(Vector2f(10, 75 + (35 * count)));
        } else {
            location.set_position(Vector2f(10, 110 + (35 * count)));
        }

        LocationList::add_location(location); // handles adding to locations lisr
    }
}

// removes the paramater index locaiton from the list
void SavedLocations::remove_location(int index) {
    // removes from csv
    std::ifstream file_old("saved_locations.csv");
    std::ofstream file_new("new_saved_locations.csv", std::ios::app);
    std::string line;
    int i = 0;
    //
    while (getline(file_old, line)) {
        if (i != index) {
            file_new << line << "\n";
        }

        i++;
    }
    file_old.close();
    file_new.close();
    remove("saved_locations.csv");
    rename("new_saved_locations.csv", "saved_locations.csv");

    LocationList::remove_location(index); // handles removing from list
}

// moves location from original index to a new index
void SavedLocations::move_location(int original_index, int new_index) {
    LocationList::move_location(original_index, new_index); // moves the location in locations array

    // deletes csv, makes new empty csv and copies the new array to the csv
    remove("saved_locations.csv");
    std::ofstream file("saved_locations.csv", std::ios::app);
    for (int i = 0; i < count; i++) {
        file << locations[i].get_string() << "," << locations[i].get_coordinates().x << "," << locations[i].get_coordinates().y << "\n";
    }
    file.close();
}

// returns the position mode
int SavedLocations::get_position_mode() {
    return position_mode;
}

// sets the position mode (how high or low the location graphics are positioned in the window)
void SavedLocations::set_position_mode(int position_mode) {
    this->position_mode = position_mode;
    if (position_mode == 0) {
        for (int i = 0 ; i < count; i++) {
            locations[i].set_position(Vector2f(10, 75 + (35 * i)));
        }
    } else if (position_mode == 1) {
        for (int i = 0 ; i < count; i++) {
            locations[i].set_position(Vector2f(10, 110 + (35 * i)));
        }
    }
}