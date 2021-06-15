class node{
	private:
	int index; //vertex
	int value; //cost of vertex
	int neigh; //neighbour
	int color;
	public:
	//default values 
	node(int n=0,int v=0,int ne=-1,int colo=-1):index(n),value(v),neigh(ne),color(colo){}
	double getValue() const{
		return value;
	}
	int getIndex()const{
		return index;
	}
	int getNeighbour()const{
		return neigh;
	}
	int getColor()const{
		return color;
	}	
	void setIndex(int i){
		index=i;
	}
	void setNeighbour(int n){
		neigh=n;
	}
	void setValue(int v){
		value=v;
	}
	void setColor(int colo){
		color=colo;
	}	
	
		
};

//compare function for class node(for priority queue)
class nodeComparator
{
public:
    bool operator() (const node& p1, const node& p2)
    {
        return p1.getValue() > p2.getValue();
    }
};
