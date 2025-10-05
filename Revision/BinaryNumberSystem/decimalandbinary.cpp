#include<iostream>
using namespace std;
void binaryTodec(int binary){
    int ans=0;
    int pow = 1;

    while(binary>0){
        int lastDigit = binary%10;

        ans+=lastDigit*pow;
        pow=pow*2;
        binary=binary/10;
    }

    cout<<"Decimal Number is "<<ans<<endl;
}

void decimalTobin(int decimalNumber){
    int ans=0;
    int pow = 1;

    while(decimalNumber>0){
        int lastDigit = decimalNumber%2;
        ans+=pow*lastDigit;

        pow=pow*10;

        decimalNumber=decimalNumber/2;
    }

    cout<<"Binary Number is "<<ans;
};
int main(){
    binaryTodec(111);

    decimalTobin(8);
}