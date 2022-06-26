#include <iostream>

using namespace std;
bool checkPrime(int num){
    bool prime = true;
    for(int i =2; i<num; ++i){
    if(num%i == 0){
            prime = false;
    }
    }
    return prime;
}
void palindrome(int num){
	int reversedNum =0; int a = num;
	for (int i =0; (num!=0); ++i){
		reversedNum = reversedNum*10 + num%10;
		num = num / 10;
    }
    if (reversedNum == a){
        cout<<a<<" is a Palindrome"<<endl;
	}
	else{
        cout<<a<<" is not a Palindrome"<<endl;
	}
}
int perfectNumber(int num){
    int sum = 0;
    for(int i=1; i<num; ++i){
        if(num%i == 0){
            sum = sum+i;
        }
    }
    return sum;
}

int main() {
    int num=0;
    cout << "Enter a number: ";
    cin >> num;

    //Checks Perfect Number
    perfectNumber(num);
    if(perfectNumber(num)==num){
    cout << num << " is a perfect number"<<endl;
    }
    else{
    cout << num << " is not a perfect number"<<endl;
    }

    //Checks Prime Number
	checkPrime(num);
	if (checkPrime(num) ==1){
        cout<<num<<" is a Prime = True"<<endl;
	}
	else{
        cout<<num<<" is a Prime = False"<<endl;
	}

	//Checks Palindrome Number
	palindrome(num);

    return 0;
}
