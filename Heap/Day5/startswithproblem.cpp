#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char, Node*> children;
    
    bool endOfWord;

    Node(){
        endOfWord=false;
    }

};

class Trie{
    public:

    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]=new Node();
            }
            temp=temp->children[key[i]];
        }
        temp->endOfWord=true;

    }

    bool search(string key){
        Node* temp = root;

        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }
        return true;

    }


};

void startWithProblem(vector<string>a,string key ){
    Trie trie;
    for(int i=0; i<a.size(); i++){
        trie.insert(a[i]);
    }


    if(trie.search(key)){
        cout<<"True";
    }else{
        cout<<"false";
    };
};
int main(){

    vector<string> words={"apple", "app", "mango", "man", "woman"};

    startWithProblem(words, "moon");
}