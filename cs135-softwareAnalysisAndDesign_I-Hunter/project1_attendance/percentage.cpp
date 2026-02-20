/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-10
Updated:     2026-2-10
Description: Reads in a zoom-style csv file
        - Prints out the percentage of students who attended for at least x minutes
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <iomanip>

using namespace std;


int main(){

    string zoomFile;
    int totalDuration;

    cout << "Enter a zoom-style csv file, containing Name (original name),Email,Total totalDuration (minutes),Guest: ";
    cin >> zoomFile;
    cout << " Enter the number of minutes to attend: ";
    cin >> totalDuration;


    ifstream reader(zoomFile);
    if(reader.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    //Stores the header
    string junk;
    getline(reader,junk);


    int totalPpl = 0, pplWhoStayed = 0 , duration = 0;
    string temp;

    //Reads each line and stores the concatenated string (temp)
    while(getline(reader,temp))
    {
        //Parses temp, duration is between the second and third comma
        int secondComma = temp.find(',',temp.find(',')+1);
        int thirdComma = temp.find(',',secondComma+1);
        duration = stoi(temp.substr(secondComma+1,thirdComma-secondComma-1));


        if(duration >= totalDuration)
        {
            pplWhoStayed++;
        }
        totalPpl++;
        
    }

    cout << "percentage of students attend at least " << fixed << setprecision(2) << totalDuration << " minutes is " << ((pplWhoStayed*1.0/totalPpl*1.0)*100.0) << '%';

    return 0;
}