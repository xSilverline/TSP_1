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
bool progressBar = false;
int dataSize = 0;
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
    cout << "Read Config File >>>>" << endl;
    inputFileName = configReader.Get("Settings","inputFileName","NONE");
    outputFileName = configReader.Get("Settings","outputFileName","DefaultOutput.txt");
    repeats = configReader.GetInteger("Settings","numberOfRepeats",1);
    killSwitch = configReader.GetInteger("Settings","killSwitch",1000);
    startingNode = configReader.GetInteger("Settings","startingNode",0);
    progressBar = configReader.GetBoolean("Settings","showProgressBar",false);

    cout << "Read DONE" << endl;
// Read Done, Ini file works properly :)

    fstream dataInput;
    dataInput.open(inputFileName);

    dataInput >> dataSize;

    graphMatrix = new int * [dataSize];
    graphList = new listElement * [dataSize];
    listElement * newNode;

    //TODO: Add validation of input data
    //  Check if open, in proper format

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

    for(int i = 0; i< dataSize; i++)
    {
        for(int j = 0; j<dataSize;j++)
        {
            cout<<graphMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    Run run;
    run.run(graphMatrix,dataSize,repeats,startingNode,progressBar);










    return 0;
}
