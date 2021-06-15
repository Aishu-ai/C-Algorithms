class graph{
	private:
	bool** gr;  //pointer to the graph matrix
	int** co;   //pointer to the color matrix
	int** cost; //pointer to the cost matrix
	int size;  //number of vertices
	double edge_den;  //edge density
	int dist_range;  //maximum distance between two vertices
	int edges;  //number of edges
	double prob()
	{
		return (static_cast<double>(rand())/RAND_MAX);
	}	
	
	
	public:
	//default size 50, density=0.2 and distance range=10(i.e cost range)
	graph(int s=50, double ed=0.2,int dr=10):size(s),edge_den(ed),dist_range(dr)
	{
		srand(time(0));
		gr=new bool*[size];
		co=new int*[size];
		cost=new int*[size];
		for(int i=0;i<size;i++)
		{
			gr[i]=new bool[size];
			co[i]=new int[size];
			cost[i]=new int[size];
		}
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				if(i==j)
				gr[i][j]=false;
				else
				{
					if(prob()<edge_den)
					{
						gr[i][j]=true;
						co[i][j]=rand()%3;
						co[j][i]=co[i][j];
						cost[i][j]=static_cast<int>(prob()*dist_range);
						cost[j][i]=cost[i][j];
					}
					else
					gr[i][j]=false;
					gr[j][i]=gr[i][j];
				}
			}
		}
	}
	
	graph(std::string& filename)//graph data from a file
	{
		std::ifstream indata;
		int num;
		indata.open(filename);
		if(!indata) { 
			std::cerr << "Error: file could not be opened" << std::endl;
			exit(1);
		}
		indata>>num;
		size=num;
		edges=0;
		gr=new bool*[size];
		co=new int*[size];
		cost=new int*[size];
		for(int i=0;i<size;i++)
		{
			gr[i]=new bool[size];
			co[i]=new int[size];
			cost[i]=new int[size];
		}
		
		int num1,num2,num3,num4;
		while ( !indata.eof() ) { 
			indata>>num1;
			indata>>num2;
			indata>>num3;
			indata>>num4;
			gr[num1][num2]=true;
			cost[num1][num2]=num3;
			co[num1][num2]=num4;
		}
		indata.close();	
	}	
		
		
	int num_of_vertices(){
		return size;
	}
	
	int num_of_edges(){
		
		return edges;
	}
	
	
	bool adjacent(int i, int j){
		return(gr[i][j]==true);
	}
	//Returns an array correspondong to the node i
	bool* neighbours_bool(int i){
		return gr[i];
	}
	int get_edge_cost(int i,int j){
		if(gr[i][j]==true)
		return cost[i][j];
		else
		return -1;
	}
	int get_edge_color(int i,int j){
		if(gr[i][j]==true)
		return co[i][j];
		else
		return -1;
	}	
		
	//Sets edge value to specified value
	void set_edge_value(int i,int j,int cos,int color){
		gr[i][j]=true;
		co[i][j]=color;
		cost[i][j]=cos;
	}					
		
};							
					
		
		
