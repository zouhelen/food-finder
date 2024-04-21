#include "button.h" // include header

Button::Button(std::function<void(void)> _onClick){ // constructor, takes in a function
    click = std::move(_onClick);
};

sf::Sprite Button::getSprite(){ // returns the button's sprite
    return sprite;
}

void Button::setSprite(sf::Sprite _sprite){ // sets the button's sprite
    sprite = _sprite;
}

void Button::onClick(){ // calls lambda function passed in
    this -> click();
}
