//
// Created by Silver on 05.10.2024.
//

#include "../Headers/Random.h"
#include <chrono>
#include <random>


std::default_random_engine generator;

int ** randMatrix = nullptr;

double Random::runRand(int **graphMatrix, int v)
{
    int visited [v];
    int visitSum = 0;
    int totalCost = 0;
    int elementList [v];
    randMatrix = new int * [v];
    string path;

    for(int i = 0; i< v; i++)
    {
        elementList[i] = i;
        randMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,randMatrix[i]);
    }

    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

    for(int i = 0; i< v; i++)
    {
        std::uniform_int_distribution<int> destination(0, v - 1 - i);
        int target = destination(generator);
        path.append(to_string(elementList[target]));
        if(target != (v-1-i))
            swap(elementList[v-1-i],elementList[target]);
    }

    std::cout<<endl;

    int current;
    int next;

    for(int i = 0; i<path.size()-1;i++)
    {
        current = (int) path[i]-48;
        next =(int) path[i+1]-48;
        totalCost+=randMatrix[current][next];
    }
    int first = (int)path[0]-48;
    totalCost+=randMatrix[next][first];

    std::cout<<path<<" --> Cost: "<<totalCost<<endl;










    return 0;
}
