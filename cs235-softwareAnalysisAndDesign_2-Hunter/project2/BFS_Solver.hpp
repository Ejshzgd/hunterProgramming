// BFS_Solver.hpp
#ifndef BFS_SOLVER_HPP
#define BFS_SOLVER_HPP
#include "Maze_Solver.hpp"

class BFS_Solver : public Maze_Solver {
  public:
    BFS_Solver();
    BFS_Solver(const std::vector<std::vector<int>>& maze, const Coord& start, const Coord& end);

    // reachable() is inherited from Maze_Solver.
    std::stack<Coord> getPath() const override;
    std::string toString() const override;
};
#endif