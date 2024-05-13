#include "Button.h"
#include "Graphic.h"
#include <SFML/Graphics.hpp>

using namespace sf;

// constructor
Button::Button(Font& font, Vector2f position, Sprite icon) : Graphic(font, position) {
    this->icon = icon;
    this->icon.setPosition(position);

    // sets the hitbox of the icon
    hitbox = this->icon.getGlobalBounds();

    // sets the background of the button, visible when is activated
    activated_background = RectangleShape(Vector2f(hitbox.width, hitbox.height));
    activated_background.setPosition(position);
    activated_background.setFillColor(Color(36, 152, 215));
}

// sets bool of is activated
void Button::set_is_activated(bool is_activated) {
    this->is_activated = is_activated;
}

// sets the graphical position of the button in window
void Button::set_position(Vector2f position) {
    this->position = position;
    icon.setPosition(position);
    activated_background.setPosition(position);
    hitbox = icon.getGlobalBounds();
}

// draws the button onto the window
void Button::draw(RenderTarget& target, RenderStates states) const {
    // only draws the background if is activated
    if (is_activated) {
        target.draw(activated_background);
    }
    target.draw(icon);
}
