#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 10;
struct edge{
    int u,v,w;
}e[N];
int n,m;
int d[2*N];
int backup[2*N];
int cnt[2 * N];
bool bellman_ford(){
    bool flag = false;
    for(int i = 1;i <= n;i ++){
        flag = false;
        memcpy(backup,d,sizeof d);
        for(int j = 1;j <= m;j ++){
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;
            if(d[v] > backup[u] + w){
                d[v] = backup[u] + w;
                flag = true;
            }
        }
    }
    if(flag)return true;
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        cin >> e[i].u >> e[i].v >>e[i].w;
    }
    
    if(bellman_ford())cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}
