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

int minJumps(vector<int>arr,int n){

    // O(n*n) approach

    // if(arr[0] == 0) return -1;
    // if( n==1 ) return 0;
    // int l = 0;
    // int r = 0;
    // int jumps=0;
    // int len = arr.size();
    
    // while(r < len-1){
    //     int maxi=0;
    //     for(int i = l;i<r+1;i++){
    //         maxi = max(maxi,i+arr[i]);
    //     }
    //     l=r+1;
    //     r=maxi;
    //     jumps++;
    // }
    // return jumps;

    // O(n) approach

    if(arr[0] == 0) return -1;
    if(n==1) return 0;
    int max_reachable=0;
    int jumps=1;
    int step=arr[0];
    for(int i=1;i<n;i++){
        if(i == n-1) return jumps;
        // if(reachable < i) return -1;
        max_reachable = max(max_reachable,i+arr[i]);
        step--;
        if(step==0){
            jumps++;
            if(i>=max_reachable) return -1;
            step = max_reachable-i;
        }
    }
    return jumps;


}
void answer()
{
    int n;
    cin >> n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++) cin >> v[i];
    cout << minJumps(v,n) << endl;
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