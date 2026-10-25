// DFS_Solver.hpp
#ifndef DFS_SOLVER_HPP
#define DFS_SOLVER_HPP

#include "Maze_Solver.hpp"

class DFS_Solver : public Maze_Solver {
  public:
    DFS_Solver();
    DFS_Solver(const std::vector<std::vector<int>>& maze, const Coord& start, const Coord& end);
    
    // reachable() is inherited from Maze_Solver.
    std::stack<Coord> getPath() const override;
    std::string toString() const override; 
};
#endif