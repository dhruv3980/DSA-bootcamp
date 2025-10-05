#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
using namespace std;

class Node{
    public:
    unordered_map<char, Node*>children;
    
    int freq;

    bool endOfWords;
    Node(){
        freq=-1;
        endOfWords=false;
    }


};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();

    }

    void insert(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
           if(temp->children.count(key[i])==0){
            temp->children[key[i]]= new Node();
            temp->children[key[i]]->freq=1;

           }
           else{
            temp->children[key[i]]->freq++;

           }
           temp=temp->children[key[i]];
        }
        temp->endOfWords=true;

    }

    string printprefix(string key){
        string prefix="";
        Node* temp=root;

        for(int i=0; i<key.size(); i++){
            prefix+=key[i];
            if(temp->children[key[i]]->freq==1){
                break;

            }
            else{
                temp=temp->children[key[i]];
            }
        }

        return prefix;
    }

};

void prefixProblem(vector<string>dict){
    Trie t;
    for(int i=0; i<dict.size(); i++){
        t.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++){
        cout<<t.printprefix(dict[i])<<"  ->";
    }

}

int main(){
    vector<string> dict = {"zebra", "dog", "duck", "dove"};

    prefixProblem(dict);


}