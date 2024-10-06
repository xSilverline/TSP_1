//
// Created by Silver on 05.10.2024.
//

#include "../Headers/NearestNeighbour.h"

int **nnMatrix = nullptr;

double NearestNeighbour::runNN(int **graphMatrix, int v)
{
    int visited [v];
    int visitSum = 0;
    int totalCost = 0;
    nnMatrix = new int * [v];

    int currentNode = 0; // TODO make in config.ini startingNode


    for(int i =0; i< v; i++)
    {
        visited[i] = 0;
        nnMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,nnMatrix[i]);
    }
    std::cout<<endl;

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
        std::cout<<currentNode<<" -> "<<totalCost<<endl;
    }

    std::cout<<"Koszt: "<<totalCost<<endl;

    return 0;
}
