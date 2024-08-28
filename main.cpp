#include <bits/stdc++.h>
using namespace std;

// Initializing number of customers as n, blocked roads length &  x,y to represent a customer in Coordinates
// Coordinates & locked_Roads 
int n, bl, x, y;
vector<vector<int>> Coordinates, Blocked_Roads;




//  Main method to start the execution of program
int main()
{
    // Inputs for n i.e number of Customers and bl i.e number of Blocked Roads
    cin >> n >> bl;

    // Consideration :- pizza shop/ delivery person initially to be at the center which we assume as (0,0) for calculations 
    Coordinates.push_back({0,0});

    // Taking inputs as Coordinates of Customers for delivery
    for(int i=0; i<n; i++){
        cin >> x >> y;
        Coordinates.push_back({x, y});
    }

    // Taking inputs for Blocked_Roads between customers
    for(int i = 0; i<bl; i++){
        cin >> x >> y;
        Blocked_Roads.push_back({x, y});
    }

    return 0;
}