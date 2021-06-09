//Node contains the vertex, its cost from the source vertex(depends upon
//path taken) and its direct neighbour(depends upon path taken)


class node{
	private:
	int index; //vertex
	double value; //cost of vertex
	int neigh; //neighbour
	public:
	//by default all values set to 0
	node(int n=0,double v=0.0,int ne=0):index(n),value(v),neigh(ne){}
	double getValue() const{
		return value;
	}
	int getIndex()const{
		return index;
	}
	int getNeighbour()const{
		return neigh;
	}
	void setIndex(int i){
		index=i;
	}
	void setNeighbour(int n){
		neigh=n;
	}
	void setValue(double v){
		value=v;
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
