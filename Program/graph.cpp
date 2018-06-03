#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;               ///int *arr= new int [];
public:
    Graph(int Vertices){
    V=Vertices;
    l=new list<int>[V];
    }
    void addEdge(int u,int v,bool bidirect=true){
        l[u].push_back(v);
        if(bidirect)    l[v].push_back(u);
    }
    void PrintAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"  --> ";

            for(auto it=l[i].begin();it!=l[i].end();it++){
                cout<<*it<<", ";
            }
            cout<<endl;
        }
    }
    void bfs(int s){
        bool *visited=new bool[V];
        for(int i=0;i<V;i++)    visited[V]=false;

        queue<int> q;
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int f=q.front();
            cout<<f<<" ";
            q.pop();

            for(auto ip=l[f].begin();ip!=l[f].end();ip++){
                if(!visited[*ip]){
                    q.push(*ip);
                    visited[*ip]=true;
                }
            }
        }
        cout<<endl;
    }
    void distance(int s,int u){
        int *distance=new int [V];
        int *parent=new int [V];
        for(int i=0;i<V;i++){
            if(i==s)    distance[i]=0;
            else distance[i]=-1;
            parent[i]=-1;
        }

        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int f=q.front();
            cout<<f<<"   "<<distance[f]<<endl;
            q.pop();
            for(auto ip=l[f].begin();ip!=l[f].end();ip++){
                if(distance[*ip]==-1){
                    q.push(*ip);
                    distance[*ip]=distance[f]+1;
                    //p[f].push_back(*ip);
                    parent[*ip]=f;

                }
            }
        }
        cout<<"\nThe distance for d is :: "<<distance[u]<<endl<<"Path is :"<<u<<"<-- ";
        int p=parent[u];
        while(p!=-1){
            cout<<p<<"<-- ";
            p=parent[p];
        }
    }
    void dfs_recursive(int node,bool *visited){
        cout<<node<<" ";
        visited[node]=true;

        for(auto ip=l[node].begin();ip!=l[node].end();ip++){
            if(!visited[*ip]){
                dfs_recursive(*ip,visited);
            }
        }
    }

    void dfs(int s){
        bool *visited=new bool [V];
        for(int i=0;i<V;i++)    visited[i]=false;
        dfs_recursive(s,visited);
        cout<<endl;
    }
    void dfsAllComponent(){
        bool *visited=new bool [V];
        for(int i=0;i<V;i++)    visited[i]=false;

        int component=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                component++;
                cout<<"component :"<<component<<" ";
                dfs_recursive(i,visited);
                cout<<endl;
            }
        }
    }
};

int main(){
    Graph g1(13);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(0,3);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.addEdge(4,5);
    g1.addEdge(6,7);
    g1.addEdge(6,8);
    g1.addEdge(9,10);
    g1.addEdge(10,11);
    g1.addEdge(10,12);
   // g1.PrintAdjList();
    //g1.dfs(0);
    //g1.dfs(2);
    g1.dfsAllComponent();

    return 0;
}

/*
int main(){
    Graph g(37);
    int board[37];
    for(int i=1;i<=36;i++)
            board[i]=i;
    board[2]=15;
    board[5]=7;
    board[9]=27;
    board[18]=29;
    board[25]=35;
    board[34]=12;
    board[32]=30;
    board[24]=16;
    board[20]=6;
    board[17]=4;

    for(int i=1;i<=36;i++){
        for(int j=1;j<=6;j++){
            int dest=i+j;
            if(dest<=36){
                dest=board[dest];
                g.addEdge(i,dest,false);
            }
        }
    }
    g.distance(1,36);

    return 0;
}

*/




/*
int main(){
    Graph g1(6);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(0,3);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(3,4);
    g1.addEdge(4,5);
    g1.PrintAdjList();

    g1.bfs(0);
    g1.bfs(4);
    g1.distance(0,4);
    return 0;
}
*/
