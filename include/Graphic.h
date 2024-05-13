#pragma once
#include <SFML/Graphics.hpp>

// common framework base class for all graphically represented classes (abstract class)
class Graphic : public sf::Drawable {
    protected:
        sf::Font font;
        sf::Vector2f position;
        sf::FloatRect hitbox;
        sf::RectangleShape hitbox_outline;
    public:
        // constructors
        Graphic();
        Graphic(sf::Font& font, sf::Vector2f position);

        // returns the graphic's position in the window
        sf::Vector2f get_postion();

        // sets the position of the graphic in the window
        virtual void set_position(sf::Vector2f position);

        // returns bool of whether a point of the window is in the graphic, point could be mouse position
        bool contains_point(sf::Vector2f point);

        // draws the graphic onto the window (pure virtual function)
        virtual void draw(sf::RenderTarget&, sf::RenderStates states) const = 0;
};