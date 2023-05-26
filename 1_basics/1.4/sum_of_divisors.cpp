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

// ll modularBinaryExponentiation(int base,int exponent){

//     if(exponent == 0)   return 1;

//     ll result = modularBinaryExponentiation(base,exponent/2);
//     if(exponent%2==1) 
//         return result*
// }

ll divisors(int n){
    vector<int>v;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            if(n/i == i) {
                v.push_back(i);
            }
            else{
                v.push_back(n/i);
                v.push_back(i);
            }
        }
    }
    ll sum = 0;
    for(int i=0;i<v.size();i++) sum+=v[i];
    return sum;
}

ll sumofDivisors(int N ){
    ll ans=0;
    // O(nsqrt(n))
    // for(int i=1;i<N+1;i++){
    //     ans += divisors(i);  TC O(nsqrt(n))
    // }    

    // O(n) 
    for(int i=1;i<=N;i++){
        ans += (N/i)*i; // TC O(n)  
    }
    return ans;

    // O(2*sqrt(n)) if n goest to 10^12
    for(ll i= 1,j;i<=N;i=j){
        ll q = N/i;
        j = N/q+1;
        ll rangeSumUptoJminus1 = (((j-1)%MOD * (j%MOD))*MOD * power(2,MOD-2))%MOD;
        ll rangeSumUptoIminus1 = (((i-1)%MOD * (i%MOD))*MOD * power(2,MOD-2))%MOD;
        ll rangeWithQuotientQ = (rangeSumUptoJminus1-rangeSumUptoIminus1+MOD)%MOD;
        ans += ((q%MOD)*rangeWithQuotientQ)%MOD;
    }
    return ans;
}
void answer()
{
    int n;
    cin >> n;
    cout << sumofDivisors(n) << endl;
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