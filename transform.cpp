/*
ID:kevin_s1
PROG:transform
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;

char source[11][11];
char target[11][11];

bool compare_mat(char sour[][11]){
	bool flag = true;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(sour[i][j] != target[i][j])
				flag = false;
		}
	}
	return flag;
}

void rotate(){
	int tmp[11][11];					
	int dst = N;

	for(int i = 1; i <= N;i++,dst--){
		for(int j = 1; j <= N; j++){
			tmp[j][dst] = source[i][j];
		}
	}

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			source[i][j] = tmp[i][j];
		}
	}
}


void Reflection(){
	for(int i = 1; i <= N/2; i++){
		for(int j = 1; j <= N; j++){
			int tmp = source[j][i];
			source[j][i] = source[j][N - i + 1];
			source[j][N - i + 1] = tmp;
		}
	}
}

void print(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout<<" "<<source[i][j];
		}
		cout<<endl;
	}
}
int main(){
	
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	cin>>N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin>>source[i][j];
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin>>target[i][j];
		}
	}
	int ans = 7;
	if(compare_mat(source)){
		ans = min(ans,6);
	}
	rotate();
	if(compare_mat(source)){
		ans = min(ans,1);
	}
	rotate();
	if(compare_mat(source)){
		ans = min(ans,2);
	}
	rotate();
	if(compare_mat(source)){
		ans = min(ans,3);
	}
	rotate();
	Reflection();
	if(compare_mat(source)){
		ans = min(ans,4);
	}
	rotate();
	if(compare_mat(source)){
		ans = min(ans,5);
	}
	rotate();
	if(compare_mat(source)){
		ans = min(ans,5);
	}
	rotate();
	if(compare_mat(source)){
		ans = min(ans,5);
	}

	
	cout<<ans<<endl;
	return 0;
}
