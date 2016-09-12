/*
ID:kevin_s1
PROG:zerosum
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
int N;
vector<string> result;
//==================


//function==========
char NumToChar(int i){
	char ch = i + 48;
	return ch;
}


void DFS(int i, int sum, string str, int last_operator){
	if(i > N + 1)
		return;
	if(i == N + 1){
		if(sum == 0){
			result.push_back(str);
		}
		return;
	}
	//plus
	string tmp1 = str;
	tmp1 = tmp1 + "+" + NumToChar(i);
	DFS(i + 1, sum + i, tmp1, i);
	//minus
	string tmp2 = str;
	tmp2 = tmp2 + "-" + NumToChar(i); 
	DFS(i + 1, sum - i, tmp2, -i);
	//multiply
	string tmp3 = str;
	tmp3 = tmp3 + " " + NumToChar(i);
	int cc = 0;
	if(last_operator > 0)
		cc = 1;
	else
		cc = -1;
	int mt = cc * (abs(last_operator) * 10 + i);
	int sum_tmp = sum - last_operator + mt;
	DFS(i + 1, sum_tmp, tmp3, mt);
	return;
}

//==================

int main(){
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	cin>>N;
	string str = "1";
	DFS(2, 1, str, 1);
	sort(result.begin(), result.end(), less<string>());
	vector<string>::iterator iter;
	for(iter = result.begin(); iter != result.end(); iter++){
		cout<<*iter<<endl;
	}
	return 0;
}
