#include <iostream>
using namespace std;
class ccv{
private:
int number1;
public:
ccv(int Number){
    number1=Number;
}
int getDigit(int n1){
    if(n1>9){
        return ((n1/10)+(n1%10));
    }
    else{
        return n1;
    }
}
int getSize(long ccn){
    string num=to_string(ccn);
    return num.length();
}
int getPrefix(long ccn,int k){
    if(getSize(ccn)>k){
        string num=to_string(ccn);
        return stol(num.substr(0,k));
    }
    return ccn;
}
bool prefixMatched(long number, int d)
{
  return getPrefix(number, getSize(d)) == d;
}
int sumOfDoubleEvenNo(long int number){
    int sum=0;
    string num=to_string(number);
    for(int i=getSize(number)-2;i>=0;i-=2){
        sum+=getDigit(int(num[i]-'0')*2);
    }
    return sum;
}
int sumOfOddNo(long number){
    int sum=0;
    string num=to_string(number);
    for(int i=getSize(number)-1;i>=0;i-=2){
        sum+=num[i]-'0';
    }
    return sum;
}
bool isValid(long int number){
return(getSize(number) >= 13 &&getSize(number) <= 16) &&(prefixMatched(number, 4) ||prefixMatched(number, 5) ||prefixMatched(number, 37) ||prefixMatched(number, 6)) &&((sumOfDoubleEvenNo(number) +sumOfOddNo(number)) % 10 == 0);
}
};
int main(){
    long int ccn;
    cout<<"Enter your credit card number: "<<endl;
    cin>>ccn;
    ccv card1(ccn);
   
    if(card1.isValid(ccn)){
        if(card1.prefixMatched(ccn, 4)){
            cout<<"Your card is Visa cards"<<endl;
        }
        else if(card1.prefixMatched(ccn, 5)){
            cout<<"Your card is Master cards"<<endl;
            
        }
        else if(card1.prefixMatched(ccn, 37)){
        cout<<"Your card is American Express cards"<<endl;
        }
        else{
          cout<<"Your card is Discover cards"<<endl;  
        }
      cout<<"Credit card is Valid"<<endl;  
    }
    else{
        cout<<"Sorry Invalid Credit card"<<endl;
    }

    return 0;
}