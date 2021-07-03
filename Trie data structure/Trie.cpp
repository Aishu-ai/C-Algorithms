#include <iostream>
#include <vector>

using namespace std;


class TrieNode{
    private:
    vector<TrieNode*>links;
    
    int R=26;
    bool isEnd=false;
    public:
    TrieNode(){
        links.assign(R,nullptr);
        
    }
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,TrieNode* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        isEnd=true;
    }
    bool IsEnd(){
        return isEnd;
    }
};



class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
        
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode* node=root;
        
        for(int i=0;i<word.length();i++){
            char current=word.at(i);
            
            if(!node->containsKey(current)){
                
                TrieNode*temp=new TrieNode();
                node->put(current,temp);
            }
            node=node->get(current);
        }
        node->setEnd();
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node=searchPrefix(word);
        return node!=nullptr&&node->IsEnd();
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node=searchPrefix(prefix);
        return node!=nullptr;
        
    }
private:
    TrieNode* root;
    TrieNode* searchPrefix(string word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            char current=word.at(i);
            if(node->containsKey(current))
                node=node->get(current);
            else
                return nullptr;
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

