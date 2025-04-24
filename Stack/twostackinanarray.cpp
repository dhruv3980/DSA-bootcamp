  #include<iostream>
  using namespace std;
  class stack{
    public:
    int size;
    int* arr;
    int top1;
    int top2;

    
    stack(int size){
        arr = new int[size];
         top1=-1;
         top2 = size;
         this->size=size;


    }

    void push1(int data ){
        if(top2-top1==1){
            cout<<" stack 1 is overflow"<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }

    void push2(int data){
        if(top2-top1==1){
            cout<< "stack 2 is overflow"<<endl;
        }
        else{
            --top2;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1>=0){
            arr[top1]=0;
            top1--;

        }
        else{
            cout<<"stack 1 is underflow"<<endl;
        }
    }
    void pop2(){
        
        if(top2<=size-1){
            arr[top2]=0;
            top2++;

        }
        else{
            cout<<"Stack2 is underflow"<<endl;
        }
    }

    void print(){
        cout<<"Top1 is "<<top1<<endl;
        cout<<"top2 is "<<top2<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


  };
  int main(){
    stack s(10);
    

    s.push1(10);
    s.print();

    s.push1(20);
    s.print();
    
    s.push1(30);
    s.print();

    s.push1(40);
    s.print();

    s.push2(100);
    s.print();

    s.push2(90);
    s.print();

    s.push2(80);
    s.print();

    s.push2(70);
    s.print();

    s.push2(60);
    s.print();
    
    s.push2(50);
    s.print();

    
    s.pop1();
    s.print();

    s.pop2();
    s.print();

    s.pop1();
    s.print();

    s.pop2();
    s.print();

    s.pop1();
    s.print();

    s.pop2();
    s.print();

    s.pop1();
    s.print();

    s.pop2();
    s.print();

    s.pop1();
    s.print();

    s.pop2();
    s.print();

   s.pop2();
   s.print();

   

    

  }