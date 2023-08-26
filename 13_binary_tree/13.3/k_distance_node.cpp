#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
#define MOD 1000000007
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vi vector<int>
#define vl vector<long long>
#define pqll priority_queue<ll>
#define ALL(t) t.begin(), t.end()
#define ALLR(t) t.rbegin(), t.rend()
#define fi first
#define se second
#define endl "\n"
#define precise(ans) cout << fixed << setprecision(15) << ans
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (int i = (b)-1; i >= (a); --i)
///// Prime factor list////
vector<int> factors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}
// power x^y//
ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res % MOD * x % MOD;
        y = y >> 1;
        x = x % MOD * x % MOD;
    }
    return res;
}
/// Palindrome Check///
bool palindrome(const string &s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void print_1d_vector(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
struct Node
{
    int data;
    struct Node *left, *right;
};
Node* bfsMapToParent(Node *root,int target,map<Node *,Node *> &mp){
    Node *res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        
        auto it = q.front();
        q.pop();
        
        if(it->data == target) res = it;
        if(it->left){
            q.push(it->left);
            mp[it->left] = it;
        }
        if(it->right){
            q.push(it->right);
            mp[it->right] = it;
        }
    }
    return res;
}
    
vector<int> findNodes(Node *targetNode,int k,map<Node*,Node*> &mp){
    queue<pair<Node*,int>> q;
    map<Node*,int> vis;
    vector<int> ans;
    q.push({targetNode,k});
    vis[targetNode]=1;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        if(it.second == 0) ans.push_back(it.first->data);
        
        if(it.first->left && it.second > 0 && !vis[it.first->left]) {
            q.push({it.first->left,it.second-1});
            vis[it.first->left] = 1;
        }
        if(it.first->right && it.second > 0 && !vis[it.first->right]) {
            q.push({it.first->right,it.second-1});
            vis[it.first->right] = 1;
        }
        if(mp.find(it.first) != mp.end() && it.second > 0 && !vis[mp[it.first]]){
            q.push({mp[it.first],it.second-1});
            vis[mp[it.first]] = 1;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
vector <int> KDistanceNodes(Node* root, int target , int k)
{
    // return the sorted vector of all nodes at k dist
    map<Node*,Node*> mp;
    Node* targetNode = bfsMapToParent(root,target,mp);
    return findNodes(targetNode,k,mp);
    
}
void answer()
{
    string s;
    getline(cin,s);
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
        answer();
}