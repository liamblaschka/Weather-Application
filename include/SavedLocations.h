#pragma once
#include "Location.h"
#include "LocationList.h"

// represents the saved locations which are saved to a csv file, inherits from LocationList as uses
// much of its functionality
class SavedLocations : public LocationList {
    private:
        sf::Font font;
        int position_mode;
    public:
        // constructor. also needs font paramater as unlike LocationList, this class creates Location
        // objects itself within the class at initialisation and with some of its functions
        SavedLocations(int size, sf::Font& font);

        // adds paramater location to the list of locations and the csv file
        void add_location(Location location) override;

        // removes location of paramater index to the list of locations and the csv file
        void remove_location(int index) override;

        // moves the location of the paramater original index to the paramater new index and adjusts the other
        // locations of the list accordingly, also does so in csv file
        void move_location(int original_index, int new_index) override;

        // returns the position mode, position mode indicates the different (two) modes of position the graphical locaitons
        // can be
        int get_position_mode();

        // sets the positon mode to paramater value
        void set_position_mode(int position_mode);
};