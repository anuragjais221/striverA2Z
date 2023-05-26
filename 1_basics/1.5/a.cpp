#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// #ifndef ONLINE_JUDGE
//     #include "debug.h"
// #endif

void bfs1(int start,vector<vector<ll>>&graph,vector<ll>&dist)
{
    ll level = 0;
    vector<bool> visited(graph.size(), false);
    vector<int> q;
    for (int i = 0; i < graph.size(); i++) 
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    q.push_back(start);
    visited[start] = true;
    int vis;
    while (!q.empty()) {
        vis = q[0];
        cout << "vis  = " << vis << endl;
        q.erase(q.begin());
        for (int i = 0; i < graph[vis].size(); i++) {
            if (graph[vis][i] == 1 && (!visited[i])) {
                dist[i] = dist[vis] + 1;
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

void bfs2(int start,vector<vector<ll>>&graph,vector<ll>&dist)
{
    ll level = 0;
    vector<bool> visited(graph.size(), false);
    vector<int> q;
    for (int i = 0; i < graph.size(); i++) 
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    q.push_back(start);
    visited[start] = true;
    int vis;
    while (!q.empty()) {
        vis = q[0];
        q.erase(q.begin());
        for (int i = 0; i < graph[vis].size(); i++) {
            if (graph[vis][i] == 1 && (!visited[i])) {
                dist[i] = dist[vis] + 1;
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

void solve() 
{    
    ll n;
    cin>>n;
	vector<vector<ll>>graph1(n,vector<ll>(n));
    vector<vector<ll>>graph2(n,vector<ll>(n));
    vector<ll>dist1(n);
    vector<ll>dist2(n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin>>graph1[i][j];
            graph2[j][i] = graph1[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph2[i][j] << " ";
        }
        cout << endl;
    }

    ll node;
    cin>>node;
    node--;
    bfs1(node,graph1,dist1);

    for(int i=0;i<dist1.size();i++){
        cout << dist1[i] << " ";
    }
    cout << endl;
    bfs2(node,graph2,dist2);
    for(int i=0;i<dist2.size();i++){
        cout << dist2[i] << " ";
    }
    cout << endl;
    ll count1 = 0;
    ll count2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (dist1[i] <= 2) count1++;
    }
     for (ll i = 0; i < n; i++)
    {
        if (dist2[i] <= 2) count2++;
    }
    cout<<count2<<" "<<count1<<"\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
        solve();
}