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
    int result [v];

    for(int i = 0; i< v; i++)
    {
        elementList[i] = i;
        randMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,randMatrix[i]);
    }

    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

    startCounter();
    for(int i = 0; i< v; i++)
    {
        std::uniform_int_distribution<int> destination(0, v - 1 - i);
        int target = destination(generator);
        result[i] = elementList[target];
        if(target != (v-1-i))
            swap(elementList[v-1-i],elementList[target]);
    }

    int current;
    int next;

    for(int i = 0; i<v-1;i++)
    {
        current = result[i];
        next =result[i+1];
        totalCost+=randMatrix[current][next];
    }
    int first = result[0];
    totalCost+=randMatrix[next][first];

    double time = getCounter();

    std::cout<<"-- Random -- "<<endl;
    if(v < 17)
    {
        std::cout<<"Best Path: "<<endl;
        for(int i : result)
        {
            cout<<i<<" -> ";
        }
        cout<<result[0]<<endl;
    }
    std::cout<<"Cost: "<<totalCost<<endl;
    std::cout<<"Time: "<<time<<" ms"<<endl;


    return time;
}
