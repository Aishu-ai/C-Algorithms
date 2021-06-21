#include <iostream>
#include <vector>
#include "quickunion.h"

using namespace std;

class Board{
	private:
	QuickUnionUF board;// array to store the connections
	char* status; //holds status of all the hexagons(either red,blue or closed)
	int N; //size of the hex board
	bool move=false; //whether a move is legal or not
	bool gamestatus=false; //true if winner is decided
	void printrow(int row){ //printing a row of the hexboard
		int index=(row-1)*N;
		for(int j=1;j<row;j++)
			cout<<" ";
		for(int i=0;i<N;i++){
			
			if(status[index+i]=='B')
			cout<<"O";
			else if(status[index+i]=='R')
			cout<<"X";
			else 
			cout<<".";
			if(i<=N-2)
			cout<<" - ";
		}
		cout<<endl;
		for(int j=1;j<row;j++)
			cout<<" ";
		if(row<N){	
		for(int i=0;i<N;i++){
			if(i==0)
			cout<<" \\";
			if(i>0)
			cout<<" \\";
			if(i<=N-2)
			cout<<" /";
		}
	}
		cout<<endl;	
}
			
			
	
	public:
	Board(int size):board(size*size+4){ //parametrized constructor
		N=size;
		
		
		status=new char[N*N]; //initializing status to closed
		for(int i=0;i<N*N;i++){
			status[i]='C';
		}
		
	}
	void choose(int row, int col,char player){ //choosing a hexagon to be of status==player
		if(row<1||row>N){
			cout<<"Invalid move"<<endl;
			return;
		}	
		if(col<1||col>N){
			cout<<"Invalid move"<<endl;
			return;
		}	
		if(player!='R'&&player!='B'){
			cout<<"Invalid move"<<endl;
			return;
		}	
		int index=(row-1)*N+col;
		if(status[index-1]=='C'){ //can choose a hexagon only if it was closed initially
			status[index-1]=player;
			move=true;
		}	
		else{
			
			cout<<"Invalid move"<<endl; //if it was already choosen
			return;
		}
		/*nodes 1 to N*N represent the hexagons on the board */
		/* node 0 represents the north side of the board i.e red-north.If a node belongs to the topmost row and choosen by the red player then connect that node to 0*/
		if((index>=1&&index<=N)&&player=='R')
		board.union_h(0,index);
		/* node N*N+2 represents the south side, red-south*/
		if((index>=N*N-N+1&&index<=N*N)&&player=='R')
		board.union_h(N*N+2,index);
		/* node N*N+1 represents blue-west.If a node belongs to the first column and is choosen by the blue player,then connect that node to N*N+1*/
		if(index%N==1&&player=='B')
		board.union_h(N*N+1,index);
		/* Similarly node N*N+3 represents blue-west */
		if(	index%N==0&&player=='B')
		board.union_h(N*N+3,index);
		//Join nodes of same status if they are neighbours
		//Neighbours of corner nodes(top left and bottom right)
		if(index==1&&status[index]==player)
		board.union_h(index,index+1);
		else if(index==1&&status[index+N-1]==player)
		board.union_h(index,index+N);
		else if(index==N*N&&status[index-2]==player)
		board.union_h(index,index-1);
		else if(index==N*N&&status[index-N-1]==player)
		board.union_h(index,index-N);
		//Neighbours of corner nodes(top right and bottom left)
		else if(index==N){
			if(status[index-2]==player)
			board.union_h(index,index-1);
			if(status[index+N-1]==player)
			board.union_h(index,index+N);
			if(status[index+N-2]==player)
			board.union_h(index,index+N-1);
		}
		else if(index==N*N-N+1){
			if(status[index]==player)
			board.union_h(index,index+1);
			if(status[index-N-1]==player)
			board.union_h(index,index-N);
			if(status[index-N]==player)
			board.union_h(index,index-N+1);	
		}
		//Neighbours of first column
		else if(index%N==1&&(index!=1&&index!=N*N-N+1)){
			if(status[index]==player)
			board.union_h(index,index+1);
			if(status[index-N-1]==player)
			board.union_h(index,index-N);	
			if(status[index-N]==player)
			board.union_h(index,index-N+1);
			if(status[index+N-1]==player)
			board.union_h(index,index+N);
			
		}
		//Neighbours of last column
		else if(index%N==0&&(index!=N&&index!=N*N)){
			if(status[index-2]==player)
			board.union_h(index,index-1);
			if(status[index-N-1]==player)
			board.union_h(index,index-N);	
			if(status[index+N-1]==player)
			board.union_h(index,index+N);
			if(status[index+N-2]==player)
			board.union_h(index,index+N-1);
		}
		//Neighbours of the rest of the hexagons
		else{
			if(status[index-2]==player)
			board.union_h(index,index-1);
			if(status[index]==player)
			board.union_h(index,index+1);
			if(index+N<=N*N&&status[index+N-1]==player)
			board.union_h(index,index+N);
			if(index-N>=0&&status[index-N-1]==player)
			board.union_h(index,index-N);
			if(index-N+1>=0&&status[index-N]==player)
			board.union_h(index,index-N+1);
			if(index+N+1<=N*N&&status[index+N]==player)
			board.union_h(index,index+N+1);
		}
		//if after the operation the game is completed
		if(board.connected(N*N+1,N*N+3)||board.connected(0,N*N+2))
			gamestatus=true;
	}
	//prints the hexboard
	void showboard(){
		for(int i=1;i<=N;i++)
			printrow(i);
		
	}
	
	bool getgamestatus(){
		return gamestatus;
	}
	void winner(){
		if(board.connected(N*N+1,N*N+3))
		cout<<"Blue has won the game"<<endl;
		if(board.connected(0,N*N+2))
		cout<<"Red has won the game"<<endl;	
	}	
			
			
			
};			

int main(){
	Board b(7);
	b.showboard();
	int row,col;
	char player;
	cout<<"Enter row and column number along with player i.e B for blue and R for red. Press enter after each entry. Do this for every move."<<endl;
	while(!b.getgamestatus()){
		cout<<"Move:"<<endl;
		cin>>row>>col>>player;
		b.choose(row,col,player);
		b.showboard();
	}
	b.winner();	
		 
	return 0;
}
		
			
		
		
