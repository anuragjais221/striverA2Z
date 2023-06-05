// Problem Link: https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=1
// Problem Link: 
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
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here

    // for +ve and -ve elements only

    // map<long long ,int> mp;
    // int n = a.size();
    // long long sum=0;
    // int maxLen=0;
    // for(int i=0;i<n;i++){
    //     sum += a[i];
    //     if(sum == k)    maxLen = max(maxLen,i+1);
    //     if(mp.find(sum-k) != mp.end())  maxLen = max(maxLen,i-mp[sum-k]);
    //     if(mp.find(sum) == mp.end()) mp[sum] = i; 
    // }
    // return maxLen;

    // for +ve and zeros only
    int n = a.size();
    int j=0;
    long long sum = a[0];
    int maxlen=0;
    int i=0;
    while(i<n){
        while(j<=i && sum > k){
            sum -= a[j];
            j++;
        }
        if(sum == k){
            maxlen = max(maxlen,i-j+1);
        }
        i++;
        if(i<n) sum += a[i];
    }
    return maxlen;
}
void answer()
{
    int n,k;
    cin >> n >> k;
    vector<int> nums;
    for(int i = 0; i < n;i++) cin >> nums[i];
    cout << longestSubarrayWithSumK(nums,k);
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