#include<iostream>
#include<queue>
const int INF = 2147483647;
using namespace std;

//图的邻接表表示
class Node{
public:
  int num,weight;
  Node *next;
  Node(int x,int y = 0,Node *t = NULL){
    num = x;
    weight = y;
    next = t;
  }
};
typedef Node* linkNode;

class Graph{
public:
  int Vcnt;
  linkNode *adj;
  linkNode now;
  Graph(int);
  ~Graph() {};
  void insert(int,int,int);
};

Graph::Graph(int n)
{
  Vcnt = n;
  adj = new linkNode[n*n+1];
  for(int i = 0; i <= n*n; i++){
    adj[i] = new Node(i);
  }
}
void Graph::insert(int v,int w,int WEIGHT)
{
	adj[v]->next = new Node(w,WEIGHT,adj[v]->next);
}


int main(){
  int N,start,end;
  cin >> N >> start >> end;
  Graph G(N);
 
  int *table=new int[N*N+1];
  queue<int> Q;
 for(int i=1;i<=N*N;i++)
  {
    cin >> table[i];
    if(table[i]==0)
	{
      int y;
	  cin>>y;
	  Q.push(y);
	}
  }
  for(int i=1;i<=N*N;i++)
  {
	  if(table[i]!=-1)
	  {
		  if((i-N)>0)
		  {
			  if(table[i-N] != -1)
				  G.insert(i,i-N,table[i]);
		  }
		  if((i-1)%N!=0)
		  {
			  if(table[i-1]!=-1)
				  G.insert(i,i-1,table[i]);
		  }
		  if((i+1)%N!=1)
		  {
			  if(table[i+1]!=-1)
				  G.insert(i,i+1,table[i]);
		  }
		  if((i+N)<N*N)
		  {
			  if(table[i+N]!=-1)
				  G.insert(i,i+N,table[i]);
		  }
		  if(table[i]==0)
		  {
			  int r=Q.front();
			  Q.pop();
			  G.insert(i,r,table[i]);
		  }
	  }
  }
  int *D = new int[N*N+1];
  for(int j = 1; j <= N*N; j++)
  {
	  D[j] = INF;
  }
  D[start] = 0;
  queue<int> queue;
  int s,num,weight,sum;
  Node *ptr;
  queue.push(start);
  while(queue.size())
  {
    s = queue.front();
    queue.pop();
	ptr = G.adj[s]->next;
	while(ptr)
	{
		num=ptr->num;
		weight=ptr->weight;
		sum=weight+D[s];
		if(sum<D[num])
		{
			D[num]=sum;
			queue.push(num);
		}
		ptr = ptr->next;
	}
  }	
  cout << D[end];
  delete []D;
  return 0;
}