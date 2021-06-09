//In the class graph below the vertices are mapped
//onto the set of integers in the range from 0 : |V|-1.
//The graph is represented using an adjacency matrix



class graph{
	private:
	double** gr;  //pointer to the graph matrix
	int size;  //number of vertices
	double edge_den;  //edge density
	double dist_range;  //maximum distance between two vertices
	int edges;  //number of edges
	
	public:
	//default size 50, density=0.1 and distance range=10.0
	graph(int s=50, double ed=0.1,double dr=10):size(s),edge_den(ed),dist_range(dr){
		
		srand(time(0));
		gr=new double*[s];
		for(int i=0;i<s;i++)
		gr[i]=new double[s];
		for(int i=0;i<s;i++){
			for(int j=0;j<s;j++){
				if(i==j) //No loops in the graph
				gr[i][j]=0;
				else{
					//An edge is present with a probability of "edge_den"
					if(static_cast<double>(rand())/RAND_MAX<ed){
						gr[i][j]=(static_cast<double>(rand())/RAND_MAX)*(dr-1)+1;
						gr[j][i]=gr[i][j];
						edges++;
					}
					else{
						gr[i][j]=0;
						gr[j][i]=gr[i][j];
					}
				}
				
			}
			
		}
	}
	
	int num_of_vertices(){
		return size;
	}
	
	int num_of_edges(){
		
		return edges;
	}
	
	
	bool adjacent(int i, int j){
		return(gr[i][j]!=0);
	}
	//Returns an array correspondong to the node i
	double* neighbours(int i){
		return gr[i];
	}
	//Sets edge value to a random number
	void set_edge_value(int i,int j){
		srand(time(0));
		gr[i][j]=(static_cast<double>(rand())/RAND_MAX)*(dist_range-1)+1;
	}
	
	double get_edge_value(int i,int j){
		return gr[i][j];
	}
	//Sets edge value to specified value
	void set_edge_value(int i,int j,double v){
		gr[i][j]=v;
	}
	
};
