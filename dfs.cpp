#include<iostream>
using namespace std;

const int MAX=100;
int adj[MAX][MAX];
bool visited[MAX];
int n,e;
void dfs(int node)
{
    cout<< node << " ";
    visited[node]=true;
    for(int i=0;i<n;i++)
    {
        if(adj[node][i] ==1 && !visited[i])
        {
            dfs(i);
        }
    }
}


int main()
{

    cout<<"Enter the number of node :";
    cin>>n;
    cout<<"Enter the number edge :";
    cin>>e;

    for(int i=0;i<n;i++)
    {
        for(int j=n;j<0;j++)
        {
            adj[i][j]=0;
        }
    }
    cout<<"Enter the edges (u,v):";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int start;
    cout<<"Enter starting node :";
    cin>>start;
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    cout<<"DFS traversal :";
    dfs(start);


}


