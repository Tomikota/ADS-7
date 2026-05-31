// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <sys/stat.h>
#include "train.h"

#if defined(_WIN32)
#include <direct.h>
#endif

void createResultDirectory() {
#if defined(_WIN32)
    _mkdir("result");
#else
    mkdir("result", 0777);
#endif
}

int main() {
    createResultDirectory();
    std::ofstream outFile("result/data.csv");
    if (!outFile.is_open()) {
        return 1;
    }
    
    outFile << "N,AllOff,AllOn,Random\n";
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    
    for (int N = 2; N <= 100; ++N) {
        Train trainOff;
        for (int i = 0; i < N; ++i) {
            trainOff.addCar(false);
        }
        trainOff.getLength();
        int opsOff = trainOff.getOpCount();
        
        Train trainOn;
        for (int i = 0; i < N; ++i) {
            trainOn.addCar(true);
        }
        trainOn.getLength();
        int opsOn = trainOn.getOpCount();
        
        int runs = 15;
        double opsRandSum = 0;
        for (int r = 0; r < runs; ++r) {
            Train trainRand;
            for (int i = 0; i < N; ++i) {
                trainRand.addCar(dis(gen) == 1);
            }
            trainRand.getLength();
            opsRandSum += trainRand.getOpCount();
        }
        double opsRandAvg = opsRandSum / runs;
        
        outFile << N << "," << opsOff << "," << opsOn << "," << opsRandAvg << "\n";
    }
    
    outFile.close();
    return 0;
}
