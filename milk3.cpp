/*
ID:kevin_s1
PROG:milk3
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A,B,C;
int milk[21][21][21];
int note[21];

void DFS(int a, int b, int c){

	if(milk[a][b][c] == 1)
		return;
	milk[a][b][c] = 1;
	if(a == 0){
		note[c] = 1;
	}	

	//A to B
	if(a + b <= B){
		DFS(0, a + b, c);
	}
	else{
		DFS(a + b - B, B, c);
	}
	//A to C
	if(a + c <= C){
		DFS(0, b, a + c);
	}else{
		DFS(a + c - C, b, C);
	}
	//B to A
	if(b + a <= A){
		DFS(a + b, 0, c);
	}
	else{
		DFS(A, a + b - A, c);
	}
	//B to C
	if(b + c <= C){
		DFS(a, 0, b + c);
	}else{
		DFS(a, b + c - C, C);
	}
	//C to A
	if(c + a <= A){
		DFS(c + a, b, 0);
	}
	else{
		DFS(A, b, a + c - A);
	}
	//C to B
	if(c + b <= B){
		DFS(a, b + c, 0);
	}
	else{
		DFS(a, B, b + c - B);
	}

	return;
}

int main(){
	
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	memset(note,0,sizeof(note));
	memset(milk,0,sizeof(milk));
	cin>>A>>B>>C;
	DFS(0, 0, C);
	bool flag = false;
	for(int i = 0; i <=20; i++){
		if(note[i] == 1 && flag){
			cout<<" ";
		}
		if(note[i]){
			cout<<i;
			flag = true;
		}
	}
	cout<<endl;
	return 0;
}
