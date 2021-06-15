#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <numeric>
#include "graph.h"
#include "node.h"

using namespace std;

class mst{
	private:
	int num_of_nodes;
	int least_dist;
	int source;
	vector <node> closed_set;
	graph gr;
	
	vector<node> paths_store(vector<node> closed){ 
		int v=source;//v is the source vertex
		priority_queue<node,vector<node>,nodeComparator> Q; //PriorityQueue (Minheap)
		node n(v,0,v,-1);
		bool*t=gr.neighbours_bool(v);
		closed[v]=n;
		int size=1;
		while(size<num_of_nodes){
			
			if(t!=NULL){
				for(int i=0;i<num_of_nodes;i++)
				{
					if(t[i]==true&&closed[i].getNeighbour()==-1)
					Q.push(node(i,gr.get_edge_cost(v,i),v,gr.get_edge_color(v,i))); //Push the neighbours of the parent node into queue
				}
			}	
			t=NULL;
			if(Q.empty()==false){
				n=Q.top();//gives us the shortest dist. node
				Q.pop();
				v=n.getIndex();
				if(closed[v].getNeighbour()==-1){
					closed[v]=n;
					size++;	
					t=gr.neighbours_bool(v);
					}
			}
			else
			{
				cout<<"The graph is not connected"<<endl;//if the source node is isolated
				break;
			}	
		}
		
		
		return closed;	
	}
	
	void sum(vector<node> closed){
		
		int su=0;
		for (auto ptr = closed.begin(); ptr < closed.end(); ptr++)
		su=su+(*ptr).getValue();
		least_dist=su;
	}
	
	
	
	public:
	mst(graph g,int v){//Source node given
		gr=g;
		source=v;
		num_of_nodes=gr.num_of_vertices();
		if(v>=num_of_nodes)
		exit(1);
		vector<node> closed(num_of_nodes);
		closed_set=paths_store(closed);
		closed.clear();
		closed.shrink_to_fit();
		
	}
	mst(graph g){ //Random source node
		gr=g;
		srand(time(0));
		num_of_nodes=gr.num_of_vertices();
		srand(time(0));
		source=rand()%num_of_nodes;
		vector<node> closed(num_of_nodes);
		closed_set=paths_store(closed);
		closed.clear();
		closed.shrink_to_fit();
	}	
	int min_dist(){
		sum(closed_set);
		return least_dist;
	}
	void tree(){
		cout<<source<<" is the source node."<<endl;
		for (auto ptr = closed_set.begin(); ptr < closed_set.end(); ptr++){
			if((*ptr).getIndex()!=source)
			cout<<(*ptr).getIndex()<<"--"<<(*ptr).getNeighbour()<<endl;
		}
	}		
};	
	
int main(){
	string str="test.txt";
	graph u(str);
	//graph u;
	mst dist(u);
	cout<<"Minimum distance: "<<dist.min_dist()<<endl;
	cout<<"Edges:"<<endl;
	dist.tree();
	return 0;

}	
