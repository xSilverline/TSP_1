//
// Created by Silver on 05.10.2024.
//

#include "../Headers/BruteForce.h"

int **bruteMatrix = nullptr;
int minCost = MAXINT;
int limitCost=MAXINT;
string bestPath;

void permutation(string path, int position = 0)
{
    if(position != path.size())
    {
        for(int i = position; i<path.size();i++)
        {
            swap(path[i],path[position]);
            permutation(path,position+1);
            swap(path[i],path[position]);
        }
    }
    else
    {
        int cost = 0;
        int current;
        int next;
        for(int i = 0; i<path.size()-1;i++)
        {
            current = (int) path[i]-48;
            next =(int) path[i+1]-48;
            cost+=bruteMatrix[current][next];
            if(cost > limitCost)
                break;
        }
        int first = (int)path[0]-48;
        cost+=bruteMatrix[next][first];

        if(minCost > cost)
        {
            minCost = cost;
            bestPath = path;
        }

        std::cout<<path<<" --> Cost: "<<cost<<endl;
    }
}

double BruteForce::runBrute(int **graphMatrix, int v, int startingNode)
{
    int counterList [v];

    NearestNeighbour nn;
    nn.runNN(graphMatrix,v,startingNode);

    limitCost = nn.getCost();

    int visited [v];
    int visitSum = 0;
    int totalCost = 0;
    bruteMatrix = new int * [v];

    int currentNode = startingNode;

    for(int i =0; i< v; i++)
    {
        counterList[i] = 0;
        visited[i] = 0;
        bruteMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,bruteMatrix[i]);
    }
    std::cout<<endl;

    string path;
    for(int i = 0; i<v;i++)
    {
        path.append(to_string(i));
    }
    std::cout<<path<<endl;
    std::cout<<endl;
    permutation(path,0);

    std::cout<<"Best Path: "<<bestPath<<endl;
    std::cout<<"Cost: "<<minCost<<endl;

    return 0;
}


