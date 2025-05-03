#include<iostream>
using namespace std;

const int MAX=100;
int visited[MAX];
int adj[MAX][MAX];
int n,e;

void bfs(int start)
{
    int queue[MAX];
    int front=0,rear=0;
    visited[start]=true;
    queue[rear++]=start;

   while(front < rear)
   {
    int node=queue[front++];
    cout<<node<< " ";

    for(int i=0;i<n;i++)
    {
        if(adj[node][i]==1 && !visited[i])
        {
        visited[i]=true;
        queue[rear++]=i;
        }
    }
   }

}

int main()
{

    cout<<"Enter the number of node :";
    cin>>n;
    cout<<"Enter the number of edges :";
    cin>>e;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
        }

    }
    cout<<"Enter the edges (u,v)";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    cout<<"Ener start node :";
    int start;
    cin>>start;

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    bfs(start);

}