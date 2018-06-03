#include<iostream>
using namespace std;
int **sol_mat;
//#define n 5
int n=5;
void printsolution(int **sol_mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sol_mat[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void recpath(int grid[][],int sol_mat[][],int x,int y){
    if(x==n-1 && y==n-1){
        sol_mat[x][y]=1;
        printsolution(sol_mat);
        return;
    }
    ///CONSTRAINTS TO BE ADDED
    if(x<0 || x>=n || y<0 || y>=n || sol_mat[x][y]==1 || grid[x][y]==1){
        return;
    }
    sol_mat[x][y]= 1;                                          ///AT EVERY POINT WE'LL CHECK IN ALL THE FOUR DIRECTIONS
    recpath(grid,sol_mat,x-1,y);
    recpath(grid,sol_mat,x+1,y);
    recpath(grid,sol_mat,x,y-1);
    recpath(grid,sol_mat,x,y+1);
    /// ONCE WE HAVE TRAVERSED ALL THE DIRECTIONS
    sol_mat[x][y]=0;
}

void pathtofollow(int grid[][],int &cnt){
    sol_mat=new int*[n];
    for(int i=0;i<n;i++){
        sol_mat[i]=new int [n];
    }
    recpath(grid,sol_mat,0,0);
}

int main(){
    int grid[][]={{0,0,0,1,0},
                  {0,1,0,1,0},
                  {0,1,0,1,0},
                  {0,0,0,0,0},
                  {1,0,1,1,0}};
    int cnt=0;
    pathtofollow(grid,cnt);
    return 0;
}
