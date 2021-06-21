class QuickUnionUF{
	private:
	 int* id;//where id[i] is the parent of i
	 int* sz;//sz[i] gives no. of objects in tree rooted at i
	 int root(int i){
		while(i!=id[i]){
			id[i]=id[id[i]];
			i=id[i];
		}
		return i;
	}
	
	//parametrized constructor
	public:
	QuickUnionUF(int N){
		id=new int[N];
		sz=new int[N];
		for(int i=0;i<N;i++){
			id[i]=i;
			sz[i]=0;
	}
	
	}
	QuickUnionUF(){
	}
	
	//if p and q belong to the same tree
	bool connected(int p,int q){
		return(root(p)==root(q));
	}
	//combining trees( weighted implementation..parent node depends upon the size of the trees being joined)
	void union_h(int p,int q){
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
};
