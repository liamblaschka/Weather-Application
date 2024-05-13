#pragma once
#include "Graphic.h"
#include "Coordinates.h"
#include <string>
#include <SFML/Graphics.hpp>

// represents a location including its name, coordinates and graphic
class Location : public Graphic {
    private:
        Coordinates coordinates;
        std::string location;
        sf::Text text;
        sf::Uint32 text_style;
        bool is_activated;
        sf::Vector2f position;
        bool is_hidden;
    public:
        // constructors 
        Location();
        Location(sf::Font& font, sf::Vector2f position, std::string location, Coordinates coordinates);

        // returns the name of the location as string
        std::string get_string();

        // sets the name of the location and its graphic text with paramater string
        void set_string(std::string location);

        // sets the style of the displayed text, e.g, regular, bold, underlined
        void set_style(sf::Uint32 style);

        // returns the coordinates (latitude, longitude) of the location as coordinate struct
        Coordinates get_coordinates();

        // sets the coordinates (latitude, longitude) of the locaiton, these coordinates are used with the API for the weather data
        void set_coordinates(Coordinates coordinates);

        // activates the location graphically with a style to change the text to (purpose to also have bool
        // to keep tack of activation state, also makes easy to deactivate and restore original text style)
        void activate(sf::Uint32 style);

        // deactivates the location graphically, setting the text style to its original state
        void deactivate();

        // returns bool is activated
        bool get_is_activated();

        // sets the graphical positoin of the location in the window
        void set_position(sf::Vector2f position) override;

        // returns the graphical position of the location in the window
        sf::Vector2f get_position();

        // returns the hitbox of the location graphic, example use case is to determine how much space
        // the text takes up graphically
        sf::FloatRect get_hitbox();

        // returns bool of whether the location is hidden graphically, the list of locaitons the user can choose
        // from does not change its contents so the locations are graphically hidden in this case instead of removed
        bool get_is_hidden();

        // sets the bool of whether the locaiton is hidden graphically
        void set_is_hidden(bool is_hidden);

        // draws the location graphic onto the window
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};