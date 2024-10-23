#include <iostream>
#include <fstream>
#include "stringvector.h"
using namespace std;

int main()
{
    clock_t time1=clock();

    StringVector stringvector; 
    string fileName = ("Dracula.txt");
    ifstream inputFile(fileName);

    if(!inputFile.is_open())
    {
        cout << "Error, could not open the file!" << endl;
    }

    //linear method
    //stringvector.AddUnsorted(inputFile);
    //stringvector.printUnsorted();

    // recurisve method
    stringvector.AddSorted(inputFile);
    stringvector.printSorted();


   clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n";

}