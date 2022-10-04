//
// Created by lori0 on 29/09/2022.
//

#ifndef FINNRUNNER_SUBJECT_H
#define FINNRUNNER_SUBJECT_H


#include "Observer.h"

class Subject {
    protected:
        virtual ~Subject() {};
    public:
        virtual void registerObserver( Observer* o ) = 0;
        virtual void removeObserver( Observer* o ) = 0;
        virtual void notifyObservers() const = 0;
};


#endif //FINNRUNNER_SUBJECT_H
