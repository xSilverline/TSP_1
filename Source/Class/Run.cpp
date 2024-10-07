//
// Created by Silver on 05.10.2024.
//

#include "../Headers/Run.h"

void Run::run(int **matrix,int size, int reps,int start, bool showPBar)
{
    this->graphMatrix = matrix;
    this->graphSize = size;
    this->repeats = reps;
    this->showProgressBar = showPBar;
    this->startingNode = start;

    double time=0;

    NearestNeighbour nearestNeighbour;
    BruteForce bruteForce;

    for(int i = 0 ; i < repeats; i++)
    {
        time = nearestNeighbour.runNN(graphMatrix,graphSize,startingNode);
        time = bruteForce.runBrute(graphMatrix,graphSize,startingNode);

    }





}


