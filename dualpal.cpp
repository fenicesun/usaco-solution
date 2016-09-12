/*
ID:kevin_s1
PROG:dualpal
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N,S;
vector<int> result;

bool isPalindromic(string num){
	bool flag = true;
	int len = num.length();
	for(int i = 0; i <= len/2; i++){
		if(num[i] != num[len - i - 1]){
			flag = false;
		}
	}
	if(num[0] == '0' || num[len - 1] == '0')
		flag = false;
	return flag;
}

string trans(int num,int base){
	string str;
	while(num > 0){
		str += num % base + '0';
		num = num / base;
	}
	reverse(str.begin(),str.end());
	return str;
}

int main(){
	
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	cin>>N>>S;
	int index = 0;
	for(int i = S + 1; index < N; i++){
		int x = i;
		int count = 0;
		for(int base = 2; base <= 10; base++){
			string num = trans(x,base);
			if(isPalindromic(num)){
				count++;
			}
		}
		if(count >= 2){
			index++;
			result.push_back(x);
		}
	}
	vector<int>::iterator iter = result.begin();
	for(;iter != result.end();iter++){
		cout<<*iter<<endl;
	}
	return 0;
}
