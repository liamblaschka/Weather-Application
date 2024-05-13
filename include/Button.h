#ifndef BUTTON_H
#define BUTTON_H

#include "Graphic.h"
#include <SFML/Graphics.hpp>

// class for button graphic
class Button : public Graphic {
    private:
        sf::Sprite icon;
        sf::RectangleShape activated_background;
        bool is_activated;
    public:
        // constructor
        Button(sf::Font& font, sf::Vector2f position, sf::Sprite icon);

        // sets the boolean is activated as a way to change how button is displayed
        void set_is_activated(bool is_activated);

        // sets the position of the button graphic in the window
        void set_position(sf::Vector2f position) override;

        // draws the button to the window
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif