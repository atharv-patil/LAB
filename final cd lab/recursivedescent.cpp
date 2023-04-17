// author: cholebhature lover
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define mpii map<ll, ll>
#define mpsi map<string, ll>
#define f first
#define s second
#define all(x) x.begin(), x.end()
int i = 0;
string a;
int n;
bool Y(), Z(), X(), W();
bool check(char x)
{
    if (i == n)
        return 0;
    else
    {
        if (a[i] == x)
        {
            i++;
            return 1;
        }
        return 0;
    }
}
bool X()
{
    if (check('x'))
    {
        return Y();
    }
    return 0;
}
bool Y()
{
    if (check('x'))
    {
        if (Y())
            return 1;
        return 0;
    }
    if (Z())
    {
        if (check('w'))
        {
            if (Y())
                return 1;
        }
        return 0;
    }
    return 1;
}
bool Z()
{
    if (check('y'))
    {
        if (W())
            return 1;
    }
    return 0;
}
bool W()
{
    if (check('z'))
    {
        if (W())
            return 1;
        return 0;
    }
    return 1;
}

int main()
{
    cin >> a;
    n = a.size();
    if (X())
        cout << 1;
    else
        cout << 0;
}
