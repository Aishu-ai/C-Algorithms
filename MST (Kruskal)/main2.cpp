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
	int least_dist=0;
	int co;//the color of edges required
	bool result;
	vector <node> closed_set;
	graph gr;
	
	void path_store(){
		priority_queue<node,vector<node>,nodeComparator> Q;
		for(int i=0;i<num_of_nodes;i++){
			for(int j=i;j<num_of_nodes;j++){
				if(gr.adjacent(i,j)&&gr.get_edge_color(i,j)==co)
				Q.push(node(j,gr.get_edge_cost(i,j),i,gr.get_edge_color(i,j)));
			}
		}
		node n=Q.top();
		QuickUnionUF q(num_of_nodes);
		int s=n.getIndex();
		int ne;
		result=true;
		while(q.size(s)<num_of_nodes){
			n=Q.top();
			Q.pop();
			s=n.getIndex();
		    ne=n.getNeighbour();
		    if(q.connected(s,ne)==false){
				q.union_n(s,ne);
				closed_set.push_back(n);
				s=q.root(s);
				}
			if(Q.empty()&&q.size(s)<num_of_nodes){
				cout<<"Graph cannot be connected with this color"<<endl;
				result=false;
				break;
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
	mst(graph g,int c){ 
		gr=g;
		co=c;
		num_of_nodes=gr.num_of_vertices();
		path_store();
	}
	int min_dist(){
		if(result)
		sum();
		return least_dist;
	}
	void tree(){
		if(result){
			for (auto ptr = closed_set.begin(); ptr < closed_set.end(); ptr++)
			cout<<(*ptr).getIndex()<<"--"<<(*ptr).getNeighbour()<<" ("<<(*ptr).getValue()<<")"<<endl;
		}
	}		
};	


int main(){
	//string str="test.txt";
	//graph u(str);
	graph u(50,0.4,10);
	mst dist(u,0);//Color of the edges as arguments
	mst dist2(u,1);
	mst dist3(u,2);
	cout<<"Minimum distance: "<<dist.min_dist()<<" "<<dist2.min_dist()<<" "<<dist3.min_dist()<<endl;
	cout<<"Edges:"<<endl;
	dist.tree();
	return 0;
}
