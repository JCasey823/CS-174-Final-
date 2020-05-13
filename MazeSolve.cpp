/**
*Maze game with solver wriiten in C++
*@author Andrew Kelly and Justin Casey CS-174
*@version 1.0, May 13, 2020
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include"MazeSolve.h"
using namespace std;

/**
* The consructor takes number of rows, columns, 2D vector to be used in class
* @param initialsize The initial size of the internal array used in making an IntVector
* @return void
*/
MazeSolve::MazeSolve(int rows, int cols, vector<vector<int> >& maze){
  this->rows = rows;
  this->cols = cols;
  this->maze = maze;
}

MazeSolve::~MazeSolve(){
  maze.clear();
}


/**
* Generates a random maze using empty maze created in constructor
* @param
* @return void
*/

void MazeSolve::generateMaze(){
  // generate maze of walls
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j){
      maze[i][j] = 1;
    }
  }
// set boundary conditions
for(int i = 0; i < rows-1;++i){
  maze[i][0] = 4;
  maze[i][cols-1] = 4;
}
// set boundary conditions
for(int i = 0; i < cols-1; ++i){
  maze[rows-1][i] = 5;
  maze[0][i] = 5;
}
// set boundary conditions
maze[rows-1][cols-1] = 5;
maze[0][cols-1] = 5;

//Initiailize starting point
int i = 1;
int j = 1;
maze[i][j] = 0;
bool stop = false;
srand(time(0));//seed a random number for our random number genrator
// we will use to randomly generate the maze
int step = 0;

while (step < cols){

  step++;
  bool done = false;
  while(done == false){
    int pick = 1+(rand()%4);
    if (pick == 1){
      if (maze[i+1][j] == 1){
        maze[i+1][j] = 3;
        ++i;
        done = true;
      }else{
        done = false;
      }
    }if (pick == 2){
      if (maze[i-1][j] == 1){
        maze[i-1][j] = 3;
        --i;
        done = true;
      }else{
        done = false;
      }
    }if (pick == 3){
      if (maze[i][j+1] == 1){
        maze[i][j+1] = 2;
        ++j;
        done = true;
      }else{
        done = false;
      }
    }if (pick == 4){
      if (maze[i][j-1] == 1){
        maze[i][j-1] = 2;
        --j;
        done = true;
      }else{
        done = false;
      }
    }if (maze[i+1][j] !=1 && maze[i-1][j] != 1 && maze[i][j+1] != 1 && maze[i][j-1] != 1){
        maze[i][j] = 1;
        done = true;
    }

  }
}

maze[i][j] = 9;// Set Goal

}

/**
* Solves randomly generated maze created by generateMaze method
* does so by first finding all junction points then following a
* a path until either a goal or deas end is reached
* @param
* @return void
*/

