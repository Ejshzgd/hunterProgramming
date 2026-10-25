// Maze_Solver.hpp
#ifndef MAZE_SOLVER_HPP
#define MAZE_SOLVER_HPP
#include <vector>
#include <stack>
#include <string>

struct Coord {
  int row;
  int col;
};

class Maze_Solver {
  public:
    Maze_Solver();
    Maze_Solver(const std::vector<std::vector<int>>& maze, const Coord& start, const Coord& end);

    std::vector<std::vector<int>> getMaze() const;
    Coord getStart() const;
    Coord getEnd() const;

    bool reachable() const;
    virtual std::stack<Coord> getPath() const = 0;
    virtual std::string toString() const;

    virtual ~Maze_Solver() = default;

    // helper function, check whether a Coord object is a valid cell in the maze and is open (value = 0)
    static bool isOpen(const std::vector<std::vector<int>>& maze, const Coord& cell);

  private:
    std::vector<std::vector<int>> maze_;
    Coord start_;
    Coord end_;
};
#endif