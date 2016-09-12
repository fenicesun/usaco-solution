/*
ID:kevin_s1
PROG:palsquare
LANG:C++
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int B;

bool isPalindromic(string num){
	bool flag = true;
	int len = num.length();
	for(int i = 0; i <= len/2; i++){
		if(num[i] != num[len - i - 1]){
			flag = false;	
		}
	}
	return flag;
}

string trans(int num, int base){
	string str;
	while(num > 0){
		if(num % base < 10){
			str += num % base + '0';
		}
		else{
			str += num % base - 10 + 'A';
		}
		num = num / base;
	}
	reverse(str.begin(),str.end());
	return str;
}



int main(){

	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	cin>>B;
	for(int i = 1; i <= 300; i++){
		int squre = i*i;
		string _squre = trans(squre,B);
		if(isPalindromic(_squre)){
			string number = trans(i,B);
			cout<<number<<" "<<_squre<<endl;
		}
	}

	return 0;
}
