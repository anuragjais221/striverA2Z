// Problem Link: https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x5808/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-pairs-whose-sum-is-x
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

pair<bool,int> binarySearch(int B[],int M,int target){
    int low=0;
    int high=M-1;

    while(low <= high ){
        int mid = low + (high-low)/2;
        if(B[mid] == target) return make_pair(true,mid);
        else if(B[mid] > target ) high = mid-1;
        else low = mid+1;
    }
    return make_pair(false,-1);
}

// bool cmp(pair<int,int>&a,pair<int,int>&b){
//     return a.first < b.first;
// }

vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
{
    // Your code goes here 
    sort(A,A+N);
    sort(B,B+M);
    vector<pair<int,int>> ans;
    for(int i = 0;i<N;i++){
        int target = X-A[i];
        pair<bool,int> y = binarySearch(B,M,target);
        if(y.first){
            ans.push_back({A[i],B[y.second]});
        }
    }
    sort(ans.begin(),ans.end());
    return ans;

}
void answer()
{
    int n,m,x;
    cin >> n >> m >> x;
    int A[n],B[m];
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<m;i++) cin >> B[i];
    vector<pair<int,int>> ans = allPairs(A,B,n,m,x);

    for(auto x: ans) cout << x.first << " " << x.second << endl;

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