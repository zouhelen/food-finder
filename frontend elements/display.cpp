#include <SFML/Graphics.hpp>
#include <functional>
#include "display.h" // include statements

void Display::welcome(){ // welcome page
    sf::Texture enterB; // enter button, set dimensions and sprite
    enterB.loadFromFile("images/enter.png");
    sf::Sprite enterImg;
    enterImg.setTexture(enterB);
    enterImg.scale(.5,.37);
    enterImg.setPosition(window.getSize().x/2 - enterB.getSize().x/4,window.getSize().y/2);
    enter.setSprite(enterImg);

    sf::Text welcomeText("Welcome to Food Finder!", font, 150); // welcome text, set size, font, color, etc
    welcomeText.setFillColor(fontC);
    welcomeText.setPosition(window.getSize().x/5,window.getSize().y/4);

    sf::Text secondary("Please click enter to begin your preference quiz.", font, 60);
    secondary.setFillColor(borderBlue);
    secondary.setPosition(window.getSize().x/4, window.getSize().y/2.5);

    this -> window.clear(bg); // clear with background color
    this -> window.draw(welcomeText); // draw elements
    this -> window.draw(secondary);
    this -> window.draw(enter.getSprite());
}

void Display::quiz() { // quiz page, a bit long because can't initialize the buttons with a loop (very diff positions on the sprite fridge)
    quizDone = false; // set quiz to unfinished
    sf::Texture subB; // submit button logistics: sets sprite, position, etc
    subB.loadFromFile("images/submit.png");
    sf::Sprite subImg;
    subImg.setTexture(subB);
    subImg.scale(0.75, 0.75);
    subImg.setPosition(window.getSize().x/2 - subB.getSize().x/3, window.getSize().y - 135);
    submit.setSprite(subImg);

    sf::Text quizText("Food Preferences", font, 150); // instruction text
    quizText.setFillColor(fontC);
    quizText.setPosition(window.getSize().x/4,window.getSize().y/18);

    sf::Text instructText("Left click to add select as an ingredient you have and right click to blacklist an ingredient (like allergies).", font, 30);
    instructText.setFillColor(borderBlue);
    instructText.setPosition(window.getSize().x/4.35, window.getSize().y/5);

    sf::Text bananaText("Banana", font, 30); // label text for each item, position set here
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

    sf::Texture bananaT; // sets texture, size, and position for each ingredient button
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

    banana.setSprite(bananaImg); // set sprite for each button
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

    this -> window.clear(bg); // clears the bg with background color

    this -> window.draw(quizText); // draw the base layer (texts and fridge graphic)
    this -> window.draw(instructText);
    this -> window.draw(fridge);

    this -> window.draw(bananaText); // draws ingredient labels
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

    this -> window.draw(banana.getSprite()); // draws ingredient sprites
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

    this -> d2.draw(); // draw dropdown menu
    this -> window.draw(submit.getSprite()); // draw submit button
}

void Display::reccs(int currentPage) {
    this->window.clear(bg);

    if(cSort == Percent){
        recipes.recipePercentRadix();
    }
    else if(cSort == LeastIngre){
        recipes.leastIngRadix();
    }
    else if(cSort == LeastSteps){
        recipes.leastStepsShell();
    }

    if (recipes.chosenRecipe.empty()) {
        // Display a message when there are no recipes
        sf::Text failed("Nothing to see here...", font, 150);
        failed.setFillColor(fontC);
        failed.setPosition(window.getSize().x / 4, window.getSize().y / 3);
        sf::Texture iconT;
        iconT.loadFromImage(icon);
        sf::Sprite iconS;
        iconS.setPosition(window.getSize().x/2.5, window.getSize().y/2);
        iconS.setTexture(iconT);

        this -> window.draw(iconS);
        this->window.draw(failed);
        this->d1.draw();
        this->d2.draw();
    } else {
        // Draw rectangles and texts for recipes
        std::vector<sf::RectangleShape> rectangles;
        std::vector<sf::Text> texts;
        sf::Vector2f position(210, 100); // Initial position of the first rectangle
        int counter = 0 + currentPage * 16; // Counter to limit the number of recipes to 16

        for (const auto& recipe : recipes.sortedRecipes) {
            if (counter >= 16 * (currentPage + 1) ){
                break;
            }

            // Create a rectangle for each recipe
            sf::RectangleShape rect(sf::Vector2f(360, 237.5));
            rect.setPosition(position);
            rectangles.push_back(rect);

            // Create text for each recipe
            sf::Text text(recipes.halfRecipeDetails(recipe), font, 20);
            text.setFillColor(fontC);
            text.setCharacterSize(24);
            text.setPosition(position.x + 10, position.y + 10); // Offset the text inside the rectangle
            texts.push_back(text);

            position.x += 380; // Increase x-coordinate for the next rectangle
            if (position.x > window.getSize().x - 380) {
                position.x = 210; // Reset x-coordinate for the next row
                position.y += 257.5; // Increase y-coordinate for the next row
            }
            counter++;
        }

        for (const auto& rect : rectangles) {
            this->window.draw(rect);
        }
        for (const auto& text : texts) {
            this->window.draw(text);
        }

        this->d1.draw();
        this->d2.draw();
    }
}



