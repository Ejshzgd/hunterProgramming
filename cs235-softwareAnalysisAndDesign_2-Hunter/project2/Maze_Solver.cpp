// Maze_Solver.cpp
#include "Maze_Solver.hpp"
#include <sstream> // Required for std::ostringstream
#include <iomanip> // Required for std::setw and std::setfill

Maze_Solver::Maze_Solver() : 
maze_({{0, 0, 0}, {1, 0, 0}, {0, 0}}), start_({0, 0}), end_({2, 1}) 
// maze_({{0, 0, 1}, {0, 1}, {0, 0}}), start_({0, 0}), end_({2, 1})
{
}

// make a deep copy
Maze_Solver::Maze_Solver(const std::vector<std::vector<int>>& maze, const Coord& start, const Coord& end) : maze_(maze), start_(start), end_(end) {
}

std::vector<std::vector<int>> Maze_Solver::getMaze() const {
  return maze_;
}

Coord Maze_Solver::getStart() const {
  return start_;
}

Coord Maze_Solver::getEnd() const {
  return end_;
}

bool Maze_Solver::reachable() const {
  return !getPath().empty();
}

std::string Maze_Solver::toString() const {
  std::ostringstream ss;
  ss << "Find a path from (" << start_.row 
     << ", " << start_.col << ") to (" 
     << end_.row << ", " << end_.col << ")\n";

  int maxNumCols = 0;
  for (int i = 0; i < static_cast<int>(maze_.size()); i++) {
    if (maxNumCols < static_cast<int>(maze_[i].size())) {
      maxNumCols = maze_[i].size();
    }
  }

  std::string b_header = "\033[34mcol "; // \033[34m is blue color
  ss << b_header << std::setw(3) << " ";
  for (int col = 0; col < maxNumCols; col++) {
    ss << std::setw(2) << col << " "; 
  }
  ss << "\n\033[0m"; // \033[0m restores to black font

  for (int row = 0; row < static_cast<int>(maze_.size()); row++) {
    if (row == 0) {
      ss << "\033[32mrow "; // \033[32m is green color
    }
    else {
      ss << std::setw(4) << " "; // length of "row "
    }
    ss << "\033[32m" << std::setw(2) << row << " \033[0m";
  
    for (int col = 0; col < static_cast<int>(maze_[row].size()); col++) {
      if (row == start_.row && col == start_.col) {
        ss << "\033[30;48;2;230;230;230m\033[31m\033[1m" << std::setw(2) <<  maze_[row][col] << " \033[0m"; // \033[30;48;2;230;230;230m very light gray background, \033\[31m red, \033\[1m bold
      }
      else if (row == end_.row && col == end_.col) {
        ss << "\033[30;48;2;230;230;230m\033[36m\033[1m" << std::setw(2) <<  maze_[row][col] << " \033[0m"; // \033[30;48;2;230;230;230m very light gray background, \033\[36m cyan, \033\[1m bold
      }
      else {
        ss << std::setw(2) << maze_[row][col] << " "; 
      }

    }
    ss << '\n';
  }

  std::stack<Coord> pathStack = getPath();

  if (pathStack.empty()) {
    ss << "No path.\n";
    return ss.str();
  }

  ss << "\nA path: \n";

  std::vector<std::vector<int>> mazeClone = maze_;
  while (!pathStack.empty()) {
    Coord cell = pathStack.top();
    pathStack.pop();
    mazeClone[cell.row][cell.col] = '*';
    ss << "(" << cell.row 
       << "," << cell.col << ")";

    if (pathStack.size() >= 1) {
      ss << " -> ";
    }
  }
  ss << "\n\n";

  for (std::size_t i = 0; i < mazeClone.size(); i++) {
    for (std::size_t j = 0; j < mazeClone[i].size(); j++) {
      if (mazeClone[i][j] == '*') {
        ss << "* ";
      }
      else {
        ss << mazeClone[i][j] << " ";
      }
    }
    ss << "\n";
  }

  return ss.str();
}

bool Maze_Solver::isOpen(const std::vector<std::vector<int>>& maze, const Coord& cell) {
  if (cell.row < 0 || cell.row >= static_cast<int>(maze.size()) ||
      cell.col < 0 || cell.col >= static_cast<int>(maze[cell.row].size()) ||
      maze[cell.row][cell.col] != 0) {
    return false;
  }

  return true;
}