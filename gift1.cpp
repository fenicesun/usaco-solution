/* 
ID:kevin_s1	
PROG:gift1
LANG:C++
*/ 


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


struct giver{
	string name;
	int init;
	int give;
	int receive;

}givers[11];

int NP;

int getIndex(string name){
	for(int i = 1; i <= NP; i++){
		if(givers[i].name == name){
			return i;
		}
	}
}

void addmoney(string name,int money){
	for(int i = 1; i <= NP; i++){
		if(givers[i].name == name){
			givers[i].receive += money;
			break;
		}
	}
}

int main(){

	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	cin>>NP;
	for(int i = 1; i <= NP; i++){
		string name;
		cin>>name;
		givers[i].name = name;
		givers[i].init = 0;
		givers[i].give = 0;
		givers[i].receive = 0;
	}
	for(int i = 1; i <= NP; i++){
		string name;
		int init,num;
		cin>>name;
		int index = getIndex(name);
		
		cin>>init>>num;
		if(init == 0)
			continue;
		if(num == 0)
			continue;
		givers[index].init = init;
		int surplus = init - num*(init/num);
		givers[index].give = init - surplus;
		int money = init/num;
		for(int j  = 1; j <= num; j++){
			cin>>name;
			addmoney(name,money);
		}
		
	}
	for(int i = 1; i <= NP; i++){
		cout<<givers[i].name<<" ";
		cout<< - givers[i].give + givers[i].receive<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
