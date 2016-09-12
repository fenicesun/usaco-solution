/*
ID: kevin_s1
PROG: ride
LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int getfinalnum(string str){
	int product = 1;
	for(int i = 0; i < str.length(); i++){
		product = product * (str[i] - 'A' + 1);
	}
	return product%47;
}

int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string comet,group;
	cin>>comet;
	cin>>group;
	int a = getfinalnum(comet);
	int b = getfinalnum(group);
	if(a == b)
		cout<<"GO"<<endl;
	else
		cout<<"STAY"<<endl;
	return 0;
}
