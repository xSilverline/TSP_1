#include <iostream>
#include <fstream>
#include "../Libraries/iniParser/INIReader.h"
#include "../Headers/Structures.h"
#include "../Headers/Run.h"

using namespace std;



string inputFileName;
string outputFileName;

int repeats=0;
int killSwitch = 0;
int startingNode = 0;
string method;
bool progressBar = false;
int dataSize = 0;
int optimalVal = 0;
int ** graphMatrix = nullptr;
listElement ** graphList = nullptr;



int main()
{

    INIReader configReader("config.ini");

    if(configReader.ParseError() < 0)
    {
        cout<<"Cannot read config file! "<<endl;
        return 1;
    }

    inputFileName = configReader.Get("Settings","inputFileName","NONE");
    outputFileName = configReader.Get("Settings","outputFileName","DefaultOutput.txt");
    repeats = configReader.GetInteger("Settings","numberOfRepeats",1);
    killSwitch = configReader.GetInteger("Settings","killSwitch",30000);
    startingNode = configReader.GetInteger("Settings","startingNode",0);
    progressBar = configReader.GetBoolean("Settings","showProgressBar",false);
    method = configReader.Get("Settings","chooseMethod","all");

    cout<<" ---- INPUT FILES ----"<<endl<<endl;
    cout<<"Config File: "<<"config.ini"<<endl;
    cout << "Input File: "<<inputFileName<<endl<<endl;
    cout<<" ---- OUTPUT FILES ----"<<endl<<endl;
    cout<<"Output File: "<<outputFileName<<endl<<endl;
// Read Done, Ini file works properly :)

    fstream dataInput;
    dataInput.open(inputFileName);

    dataInput >> dataSize;
    dataInput>>optimalVal;

    graphMatrix = new int * [dataSize];
    graphList = new listElement * [dataSize];
    listElement * newNode;



    int temp=0;
    for(int i = 0; i< dataSize; i++)
    {
        graphMatrix[i] = new int [dataSize];
        graphList[i] = nullptr;

        for(int j = 0; j<dataSize;j++)
        {
            dataInput >> temp;

            graphMatrix[i][j] = temp;

            if(temp != -1)
            {
                newNode = new listElement;
                newNode->target = j;
                newNode->weight = temp;
                newNode->next = graphList[i];
                graphList[i] = newNode;
            }


        }
    }
    cout<<" ---- PROGRAM SETTINGS ----"<<endl<<endl;
    cout<<"Time limit :"<<killSwitch<<" ms"<<endl;
    cout<<"Repeats: "<<repeats<<endl;
    cout<<"Method: "<<method<<endl;
    cout<<"First node (NN): "<<startingNode<<endl;
    cout<<"Instance size: "<<dataSize<<endl<<endl;



    cout<<" ---- KNOWN OPTIMAL ----"<<endl<<endl;
    cout<<"Optimal value: "<<optimalVal<<endl<<endl;

    cout<<" ---- RESULTS ----"<<endl<<endl;


//    cout<<"Optimal path: "<<endl;



//    for(int i = 0; i< dataSize; i++)
//    {
//        for(int j = 0; j<dataSize;j++)
//        {
//            cout<<graphMatrix[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    cout<<endl<<endl;

    Run run{};
    run.run(graphMatrix,dataSize,repeats,startingNode,progressBar,killSwitch,method,outputFileName,inputFileName,optimalVal);









    system("pause");
    return 0;
}

