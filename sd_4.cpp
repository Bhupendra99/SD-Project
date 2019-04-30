#include<iostream>
using namespace std;

int findminvertex(int weights[],int visited[],int vertex)
{   int minvertex=-1;

         for(int i=0;i<vertex;i++)
    {
        if(visited[i]!=1 && (weights[i]<weights[minvertex] || minvertex==-1))
            {
                    minvertex=i;
            }
    }
    return minvertex;

}

void prims(int graph[][10],int vertex)
{
    int parent[10],visited[10],weights[10];

    for(int i=0;i<vertex;i++)
    {
        visited[i]=0;
        weights[i]=INT_MAX;
    }
    weights[0]=0;
    parent[0]=-1;

    for(int i=0;i<vertex;i++)
    {
        int minvertex=findminvertex(weights,visited,vertex);

         visited[minvertex]=1;
         for(int j=0;j<vertex;j++)
         {
                if(graph[minvertex][j]!=0 && visited[j]!=1)
                {
                        if(graph[minvertex][j]<weights[j])
                        {
                            weights[j]=graph[minvertex][j];
                            parent[j]=minvertex;

                        }
                }
         }

    }

    cout<<"\n\n";
    for(  int k=1;k<vertex;k++)
    {
            cout<<weights[k];
    }
    cout<<"\n\n";
    for(int i=1;i<vertex;i++)
    {
        if(parent[i]<i)
        {
        cout<<parent[i]<<" "<<i<<" "<<weights[i]<<"\n";
        }
        else{

        cout<<i<<" "<<parent[i]<<" "<<weights[i]<<"\n";

        }
    }

}

int main()
{
    int edges,vertex,cost,v1,v2;
    cout<<"\n enter no of edges \n";
    cin>>edges;
    cout<<"\n enter no of vertex \n";
    cin>>vertex;
    int graph[10][10];
    for(int i=0;i<edges;i++)
    {
        cin>>v1;
        cin>>v2;
        cin>>cost;
        graph[v1][v2]=graph[v2][v1]=cost;
    }

        prims(graph,vertex);
return 0;
}

