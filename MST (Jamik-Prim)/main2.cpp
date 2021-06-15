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
	int least_dist=0;
	int source;
	int color;//required color of the mst 
	bool result;
	vector <node> closed_set;
	graph gr;
	
	vector<node> paths_store(vector<node> closed){ 
		
		int v=source;//v is the source node
		int co=color;// color of the edge required in the spanning tree
		priority_queue<node,vector<node>,nodeComparator> Q; //PriorityQueue (Minheap)
		node n(v,0,v,-1);
		bool*t=gr.neighbours_bool(v);
		closed[v]=n;
		int size=1;
		result=true;//assuming graph to be connected
		while(size<num_of_nodes){
			
			if(t!=NULL){
			for(int i=0;i<num_of_nodes;i++)
			{
				if(t[i]==true&&closed[i].getNeighbour()==-1){
					if(gr.get_edge_color(v,i)==co)//if the edge is of the required color
					Q.push(node(i,gr.get_edge_cost(v,i),v,gr.get_edge_color(v,i))); //Push the neighbours of the parent node into queue
				}
			}
			}	
			t=NULL;
			if(Q.empty()==false){
				n=Q.top();//gives us the shortest dist. node of the required coloured edge
				Q.pop();
				v=n.getIndex();
				if(closed[v].getNeighbour()==-1){
					closed[v]=n;
					size++;	
					t=gr.neighbours_bool(v);
					}
					//cout<<"Hello"<<endl;
			}
			else //unable to connect rest of tree through that color
			{
				cout<<"The graph is not connected through colour "<<color<<"."<<endl;//if the source node is isolated
				result=false; //graph cannot be connected through the given color
				break;
			}	
			
		}
		
		
		
		return closed;	
	}
	
	void sum(vector<node> closed){//sum of all costs in the vector
		
		int su=0;
		for (auto ptr = closed.begin(); ptr < closed.end(); ptr++)
		su=su+(*ptr).getValue();
		least_dist=su;
	}
	
	public:
	mst(graph g,int v,int co){ //color and source node given
		if(v>=num_of_nodes)
		exit(1);
		gr=g;
		source=v;
		color=co;
		num_of_nodes=gr.num_of_vertices();
		vector<node> closed(num_of_nodes);
		closed_set=paths_store(closed);
		closed.clear();
		
	}
		
	int min_dist(){
		if(result==true) //if graph is connected
		sum(closed_set);
		return least_dist;
	}
	void tree(){
		if(result==true){
			cout<<source<<" is the source node."<<endl;
			for (auto ptr = closed_set.begin(); ptr < closed_set.end(); ptr++){
				if((*ptr).getIndex()!=source)
				cout<<(*ptr).getIndex()<<"--"<<(*ptr).getNeighbour()<<" "<<"("<<(*ptr).getColor()<<")"<<endl;
			}
		}
	}			
};

int main(){
	//string str="test.txt";
	//graph u(str);
	graph u(50,0.4,10);
	mst dist(u,40,2); //Node 40 as source and  2 as the color.
	cout<<"Minimum distance: "<<dist.min_dist()<<endl;
	cout<<"Edges:"<<endl;
	dist.tree();
	return 0;

}
