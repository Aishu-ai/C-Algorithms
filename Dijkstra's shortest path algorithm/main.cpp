#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <ctime>
#include "graph.h"
#include "node.h"


using namespace std;

class shortest_path{
	private:
	vector<node> closed; //for storing final cost of all vertices
	vector<node>::iterator ptr; //iterator for the vector
	graph gr; // the graph being intercepted
	int num_of_nodes;//number of vertices
	
	//Stores the shortest path of each vertex from the source vertex
	void paths_store(const int p){ //p is the source vertex
		int v=p;
		double d=0.0;
		priority_queue<node,vector<node>,nodeComparator> Q; //PriorityQueue (Minheap)
		node n(v,d,v);
		while(static_cast<int>(closed.size())<num_of_nodes){
			if(ptr==closed.end()||closed.empty()==true)
			closed.push_back(n); //Push the parent node into the vector
			double* t=gr.neighbours(v);
			for(int i=0;i<num_of_nodes;i++){
				if(t[i]!=0)
				Q.push(node(i,t[i]+d,v)); //Push the neighbours of the parent node into queue
				}
			if(Q.empty()==false){
				n=Q.top();//gives us the shortest dist. node
				Q.pop();
				v=n.getIndex();//replace the parent node
				d=n.getValue();
				for (ptr = closed.begin(); ptr < closed.end(); ptr++){
					if((*ptr).getIndex()==v)
					break;
					}
					if(d<(*ptr).getValue()&&ptr!=closed.end())//if the cost obtained is less than the cost already present then replace the cost value
					(*ptr).setValue(d);
			}
			else
			{
				cout<<"The graph is not connected"<<endl;//if the source node is isolated
				break;
			}
		}
	}
	
	
	public:
	shortest_path(graph g,const int v){//paramterized constructor..takes graph and source node as inputs
		gr=g;
		num_of_nodes=g.num_of_vertices();
		paths_store(v);
		}
	
	void path(const int v,const int u){
		
		if(v!=u){
			int n;
			for (ptr = closed.begin(); ptr < closed.end(); ptr++){
				if((*ptr).getIndex()==u){
					cout<<"Shortest path between "<<v<<" and "<<u<<" is "<<(*ptr).getValue()<<endl;
					n=(*ptr).getNeighbour();
					break;
					}
			}
			cout<<"Sequence of vertices representing the path: "<<endl;//Traverse the neighbours until we reach the source node
			cout<<(*ptr).getIndex()<<"-";
			while((*ptr).getNeighbour()!=v){
				cout<<n<<"-";
				for (ptr = closed.begin(); ptr < closed.end(); ptr++){
					if((*ptr).getIndex()==n)
					break;
				}
				n=(*ptr).getNeighbour();	
			}
			cout<<v<<endl;
		}
	}
	
	double avg_length(){//The avg of all num_of_nodes-1 distances from source node
		double sum=0.0;
		for (ptr = closed.begin(); ptr < closed.end(); ptr++)
			sum=sum+(*ptr).getValue();
		sum=sum/(num_of_nodes-1);
		return sum;
	}	
		
};

//Client code
int main(){
	graph t(50,0.2,10.0);
	shortest_path s(t,1);
	
	
	for(int i=0;i<50;i++)
	s.path(1,i);
	cout<<s.avg_length()<<endl;
    return 0;
}

