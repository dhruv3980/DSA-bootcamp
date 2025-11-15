#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Node{
    public:
    unordered_map<char, Node*>children;
    int frequency;
    bool endOfWord;

    Node(){
        frequency=0;
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
                temp->children[ch]->frequency=1;
            }else{
                temp->children[ch]->frequency+=1;    
                

            }
            temp = temp->children[ch];

        }

        temp->endOfWord=true;
    }


    string shortestuniquePrefix(string word){
        Node* temp = root;
        string prefix = "";
        for(int i=0; i<word.length(); i++){
            char ch = word[i];

            if(temp->children.count(ch)){
                prefix.push_back(ch);

                if(temp->children[ch]->frequency==1){
                    return prefix;
                }


            }
            else{
                break;
            };
           

        }

        return prefix;


    }
        

     

};

int main(){

    vector<string>words = {"zebra", "dog", "duck", "dove"};

    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    vector<string>ans;

    for(int i=0; i<words.size(); i++){
        ans.push_back(trie.shortestuniquePrefix(words[i]));
    }

    for(auto it: ans){
        cout<<it<<" ";
    }

}