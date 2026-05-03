#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    cin >> L >> R;

    long long oddCount = (R + 1) / 2 - (L / 2);

    if (oddCount % 2 == 0)
        cout << "even";
    else
        cout << "odd";

    return 0;
}