/*
ID:kevin_s1
PROG:lamps
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
#include <bitset>
#include <strstream>

using namespace std;

//gobal variable====
int N;
int C;
int state[101];
int on, off;
int ons[101], offs[101];
int _count;
vector<long long> hash;
vector<string> result;
//==================


//function==========
void print(){
	for(int i = 1; i <= N; i++){
		cout<<state[i];
	}
	cout<<endl;
}

void init(){
	for(int i = 1; i <= N; i++)
		state[i] = 1;
}

bool check(){
	for(int i = 0; i < on; i++){
		if(state[ons[i]] != 1){
			return false;
		}
	}
	for(int i = 0; i < off; i++){
		if(state[offs[i]] != 0){
			return false;
		}
	}
	return true;
}

void change(int i){
	if(state[i] == 0)
		state[i] = 1;
	else if(state[i] == 1)
		state[i] = 0;
}

void Button1(){
	for(int i = 1; i <= N; i++){
		change(i);
	}
}

void Button2(){
	for(int i = 1; i <= N; i+=2){
		change(i);
	}
}

void Button3(){
	for(int i = 2; i <= N; i+=2){
		change(i);
	}
}

void Button4(){
	for(int i = 0; (3*i + 1) <= N; i++){
		int k = 3 * i + 1;
		change(k);
	}
}

void Button(int i){
	if(i == 1)
		Button1();
	if(i == 2)
		Button2();
	if(i == 3)
		Button3();
	if(i == 4)
		Button4();
}

void DFS(int i){
	if(i > C)
		return;
	if(check()){
		long long sum = 0;
		for(int i = 1; i <= N; i++){
			sum = sum * 10;
			sum = sum + state[i];
		}
		vector<long long>::iterator iter = find(hash.begin(), hash.end(), sum);
		if(iter == hash.end()){
			_count++;
			hash.push_back(sum);
			string str;
			for(int i = 1; i <= N; i++){
				char ch = state[i] + 48;
				str = str + ch;
			}
			result.push_back(str);
		}
	}
	for(int j = 1; j <= 4; j++){
		Button(j);
		DFS(i + 1);
		Button(j);
	}
	return;
}


//==================

int main(){
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	cin>>N;
	cin>>C;
	on = 0, off = 0;
	_count = 0;
	int _on, _off;
	while(cin>>_on && _on != -1){
		ons[on++] = _on;
	}
	while(cin>>_off && _off != -1){
		offs[off++] = _off;
	}
	init();
	while(C > 4){
		C = C - 2;
	}
	DFS(0);
	sort(result.begin(), result.end(), less<string>());
	vector<string>::iterator iter = result.begin();
	for(;iter != result.end(); iter++){
		cout<<*iter<<endl;
	}
	if(_count == 0){
		cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
