#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next=NULL;

    }

    ~Node(){
       
        if(next!=NULL){
            delete next;
            next=NULL;

        }
    }

};

class LinkList{
    Node* head;
    Node* tail;

    public:
    LinkList(){
        head=tail=NULL;
    }


    void pushfront(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head=tail=newNode;

        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }

    void push_back(int data){
        Node* newNode=new Node(data);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void popfront(){
        if(head==NULL){
            cout<<"Cant delete empty linkedlist"<<"\n";
            return;

        }

        Node* temp = head;
        head=head->next;

        temp->next=NULL;
        delete temp;

    }

    void pop_back(){
       Node* temp=head;
        if(temp==NULL){
            cout<<"LinkList empty not delete anything"<<endl;

            return;
        }

        while(temp->next->next!=NULL){
            temp=temp->next;
        }

        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    
    

    void printLinkList(){
        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->data<<"=>";

            temp=temp->next;
        }

        cout<<"NULL";
    }

    void reverseALinkList(){
        Node* prev=NULL;
        Node* current = head;
        
        

        while(current!=NULL){
            Node* next = current->next;

            current->next=prev;
            prev=current;
           
            current=next;

        }

        head = prev;
    }

    void insertInALLMiddle(int pos, int data){
        Node* temp = head;

        for(int i=0; i<pos-1; i++){
            temp=temp->next;
        }

        Node* newNode = new Node(data);

        newNode->next=temp->next;

        temp->next=newNode;

    }

    int searchKey(int data){
        Node* temp = head;
        if(temp==NULL){
            cout<<"key not exist"<<endl;
            return -1;
        }

        int idx=0;

        while(temp!=NULL){
            if(temp->data==data){
                return idx+1;
            }
            idx++;
            temp=temp->next;
        }

        return -1;
    }

    int helper(int data, Node* head){
        if(head==NULL){
            return -1;
        }

        if(head->data==data){
            return 1;

        }

        int ans= helper(data, head->next);
        if(ans){
            return 1+ans;
        }
        return -1;
    }
    int searchRec(int data){
        helper(data, head);

        
    }

    
    int size(){
        Node* temp = head;

        int idx =0;

        while(temp!=NULL){
            idx++;
            temp=temp->next;
        }

        return idx;
    }

    void removeNthNode(int n){
        int lsize = size();

     

        Node* temp = head;
        

        for(int i=0; i<lsize-n-1; i++){
            temp=temp->next;
        }

        Node* deleteNode = temp->next;

        temp->next= temp->next->next;

        deleteNode->next=NULL;
        delete deleteNode;

    }


    ~LinkList(){
        if(head!=NULL){
            delete head;
            head=NULL;

        }
        
    }

};
int main(){

    LinkList ll;


    ll.push_back(4);
    ll.push_back(5);
    
    ll.pushfront(3);
    ll.pushfront(2);
    ll.pushfront(1);

    // // ll.popfront();
    // ll.insertInALLMiddle(2,100);

    // int ans=ll.searchRec(3);
    // cout<<ans;

    

   

    ll.reverseALinkList();

    ll.removeNthNode(4);

    ll.printLinkList();


}