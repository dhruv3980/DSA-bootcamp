#include<iostream>
using namespace std;

int getlength(char arr[]){ // get the length
    int i=0;
    int length=0;
    while(arr[i]!= '\0'){
        length++;
        i++;

    }
    return length;
}
void   reverse(char arr[]){ // reverse a string
    int i=0;
    int  j =getlength(arr)-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;

    }
    
    
}
bool palindrome(char arr[]){ // check string is palindrome or not
    int start=0;
    int end = getlength(arr)-1;
    while(start<end){
        if(arr[start]==arr[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;

}
void convertlowercase(char arr[]){// convert arr ele into lower case
    int start=0;
    int end = getlength(arr);
    for(int i=0; i<end; i++){
        if(arr[i]>='A' && arr[i]<='Z'){
            arr[i]=arr[i]-'A'+'a';
        }
    }

}

int main(){
    char name[100];
    cin.getline(name,50);
    
    // cout<<"before swapping array is "<<name<<endl;

    //  reverse(name);
    //  cout<<"After swapping array is "<<name<<endl;
    // cout<<"string is palindrome if 1 then yes otherwise no "<<palindrome(name);

    convertlowercase(name);
    cout<<name;
     

     
}