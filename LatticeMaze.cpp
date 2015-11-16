#include<iostream>
using namespace std;

//图的邻接表表示
class Node{
public:
  int num,weight;
  gNode *next;
  gNode(int x,int y,gNode *t){
    M = x;
    weight = y;
    next = t;
  }
};

class Graph{
public:
  

};

void initMazeGraph(int N){
  
  
}

int main(){
  int N,start,end;
  cin >> N >> start >> end;
  initMazeGraph(N);
  
  return 0;
}
