#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> movieBookings;
    unordered_map<int, int> availableTickets;

public:
    bool book(int X, int Y) {
        if (movieBookings[Y].count(X)) return false;

        if (availableTickets[Y] == 0) return false;

        movieBookings[Y].insert(X);
        availableTickets[Y]--;
        return true;
    }

    bool cancel(int X, int Y) {
        if (!movieBookings[Y].count(X)) return false;

        movieBookings[Y].erase(X);
        availableTickets[Y]++;
        return true;
    }

    bool isBooked(int X, int Y) {
        return movieBookings[Y].count(X);
    }

    int available(int Y) {
        if (availableTickets.find(Y) == availableTickets.end())
            return 100;
        return availableTickets[Y];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.available(Y) << endl;
        }
    }

    return 0;
}