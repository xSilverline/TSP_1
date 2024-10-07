//
// Created by Silver on 05.10.2024.
//

#ifndef TSP_1_NEARESTNEIGHBOUR_H
#define TSP_1_NEARESTNEIGHBOUR_H

#include "TimeCounter.h"


class NearestNeighbour
        {
private:
public:
            int getCost();
            double runNN(int ** graphMatrix, int v,int startingNode);

};


#endif //TSP_1_NEARESTNEIGHBOUR_H
