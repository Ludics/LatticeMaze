#include<iostream>
using namespace std;

//图的邻接表表示
class Node{
public:
  int num,weight;
  Node *next;
  Node(int x,int y = 0,gNode *t = NULL){
    num = x;
    weight = y;
    next = t;
  }
};

class Graph{
public:
  int Vcnt,Ecnt;
  Node **adj;
  Graph();
  ~Graph();
  void insert();
  void remove();
  void destroyGraph();
};

Graph::Graph(int n)
{
  Vcnt = n;
  Ecnt = 0;
  adj = new *Node[n];
  for(int i = 0; i < n; i++){
    adj[i] = new Node(i);
  }
}
Graph::~Graph()
{
  destroyGraph();
}
void Graph::destroyGraph()
{
  
}

void initMazeGraph(int N){
  
  
}

int main(){
  int N,start,end;
  cin >> N >> start >> end;
  initMazeGraph(N);
  
  return 0;
}
