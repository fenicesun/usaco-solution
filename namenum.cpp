/*
ID:kevin_s1
PROG:namenum
LANG:C++
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

string str[10];

set<string> dict;
set<string> vec;

string num;   //the number of input
int n;     //the bit of the input number
int numm[13];

string _name;
int result;

int splitNum(int *a,string num){
	int nn = 1;
	for(int i = 0; i < num.length(); i++){
		a[nn++] = num[i] - '0';
	}
	nn--;
	/*
	while(num != 0){
		a[nn++] = num%10;
		num = num/10;
	}
	nn--;
	for(int i = 1; i <= nn/2; i++){
		int tmp = a[i];
		a[i] = a[nn - i + 1];
		a[nn - i + 1] = tmp;
	}
	*/
	return nn;
}


//search
void DFS(int index){
	if(index == n){
		//
		set<string>::iterator iter = dict.begin();
		iter = dict.find(_name);
		if(iter != dict.end()){
			vec.insert(*iter);
			result++;
		}
		return;
	}
	for(int i = 1; i <= 3; i++){
		//
		string _str = _name;
		char ch = str[numm[index + 1]][i];		
		//set the index-th char of the string
		_name = _name + ch;
		DFS(index + 1);
		//remove the index-th char of the string
		_name = _str;
	}
}


int main(){
	str[2] = " ABC";
	str[3] = " DEF";
	str[4] = " GHI";
	str[5] = " JKL";
	str[6] = " MNO";
	str[7] = " PRS";
	str[8] = " TUV";
	str[9] = " WXY";
	ifstream ifs("dict.txt");
	streambuf* old_buf = cin.rdbuf(ifs.rdbuf());
	string name;
	while(cin>>name){
		dict.insert(name);
	}
	cin.rdbuf(old_buf);
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	cin>>num;
	n = splitNum(numm,num);
	_name = "";
	result = 0;
	DFS(0);
	if(result == 0){
		cout<<"NONE"<<endl;
	}
	set<string>::iterator iter = vec.begin();
	for(; iter != vec.end(); iter++){
		cout<<*iter<<endl;
	}
	return 0;
}
