// author: cholebhature lover
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define mpii map<ll, ll>
#define mpsi map<string, ll>
#define f first
// #define ss second
#define all(x) x.begin(), x.end()
// vector<char> a = {'E', 'R', 'T', 'Y', 'F'};
vector<char> a = {'S', 'B', 'C', 'D', 'E', 'F'};
void f(map<char, vector<string>> &d, map<char, set<char>> &ans, char i, set<char> &s)
{
    for (auto j : d[i])
    {
        int ii = 0;
        while (ii < j.size())
        {
            char k = j[ii];
            if ('A' <= k and k <= 'Z')
            {

                if (s.find(k) != s.end())
                    continue;
                s.insert(k);
                f(d, ans, k, s);
                if (ans[k].find('#') == ans[k].end())
                {
                    for (auto z : ans[k])
                    {
                        ans[i].insert(z);
                    }
                    break;
                }
                else
                {
                    for (auto z : ans[k])
                    {
                        if (z == '#')
                            continue;
                        ans[i].insert(z);
                    }
                    ii++;
                }
            }
            else
            {
                ans[i].insert(k);
                break;
            }
        }
        if (ii == j.size())
        {
            ans[i].insert('#');
        }
    }
}

void ff(map<char, set<char>> &follow, map<char, set<char>> &ans, map<char, vector<string>> &d, char i, set<char> s)
{
    for (auto j : a)
    {
        for (int ii = 0; ii < d[j].size(); ii++)
        {
            for (int iii = 0; iii < d[j][ii].size(); iii++)
            {
                if (d[j][ii][iii] != i)
                    continue;
                if (iii + 1 < d[j][ii].size())
                {
                    if ('A' <= d[j][ii][iii + 1] and d[j][ii][iii + 1] <= 'Z')
                    {

                        int idx = iii + 1;
                        while (idx < d[j][ii].size())
                        {
                            char ok = d[j][ii][idx];
                            if (!('A' <= ok and ok <= 'Z'))
                            {
                                follow[i].insert(ok);
                                break;
                            }
                            if (ans[d[j][ii][idx]].find('#') != ans[d[j][ii][idx]].end())
                            {
                                for (auto z : ans[d[j][ii][idx]])
                                {
                                    if (z == '#')
                                        continue;
                                    follow[i].insert(z);
                                }
                                idx++;
                            }
                            else
                            {
                                for (auto z : ans[d[j][ii][idx]])
                                {
                                    follow[i].insert(z);
                                }
                                break;
                            }
                        }
                        if (idx == d[j][ii].size())
                        {
                            if (j == i)
                                continue;
                            ff(follow, ans, d, j, s);
                            for (auto z : follow[j])
                            {
                                follow[i].insert(z);
                            }
                        }
                    }
                    else
                    {
                        follow[i].insert(d[j][ii][iii + 1]);
                    }
                }
                else
                {
                    if (j == i)
                        continue;
                    ff(follow, ans, d, j, s);
                    for (auto z : follow[j])
                    {
                        follow[i].insert(z);
                    }
                }
            }
        }
    }
}
int main()
{
    map<char, vector<string>> d;
    map<char, set<char>> ans, follow;
    set<char> s;
    // d['E'].push_back("TR");
    // d['R'].push_back("+TR");
    // d['R'].push_back("#");
    // d['T'].push_back("FY");
    // d['Y'].push_back("*FY");
    // d['Y'].push_back("#");
    // d['F'].push_back("(E)");
    // d['F'].push_back("i");
    d['S'].push_back("aBDh");
    d['B'].push_back("cC");
    d['C'].push_back("bC");
    d['C'].push_back("#");
    d['D'].push_back("EF");
    d['E'].push_back("g");
    d['E'].push_back("#");
    d['F'].push_back("f");
    d['F'].push_back("#");
    cout << "First" << endl;
    for (auto i : a)
    {
        if (ans[i].size() == 0)
            f(d, ans, i, s);

        cout << i << " ";
        for (auto j : ans[i])
            cout << j << " ";
        cout << endl;
    }

    set<char> ss;
    cout << "follow" << endl;
    follow['S'].insert('$');
    for (auto i : a)
    {

        ff(follow, ans, d, i, ss);

        cout << i << " ";
        for (auto k : follow[i])
            cout << k << " ";
        cout << endl;
    }
}