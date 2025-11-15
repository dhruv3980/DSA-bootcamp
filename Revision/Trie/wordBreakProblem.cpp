#include<iostream>
#include<vector>    
#include<unordered_map>
#include<string>    
using namespace std; 

class Node{
    public:
    unordered_map<char, Node*>children;
    
    bool endOfWord;

    Node(){
        
        endOfWord=false;
    }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* temp =root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(temp->children.count(ch)==0){
                Node* newNode = new Node();
                temp->children[ch]=newNode;
                
            }
            temp = temp->children[ch];

        }

        temp->endOfWord=true;
    }


    bool search(string word){
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            temp = temp->children[ch];
        }

        return temp->endOfWord;
    }


    bool hepler(Trie & trie, string key){
        if(key.size()==0){
            return true;
        }
        for(int i=0; i<key.length(); i++){
            string firstpart = key.substr(0,i+1);
            string secondpart = key.substr(i+1);

            if(trie.search(firstpart) && hepler(trie, secondpart)){
                return true;
            }
            
        }   

        return false;
    }
};
int main(){
    vector<string> dictionary = {"i","like","sam","sung","samsung","mobile","ice"};


    Trie trie;
    for(auto word: dictionary){
        trie.insert(word);
    }
    string key = "ilikesamsung";
    if(trie.hepler(trie, key)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


}