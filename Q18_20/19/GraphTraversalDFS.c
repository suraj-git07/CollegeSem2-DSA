// DFS algorithm in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
// src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// DFS algo
void DFS(struct Graph* graph, int vertex) {
  
  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;


  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

int main() {
  int numVertices=0;
  printf("Enter the number of vertices\n");
  scanf("%d",&numVertices);
 
  struct Graph* graph = createGraph(numVertices);
  
  // adding edges
  while (1)
  {
    int chosen = 0;
    printf("Add edge? 1 == yes 2 == no \n");
    scanf("%d",&chosen);
    if (chosen == 2)
    {
       break;
    }
    int src = 0, dest = 0;
    printf("Enter src:\n");
    scanf("%d",&src);
    printf("Enter dest:\n");
    scanf("%d",&dest);
    addEdge(graph, src, dest);
    printf("Edge added %d to %d\n",src,dest);
  }

  int startnode=0;
  printf("Enter the starting vertex\n");
  scanf("%d",&startnode);

  DFS(graph, startnode);

  return 0;

  return 0;
}