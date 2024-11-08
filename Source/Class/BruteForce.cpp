//
// Created by Silver on 05.10.2024.
//

#include "../Headers/BruteForce.h"


int **bruteMatrix = nullptr;
int minCost = MAXINT;
int limitCost=MAXINT;
bool overLimit = false;
int killBrute;


int *bestPath;

void permutation(int *path, int position = 0, int v=0)
{


    double killTimer = getCounter();

    if(killTimer > killBrute)
        return;

    if(position != v)
    {
        for(int i = position; i<v;i++)
        {
            swap(path[i],path[position]);
            permutation(path,position+1,v);
            swap(path[i],path[position]);
        }
    }
    else
    {
        int cost = 0;
        int current;
        int next;
        for(int i = 0; i<v-1;i++)
        {
            current = path[i];
            next =path[i+1];
            cost+=bruteMatrix[current][next];
            if(cost > limitCost || cost > minCost)
            {
                overLimit = true;
                break;
            }

        }
        if(!overLimit)
        {
            int first = path[0];
            cost+=bruteMatrix[next][first];

            if(minCost > cost)
            {
                minCost = cost;
                copy(path,path+v,bestPath);
            }


//            std::cout<<path<<" --> Cost: "<<cost<<endl;
        }
//        else
//        {
////            std::cout<<path<<" --> Cost: Over Limit - skip"<<endl;
//        }
        overLimit = false;
//        for(int i = 0; i<v;i++)
//        {
//            cout<<bestPath[i]<<" ";
//        }
//        cout<<endl;

    }
}

double BruteForce::runBrute(int **graphMatrix, int x,int killSwitch,int startingNode)
{
    minCost = MAXINT;
    limitCost=MAXINT;
    int v = 0;
    v=x;
    killBrute = killSwitch;
    int counterList [v];
    bestPath = new int [v];
    NearestNeighbour nn;
//    nn.runNN(graphMatrix,v,startingNode);

    limitCost = nn.getCost();
    if(limitCost == 0)
    {
        nn.runNN(graphMatrix,v,startingNode,true,killSwitch);
        limitCost = nn.getCost();
    }

//    cout<<limitCost<<endl;

    int visited [v];
    int path[v];

    bruteMatrix = new int * [v];



    for(int i =0; i< v; i++)
    {
        counterList[i] = 0;
        path[i]=i;
        visited[i] = 0;
        bruteMatrix[i] = new int [v];
        std::copy(graphMatrix[i],graphMatrix[i]+v,bruteMatrix[i]);
    }


    startCounter();

    permutation(path,0,v);

    double time = getCounter();

    std::cout<<"-- Brute Force -- "<<endl;
    if(v < 17)
    {
        std::cout<<"Best Path: "<<endl;
        for(int i=0;i<v;i++)
        {
            cout<<bestPath[i]<<" -> ";
        }
        cout<<bestPath[0]<<endl;
    }
    std::cout<<"Cost: "<<minCost<<endl;
    std::cout<<"Time: "<<time<<" ms"<<endl;
    if(time > killSwitch)
        cout<<"Process killed - time limit exceeded!  "<<endl;

    return time;
}

//resultHelper BruteForce::getResult()
//{
//    resultHelper result{};
//    result.cost = minCost;
//    result.path = bestPath;
//    return result;
//}


