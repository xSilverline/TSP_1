//
// Created by Silver on 06.10.2024.
//

#ifndef TSP_1_STRUCTURES_H
#define TSP_1_STRUCTURES_H

struct listElement
{
    listElement *next;
    int target = 0;
    int weight = 0;
};

struct resultHelper
{
    int * path;
    int cost;
};


#endif //TSP_1_STRUCTURES_H
