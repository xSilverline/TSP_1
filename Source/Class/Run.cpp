//
// Created by Silver on 05.10.2024.
//

#include "../Headers/Run.h"

void Run::run(int **matrix,int size, int reps, bool showPBar)
{
    this->graphMatrix = matrix;
    this->graphSize = size;
    this->repeats = reps;
    this->showProgressBar = showPBar;

    double time=0;

    NearestNeighbour nearestNeighbour;

    time = nearestNeighbour.runNN(graphMatrix,graphSize);



}


