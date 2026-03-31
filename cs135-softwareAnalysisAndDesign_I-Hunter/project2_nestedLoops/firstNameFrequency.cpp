/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-3-27
Updated:     2026-3-27
Description: Read a TSV file
                -Contains  a header line followed by names in "first name last name" format
             Initialize an array and set max capacity to 100
             Sort the array in first name alphabetical order (Selection Sort)
             Count the frequency of each first name and output the results

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cmath>

using namespace std;


int main(){

    string fileName, junk;

    cout << "Enter a file name in .tsv: ";
    cin >> fileName;

    ifstream reader(fileName);

    if(reader.fail())
    {
        cerr << "File cannot be opened!" << endl;
        exit(1);   
    }

    //Stores the header
    getline(reader,junk);


    int countArr = 0;
    string names[100];
    string firstName;

    //Reads in all the first names and stores them in "names"
    while(reader >> firstName >> junk)
    {
        names[countArr] = firstName;
        countArr++;
    }
    
    //Loops through "names" , finds the smallest letter, swaps the current and smallest letter position
    //If the letters are the same, checks the next letter
    for(int i = 0; i < countArr-1; i++)
    {
        int minIndex = i;
        string minName = names[i];

        for(int n = i + 1; n < countArr; n++)
        {
            int countIndex = 0;
            string name = names[n];
            if(minName[countIndex] >= name[countIndex])
            {
                while(countIndex < name.length() && countIndex < minName.length())
                {
                    if(minName[countIndex] > name[countIndex])
                    {
                        minIndex = n;
                        minName = names[n];
                        break;
                    }
                    countIndex++;
                }
            }
            
        }
        names[minIndex] = names[i];
        names[i] = minName;
    }
    
    //Loops through the sorted array , counts the frequency of each unique first name
    int index = 0;
    while(index < countArr)
    {   
        int count = index + 1;
        string name = names[index];
        while(count < countArr && name == names[count])
        {
            count++;
        }

        cout << name << ',' << abs(count-index) << endl;
        index = count;
    }


    return 0;
}