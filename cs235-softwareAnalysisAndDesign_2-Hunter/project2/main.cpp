// main.cpp
#include "Maze_Solver.hpp"
#include "DFS_Solver.hpp"
#include "BFS_Solver.hpp"
#include <iostream>
#include <string>

int main() {
  DFS_Solver dfs;
  BFS_Solver bfs;
  Maze_Solver *solvers[]{&dfs, &bfs};
  for (const Maze_Solver* curr : solvers) {
    std::cout << curr->toString() << '\n';
  }

  return 0;
}