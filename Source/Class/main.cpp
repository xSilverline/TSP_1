#include <iostream>
#include <fstream>
#include "../Libraries/iniParser/INIReader.h"



using namespace std;

string inputFileName;
string outputFileName;

int repeats=0;
int killSwitch = 0;
bool progressBar = false;
int dataSize = 0;
int ** graphMatrix = nullptr;

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
    progressBar = configReader.GetBoolean("Settings","showProgressBar",false);

    cout << "Read DONE" << endl;
// Read Done, Ini file works properly :)

    fstream dataInput;
    dataInput.open(inputFileName);

    dataInput >> dataSize;

    graphMatrix = new int * [dataSize];

    //TODO: Add validation of input data
    //  Check if open, in proper format

    for(int i = 0; i< dataSize; i++)
    {
        graphMatrix[i] = new int [dataSize];
        for(int j = 0; j<dataSize;j++)
        {
            dataInput >> graphMatrix[i][j];
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








    return 0;
}
