#ifndef MAZESOlVE_H_
#define MAZESOlVE_H_

using std::cout;
class MazeSolve {
private:
  int rows;
  int cols;
  std::vector<std::vector<int> > maze;
public:
  void generateMaze();
  void solveMaze();
  void printSolvedMaze();
  MazeSolve(int rows, int cols, std::vector<std::vector<int> >& maze);
  ~MazeSolve();
};

#endif
