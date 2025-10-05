#include <iostream>
#include <string>
using namespace std;
class Node
{
    public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next; 
        }

    }

};

class HashTable{
    int totalSize=5;
    int currentSize;
    Node** table;

    int hashing(string key){
        int idx=0;
        for(int i=0; i<key.size(); i++){
            idx+=(key[i]*key[i])%totalSize;
             idx %= totalSize;

        }
        return idx;
    };


    
    void rehashing(){
        int oldSize = totalSize;
        Node** oldTable = table;
        currentSize=0;
        totalSize = totalSize*2;

        table = new Node*[totalSize];
        for(int i=0; i<totalSize; i++){
            table[i]=NULL;
        }

        // copy old value
        for(int i=0; i<oldSize; i++){
            Node* head = oldTable[i];
            while(head!=NULL){
                insert(head->key, head->value);
                head=head->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable[i];
            }
           

        }

        delete[] oldTable;

        
    }
   
 
    public:

    HashTable(){
        totalSize=7;
        currentSize=0;
        table=new Node*[totalSize];

        for(int i=0; i<totalSize; i++){
            table[i] = NULL;
        };

    };



    void insert(string key, int val){
        int idx = hashing(key);

        Node* newNode = new Node(key, val);


        // Node* head = table[idx]; //NULL

        newNode->next =table[idx];

        // head=newNode;
        table[idx] = newNode;

        currentSize++;


        // now check the size of table is greater then the total size if yes then rehashing

        double lamda = currentSize/(double) totalSize;

        if(lamda>1){
            rehashing(); //o(n)
        }

        





       

    }

    bool exist(string key){
        int idx = hashing(key);

        Node* head = table[idx];
        while(head!=NULL){
            if(head->key==key){
                return true;
            }
            head=head->next;
        }
        return false;
    }
    int search(string key){
        int idx = hashing(key);
        Node* head =table[idx];

        while(head!=NULL){
            if(head->key == key){
                return head->value;
            }

            head=head->next; 


        }
        return -1;

    }
    void erase(string key){

        int idx = hashing(key);
        Node* temp = table[idx];
        Node* prev = temp;

        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[idx]=temp->next;

                }
                else{
                    prev->next=temp->next; 

                 }
                 break;
            }
            prev=temp;
            temp=temp->next;
            
        }
    }
    
    void print(){
         for(int i=0; i<totalSize; i++){
            cout<<"idx "<<i<<"->";
            Node* temp = table[i];
            while(temp!=NULL){
                cout<<"(" <<temp->key<<","<<temp->value<<")"<<"->";
                temp=temp->next;
            }
            cout<<endl; 
         }
    }


};


 int main(){

    HashTable ht;
    
    ht.insert("india", 150);
    ht.insert("china", 1570);
    ht.insert("usa", 1580);
    ht.insert("austrellia", 1750);
    ht.insert("newzeland", 1580);
     ht.insert("newzelad", 180);

    if(ht.exist("newzelad")){
        cout<<"newzelad "<<ht.search("newzelad")<<endl;
    }

    ht.print();
    cout<<"after erasing hast table is "<<endl;
    ht.erase("newzeland");
    ht.print();
     
}








// for averge case time complexity is o(1) for insertion and in worst case time complexity is o(n)


