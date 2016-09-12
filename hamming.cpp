/*
ID:kevin_s1
PROG:hamming
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
#include <bitset>
#include <cmath>

using namespace std;

//gobal variable====
int N, B, D;
vector<bitset<8> > result;
string str = "11111111";
bitset<8> last(str);
int MaxDeep;
//==================


//function==========

int hammingDis(bitset<8> a, bitset<8> b){
	bitset<8> x = a xor b;
	return x.count();
}

bool check(bitset<8> bit){
	for(int i = 0; i < result.size(); i++){
		if(hammingDis(bit, result[i]) < D)
			return false;
	}
	return true;
}

void DFS(int deep, int count){
	if(deep > MaxDeep)
		return;
	if(count > N)
		return;
	//
	bitset<8> tmp(deep + 1);
	//int dist = hammingDis(last, tmp);
	if(/*dist >= D*/check(tmp) == true){
		result.push_back(tmp);
		last = tmp;
		DFS(deep + 1, count + 1);
	}
	else{
		DFS(deep + 1, count);
	}
	return;
}
//==================

int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	cin>>N>>B>>D;
	MaxDeep = (int)pow(2.0, (double)B) - 1;
	DFS(-1, 0);
	for(int i = 0; i < N; i++){
		cout<<result[i].to_ulong();
		if(i != N - 1){
			if(i % 10 == 9)
				cout<<endl;
			else
				cout<<" ";
		}
	}
	cout<<endl;
	return 0;
}
