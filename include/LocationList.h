#pragma once
#include "Location.h"
#include <SFML/Graphics.hpp>
#include <string>

// represents the list of locaitons 
class LocationList : public sf::Drawable {
    protected:
        Location* locations;
        int size;
        int count;
    public:
        // constructor
        LocationList(int size);

        // returns the size of the list of locations
        int get_size();

        // returns the number of locaitons that are in the list
        int get_count();

        // adds a location object to the list
        virtual void add_location(Location location);

        // removes the location of the paramater index from the list
        virtual void remove_location(int index);

        // moves the location of the paramater original index to the paramater new index and adjusts the other
        // locations of the list accordingly
        virtual void move_location(int original_index, int new_index);

        // returns location object from list at paramater index
        Location get_location(int index);

        // returns the string (name) of the location in the list at the paramater index
        std::string get_string(int index);

        // returns the coordinates (latitude, longitude) of the location in the list at the paramater index 
        Coordinates get_coordinates(int index);
        
        // returns the graphical position in the window of the location in the list at the paramater index
        sf::Vector2f get_position(int index);

        // sets the graphical position in the window of the locaiton at the paramater index
        void set_position(int index, sf::Vector2f position);

        // returns the hitbox of the location in the list at the paramater index, example use case is to determine how much space
        // the text takes up graphically
        sf::FloatRect get_hitbox(int index);

        // activates the paramater index location in the list graphically with a style to change the text to
        // (makes easy to deactivate and restore original text style, also with bool to track whether is activated)
        void activate(int index, sf::Uint32 style);

        // deactivates the paramater index location in the list graphically, returning the text to its original style
        void deactivate(int index);

        // returns bool of whether a point of the window is contained in the location graphic in the list at the inputted index,
        // for example, the point could be a mouse position
        bool contains_point(int index, sf::Vector2f point);

        // returns the is_hidden bool of locaiton at paramater index, is_hidden state is whether the locaiton is graphically hidden,
        // this is used in some cases instead of removing the locaiton from the list, the locaiton will be hidden
        bool get_is_hidden(int index);

        // sets the is hidden bool to the paramater value of the location of the list at the paramater index
        void set_is_hidden(int index, bool is_hidden);

        // draws all of the locations in the list locations to the window
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // destructor to free dynamically allocated array locations
        ~LocationList();
};