#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(){
        this-> data =0;
        this->prev=NULL;
        this->next=NULL;

    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next=NULL;
    }

};

int findlen(Node* head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp= temp->next;
    }

    return len;
}


void print(Node*head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;

    };
};

void insertathead(Node*&head, Node*&tail, int data){
    if(head==NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail= newnode;
        return;
    }

    Node* newnode = new Node(data);
    newnode->next = head;
    head->prev= newnode;
    head=newnode;

};

void inserattail(Node* &head, Node* &tail, int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head= newNode;
        tail= newNode;
        return;
    }

    Node* newNode=new Node(data);
    newNode->prev = tail;
    tail->next=newNode;
    tail = newNode;
};

void insertatpos(Node* &head, Node* &tail, int data, int pos){
    if(head==NULL){
        Node* newnode = new Node(data);
        tail = newnode;
        head = newnode;
        return;



    }

    if(pos==1){
        insertathead(head,tail,data);
        return;
    }

    int len = findlen(head);
    if(pos>len){
        inserattail(head,tail,data);
        return;
    }

    // insertion in middle
    // step -> 1 find prev and curr
    int i=1;
    Node* prev1 = head;
    while(i<pos-1){
        prev1= prev1->next;
        i++;

    }
   
    Node* curr = prev1->next;
    
    // step->2 create a node
    Node* newnode = new Node(data);

    // step->3
    newnode->prev=prev1;
    prev1->next= newnode;

    newnode->next = curr;
    curr->prev=newnode;


    



};

void deletenode(Node* &head, Node* &tail, int pos){
    if(head==NULL){
        cout<<"impossible to delete";
        return;
    }
    int len = findlen(head);
    if(pos>len){
        cout<<"are you mad you try to delete that value which doesn't exist";
    }

    if(head->next ==NULL){
        Node* temp = head;
        head= NULL;
        tail=NULL;
        delete temp;
        
        return;
    }
    //delete from middle of linked list

    // step1: find left, find right,  find current
    Node* left = head;
    int i=1;
    while(i<pos-1){
       left = left->next;
       i++;

    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next=right;
    right->prev = left;
    curr->prev=NULL;
    curr->next=NULL;
    delete curr;

};
int main(){

    

    Node* head =  NULL;
    Node* tail = NULL;

    insertathead(head,tail, 15);
    inserattail(head,tail,20);
    inserattail(head,tail,22);
    inserattail(head,tail,23);
    inserattail(head,tail,24);
    insertatpos(head,tail,35,4);

    deletenode(head,tail, 3);
    
    print(head);

}