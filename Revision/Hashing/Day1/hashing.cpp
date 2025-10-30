#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val=val;
        next=NULL;

    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
       
    }
};

class HashTable{
    Node** arr;
    int currentSize;
    int totalSize;


    int hashingidx(string key){
        double idx =0;
        for(int i=0; i<key.size(); i++){
            idx+=(key[i]*key[i])%totalSize;

        }

        return (int) idx% totalSize;

    }

    void rehashing(){
        Node** oldTable = arr;
        int oldSize = totalSize;

        totalSize = 2*oldSize;

        arr = new Node*[2*oldSize]; 
        currentSize=0;
        for (int i = 0; i < totalSize; i++) arr[i] = NULL;


        for(int i=0; i<oldSize; i++){
            Node* temp = oldTable[i];

            while(temp!=NULL){
                insert(temp->key, temp->val);

                temp=temp->next;

            }
        }

        // now here delete the oldtable
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != NULL) {
                delete oldTable[i]; // Node destructor will delete the full chain
            }
        }


        delete[] oldTable;


    }
    
    public:
    HashTable(int size=5){
        totalSize=size;
        currentSize=0;
        arr = new Node* [totalSize];

        for(int i=0; i<size; i++){
            arr[i]=NULL;
        }

    }

    void insert(string key, int val){
        // first find the index where to stored the value
        int idx = hashingidx(key);
        // after insert the value
        
        Node* newNode = new Node(key, val);

        newNode->next = arr[idx];
        arr[idx]=newNode;

        currentSize++;

        double lamda = currentSize/(double) totalSize;
        if(lamda>1){
            rehashing();
        }



    }


    void  erase(string key){
        int idx = hashingidx(key);

        // now i take two pointer first one is prev and current then if current ==key then erase
        Node* temp = arr[idx];
        Node* prev = temp;

        while(temp!=NULL){
            if(temp->key ==key){
                // here check if temp and prev same that means the root val deleted
                if(temp==prev){
                    arr[idx] = temp->next;

                    temp->next = NULL;

                    delete temp;
                    break;

                }else{
                    prev->next = temp->next;
                    temp->next = NULL;
                    delete temp;

                    break;

                }

            }

            prev=temp;
            temp = temp->next;
            

        }
    }


    bool exist(string key){
         int idx = hashingidx(key);
         Node* temp = arr[idx];

         while(temp!=NULL){
            if(temp->key==key){
                return true;
                
            }
            temp=temp->next;
         }

         return false;

    }

    int searchkey(string key){
        int idx = hashingidx(key);

        Node* temp = arr[idx];

        while(temp!=NULL){
            if(temp->key == key){
                return temp->val;
            }

            temp=temp->next;
        }

        return -1;
    }

    void print(){
        for(int i=0; i<totalSize; i++){
            Node* temp = arr[i];

            while(temp!=NULL){
                cout<<i<<" "<<temp->key<<" , "<<temp->val<<endl;
                temp= temp->next;
            }

        }

    }


};
int main(){


HashTable ht(5);

ht.insert("India", 150);
ht.insert("China", 150);
ht.insert("US", 50);
ht.insert("Nepal", 10);
ht.insert("UK", 20);


ht.print();


cout<<ht.searchkey("US");



} 