#include "LocationList.h"
#include "Location.h"
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

// constructor
LocationList::LocationList(int size) {
    this-> size = size;
    locations = new Location[size];
    count = 0;
}

// returns the size of the list
int LocationList::get_size() {
    return size;
}

// returns the number of locations in the list
int LocationList::get_count() {
    return count;
}

// adds the paramater locaiton to the list
void LocationList::add_location(Location location) {
    if (count < size){
        locations[count] = location;
        count++;
    }
}

// removes a location of paramater index from the list
void LocationList::remove_location(int index) {
    if (count > index) {
        locations[index] = Location(); // sets to empty location
        count--;

        // adjusts the list accordingly
        for (int i = index; i < count; i++) {
            locations[i] = locations[i + 1];
        }
    }
}

// moves a location of paramater original index to paramater new index
void LocationList::move_location(int original_index, int new_index) {
    if (new_index < count) {
        Location location = locations[original_index];
        
        // if new index is less than original, shift down
        if (new_index < original_index) {
            for (int i = original_index; i > new_index; i--) {
                locations[i] = locations[i - 1];
            }
            locations[new_index] = location;
        } 
        // else if new index is greater than the original, shift up
        else {
            for (int i = original_index; i < new_index; i++) {
                locations[i] = locations[i + 1];
            }
            locations[new_index] = location;
        }
    }
}

// returns the location at paramater index in the list
Location LocationList::get_location(int index) {
    return locations[index];
}

// returns the string (name) of the location at the paramater index
std::string LocationList::get_string(int index) {
    return locations[index].get_string();
}

// returns the positon at the paramater index
Vector2f LocationList::get_position(int index) {
    return locations[index].get_position();
}

// sets the postion of the locaiton in the list at the inputted index
void LocationList::set_position(int index, Vector2f position) {
    locations[index].set_position(position);
}

// returns the hitbox of the locaiton in the list at the inputted index
FloatRect LocationList::get_hitbox(int index) {
    return locations[index].get_hitbox();
}

// returns the coordinates of the location in the list at the paramater index 
Coordinates LocationList::get_coordinates(int index) {
    return locations[index].get_coordinates();
}

// activates the location at the inputted index of the list, changing its text style
// to the inputted style
void LocationList::activate(int index, Uint32 style) {
    locations[index].activate(style);
}

// deactivated the location in the list at the index inputted, resetting its style 
void LocationList::deactivate(int index) {
    locations[index].deactivate();
}

// returns bool of whether the locaiton graphic of the inputted index contains the point inputted
bool LocationList::contains_point(int index, Vector2f point) {
    return locations[index].contains_point(point);
}

// returns the bool is hidden of inputted index
bool LocationList::get_is_hidden(int index) {
    return locations[index].get_is_hidden();
}

// sets is hidden of inputted index with inputted bool
void LocationList::set_is_hidden(int index, bool is_hidden) {
    locations[index].set_is_hidden(is_hidden);
}

// draws all of the location graphics onto the window
void LocationList::draw(RenderTarget& target, RenderStates states) const {
    for (int i = 0; i < count; i++) {
        if (!locations[i].get_is_hidden()) {
            target.draw(locations[i]);
        }
    }
}

// destructor frees dynamically allocated array locations
LocationList::~LocationList() {
    delete[] locations;
}