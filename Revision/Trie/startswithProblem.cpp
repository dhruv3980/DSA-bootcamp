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
        root=new Node();
    }

    void insert(string word){
        Node* temp = root;

        for(int i=0; i<word.length(); i++){

            if(temp->children.count(word[i])==0){
                Node* newNode = new Node();
                temp->children[word[i]]=newNode;
            }

            temp=temp->children[word[i]];

        }  
        temp->endOfWord=true;  
    };


    bool startwith(string word){
        Node* temp = root;

        for(int i=0; i<word.length();i++){
            char ch = word[i];

            if(temp->children[ch]){
                temp=temp->children[ch];

            }else{
                return false;
            }
        }


        return true;
    }

};
int main(){

    vector<string>words = {"apple", "app", "mango", "man", "woman"};

    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }


    cout<<trie.startwith("ap")<<endl;
    cout<<trie.startwith("moon")<<endl;

}