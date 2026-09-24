#include<bits/stdc++.h>
using namespace std;
const int N = 20000 + 10;

int n,m;
int d[N];
struct edge{
    int to;
    int w;
};
bool vis[N];
int cnt[N];
vector<edge> v[N];
bool spfa(){
    queue<int> q;
    for(int i = 1;i <= n;i ++){
        q.push(i);
        vis[i] = true;
    }
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        vis[t] = false;
        for(int i = 0;i< v[t].size();i ++){
            int y = v[t][i].to;
            int w = v[t][i].w;
            if(d[y] > d[t] + w){
                d[y] = d[t] + w;
                cnt[y] = cnt[t] + 1;
                if(cnt[y] >= n)return true;
                if(!vis[y]){
                    vis[y] = true;
                    q.push(y);
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int a,b,c;cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    
    if(spfa())cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}