void MazeSolve::solveMaze(){
  // 2 for loops search for all points where there will be no
  // 2 or more paths we can follow
  for(int i = 1; i < rows-1; ++i){
    for (int j = 1; j < cols-1; ++j){
      if(maze[i][j] == 2){
        if(maze[i+1][j] == 3 && maze[i][j+1] == 2 ){
           maze[i][j] = 8;
        }if(maze[i+1][j] == 3 && maze[i][j-1] == 2 ){
          maze[i][j] = 8;
        }if(maze[i-1][j] == 3 && maze[i][j+1] == 2){
           maze[i][j] = 8;
         }if(maze[i-1][j] == 3 && maze[i][j-1] == 2){
           maze[i][j] = 8;
       }
     }else if(maze[i][j] == 3){
       if(maze[i+1][j] == 3 && maze[i][j+1] == 2 ){
          maze[i][j] = 8;
       }if(maze[i+1][j] == 3 && maze[i][j-1] == 2 ){
          maze[i][j] = 8;
       }if(maze[i-1][j] == 3 && maze[i][j+1] == 2){
          maze[i][j] = 8;
        }if(maze[i-1][j] == 3 && maze[i][j-1] == 2){
          maze[i][j] = 8;
      }
     }
   }
 }

    // initialize i and j at our starting points
    int i = 1;
    int j = 1;
    // while loop navigates through maze by checking value in a given a cell and
    // either goes down, right,
    while(maze[i][j] != 9){
      // if statement checks to see if within one move of goal
      if(maze[i+1][j] == 9 || maze[i-1][j] == 9 || maze[i][j+1] == 9 || maze[i][j-1] == 9){
        if(maze[i+1][j] == 9){
          cout << "Down" << endl;
          maze[i][j] = 7;
          ++i;
        }else if(maze[i-1][j] == 9){
          cout << "Up" << endl;
          maze[i][j] = 7;
          --i;
        }else if(maze[i][j+1] == 9){
          cout << "Right" << endl;
          maze[i][j] = 7;
          ++j;
        }else{
          cout << "Left" << endl;
          maze[i][j] = 7;
          --j;
        }
        // Next four else if statements decide which direction to move the
        // depending on value of surronfing cells and marks current cell as visited
      }else if(maze[i+1][j] == 3 || maze[i+1][j] == 8){
        cout << "down" << endl;
        if(maze[i][j] != 8){
          maze[i][j] = 7;
        }else{
          maze[i][j] = 6;
        }
        ++i;
      }else if(maze[i][j+1] == 2 || maze[i][j+1] == 8){
        cout << "right" << endl;
        if(maze[i][j] != 8){
          maze[i][j] = 7;
        }else{
          maze[i][j] = 6;
      }
      ++j;
    }else if(maze[i-1][j] == 3 || maze[i-1][j] ==8){
        cout << "up" << endl;
        if(maze[i][j] != 8){
          maze[i][j] = 7;
        }else{
          maze[i][j] = 6;
      }
       --i;
     }else if(maze[i][j-1] == 2 || maze[i][j-1] == 8){
        cout << "left" << endl;
        if(maze[i][j] != 8){
          maze[i][j] = 7;
        }else{
          maze[i][j] = 6;
        }
        --j;

      // If no unvisited cells are available to move to, we must be at a dead end
      // We then back trace through visited cells, closing them off with walls to be sure not
      // to follow this path again, until we reach an unvisited cell
    }else if(maze[i+1][j] != 3 && maze[i-1][j] != 3 && maze[i][j+1] != 2 && maze[i][j-1] != 2){

        while(maze[i+1][j] != 3 && maze[i-1][j] != 3 && maze[i][j+1] != 2 && maze[i][j-1] != 2){
          if(maze[i-1][j] == 7 || maze[i-1][j] ==6){
            cout << "UP" << endl;
            if(maze[i][j] != 6){
              maze[i][j] = 1;
            }
            --i;
          }else if(maze[i][j-1] == 7 || maze[i][j-1] == 6){
            cout << "LEFT" << endl;
            if(maze[i][j] != 6){
              maze[i][j] = 1;
            }
            --j;
          }else if(maze[i+1][j] == 7 || maze[i+1][j] == 6){
            cout << "DOWN" << endl;
            if(maze[i][j] != 6){
              maze[i][j] = 1;
            }
            ++i;
          }else if(maze[i][j+1] == 7 || maze[i][j+1] == 6){
            cout << "RIGHT" << endl;
            if(maze[i][j] != 6){
              maze[i][j] = 1;
            }
            ++j;
          }
        }
      }
    }
  }



/**
* Prints out solved Maze with 7 being a visited cell, 6 being a visited junction cell
* and 8, :, and - being unvisted cells and junctions
* @param
* @return void
*/

void MazeSolve::printSolvedMaze(){
  for (int i=0; i<rows; ++i){
    for (int j=0; j<cols;++j){
      if( maze[i][j] == 2){
	cout<<"-"<<" ";
      }else if (maze[i][j] == 3){
	cout << ":" << " ";
      }else if(maze[i][j] == 4){
	cout << "|"<< " ";
      }else if(maze[i][j] == 1){
	cout << "X" << " ";
      }else if(maze[i][j] == 5){
	cout << "_" << " ";
      }else{
	cout << maze[i][j] << " ";
      }
    }
    cout << endl;
  }

  cout << "Solved" << endl;

}
