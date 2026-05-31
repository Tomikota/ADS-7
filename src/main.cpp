// Copyright 2025

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "train.h"

int main() {
    std::srand(static_cast<unsigned>(time(nullptr)));

    std::cout << "n false true random\n";

    for (int n = 2; n <= 100; n++) {
        int opFalse;
        int opTrue;
        int opRandom;

        {
            Train train;

            for (int i = 0; i < n; i++) {
                train.addCar(false);
            }

            train.getLength();

            opFalse = train.getOpCount();
        }

        {
            Train train;

            for (int i = 0; i < n; i++) {
                train.addCar(true);
            }

            train.getLength();

            opTrue = train.getOpCount();
        }

        {
            Train train;

            for (int i = 0; i < n; i++) {
                train.addCar(std::rand() % 2);
            }

            train.getLength();

            opRandom = train.getOpCount();
        }

        std::cout << n << " "
                  << opFalse << " "
                  << opTrue << " "
                  << opRandom << std::endl;
    }

    return 0;
}
