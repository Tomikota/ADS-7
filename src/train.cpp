// Copyright 2025

#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

Train::~Train() {
    if (first == nullptr) {
        return;
    }

    Car* current = first->next;

    while (current != first) {
        Car* temp = current;
        current = current->next;
        delete temp;
    }

    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car;

    newCar->light = light;

    if (first == nullptr) {
        first = newCar;

        first->next = first;
        first->prev = first;

        return;
    }

    Car* last = first->prev;

    newCar->next = first;
    newCar->prev = last;

    last->next = newCar;
    first->prev = newCar;
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }

    countOp = 0;

    Car* current = first;

    current->light = true;

    while (true) {
        int distance = 0;

        do {
            current = current->next;

            countOp++;

            distance++;
        } while (!current->light);

        current->light = false;

        for (int i = 0; i < distance; i++) {
            current = current->prev;

            countOp++;
        }

        if (!current->light) {
            return distance;
        }
    }
}
