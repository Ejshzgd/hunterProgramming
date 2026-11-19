//BFS_Solver.cpp    
#include "BFS_Solver.hpp"
#include <queue>

bool equalCellBFS(Coord const cellOne, Coord const cellTwo);

BFS_Solver::BFS_Solver():Maze_Solver(){}

BFS_Solver::BFS_Solver(const std::vector<std::vector<int>>& maze, const Coord& start, const Coord& end):Maze_Solver(maze,start,end){}

std::stack<Coord> BFS_Solver::getPath() const {
    std::stack<Coord> path;
    std::queue<Coord> toExplore;
    std::vector<std::vector<bool>> visitMap;
    std::vector<std::vector<Coord>> parent;

    const Coord start = getStart();
    const Coord end = getEnd();

    if (!isOpen(getMaze(), start) || !isOpen(getMaze(), end)) {
        return path;
    }

    // Initialize visited and parent maps
    for (const auto& row : getMaze()) {
        visitMap.push_back(std::vector<bool>(row.size(), false));
        parent.push_back(std::vector<Coord>(row.size(), {-1, -1}));
    }

    // Start BFS
    visitMap[start.row][start.col] = true;
    toExplore.push(start);

    bool found = false;

    while (!toExplore.empty()) {
        const Coord cell = toExplore.front();
        toExplore.pop();

        if (equalCellBFS(cell, end)) {
            found = true;
            break;
        }

        Coord neighbors[] = {
            {cell.row, cell.col - 1}, // Left
            {cell.row, cell.col + 1}, // Right
            {cell.row - 1, cell.col}, // Up
            {cell.row + 1, cell.col}  // Down
        };

        for (const Coord& n : neighbors) {
            if (isOpen(getMaze(), n) && !visitMap[n.row][n.col]) {
                visitMap[n.row][n.col] = true;
                parent[n.row][n.col] = cell;
                toExplore.push(n);
            }
        }
    }

    // Return empty stack if no path exists
    if (!found) {
        return path;
    }

    // Reconstruct path from end to start
    Coord current = end;

    while (!equalCellBFS(current, start)) {
        path.push(current);
        current = parent[current.row][current.col];
    }

    path.push(start);

    return path;
}

bool equalCellBFS(Coord const cellOne, Coord const cellTwo){
    if(cellOne.row == cellTwo.row && cellOne.col == cellTwo.col)
    {
        return true;
    }
    return false;
}

std::string BFS_Solver::toString() const {
    return "Use Breadth First Search\n" + Maze_Solver::toString();
}