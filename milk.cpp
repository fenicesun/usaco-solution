/*
ID:kevin_s1
PROG:milk
LANG:C++
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAXN 5001

using namespace std;

int N,M;
struct farmer{
	int Pi;
	int Ai;
}farmers[MAXN];

int cmp(farmer a,farmer b){
	return a.Pi < b.Pi;
}

int main(){
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	cin>>N>>M;
	for(int i = 1; i <= M; i++){
		cin>>farmers[i].Pi>>farmers[i].Ai;
	}
	sort(farmers + 1, farmers + M + 1, cmp);
	int count = 0;
	int index = 1;
	int money = 0;
	while(count < N){
		if(count + farmers[index].Ai <= N){
			count = count + farmers[index].Ai;
			money += farmers[index].Pi * farmers[index].Ai;
			index++;
		}
		if(count + farmers[index].Ai > N){
			money += farmers[index].Pi * (N - count);
			count = N;
			index ++;
		}
	}
	cout<<money<<endl;

	return 0;
}
