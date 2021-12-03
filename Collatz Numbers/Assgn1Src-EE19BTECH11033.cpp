#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>

using namespace std;
int collatz_num(int ent){
	
	pid_t pid;
	pid=fork();
	if (pid < 0){/*error occured*/
		cout<<"Fork Failed"<<endl;
		return 1;
	}
	else if(pid==0){ /*child process */
		cout<<ent<<endl; 
		while(ent!=1){
			ent=(ent%2==0)?ent/2:3*ent+1; //using the given conjecture
			cout<<ent<<endl; /*Printing the sequence*/
		}	
	}
	else /*Parent Process*/
	wait(NULL); //waiting for the child process to be completed
	
	return 0;	
			 
}	

int main(){
	string in;
	cout<<"Input:";
	cin>>in;
	
	for(auto &t:in)
	if(!isdigit(t)){ /*Input is not an integer or is negative */
		cout<<"Invalid Input";
	    return 1;
	} 
	int ent=stoi(in);
	if(ent==0){ /* Input is zero*/
		cout<<"Invalid Input";
	    return 1;
	}    
	return collatz_num(ent);
}	
		


