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
        endOfWord = false;  
    }


    
};

class Trie{
    Node* root;

    public:
    Trie(){
        root =new Node();
    }

    void insert(string word){
        Node* temp = root;

        for(int i=0; i<word.length(); i++){
            char ch = word[i];

            if(temp->children.count(ch)==0){
                Node* newNode = new Node();
                temp->children[ch]=newNode;
            }

            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }

    string largestwordhelper(Node* root, string& ans, string temp){
        for(auto it: root->children){
            char ch = it.first;
            Node* nextNode = it.second;

            if(nextNode->endOfWord==true){
                temp.push_back(ch);

                if(temp.length()>ans.length() || (temp.length()==ans.length() && temp<ans)){
                    ans = temp;
                }

                largestwordhelper(nextNode, ans, temp);

                temp.pop_back();
            }
        }

        return ans;

    }

    string longestWordWithAllPrefix(){
        string ans="";

        return largestwordhelper(root, ans, "");
    }

};




int main(){

    vector<string>words = {"a", "banana", "app", "appl", "ap",  "apple","apply"};

    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
        
    }

    cout<<trie.longestWordWithAllPrefix()<<endl;


}