#include "graphics/screen/Button.hpp"
#include "geometry/Geometry.hpp"
#include "utils/Cli.hpp"

void Button::handleEvent(sf::Event event) {
    auto mousePosition = this->getRelativeMousePosition();

    if (!Geometry::insideUnitBox(mousePosition)) 
        return;
    
    this->onHoverFunction(event);
    if (event.type == sf::Event::MouseButtonPressed) 
        this->onClickFunction(event);
}