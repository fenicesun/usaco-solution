/*
ID:kevin_s1
PROG:pprime
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std;

//gobal variable====
long long a,b;
const int MAX_PRIME = 1000000;
int PrimeTable[MAX_PRIME];
int IsPrime[MAX_PRIME + 1];
int PrimeCnt = 0;
//==================


//function==========

void GetPrime(){
	memset(IsPrime, 1, sizeof(IsPrime));
	IsPrime[0] = IsPrime[1] = 0;
	for(int i = 2; i < MAX_PRIME; i++){
		if(IsPrime[i]){
			for(long long j = (PrimeTable[PrimeCnt++] = i) * (long long)i; j < MAX_PRIME; j += i){
				IsPrime[j] = 0;
			}
		}
	}
}

bool isPalindromic(string num){
	bool flag = true;
	long long len = num.length();
	for(long long i = 0; i <= len/2; i++){
		if(num[i] != num[len - i - 1]){
			flag = false;
		}
	}
	return flag;
}

string trans(long long num, int base){
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
//==================

int main(){
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	cin>>a>>b;
	GetPrime();
	for(long long i = a; i <= b; i ++){
		if(IsPrime[i]){
			string num = trans(i, 10);
			if(isPalindromic(num)){
				cout<<num<<endl;
			}
		}
	}

	return 0;
}
