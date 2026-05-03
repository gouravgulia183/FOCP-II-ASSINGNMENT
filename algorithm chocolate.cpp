#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> &a) {
    // Step 1: take unique values
    set<int> st(a.begin(), a.end());

    // Step 2: move to vector
    vector<int> v(st.begin(), st.end());

    // Step 3: sort descending
    sort(v.rbegin(), v.rend());

    long long alex = 0, bob = 0;

    // Step 4: alternate picking
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0)
            alex += v[i];
        else
            bob += v[i];
    }

    // Step 5: decide winner
    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(n, a);
    return 0;
}