// Problem Link: https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=array-of-alternate-ve-and-ve-nos
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
void rearrange(int arr[], int n) {
	    // code here
    // for(int i=0;i<n;i++){
    //     if(i&1){
    //         if(arr[i] >= 0) {
    //             int j = i+1;
    //             while(j < n && arr[j] > 0) j++;
    //             if(j<n) swap(arr[i],arr[j]);
    //         }
    //     }
    //     else{
    //         if(arr[i] < 0){
    //             int j=i+1;
    //             while(j<n && arr[j]<0 ) j++;
    //             if(j<n) swap(arr[i],arr[j]);
    //         }
    //     }
    // }

    vector<int> pos;
    vector<int> neg;

    for(int i=0;i<n;i++){
        if(arr[i]>=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    int p = pos.size();
    int q = neg.size();

    int i=0;
    int j=0;

    int cnt=0;
    vector<int> ans;
    while(i<p && j<q){
        if(cnt & 1){
            ans.push_back(neg[j]);
            j++;
        }
        else{
            ans.push_back(pos[i]);
            i++;
        }
        cnt++;
    }
    while(i<p){
        ans.push_back(pos[i]);
        i++;
    }
    while(j<q){
        ans.push_back(neg[j]);
        j++;
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << endl; 
}
void answer()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    rearrange(arr,n);
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