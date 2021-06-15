class QuickUnionUF{
	private:
	int* id; //id array which stores the root/parent of each node
	int* sz; //sz of tree rooted at node i
	
	
	
	public:
	
	QuickUnionUF(int N){
		id=new int[N];
		sz=new int[N];
		for(int i=0;i<N;i++){
			id[i]=i; //Creating a forest where all nodes are individual trees
			sz[i]=1;
		}
	}
	
	bool connected(int p,int q){
		return(root(p)==root(q));//conected if they belong to same tree
	}	
	void union_n(int p,int q){//connecting two nodes
		int i=root(p);
		int j=root(q);
		if(i==j)
		return;
		if(sz[i]<sz[j]){
			id[i]=j;
			sz[j]+=sz[i];
		}
		else{
			id[j]=i;
			sz[i]+=sz[j];
		}
	}
	int root(int i){ //finding root of a tree using a leaf
		while(i!=id[i]){
			id[i]=id[id[i]];
			i=id[i];
		}
		return i;
	}
	int size(int i){
		return sz[i];
	}	
		
};	
