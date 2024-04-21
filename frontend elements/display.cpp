#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <iostream>
#include "display.h"

void Display::welcome(){
    sf::Texture enterB;
    enterB.loadFromFile("images/enter.png");
    sf::Sprite enterImg;
    enterImg.setTexture(enterB);
    enterImg.scale(.5,.37);
    enterImg.setPosition(window.getSize().x/2 - enterB.getSize().x/4,window.getSize().y/2);

    sf::Text welcomeText("Welcome to Food Finder!", font, 150);
    welcomeText.setFillColor(fontC);
    welcomeText.setPosition(window.getSize().x/5,window.getSize().y/4);

    sf::Text secondary("Please click enter to begin your preference quiz.", font, 60);
    secondary.setFillColor(borderBlue);
    secondary.setPosition(window.getSize().x/5, window.getSize().y/2.5);

    enter.setSprite(enterImg);

    this -> window.clear(bgGreen);
    this -> window.draw(welcomeText);
    this -> window.draw(secondary);
    this -> window.draw(enter.getSprite());
}


void Display::quiz() { // note: probably a more efficient way to do it, but I got in too deep and didn't want to delete all my work
    sf::Text quizText("Food Preferences", font, 150);
    quizText.setFillColor(fontC);
    quizText.setPosition(window.getSize().x/4,window.getSize().y/18);

    sf::Text instructText("Left click to add select as an ingredient you have and right click to blacklist an ingredient (like allergies).", font, 30);
    instructText.setFillColor(borderBlue);
    instructText.setPosition(window.getSize().x/4.35, window.getSize().y/5);

    sf::Text bananaText("Banana", font, 30);
    bananaText.setFillColor(fontC);
    bananaText.setPosition(window.getSize().x/1.9 - 10, 465);
    sf::Text beefText("Beef", font, 30);
    beefText.setFillColor(fontC);
    beefText.setPosition(window.getSize().x/1.9 - 10, 625);
    sf::Text carrotText("Carrot", font, 30);
    carrotText.setFillColor(fontC);
    carrotText.setPosition(window.getSize().x/1.9 + 150, 780);
    sf::Text cheeseText("Cheese", font, 30);
    cheeseText.setFillColor(fontC);
    cheeseText.setPosition(window.getSize().x/4 + 330, 575);
    sf::Text chickenText("Chicken", font, 30);
    chickenText.setFillColor(fontC);
    chickenText.setPosition(window.getSize().x/1.9 + 95, 625);
    sf::Text cocoText("Coconut", font, 30);
    cocoText.setFillColor(fontC);
    cocoText.setPosition(window.getSize().x/1.9 + 300, 465);
    sf::Text cucumberText("Cucumber", font, 30);
    cucumberText.setFillColor(fontC);
    cucumberText.setPosition(window.getSize().x/1.9 + 250, 780);
    sf::Text eggText("Egg", font, 30);
    eggText.setFillColor(fontC);
    eggText.setPosition(window.getSize().x/4 + 240, 575);
    sf::Text milkText("Milk", font, 30);
    milkText.setFillColor(fontC);
    milkText.setPosition(window.getSize().x/4 + 20, 575);
    sf::Text mushroomText("Mushroom", font, 30);
    mushroomText.setFillColor(fontC);
    mushroomText.setPosition(window.getSize().x/1.9 + 300, 625);
    sf::Text pbText("Peanut Butter", font, 30);
    pbText.setFillColor(fontC);
    pbText.setPosition(window.getSize().x/4 + 90, 575);
    sf::Text porkText("Pork", font, 30);
    porkText.setFillColor(fontC);
    porkText.setPosition(window.getSize().x/1.9 + 220, 625);
    sf::Text potatoText("Potato", font, 30);
    potatoText.setFillColor(fontC);
    potatoText.setPosition(window.getSize().x/1.9 + 55, 780);
    sf::Text strawberryText("Strawberry", font, 30);
    strawberryText.setFillColor(fontC);
    strawberryText.setPosition(window.getSize().x/1.9 + 80, 465);
    sf::Text tomatoText("Tomato", font, 30);
    tomatoText.setFillColor(fontC);
    tomatoText.setPosition(window.getSize().x/1.9 + 210, 465);

    sf::Texture bananaT;
    bananaT.loadFromFile("images/banana.png");
    sf::Sprite bananaImg;
    bananaImg.setTexture(bananaT);
    bananaImg.setPosition(window.getSize().x/1.9 - 10, 400);

    sf::Texture beefT;
    beefT.loadFromFile("images/beef.png");
    sf::Sprite beefImg;
    beefImg.setTexture(beefT);
    beefImg.setPosition(window.getSize().x/1.9 - 10, 560);

    sf::Texture carrotT;
    carrotT.loadFromFile("images/carrot.png");
    sf::Sprite carrotImg;
    carrotImg.setTexture(carrotT);
    carrotImg.setPosition(window.getSize().x/1.9 + 150, 710);

    sf::Texture cheeseT;
    cheeseT.loadFromFile("images/cheese.png");
    sf::Sprite cheeseImg;
    cheeseImg.setTexture(cheeseT);
    cheeseImg.setPosition(window.getSize().x/4 + 330, 510);

    sf::Texture chickenT;
    chickenT.loadFromFile("images/chicken.png");
    sf::Sprite chickenImg;
    chickenImg.setTexture(chickenT);
    chickenImg.setPosition(window.getSize().x/1.9 + 100, 560);

    sf::Texture eggT;
    eggT.loadFromFile("images/egg.png");
    sf::Sprite eggImg;
    eggImg.setTexture(eggT);
    eggImg.setPosition(window.getSize().x/4 + 220, 510);

    sf::Texture mushroomT;
    mushroomT.loadFromFile("images/mushroom.png");
    sf::Sprite mushroomImg;
    mushroomImg.setTexture(mushroomT);
    mushroomImg.setPosition(window.getSize().x/1.9 + 300, 560);

    sf::Texture porkT;
    porkT.loadFromFile("images/pork.png");
    sf::Sprite porkImg;
    porkImg.setTexture(porkT);
    porkImg.setPosition(window.getSize().x/1.9 + 200, 560);

    sf::Texture potatoT;
    potatoT.loadFromFile("images/potato.png");
    sf::Sprite potatoImg;
    potatoImg.setTexture(potatoT);
    potatoImg.setPosition(window.getSize().x/1.9 + 50, 710);

    sf::Texture strawberryT;
    strawberryT.loadFromFile("images/strawberry.png");
    sf::Sprite strawberryImg;
    strawberryImg.setTexture(strawberryT);
    strawberryImg.setPosition(window.getSize().x/1.9 + 100, 400);

    sf::Texture tomatoT;
    tomatoT.loadFromFile("images/tomato.png");
    sf::Sprite tomatoImg;
    tomatoImg.setTexture(tomatoT);
    tomatoImg.setPosition(window.getSize().x/1.9 + 200, 400);

    sf::Texture cucumberT;
    cucumberT.loadFromFile("images/cucumber.png");
    sf::Sprite cucumberImg;
    cucumberImg.setTexture(cucumberT);
    cucumberImg.setPosition(window.getSize().x/1.9 + 250, 710);

    sf::Texture coconutT;
    coconutT.loadFromFile("images/coconut.png");
    sf::Sprite coconutImg;
    coconutImg.setTexture(coconutT);
    coconutImg.setPosition(window.getSize().x/1.9 + 300, 400);

    sf::Texture milkT;
    milkT.loadFromFile("images/milk.png");
    sf::Sprite milkImg;
    milkImg.setTexture(milkT);
    milkImg.setPosition(window.getSize().x/4, 510);

    sf::Texture pbT;
    pbT.loadFromFile("images/pb.png");
    sf::Sprite pbImg;
    pbImg.setTexture(pbT);
    pbImg.setPosition(window.getSize().x/4 + 110, 510);

    sf::Texture fridgeT;
    fridgeT.loadFromFile("images/fridge.png");
    sf::Sprite fridge;
    fridge.setTexture(fridgeT);
    fridge.scale(1.5,1.5);
    fridge.setPosition(window.getSize().x/4.35, window.getSize().y/5+100);

    banana.setSprite(bananaImg);
    beef.setSprite(beefImg);
    carrot.setSprite(carrotImg);
    cheese.setSprite(cheeseImg);
    chicken.setSprite(chickenImg);
    egg.setSprite(eggImg);
    mushroom.setSprite(mushroomImg);
    pork.setSprite(porkImg);
    potato.setSprite(potatoImg);
    strawberry.setSprite(strawberryImg);
    tomato.setSprite(tomatoImg);
    cucumber.setSprite(cucumberImg);
    coconut.setSprite(coconutImg);
    milk.setSprite(milkImg);
    pb.setSprite(pbImg);

    this -> window.clear(bgGreen);

    this -> window.draw(quizText);
    this -> window.draw(instructText);
    this -> window.draw(fridge);

    this -> window.draw(bananaText);
    this -> window.draw(beefText);
    this -> window.draw(carrotText);
    this -> window.draw(cheeseText);
    this -> window.draw(chickenText);
    this -> window.draw(cocoText);
    this -> window.draw(cucumberText);
    this -> window.draw(eggText);
    this -> window.draw(milkText);
    this -> window.draw(mushroomText);
    this -> window.draw(pbText);
    this -> window.draw(porkText);
    this -> window.draw(potatoText);
    this -> window.draw(strawberryText);
    this -> window.draw(tomatoText);

    this -> window.draw(banana.getSprite());
    this -> window.draw(beef.getSprite());
    this -> window.draw(carrot.getSprite());
    this -> window.draw(cheese.getSprite());
    this -> window.draw(chicken.getSprite());
    this -> window.draw(coconut.getSprite());
    this -> window.draw(cucumber.getSprite());
    this -> window.draw(egg.getSprite());
    this -> window.draw(milk.getSprite());
    this -> window.draw(mushroom.getSprite());
    this -> window.draw(pb.getSprite());
    this -> window.draw(pork.getSprite());
    this -> window.draw(potato.getSprite());
    this -> window.draw(strawberry.getSprite());
    this -> window.draw(tomato.getSprite());
    this -> d2.draw();
}

