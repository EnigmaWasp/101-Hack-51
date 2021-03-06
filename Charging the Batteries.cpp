#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<LL, LL> pii;


const int MaxN = 200 * 1000;
pii p[MaxN+10];
LL tm[MaxN+10];

int getDist(int x1, int y1, int x2, int y2, int n)
{
    if ( (x1 == 0 && x2 == 0) || (x1 == n && x2 == n) )
    {
        return abs(y1-y2);
    }
    if ( (y1 == 0 && y2 == 0) || (y1 == n && y2 == n) )
    {
        return abs(x1 - x2);
    }
    int dist = 0;
    if (x1 == 0)
    {
        dist = (n-y1);
        if (x2 == n) dist += n + (n-y2);
        else
        {
            if (y2 == n) dist += x2;
            else dist += 2*n + (n-x2);
        }
        return dist;
    }

    if (y1 == n)
    {
        dist = n - x1;
        if (x2 == n) dist += n - y2;
        else
        {
            if (y2 == 0) dist += n + (n-x2);
            else dist += 2*n + y2;
        }
        return dist;
    }

    if (x1 == n)
    {
        dist = y1;
        if (y2 == 0) dist += (n-x2);
        else
        {
            if (x2 == 0) dist += n + y2;
            else dist += 2*n + x2;
        }
        return dist;
    }

    if (y1 == 0)
    {
        dist = x1;
        if (x2 == 0) dist += y2;
        else
        {
            if (y2 == n) dist += n + x2;
            else dist += 2*n + (n-y2);
        }
        return dist;
    }

    return 4 * n;
}

int main() {

    ios_base::sync_with_stdio(0);
	cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }

    vector<pii> v1, v2, v3, v4;
    for (int i = 1; i <= m; i++)
    {
        if (p[i].first == 0) v1.push_back(p[i]);
        else
        {
            if (p[i].first == n) v3.push_back(p[i]);
            else
            {
                if (p[i].second == n) v2.push_back(p[i]);
                else v4.push_back(p[i]);
            }
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.rbegin(), v3.rend());
    sort(v4.rbegin(), v4.rend());
    {
        int i = 1;
        for (int j = 0; j < v1.size(); j++)
        {
            p[i++] = v1[j];
        }

        for (int j = 0; j < v2.size(); j++)
        {
            p[i++] = v2[j];
        }

        for (int j = 0; j < v3.size(); j++)
            p[i++] = v3[j];

        for (int j = 0; j < v4.size(); j++)
            p[i++] = v4[j];
    }

    int N =2*m + 3;
    for (int i = m+1; i <= N; i++)
        p[i] = p[i-m];
    tm[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        tm[i] = getDist(p[i-1].first, p[i-1].second, p[i].first, p[i].second, n);
       // cout << tm[i] << " : " << p[i-1].first << " " << p[i-1].second << " " << p[i].first << " " << p[i].second << endl;
    }
//cout << endl;

    for (int i = 2; i <= N; i++)
        tm[i] += tm[i-1];

    LL ans = tm[k];
    tm[0] = 0;
    for (int i = k + 1; i <= N; i++)
    {
        LL t = tm[i] - tm[i-k+1];
        if (t < ans)
            ans = t;
    }

    cout << ans << endl;
	return 0;
}
