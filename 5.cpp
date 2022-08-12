#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int x,y,z;
const int maxn=1e5+5;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int st[maxn],dis[maxn];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int spfa(){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=1;
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                if(!st[j]){
                    q.push(j);
                    st[j]=1;
                }
            }
        }
    }
    if(dis[n]>0x3f3f3f3f/2) return 0x3f3f3f3f;
    return dis[n];
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++) {
        cin>>x>>y>>z;
        add(x,y,z);
    }
    int t=spfa();
    if(t==0x3f3f3f3f) printf("impossible\n");
    else printf("%d",t);
    return 0;
}
