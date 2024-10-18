//
// Created by Silver on 05.10.2024.
//

#include <fstream>
#include <iomanip>
#include "../Headers/Run.h"

string outFileName;
string inFileName;
int optimal;

void Run::run(int **matrix,int size, int reps,int start, bool showPBar,int killSwitch,const string& method,string output,string input,int opt)
{
    optimal = opt;
    inFileName = input;
    outFileName = output;
    this->graphMatrix = matrix;
    this->graphSize = size;
    this->repeats = reps;
    this->showProgressBar = showPBar;
    this->startingNode = start;

    if(method == "bf")
    {
        runBF(killSwitch);
    }
    else if(method == "nn")
    {
        runNN();
    }
    else if(method == "rn")
    {
        runRN();
    }
    else if(method == "all")
    {
        runAll(killSwitch);
    }
    else
        cout<<"Wrong method! Check config file ! "<<endl;


}

void Run::runBF(int killSwitch)
{
    ofstream outputFile;
    outputFile.open (outFileName);
    outputFile<<"Input file\t"<<inFileName<<endl;
    outputFile<<"Optimal cost\t"<<optimal<<endl;


    double time=0;
    double oneTime=0;
    BruteForce bruteForce;

    for(int i = 0 ; i < repeats; i++)
    {
        oneTime = bruteForce.runBrute(graphMatrix,graphSize,killSwitch,startingNode);
        outputFile<<"Time Attempt "<<i+1<<"\t"<<oneTime<<endl;
        time+=oneTime;
        cout<<endl;
    }

    time /= repeats;
    outputFile<<"Time Avg\t"<<time<<endl;
//    resultHelper result = bruteForce.getResult();

}

void Run::runNN()
{
    ofstream outputFile;
    outputFile.open (outFileName);
    outputFile<<"Input file\t"<<inFileName<<endl;
    outputFile<<"Optimal cost\t"<<optimal<<endl;

    double time=0;
    double oneTime=0;
    NearestNeighbour nearestNeighbour;

    for(int i = 0 ; i < repeats; i++)
    {
        oneTime= nearestNeighbour.runNN(graphMatrix,graphSize,startingNode,true);
        outputFile<<"Time NN Rep "<<i+1<<"\t"<<fixed<<setprecision(4)<<oneTime<<endl;
        time += oneTime;
        cout<<endl;
    }

    time /= repeats;
    outputFile<<"Time Avg\t"<<fixed<<setprecision(4)<<time<<endl;

}

void Run::runRN()
{
    ofstream outputFile;
    outputFile.open (outFileName);
    outputFile<<"Input file\t"<<inFileName<<endl;
    outputFile<<"Optimal cost\t"<<optimal<<endl;

    double time=0;
    double oneTime=0;
    Random random;

    for(int i = 0 ; i < repeats; i++)
    {
        oneTime = random.runRand(graphMatrix,graphSize);
        outputFile<<"Time RN Rep "<<i+1<<"\t"<<fixed<<setprecision(4)<<oneTime<<endl;
        time += oneTime;
        cout<<endl;
    }

    time /= repeats;
    outputFile<<"Time Avg\t"<<fixed<<setprecision(4)<<time<<endl;

}

void Run::runAll(int killSwitch)
{
    ofstream outputFile;
    outputFile.open (outFileName);
    outputFile<<"Input file\t"<<inFileName<<endl;
    outputFile<<"Optimal cost\t"<<optimal<<endl;

    double timeBf=0;
    double timeNN=0;
    double timeRn=0;
    double oneTimeB=0;
    double oneTimeN=0;
    double oneTimeR=0;
    NearestNeighbour nearestNeighbour;
    BruteForce bruteForce;
    Random random;

    for(int i = 0 ; i < repeats; i++)
    {
        oneTimeN = nearestNeighbour.runNN(graphMatrix,graphSize,startingNode,true);
        outputFile<<"Time NN Rep "<<i+1<<"\t"<<fixed<<setprecision(4)<<oneTimeN<<endl;
        timeNN += oneTimeN;
        cout<<endl;

        oneTimeB= bruteForce.runBrute(graphMatrix,graphSize,killSwitch,startingNode);
        outputFile<<"Time BF Rep "<<i+1<<"\t"<<fixed<<setprecision(4)<<oneTimeB<<endl;
        timeBf += oneTimeB;
        cout<<endl;

        oneTimeR = random.runRand(graphMatrix,graphSize);
        outputFile<<"Time RN Rep "<<i+1<<"\t"<<fixed<<setprecision(4)<<oneTimeR<<endl;
        timeRn += oneTimeR;
        cout<<endl;
    }

    timeBf /= repeats;
    timeNN /= repeats;
    timeRn /= repeats;

    outputFile<<"Avg Time BF \t"<<fixed<<setprecision(4)<<timeBf<<endl;
    outputFile<<"Avg Time NN \t"<<fixed<<setprecision(4)<<timeNN<<endl;
    outputFile<<"Avg Time Rn \t"<<fixed<<setprecision(4)<<timeRn<<endl;

}
