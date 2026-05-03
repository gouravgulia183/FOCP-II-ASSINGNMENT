#include <bits/stdc++.h>
using namespace std;

class Bank {
    unordered_map<int, long long> balance;

public:
    bool create(int X, long long Y) {
        if (balance.find(X) == balance.end()) {
            balance[X] = Y;
            return true;
        } else {
            balance[X] += Y;
            return false;
        }
    }

    bool debit(int X, long long Y) {
        if (balance.find(X) == balance.end() || balance[X] < Y)
            return false;

        balance[X] -= Y;
        return true;
    }

    bool credit(int X, long long Y) {
        if (balance.find(X) == balance.end())
            return false;

        balance[X] += Y;
        return true;
    }

    long long getBalance(int X) {
        if (balance.find(X) == balance.end())
            return -1;

        return balance[X];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.getBalance(X) << endl;
        }
    }

    return 0;
}