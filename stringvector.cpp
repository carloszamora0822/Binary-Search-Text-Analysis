#include <iostream>
#include "stringvector.h"
using namespace std;

// constructor
StringVector::StringVector()
{
    countCleanedWords = 0; 
    countTotalWords = 0; 
}

// destructor
StringVector::~StringVector()
{
}

// linear search
int StringVector::LinearSearch(string word)
{
    for(int i = 0; i < unsortedVector.size(); i++) 
    {
        if(word == unsortedVector[i]) 
        {
            return i;  
        }
    }

    return -1;
}

// adds all unique words into vector 
void StringVector::AddUnsorted(ifstream &inputfile) 
{
    string word;

    // starts reading file
    while (inputfile >> word) 
    {
        string cleanedWord = "";
        countTotalWords++;

        // checking its a valid word
        for (int i = 0; i < word.length(); i++) 
        {
            if (isalpha(word[i]) || word[i] == '-' || word[i] == '\'') 
            {
                cleanedWord += tolower(word[i]);
            }
        }

        // calling search method and storing values in unsorted vector
        if (!cleanedWord.empty()) 
        {
            int index = LinearSearch(cleanedWord);

            if (index == -1) 
            {
                unsortedVector.push_back(cleanedWord);
                countCleanedWords++;  
                index = unsortedVector.size() - 1;  
            }
        }
    }
}

// print unsorted vector and counts
void StringVector::printUnsorted()
{
    for(int i = 0; i < unsortedVector.size(); i++)
    {
        cout << unsortedVector[i] << endl;
    }

    cout << "Unique words: " << countCleanedWords << endl;
    cout << "Total words: " << countTotalWords << endl;
    
}

// binary search
int StringVector::BinarySearch(string word) 
{
    int low = 0;
    int high = sortedVector.size() - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if (sortedVector[mid] == word) 
        {
            return mid; // word found!
        } 
        else if (sortedVector[mid] < word) 
        {
            low = mid + 1; 
        } 
        else 
        {
            high = mid - 1;  
        }
    }

    return low;  
}



void StringVector::AddSorted(ifstream &inputfile) 
{
    string word;

    // reads file, method is from read_txt in project 3
    while (inputfile >> word) 
    {
        string cleanedWord = "";
        countTotalWords++;
        
        // check word validity
        for (int i = 0; i < word.length(); i++) 
        {
            if (isalpha(word[i]) || word[i] == '-' || word[i] == '\'') 
            {
                cleanedWord += tolower(word[i]);
            }
        }

        // recursive call to binary search
        if (!cleanedWord.empty()) 
        {
            int index = BinarySearch(cleanedWord);  

            if (index == sortedVector.size() || (index >= 0 && sortedVector[index] != cleanedWord)) 
            {
                sortedVector.insert(sortedVector.begin() + index, cleanedWord);
                countCleanedWords++;  
            }
        }
    }

}

// print sorted vector and counts
void StringVector::printSorted()
{
    for(int i = 0; i < sortedVector.size(); i++)
    {
        cout << sortedVector[i] << endl;
    }

    cout << "Unique words: " << countCleanedWords << endl;
    cout << "Total words: " << countTotalWords << endl;
    
}



