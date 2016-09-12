/*
ID:kevin_s1
PROG:prefix
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cstring>

using namespace std;

struct trie_node{
    trie_node* next[26];
    bool is_terminal;
    trie_node(){
        memset(next,0,sizeof(next));
        is_terminal = false;
    }
};

void insert_str(trie_node*root,const char*str,int len)
{
    trie_node * cur=root;

    for(int i=0;i<len;++i){
        if( cur->next[str[i]-'A']==NULL){
            cur->next[str[i]-'A'] = new trie_node;
        }
        cur = cur->next[str[i]-'A']; 
    }

    cur->is_terminal = true;
}

bool find_str(trie_node*root,const char *str,int len)
{
    trie_node * cur = root;

    for(int i=0;i<len;++i){
        if( cur->next[str[i]-'A'] == NULL )
            return false;
        else 
            cur = cur->next[str[i]-'A'];
    }

    if(cur->is_terminal) 
        return true;
    else
        return false;
}

char buf[200000];
int dp[2000001];
int buf_len;
trie_node root;

void input()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);

    while(scanf("%s",buf)&&strcmp(buf,".")!=0){
//        printf("%s ",buf);
          insert_str(&root,buf,strlen(buf));
    }

//    printf("\n");

    int c;
    buf_len=0;
    while( (c=getchar())!=EOF){
        if(!isspace(c)){
            buf[buf_len++] = (char)c;
//            printf("%c",c);
        }
    }
//    printf("%d\n",buf_len);
}

void solve()
{
    input();

    dp[buf_len]=0;
    for(int i=buf_len-1;i>=0;--i){
       for(int j=1;j<=10&&i+j-1<buf_len;++j){
           if( find_str(&root,&buf[i],j) )
               if(dp[i+j]+j>dp[i])
                   dp[i] = dp[i+j]+j;
       } 
    }

    printf("%d\n",dp[0]);
}

int main(int argc,char *argv[])
{
    solve(); 
    return 0;
}