std::function<void(void)> Display::swapQuiz(){
    return [this]() {
        cPage = Q;
    };
}

void Display::reccs() {
}

// create methods for each page. submit button reloads to reccs, then a quiz retake option, a see reccs option, and a browse option
void Display::render(){ // puts everything together, onclick stuff
    icon.loadFromFile("images/icon.png");

    video = sf::VideoMode::getDesktopMode();

    this -> window.create(this -> video, "Food Finder", sf::Style::Titlebar | sf::Style::Close);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    this -> font.loadFromFile("Cave-Story.ttf");

    sf::Texture* sortT = new sf::Texture();
    sortT -> loadFromFile("images/sort by.png");

    sf::Texture* menuT = new sf::Texture();
    menuT -> loadFromFile("images/menu.png");

    while(this -> window.isOpen()) {
        if(cPage == W){
            welcome();
        }
        else if(cPage == Q){
            quiz();
        }
        else if(cPage == R){
            reccs();
        }
        while (this -> window.pollEvent(this -> ev)) {
            if (ev.type == sf::Event::Closed) {
                this -> window.close();
                break;
            }
            else if(ev.type == sf::Event::KeyPressed){
                if(ev.key.code == sf::Keyboard::Escape){
                    this -> window.close();
                }
                break;
            }
            else if (ev.type == sf::Event::MouseButtonPressed) {
                if (ev.mouseButton.button == sf::Mouse::Left || ev.mouseButton.button == sf::Mouse::Right) {
                    if (ev.mouseButton.x >= d1.menu.getPosition().x && ev.mouseButton.x <= d1.menu.getPosition().x + d1.menu.getSize().x &&
                               ev.mouseButton.y >= d1.menu.getPosition().y && ev.mouseButton.y <= d1.menu.getPosition().y + d1.menu.getSize().y) {
                        d1.toggle();
                    }

                    if (ev.mouseButton.x >= d2.menu.getPosition().x && ev.mouseButton.x <= d2.menu.getPosition().x + d2.menu.getSize().x &&
                               ev.mouseButton.y >= d2.menu.getPosition().y && ev.mouseButton.y <= d2.menu.getPosition().y + d2.menu.getSize().y) {
                        d2.toggle();
                    }
                    if(d2.isOpen() && d2.rects[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d2.toggle();
                        cPage = Q;
                    }
                    if(d2.isOpen() && d2.rects[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d2.toggle();
                        cPage = R;
                    }
                    if(d2.isOpen() && d2.rects[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d2.toggle();
                        cPage = B;
                    }
                    if(enter.getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        enter.onClick();
                    }
                }
            }
        }
        this -> window.display();
    }
}