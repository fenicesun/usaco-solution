/*
ID:kevin_s1
PROG:sprime
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
vector<vector<int> > prime(9);
int N;
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

bool isPrime(int i)
{
	bool tag = true;
	int place = (int)sqrt((double)i);
	int value;
	for(int j = 3; j <= place; j+=2)//质数判别
	{
		if(i % j == 0)
		{
			tag = false;
			break;
		}
	}
	return tag;
}

//==================

int main(){
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	cin>>N;
	GetPrime();
	prime[1].push_back(2);
	prime[1].push_back(3);
	prime[1].push_back(5);
	prime[1].push_back(7);
	for(int i = 2; i <= N; i++){
		for(int j = 0; j < prime[i - 1].size(); j++){
			long long num = prime[i - 1][j] * 10;
			if(isPrime(num + 1))
				prime[i].push_back(num + 1);
			if(isPrime(num + 3))
				prime[i].push_back(num + 3);
			if(isPrime(num + 7))
				prime[i].push_back(num + 7);
			if(isPrime(num + 9))
				prime[i].push_back(num + 9);
		}
	}
	for(int i = 0; i < prime[N].size(); i++){
		cout<<prime[N][i]<<endl;
	}
	return 0;
}
