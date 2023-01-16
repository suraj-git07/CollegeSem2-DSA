#include <stdio.h>
#include <stdlib.h>

// Queue for BFS
struct queue {
  int items[40];
  int front;
  int rear;
};
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
void enqueue(struct queue* q, int value) {
  if (q->rear == 39)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    // printf("Queue is empty\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
    //   printf("Resetting queue\n ");
      q->front = q->rear = -1;
    }
  }
  return item;
}
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
    printf("\n");
  }
}

// Graph 
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
  struct node** adjLists; // array of linked list
  int* visited;
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

  //dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}


// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    // printQueue(q);
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
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

  bfs(graph, startnode);

  return 0;
}