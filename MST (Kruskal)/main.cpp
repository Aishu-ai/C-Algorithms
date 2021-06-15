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
#include "quickunion.h"

using namespace std;

class mst{
	private:
	int num_of_nodes;
	int least_dist;
	vector <node> closed_set;
	graph gr;
	
	void path_store(){
		priority_queue<node,vector<node>,nodeComparator> Q;
		for(int i=0;i<num_of_nodes;i++){
			for(int j=i;j<num_of_nodes;j++){
				if(gr.adjacent(i,j))
				Q.push(node(j,gr.get_edge_cost(i,j),i,gr.get_edge_color(i,j)));//Sorting all the edges in ascending order
			}
		}
		node n=Q.top();
		QuickUnionUF q(num_of_nodes);
		int s=n.getIndex();
		int ne;
		while(q.size(s)<num_of_nodes){//if the size of the tree is not yet=no.of nodes
			n=Q.top();
			Q.pop();
			s=n.getIndex();
		    ne=n.getNeighbour();
		    if(q.connected(s,ne)==false){//if the nodes are not already connected
				q.union_n(s,ne);
				closed_set.push_back(n);
				s=q.root(s);//find the root of the tree
				}
		}
	}
	void sum(){
		
		int su=0;
		for (auto ptr = closed_set.begin(); ptr < closed_set.end(); ptr++)
		su=su+(*ptr).getValue();
		least_dist=su;
	}		
	
	public:
	mst(graph g){ 
		gr=g;
		num_of_nodes=gr.num_of_vertices();
		path_store();
	}
	int min_dist(){
		sum();
		return least_dist;
	}
	void tree(){
		
		for (auto ptr = closed_set.begin(); ptr < closed_set.end(); ptr++)
		cout<<(*ptr).getIndex()<<"--"<<(*ptr).getNeighbour()<<" ("<<(*ptr).getValue()<<")"<<endl;
		}	
};	


int main(){
	//string str="test.txt";
	//graph u(str);
	graph u;
	mst dist(u);
	cout<<"Minimum distance: "<<dist.min_dist()<<endl;
	cout<<"Edges:"<<endl;
	dist.tree();
	return 0;
}				
