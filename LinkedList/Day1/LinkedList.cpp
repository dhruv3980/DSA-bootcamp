#include<iostream>
using namespace std;// linked list is hindi linear data structure dynamically create ker sakte hai node and delete bhi ker sakte hai 
class Node{
    public:
    int data;
    Node* next; 

    Node(){
        this->data = 0;
        this->next = NULL;

    }

    Node(int data){
        this->data = data;
        this->next=NULL;
    }





};
void insertathead(Node* &head, Node* &tail, int data ){
    // step ->1
    Node* newNode = new Node(data);
    // step ->2
   
    newNode->next = head;

    if(head==NULL){
        tail=newNode;
    }
     
    // step ->3
    head = newNode;



};

// i want to insert a node at the right at the head of the linked list

void insertattail(Node* &head, Node* &tail, int data){
    // step ->1 create a node
    Node* newnode = new Node(data);
    // step ->2 connect with tail node
    if(head==NULL){
        head =newnode;
        tail = newnode;
    }
    else{

        tail->next=newnode;
        // step->3 update tail
        tail = newnode;
    }
   


     

};
void print(Node* &head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

};

int findlength(Node* &head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void insertatpos(Node* &head, Node* &tail, int data , int pos){
    if(head==NULL){
        Node* newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    if(pos==0){
        insertathead(head,tail,data);
        return;
    }

    int len =findlength(head);
    if(pos>=len){
        insertattail(head,tail,data);
        return;
    }



    // step ->1 find the position of prev and current
    int i=1;
    Node*prev = head;
    while(i<pos){
        prev = prev->next;

        i++;
    }
    Node* curr = prev->next;

    // step ->2
    Node* newnode = new Node(data);

    // step->3

    newnode->next = curr;
    prev->next=newnode;


}
void deletenode (int pos, Node* &head, Node* &tail){
    if(head==NULL){
        cout<<"cannot delete , LinkedList is empty";
        return;
    }

    if(pos==1){
        Node* temp = head;
        head = temp->next;
        temp->next=NULL;

        delete temp;

    }


    int len = findlength(head);
    if(pos==len){
        // find prev
        int i=1;
        Node* prev=head;
        while(i<pos-1){
            prev = prev->next;
            i++;
        }

        //step->2
        prev->next=NULL;

        // step ->3
        Node* temp = tail;
        // step-4

        tail=prev;
        // step-5
        delete temp;

    }

    
    // step : find prev and curr
    int i=1;
    Node* prev = head;
    while(i<pos-1){
        prev=prev->next;
        i++;
    }

    Node* curr = prev->next;

    // step -2
    prev->next = curr->next;
    curr->next = NULL;

    delete curr;

}


int main(){
    Node* head = NULL;
    Node*tail = NULL;

    insertattail(head,tail,12);
    insertattail(head,tail,120);

    insertatpos(head,tail,2,0);

    deletenode(2,head,tail);



    cout<<"print the Linked List"<<endl;
    print(head);




}