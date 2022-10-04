//
// Created by lori0 on 29/09/2022.
//

#ifndef FINNRUNNER_OBSERVER_H
#define FINNRUNNER_OBSERVER_H


class Observer {
    protected:
        virtual ~Observer() {};
    public:
        virtual void update() = 0;
};


#endif //FINNRUNNER_OBSERVER_H
