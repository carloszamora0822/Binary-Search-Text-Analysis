#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class StringVector
{
    public:
    StringVector();
    ~StringVector();

    int LinearSearch(string word);
    void AddUnsorted(ifstream &inputfile);

    int BinarySearch(string word);  
    void AddSorted(ifstream &inputfile);

    bool TRACE = true;

    void printSorted(); 
    void printUnsorted();


    private:
    vector<string> unsortedVector;
    vector<string> sortedVector;
    int countCleanedWords;
    int countTotalWords;

};