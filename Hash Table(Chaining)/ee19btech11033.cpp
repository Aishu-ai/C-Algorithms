#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>



/* Instructions to execute this file from terminal:
 * Go to the directory where this file is placed.
 * 
 * Use the following command:
 * g++ ee19btech11033.cpp -o ee19btech11033
 * 
 * To execute it:
 * ./ee19btech11033 userInfo.csv
 * 
 * Then the progrm prompts the user to enter the username.
 
  */

using namespace std;
//Node to hold the login details of the user
class Node{
	public:
	string username;
	string password;
	Node(string user,string pass):username(user),password(pass){}
		
};

int N;//Size of table
vector<vector<Node>>hashtable;//hashtable

//Hash function being used
long long hashFun(string str)
{
    int p = 31;
    int m = 1000000009;
    long long pp = 1;
    long long hash_val = 0;
    for (int i = 0; i < (int)str.length(); i++) {
		int base=isdigit(str[i])==0?str[i]-'a'+1:str[i]-'0'+1;//relative value of the characters
        hash_val= (hash_val+ base * pp)% m; //computing hash value of the string
        pp=(pp*p)% m;
    }
    return (hash_val%m+m)%m;
}

//Inserting a node in the table
void hashing(string user,string pass){
	int in=static_cast<int>(hashFun(user)%N);
	hashtable[in].push_back(Node(user,pass));
}

//Inserting all the users in the table
void insert_in_table(string name){
	fstream fin;
    fin.open(name, ios::in);
    vector<string> row;
    string line, word;
    while (!fin.eof()) {
		row.clear();
        getline(fin, line);
        stringstream s(line);
        while(getline(s, word, ',')){
			row.push_back(word);
	    }	
	hashing(row[0],row[1]);
	}
}	

//Checking for the given user in the table
int check_user(string entry){
	if(entry.empty()){
		cout<<"Name Not Found"<<endl;
		return 1;
	}	
	
	int in=static_cast<int>(hashFun(entry)%N);
	
	
	vector<Node>::iterator itr = hashtable[in].begin();//to iterate through the chain
	for(;itr!=hashtable[in].end();itr++){
		if((*itr).username==entry){//stop if the user is found
			break;
		}
	}
	if(itr==hashtable[in].end()){//if the user is not found
		cout<<"Name Not Found"<<endl;
		return 1;
	}
	
	(*itr).password.pop_back();
	
	cout<<"Enter Password:";
	string pass;
	cin>>pass;
	if(pass.compare((*itr).password)==0){//if password entered matches
		cout<<"Login Successful"<<endl;
	    return 0;
		
	}
	cout<<"Incorrect password"<<endl;//if it does not match
	return 1;
	
}
int main(int argc, char** argv){
	N=5000;
	hashtable.assign(N,vector<Node>());
	if(argc<2){
		cout<<"Insufficient arguments";
		return 1;
	}	
	insert_in_table(argv[1]);
	cout<<"Enter Username:";
	string user;
	cin>>user;
	return check_user(user);
	
} 					
