#include <bits/stdc++.h>
using namespace std;

bool canTurnOff(string &bulbs, int n, int m, int k) {
    int operations = 0;

    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            operations++;
            if (operations > m) return false;
            i += k;  // turn OFF next k bulbs
        } else {
            i++;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    string bulbs;
    cin >> bulbs;

    int low = 1, high = n;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canTurnOff(bulbs, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller k
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}