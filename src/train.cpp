// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (!first) return;
    first->prev->next = nullptr;
    Car *curr = first;
    while (curr != nullptr) {
        Car *temp = curr->next;
        delete curr;
        curr = temp;
    }
    first = nullptr;
}

void Train::addCar(bool light) {
    Car *newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car *last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        last->next = newCar;
        first->prev = newCar;
    }
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (!first) return 0;
    countOp = 0;
    
    first->light = true;
    
    Car *curr = first;
    int i = 1;
    while (true) {
        curr = curr->next;
        countOp++;
        
        if (curr->light) {
            curr->light = false;
            
            for (int step = 0; step < i; ++step) {
                curr = curr->prev;
                countOp++;
            }
            
            if (!first->light) {
                return i;
            }
            
            for (int step = 0; step < i; ++step) {
                curr = curr->next;
                countOp++;
            }
        }
        i++;
    }
}
