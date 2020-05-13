#include<iostream>
#include<vector>
#include"MazeSolve.h"
using namespace std;

int main(int argc, char** argv){
  cout << "Test" << endl;

  int k = 15; // rows
  cout << "Number of Rows: ";
  cin >> k;
  int l = 20; // cols
  cout << "Number of Columns: ";
  cin >> l;
  vector<vector<int> > maze(k, vector<int>(l));
  MazeSolve m(k, l, maze);
  m.generateMaze();
  m.solveMaze();
  m.printSolvedMaze();

  return 0;
}
