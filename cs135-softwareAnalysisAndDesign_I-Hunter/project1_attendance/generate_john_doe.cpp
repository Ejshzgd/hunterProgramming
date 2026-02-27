/*
Copyright (c) 2026 Carey Jiang

Author:      Carey Jiang
Created:     2026-2-18
Updated:     2026-2-18
Description: Writes the contents of john_doe.txt into a .pdf file
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){

    string outputFilename,johnDoeFile;

    johnDoeFile = "%PDF-1.4\n1 0 obj\n<< /Type /Catalog /Pages 2 0 R >>\nendobj\n2 0 obj\n<< /Type /Pages /Kids [3 0 R] /Count 1 >>"
                  "\nendobj\n3 0 obj\n<<\n  /Type /Page\n  /Parent 2 0 R\n  /MediaBox [0 0 612 792]\n  /Contents 4 0 R\n  /Resources <<"
                  "\n    /Font <<\n      /F1 5 0 R\n    >>\n  >>\n>>\nendobj\n4 0 obj\n<< /Length 44 >>\nstream\nBT\n/F1 24 Tf\n100 692 Td"
                  "\n(John Doe) Tj\nET\nendstream\nendobj\n5 0 obj\n<<\n  /Type /Font\n  /Subtype /Type1\n  /BaseFont /Helvetica-Bold"
                  "\n>>\nendobj\nxref\n0 6\n0000000000 65535 f \n0000000009 00000 n \n0000000058 00000 n \n0000000115 00000 n \n0000000267 00000 n "
                  "\n0000000357 00000 n \ntrailer\n<< /Size 6 /Root 1 0 R >>\nstartxref\n438\n%%EOF";

    cout << "Enter a .pdf file to write to: ";
    cin >> outputFilename;


    ofstream outFile(outputFilename);

    if(outFile.fail())
    {
        cerr << "File cannot be opened!" << endl;
        exit(1);        
    }
    

    outFile << johnDoeFile;
    
    outFile.close();

    cout << "Data written to log.txt successfully." << endl;


    return 0;
}

