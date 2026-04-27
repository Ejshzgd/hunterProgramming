#include "Floor.hpp"
#include <string>
#include <iostream>

using namespace std;

Floor::Floor() : Floor(20){}

Floor::Floor(int size){
    if(size < 10)
    {
        size = 20;
    }

    grid.resize(size);

    for(std::vector<char> &row : grid)
    {
        row.resize(size);
        for(char &c : row)
        {
                c = ' ';
        }
    }
}

int Floor::getNumRows() const{
    return grid.size();
}

int Floor::getNumCols() const{
    return grid[0].size();
}

void Floor::mark(int row, int col, char ch){
    if(row >= 0 && row < getNumRows() &&
       col >= 0 && col < getNumCols())
    {
        grid[row][col] = ch;
    }
}

char Floor::at(int row, int col) const{
    if(row >= 0 && row < getNumRows() &&
       col >= 0 && col < getNumCols())
    {
        return grid[row][col];
    }
    return '\0';
}

void Floor::clear(){
    for(std::vector<char> &row : grid)
    {
        for(char &c : row)
        {
            c = ' ';
        }
        }
}

string Floor::to_string() const {
    int rows = getNumRows();
    int cols = getNumCols();
    string out;

    // ===== column tens row =====
    out += "  ";
    for (int c = 0; c < cols; c++) {
        if (c % 10 == 0 && c / 10 >= 1)
            out += char('0' + c / 10);
        else
            out += ' ';
    }
    out += '\n';

    // ===== column units row =====
    out += "  ";
    for (int c = 0; c < cols; c++) {
        out += char('0' + c % 10);
    }
    out += '\n';

    // ===== grid =====
    for (int r = 0; r < rows; r++) {

        // row label
        if (r % 10 == 0 && r / 10 >= 1)
            out += char('0' + r / 10);
        else
            out += ' ';

        out += char('0' + r % 10);

        // row contents
        for (int c = 0; c < cols; c++) {
            out += grid[r][c];
        }

        out += '\n';
    }

    return out;
}
