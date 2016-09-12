/*
ID:kevin_s1
PROG:runround
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
//直接枚举即可

//gobal variable====
long long M;
int num[100];
int num_size;

int hash[10];
int hash1[10];
//==================


//function==========
int init(long long i){
	int x = 1;
	while(i != 0){
		num[x++] = i % 10;
		i = i / 10;
	}
	x--;
	for(int i = 1; i <= x/2; i++){
		int tmp = num[i];
		num[i] = num[x - i + 1];
		num[x - i + 1] = tmp;
	}
	return x;
}

bool judge(long long x){
	for(int i = 1; i <= num_size; i++){
		hash1[num[i]]++;
		if(hash1[num[i]] > 1 || num[i] == 0){
			return false;
		}
	}
	int j = 1;
	for(int i = 1; i <= num_size; i++){
		int bit = num[j];
		j = j + bit;
		if(j > num_size && (j % num_size) != 0){
			j = j % num_size;
		}
		if(j > num_size && (j % num_size) == 0){
			j = num_size;
		}
		if(hash[j] == 1){
			return false;
		}
		hash[j] = 1;
	}
	bool flag = true;
	if(j != 1)
		flag = false;
	for(int i = 1; i <= num_size; i++){
		if(hash[i] == 0){
			flag = false;
			break;
		}
	}
	return flag;
}

//==================

int main(){
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	cin>>M;
	memset(num, 0, sizeof(num));
	memset(hash, 0, sizeof(hash));
	memset(hash1, 0, sizeof(hash1));
	M++;
	num_size = init(M);
	while(!judge(M)){
		M++;
		memset(num, 0, sizeof(num));
		memset(hash, 0, sizeof(hash));
		memset(hash1, 0, sizeof(hash1));
		num_size = init(M);
	}
	cout<<M<<endl;
	return 0;
}
