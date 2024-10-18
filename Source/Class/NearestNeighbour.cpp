//
// Created by Silver on 05.10.2024.
//

#include "../Headers/NearestNeighbour.h"

int **nnMatrix = nullptr;
int cost=0;

double NearestNeighbour::runNN(int **graphMatrix, int v,int startingNode,bool print)
{
    int visited [v];
    int visitSum = 0;
    int totalCost = 0;
    int result [v];
    int resultCounter=0;
    nnMatrix = new int * [v];
    string path;
    int currentNode = startingNode;

    for(int i =0; i< v; i++)
    {
        visited[i] = 0;
        result[i] = 0;
        nnMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,nnMatrix[i]);
    }

    startCounter();

    result[resultCounter] = currentNode;
    resultCounter++;



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
        result[resultCounter] = goToN;
        resultCounter++;
//        path.append(to_string(goToN));
//        std::cout<<currentNode<<" -> "<<goToN<<" "<<minimum<<endl;
        totalCost+=minimum;
        currentNode = goToN;
//        std::cout<<currentNode<<" -> "<<totalCost<<endl;
    }

    totalCost+=graphMatrix[currentNode][startingNode];
    cost = totalCost;

    double time = getCounter();
//    std::cout<<currentNode<<" -> "<<startingNode<<" "<<graphMatrix[currentNode][startingNode]<<endl;
if(print)
{
    std::cout << "-- Nearest Neighbour -- " << endl;
    if (path.size() < 17) {
        std::cout << "Best Path: " << endl;
        for (int i: result) {
            cout << i << " -> ";
        }
        cout << result[0] << endl;
    }
    std::cout << "Cost: " << totalCost << endl;
    std::cout << "Time: " << time << " ms" << endl;
}

    return time;
}

int NearestNeighbour::getCost()
{
    return cost;
}
