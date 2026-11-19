//DFS_Solver.cpp    
#include "DFS_Solver.hpp"

bool equalCellDFS(Coord const cellOne, Coord const cellTwo);
void helper(const Coord& cell, const Coord& end, const std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visitMap, std::stack<Coord>& path);

DFS_Solver::DFS_Solver() : Maze_Solver() {
}

DFS_Solver::DFS_Solver(const std::vector<std::vector<int>>& maze, const Coord& start, const Coord& end): Maze_Solver(maze,start,end){
}

std::stack<Coord> DFS_Solver::getPath() const{
    std::vector<std::vector<bool>> visitMap;
    std::stack<Coord> path;
    const Coord start = getStart();
    const Coord end = getEnd();

    if (!isOpen(getMaze(), start) || !isOpen(getMaze(), end)){
        return path;
    }

    //visited = true 
    //unvisited = false;
    visitMap.resize(getMaze().size());
    for(int r = 0; r < getMaze().size(); r++)
    {
        int colSize = getMaze().at(r).size();
        visitMap.at(r).resize(colSize);

        for(int c = 0; c < colSize; c++)
        {
            visitMap[r][c] = false;
        }
    }

    helper(start,end,getMaze(),visitMap,path);
    return path;

}


void helper(const Coord& cell, const Coord& end, const std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visitMap, std::stack<Coord>& path){  
    visitMap[cell.row][cell.col] = true;

    if(equalCellDFS(cell,end)){
       path.push(cell); 
       return;
    }
    
    Coord neighbors[] = {
                            {cell.row, cell.col-1}, //Left
                            {cell.row, cell.col+1}, //Right
                            {cell.row-1, cell.col}, //Up
                            {cell.row+1, cell.col}  //Down
                        };

    for(const Coord& n : neighbors){
        if(Maze_Solver::isOpen(maze,n) && !visitMap[n.row][n.col]){
            helper(n,end,maze,visitMap,path);

            if(!path.empty()){
                path.push(cell);
                return;
            }
        }
    }
}

bool equalCellDFS(Coord const cellOne, Coord const cellTwo){
    if(cellOne.row == cellTwo.row && cellOne.col == cellTwo.col)
    {
        return true;
    }
    return false;
}

std::string DFS_Solver::toString() const {
    return "Use Depth First Search\n" + Maze_Solver::toString();
}