#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


// Graph Typedefs

typedef int vertex;
typedef int distance;

typedef struct vertNode{
    vertex vertID;
    int cost;
    bool visited;    
    struct vertNode* next;
}vertNode;

// can comment cost between edges or visited depending on the problem

typedef struct stGraph{
    int numNodes;
    struct GraphNode* vertices;
}stGraph;

typedef vertNode* GraphNode;
typedef stGraph* Graph;

// Heap Typedefs for Djikstra
#define negative_infty -INT_MAX

typedef struct heapElem{
    vertex vertID;
    distance dist;
}heapElem;

typedef struct stHeap{
    int iSize;
    int iCapacity;
    heapElem* HeapElements;
}stHeap;

typedef stHeap* Heap;

// HeapFunction Signatures
Heap CreateHeap(int size);
void InsertMinHeap(Heap H, heapElem x);
void Heapify(Heap H, int i);
heapElem ExtractMin(Heap H);

// Graph Function Signatures
Graph CreateGraph(int size);
bool Find(Graph G, vertex source, vertex dest);
void InsertEdge(Graph G, vertex source, vertex dest);
void Djikstra(Graph G, vertex source, vertex dest);

// Heap Function Definitions
Heap CreateHeap(int size){
    Heap H=(Heap)malloc(sizeof(stHeap));
    assert(H != NULL);
    
    H->iSize=size;
    H->capacity=0;
    H->HeapElements=(heapElem*)malloc(sizeof(heapElem)*(size+1));
    assert(H->HeapElements != NULL);

    H->HeapElements[0].vertexID=negative_infty;
    H->HeapElements[0].dist=negative_infty;

    return H;
}

void InsertMinHeap(Heap H, heapElem x){
    H->HeapElements[++H->iSize]=x;

    Heapify(H, H->iSize);
    return;
}

void Heapify(Heap H, int index){
    if(index == 1){
        return;
    }
    else{
        if(index/2 != 0 && H->HeapElements[index/2].dist > H->HeapElements[index].dist){
            heapElem temp = H->HeapElements[index/2];
            H->HeapElements[index/2]=H->HeapElements[index];
            H->HeapElements[index]=temp;
            Heapify(H, index/2);
        }
    }

    return;
}

heapElem ExtractMin(Heap H){
    
}

Graph CreateGraph(int size){
    Graph G=(Graph)malloc(sizeof(stGraph));
    assert (G != NULL);

    G->numNodes=size;
    G->vertices=(GraphNode*)malloc(sizeof(GraphNode)*size);
    assert(G->vertices != NULL);

    for(int i=0;i<size;i++){
        vertices[i]->vertID=i+1;
        vertices[i]->visited=0;
        vertices[i]->cost=0;
        vertices[i]->next=NULL;
    }

    return G;
}

bool Find(Graph G, vertex source, vertex dest){
    GraphNode temp=G->vertices[source-1];
    
    while(temp != NULL){
        if(temp->vertID == dest) return 1;
        temp=temp->next;
    }

    return 0;
}

void InsertEdge(Graph G, vertex source, vertex dest, int weight){

    // Find function can be commented out in many cases if the edges are unique
    // Don't need cost function if this is a unweighted graph
    // If Undirected graph just call Insert Edge twice on (u, v) and (v,u)

    if(!Find(G, source, dest)){
        vertNode* new=(vertNode*)malloc(sizeof(vertNode));
        assert(vertNode) != NULL;

        new->vertID=dest;
        new->cost=weight;
        new->visited=0;
        new->next=G->vertices[source-1]->next;

        G->vertices[source-1]->next=new;
    }

    return;
}

void Djikstra(Graph G, vertex source, vertex dest){

}

