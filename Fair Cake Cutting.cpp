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


int main() {

    LL a,b,n;
    cin >> a >> b >> n;

    LL m = (n*b) / a;
    cout << m << endl;
	return 0;
}
