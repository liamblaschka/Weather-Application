#pragma once
#include "Graphic.h"
#include <string>
#include <SFML/Graphics.hpp>

// represents the graphic for weather data, inherits from the graphic class,
// is an abstract class
class WeatherGraphic : public Graphic {
    protected:
        sf::Vector2f position;
        sf::Font font;
        std::string icon_id;
        sf::Texture weather_icons;
        sf::Sprite icon;
        sf::Text temperature_text;
     public:
        // constructors
        WeatherGraphic();
        WeatherGraphic(sf::Font& font, sf::Vector2f position);

        // returns the position of the weather graphic within the window
        sf::Vector2f get_position();

        // sets the postion of the weather graphic in the window
        virtual void set_position(sf::Vector2f position);

        // returns the icon id of the weather graphic, the different graphic icons are identified by this id which is
        // given in the data returned by the API
        std::string get_icon_id();

        // sets the icon of the weather graphic associated with the paramater icon id
        virtual void set_icon(std::string icon_id);

        // draws the weahter graphic onto the window (pure virtual)
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};