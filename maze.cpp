#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(int argc, char** argv){
  int k = 10;
  int maze[k][k];
  // for loop to create maze
  for (int i = 0; i < k; ++i){
    for (int j = 0; j < k; ++j){
      maze[i][j] = 1;
    }
  }

  int i = 1;
  int j = 1;
  maze[0][0] = 0;
  maze[i][j] = 0;
  int step = 1;
  bool up_down = true; // true = vertical false = horizontal
  int max_idx = k-1;
  srand(time(0));
  // while loop to create correct path
  while(i < max_idx && j < k){
    int a = i; //make these pointers
    int b = j;
      if(step %5 != 0){
        if(up_down == true){
          while(a < k-1){
            maze[a][b] = 0;
            up_down = false;
            ++a;
            //cout << 2 << endl;
          }
        }else{
          while(b < k-1){
            maze[a][b] = 0;
            up_down = true;
            ++b;
            //cout << 3 << endl;
          }
        }
      }


      int pick = 1+(rand()%5);

      if(pick == 1){
        maze[i+1][j] = 0;
        ++i;
      }else if(pick == 2){
        maze[i][j+1] = 0;
        ++j;
      }else if(pick == 3){
        maze[i-1][j] = 0;
        ++i;
      }else if(pick == 4){
        maze[i][j-1] = 0;
        ++j;
      }else{
        maze[i+1][j+1] = 0;
        ++i;
        ++j;
      }
      //cout << i << " " << j << endl;
      ++step;
    }

    for(int i = 0; i < max_idx; ++i){
        if(maze[0][i] == 0 && i != 1){
          maze[i][0] = 1;
        }else if(maze[i][0] == 0){
          maze[i][0] = 1;
        }
    }

    maze[0][0] = 0;


  // prints out maze
  for (int i=0; i<k; ++i){
    for (int j=0; j<k;++j){
      cout << maze[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
