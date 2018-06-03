#include<iostream>
#include<cstring>
using namespace std;
#define M 5
#define N 5

void PrintMaze(char maze[M][N]){
    for (int i=0; i<M;i++){
        for (int j=0;j<N;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void BringRattoCheese(char maze[M][N], int &cnt, int r, int c){
    maze[r][c]='*';
    if (r==M-1 && c==N-1 ){
        cnt++;
        PrintMaze (maze);
        return;
    }
    if (r<M-1 && maze[r+1][c]!='x') BringRattoCheese(maze,cnt,r+1,c);
    if (c<N-1 && maze[r][c+1]!='x') BringRattoCheese(maze,cnt,r,c+1);
    maze[r][c]='0';
}


int main(){

    char maze[M][N]={{'0','0','0','x','0'},
                     {'0','x','0','x','0'},
                     {'0','x','0','x','0'},
                     {'0','0','0','0','0'},
                     {'0','0','x','0','0'}};

    int cnt=0;

    BringRattoCheese (maze,cnt,0,0);

    cout<<cnt;
}
