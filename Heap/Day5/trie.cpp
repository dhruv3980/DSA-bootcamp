#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
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
        root=new Node();
    }
  

    void insert(string key){
        Node* temp=root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();

            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;
    }

    bool search(string key){
        Node* temp=root;

        for(int i=0; i<key.size(); i++){
            if(temp->children[key[i]]){
                temp=temp->children[key[i]];


            }else{
                return false;

            }
        }
        return temp->endOfWord;
        

       

    }
    
};
int main(){
    vector<string>words = {"the", "a", "there", "their", "any", "there"};

    Trie a;

    for(int i=0; i<words.size(); i++){ // TC -> O(n*L) where L is the length of the key
        a.insert(words[i]);
    }
    
    cout<<a.search("there");

}