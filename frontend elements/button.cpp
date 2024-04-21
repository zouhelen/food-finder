// Beiyu Wang
#include "button.h"
#include "display.h"

Button::Button(std::function<void(void)> _onClick){ // constructor, takes in a function
    click = std::move(_onClick);
};

sf::Sprite Button::getSprite(){
    return sprite;
}

void Button::setSprite(sf::Sprite _sprite){
    sprite = _sprite;
}

void Button::onClick(){ // calls function passed in? not too sure, checked cpp references for this part
    this -> click();
}
