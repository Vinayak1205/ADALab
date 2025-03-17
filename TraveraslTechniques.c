#include <stdio.h>
#define MAX 100

int vis[MAX]={0};
int adj[MAX][MAX];

int queue[MAX];
int front = -1;
int rear = -1;

void dfs(int node,int V){

    vis[node] = 1;

    printf("%d ",node);

    for(int i=0; i<V; i++){

        if(!vis[i] && adj[node][i])
            dfs(i,V);
    }


}

void bfs(int node, int V){

    int vis[MAX]={0};

    vis[node] = 1;

    front++;
    queue[++rear] = node;

    printf("\nBFS Traversal: ");

    while(front <= rear){

   
        int src = queue[front++];
        printf("%d ",src);

        for(int i=0; i<V; i++){
            
            if(!vis[i] && adj[src][i]){
                vis[i] = 1;
                queue[++rear] = i;
            }
        }
    }


}



int main(){

    int n,m;

    printf("\nEnter the no of vertices and edges: ");
    scanf("%d%d",&n,&m);

    int u,v;

    printf("\nEnter %d edges: ",m);
    for(int i=0; i<m; i++){

        printf("\nEnter edge %d ( u and v ): ",i+1);
        scanf("%d%d",&u,&v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nDFS Traversal: ");
    dfs(0,n);
    bfs(0,n);

    



}
