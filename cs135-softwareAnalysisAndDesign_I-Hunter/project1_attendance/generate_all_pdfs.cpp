/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-25
Updated:     2026-2-25
Description: Reads the names of a .csv file
            - Generate a pdf for each name and write it's content based on John_Doe.pdf
            - Format: firstName_lastName.pdf
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;


int main(){

    string fileName;


    cout << "Enter a file in .CSV format: ";
    cin >> fileName;


    ifstream reader(fileName);
    if(reader.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    //Stores the header
    string junk;
    getline(reader,junk);


    //Reads every line and extracts the names
    string concatString, firstName, lastName;
    while(getline(reader,concatString)){
        //Ex: Carey Jiang,blahblah
        int firstSpace = concatString.find(' ');
        int firstComma = concatString.find(',');

        firstName = concatString.substr(0,firstSpace);
        lastName = concatString.substr(firstSpace+1, firstComma-firstSpace-1);


        //John_Doe.pdf's changing values
        int val1 = 44, val3 = 357, val4 = 438 , differ, val2Length; 
        string val2;
        

        //John_Doe has a length of 8,
        //If the length of a name is greater than 8, then increase the values by the difference
        //Else subtract the values by the difference
        val2 = firstName + ' ' + lastName;
        val2Length = val2.length();
        (8 > val2Length) ? ((differ = 8-val2Length) , (val1 -= differ) , (val3 -= differ) , (val4 -= differ)) 
        : ((differ = val2Length-8) , (val1 += differ) , (val3 += differ) , (val4 += differ));
        
        
        string fileContent = "%PDF-1.4\n1 0 obj\n<< /Type /Catalog /Pages 2 0 R >>\nendobj\n2 0 obj\n<< /Type /Pages /Kids [3 0 R] /Count 1 >>"
                  "\nendobj\n3 0 obj\n<<\n  /Type /Page\n  /Parent 2 0 R\n  /MediaBox [0 0 612 792]\n  /Contents 4 0 R\n  /Resources <<"
                  "\n    /Font <<\n      /F1 5 0 R\n    >>\n  >>\n>>\nendobj\n4 0 obj\n<< /Length "+ to_string(val1) + " >>\nstream\nBT\n/F1 24 Tf\n100 692 Td"
                  "\n("+ val2 +") Tj\nET\nendstream\nendobj\n5 0 obj\n<<\n  /Type /Font\n  /Subtype /Type1\n  /BaseFont /Helvetica-Bold"
                  "\n>>\nendobj\nxref\n0 6\n0000000000 65535 f \n0000000009 00000 n \n0000000058 00000 n \n0000000115 00000 n \n0000000267 00000 n "
                  "\n0000000"+ to_string(val3) +" 00000 n \ntrailer\n<< /Size 6 /Root 1 0 R >>\nstartxref\n"+ to_string(val4) +"\n%%EOF";


        ofstream writer("data/" + (firstName + '_' + lastName) + ".pdf");
        writer << fileContent;
        
    }


    return 0;
}