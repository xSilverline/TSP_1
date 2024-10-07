//
// Created by Silver on 05.10.2024.
//

#ifndef TSP_1_RUN_H
#define TSP_1_RUN_H

#include "NearestNeighbour.h"
#include "BruteForce.h"

class Run
        {

private:
            int ** graphMatrix;
            int graphSize;
            int repeats;
            int startingNode;
            bool showProgressBar;
//            void runNN();
//            void runBrute();
//            void runRandom();



public:
            void run(int ** graphMatrix, int graphSize, int repeats,int start,bool showProgressBar);


};


#endif //TSP_1_RUN_H
