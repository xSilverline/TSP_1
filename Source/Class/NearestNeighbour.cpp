//
// Created by Silver on 05.10.2024.
//

#include "../Headers/NearestNeighbour.h"

int **nnMatrix = nullptr;
int cost=0;

double NearestNeighbour::runNN(int **graphMatrix, int v,int startingNode)
{
    int visited [v];
    int visitSum = 0;
    int totalCost = 0;
    nnMatrix = new int * [v];

    int currentNode = startingNode;


    for(int i =0; i< v; i++)
    {
        visited[i] = 0;
        nnMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,nnMatrix[i]);
    }
    std::cout<<endl;

    startCounter();
    while(visitSum<v-1)
    {

        visited[currentNode] = 1;
        visitSum++;
        int minimum = MAXINT;
        int goToN = -1;
        for(int neighbour = 0; neighbour<v;neighbour++)
        {
            int temp = nnMatrix[currentNode][neighbour];
            if(temp != -1 && temp < minimum && !visited[neighbour])
            {
                minimum = temp;
                goToN = neighbour;
            }

        }
        std::cout<<currentNode<<" -> "<<goToN<<" "<<minimum<<endl;
        totalCost+=minimum;
        currentNode = goToN;
//        std::cout<<currentNode<<" -> "<<totalCost<<endl;


    }

    totalCost+=graphMatrix[currentNode][startingNode];
    cost = totalCost;

    double time = getCounter();
    std::cout<<currentNode<<" -> "<<startingNode<<" "<<graphMatrix[currentNode][startingNode]<<endl;

    std::cout<<"Koszt: "<<totalCost<<endl;
    std::cout<<"Czas: "<<time<<endl;

    return 0;
}

int NearestNeighbour::getCost()
{
    return cost;
}