std::function<void(void)> Display::changeIngre(int i){ // onclick to select/deselect the ingredient button
    return [i, this]() { // lambda, passes in an index i and the current display
        if (ev.mouseButton.button == sf::Mouse::Left) { // if left click = add to user's ingredients
            added[i] = !added[i]; // sets to opposite of selection
            if(removed[i] && added[i]){ // set removed to false if added == true
                removed[i] = false;
            }
        } else if (ev.mouseButton.button == sf::Mouse::Right) { // if right click = remove from ingredient list
            removed[i] = !removed[i]; // set to opposite of selection
            if(added[i] && removed[i]){ // set added to false if removed == true
                added[i] = false;
            }
        }
    };
}

std::function<void(void)> Display::submitB(){ // onclick to change page and submit the quiz
    return [this]() {
        quizDone = true;
        for(int i = 0; i < 15; i++){
            std::cout << added[i] << std::endl;
        }
        recipes.chosenIng.clear();
        recipes.generateRecipeSubset(added, removed);
        cPage = R; // change page to reccs, mark the quiz as done
        for(int i = 0; i < 15; i++){
            added[i] = false;
            removed[i] = false;
        }
    };
}

std::function<void(void)> Display::swapQuiz(){ // onclick to swap pages
    return [this]() {
        cPage = Q; // when user clicks enter, swap to quiz page
    };
}

void Display::render(){ // puts everything together
    icon.loadFromFile("images/icon.png"); // load icon image

    video = sf::VideoMode(1920, 1200); // set videomode to a consistent size

    this -> window.create(this -> video, "Food Finder", sf::Style::Titlebar | sf::Style::Close); // create the window
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr()); // set app icon

    this -> font.loadFromFile("Cave-Story.ttf"); // set font

    sf::Texture* sortT = new sf::Texture(); // set menu top images
    sortT -> loadFromFile("images/sort by.png");

    sf::Texture* menuT = new sf::Texture();
    menuT -> loadFromFile("images/menu.png");

    while(this -> window.isOpen()) { // loop to update the window: while the user does not click out
        if(cPage == W){ // load page based on the current page saved in the enum
            welcome();
        }
        else if(cPage == Q){
            quiz();
        }
        else if(cPage == R){
            reccs(current);
        }

        while (this -> window.pollEvent(this -> ev)) { // poll for event
            if (ev.type == sf::Event::Closed) { // if closed: close the window and exit
                this -> window.close();
                break;
            }
            else if(ev.type == sf::Event::KeyPressed){ // if escape pressed: close the window and exit
                if(ev.key.code == sf::Keyboard::Escape){
                    this -> window.close();
                }
                break;
            }
            else if (ev.type == sf::Event::MouseButtonPressed) { // if a mouse button is pressed
                if (ev.mouseButton.button == sf::Mouse::Left || ev.mouseButton.button == sf::Mouse::Right) { // if its a left or right click
                    // toggle menu options for sort menu
                    if (ev.mouseButton.x >= d1.menu.getPosition().x && ev.mouseButton.x <= d1.menu.getPosition().x + d1.menu.getSize().x &&
                        ev.mouseButton.y >= d1.menu.getPosition().y && ev.mouseButton.y <= d1.menu.getPosition().y + d1.menu.getSize().y) {
                        d1.toggle();
                    }
                    // if clicked in one of the options, toggle the enum that chooses which sort
                    if(d1.isOpen() && d1.rects[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d1.toggle();
                        cSort = LeastIngre;
                    }
                    if(d1.isOpen() && d1.rects[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d1.toggle();
                        cSort = LeastSteps;
                    }
                    if(d1.isOpen() && d1.rects[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d1.toggle();
                        cSort = Percent;
                    }
                    //toggle menu options for menu dropdown
                    if (ev.mouseButton.x >= d2.menu.getPosition().x && ev.mouseButton.x <= d2.menu.getPosition().x + d2.menu.getSize().x &&
                        ev.mouseButton.y >= d2.menu.getPosition().y && ev.mouseButton.y <= d2.menu.getPosition().y + d2.menu.getSize().y) {
                        d2.toggle();
                    }
                    // if clicked in one of the options, toggle enum that chooses page
                    if(d2.isOpen() && d2.rects[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d2.toggle();
                        cPage = Q;
                    }
                    if(d2.isOpen() && d2.rects[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        d2.toggle();
                        cPage = R;
                    }
                    // onclicks for each submit and enter button, just calls onclick for them if it's in bounds
                    if(enter.getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        enter.onClick();
                    }
                    if(submit.getSprite().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))){
                        submit.onClick();
                    }

                    // if the page is on quiz, and it's not done, toggle whichever ingredient button the user clicks with the built-in onclick function
                    if(!quizDone && cPage == Q) {
                        if (banana.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            banana.onClick();
                        }

                        if (beef.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            beef.onClick();
                        }

                        if (carrot.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            carrot.onClick();
                        }

                        if (cheese.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            cheese.onClick();
                        }

                        if (chicken.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            chicken.onClick();
                        }

                        if (coconut.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            coconut.onClick();
                        }

                        if (cucumber.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            cucumber.onClick();
                        }

                        if (egg.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            egg.onClick();
                        }

                        if (milk.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            milk.onClick();
                        }

                        if (mushroom.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            mushroom.onClick();
                        }

                        if (pb.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            pb.onClick();
                        }

                        if (pork.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            pork.onClick();
                        }

                        if (potato.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            potato.onClick();
                        }

                        if (strawberry.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            strawberry.onClick();
                        }

                        if (tomato.getSprite().getGlobalBounds().contains(
                                static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
                            tomato.onClick();
                        }
                    }
                }
            }
        }
        this -> window.display(); // display the window
    }
}