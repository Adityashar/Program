#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> ii;
typedef list<ii>::iterator lit;

class comp          ///for comparison
{
public:
    bool operator() ()

}

class Graph
{
    list<ii> *adjlist;
    int nV;
public:
    Graph(int V)
    {
        nV=V;
        adjlist=new list<ii>[nV+1];
    }

    void addEdge(int src,int dest,int wt)
    {
        adjlist[src].push_back(make_pair(dest,wt));   ///make_pair (,) returns a pair
    }
    int dijkstra(int src,int dest)
    {
        priority_queue<ii,vector<ii>,comp> pq;
        int *dist=new int [nV+1];
        for(int i=0; i<=nV; i++)
        {
            dist[i]=INT_MAX;
        }
        dist[src]=0;
        pq.push(make_pair(src,0));

        while(!pq.empty())
        {
            ii cur=pq.top();
            pq.pop();
            int curVer=cur.first;               ///first element of the pair cur
            int curWt=cur.second;               ///second element of the pair cur

            if(dist[curVer]<curWt)  continue;
            dist[curVer]=curWt;
            for(lit it=adjlist[curVer].begin(); it!=adjlist[curVer].end(); it++)
            {
                ii n=*it;
                int childDist=dist[curVer]+n.second;
                if(childDist>dist[it.first])    continue;
                pq.push(make_pair(n.first,childDist));
            }
        }
        for(int i=1; i<=nV; i++) cout<<i<<"-"<<dist[i]<<endl;
        int ans=dist[dest];
        delete [] dist;
        return ans;
    }
};


int main()
{
    Graph g(7);
    g.addEdge(1,2,10);
    g.addEdge(1,3,80);
    g.addEdge(2,3,6);
    g.addEdge(3,4,70);
    g.addEdge(2,5,20);
    g.addEdge(5,6,50);
    g.addEdge(5,7,10);
    g.addEdge(7,6,5);
    cout<<g.dijkstra(1,6)<<endl;
    return 0;
}


int main()
{

    return 0;
}
