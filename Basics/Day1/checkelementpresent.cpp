#include<iostream>
using namespace std;
// bool find(int arr[], int size , int key){
//     for(int i=0; i<size; i++){
//         if(arr[i]==key){
//             return true;
//         }
//     }
//     return false;
// }
// int main(){
//     int arr[8]={1,2,3,4,5,6,7,8};
//     if(find(arr, 8, 15)){
//         cout<<"found;";
//     }
//     else{
//         cout<<"not found";
//     }

// }

int main(){
    bool flag =0;
    int arr[]={1,2,3,4,5,6,7};
    int size =7;
    int key =15;

   for(int i=0; i<size; i++){
    if(arr[i]==key){
        flag=1;
        break;
    }
   }
   if(flag==1){
    cout<<"found";
   }
   else{
    cout<<"not found";
   }
}