// Beiyu Wang
#include "button.h"

Button::Button(sf::Vector2f _position, std::function<void(void)> _onClick){ // constructor, takes in a function
    position = _position; // sets each param
    sprite = nullptr;
    click = std::move(_onClick);
};

sf::Vector2f Button::getPosition(){ // setters
    return position;
}

sf::Sprite* Button::getSprite(){
    return sprite;
}

void Button::setSprite(sf::Sprite* _sprite){
    sprite = _sprite;
}

void Button::onClick(){ // calls function passed in? not too sure, checked cpp references for this part
    this -> click();
}



