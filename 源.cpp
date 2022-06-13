#include <iostream>
using namespace std;
const int N = 501000;
#define ll long long
ll n, m, i, j, k, a[N], b[N], cnt;
void merge(ll a[], ll l, ll r)
{
    if (r - l < 1)
        return;
    ll mid = (l + r)  /2;
    merge(a, l, mid);
    merge(a, mid + 1, r);
    ll i = l, j = mid + 1,g=l;//i为左数组第一个，j为右数组第一个
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            b[g++] = a[i++];
        }
        else
        {
            b[g++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        b[g++] = a[i++];
    }
    while (j <= r)
    {
        b[g++] = a[j++];
    }
    for (ll k = l; k <= r; k++)
        a[k] = b[k];
}




int main()
{
    
    while (cin >> n && n)
    {
        for (i = 1; i <= n; i++)
            cin >> a[i];
        cnt = 0;
        merge(a, 1, n);
        cout << cnt << endl;
    }
    return 0;
}