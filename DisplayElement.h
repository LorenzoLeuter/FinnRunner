#ifndef FINNRUNNER_DISPLAYELEMENT_H
#define FINNRUNNER_DISPLAYELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class DisplayElement {
    protected:
        virtual ~DisplayElement() {};
    public:
        virtual void draw() = 0;
};


#endif //FINNRUNNER_DISPLAYELEMENT_H
