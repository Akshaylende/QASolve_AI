#include <bits/stdc++.h>
using namespace std;

// Initializing number of customers as n, blocked roads length &  x,y to represent a customer in Coordinates
// Coordinates & locked_Roads 
int n, bl, x, y;
vector<vector<int>> Coordinates, Blocked_Roads;
vector<vector<int>> Distance;

//  CalculateDistance Method will Initializes the Distance Grid to store the distances between any two customers 
// & also keeps track for Blocked Roads
void CalculateDistance(){
    Distance.resize(n+1, vector<int>(n+1));
    for(int x = 0; x <= n; x++){
        for(int y = x; y <= n; y++){
            Distance[x][y] = Distance[y][x] = abs(Coordinates[x][0] - Coordinates[y][0]) + abs(Coordinates[x][1] - Coordinates[y][1]);
        }
    }

    // Marking the Blocked_Roads with Distance as Infinity/INT_MAX as per Assumption 
    for(auto cords : Blocked_Roads){
        Distance[cords[0]][cords[1]] = Distance[cords[1]][cords[0]] = INT_MAX;
    }
}


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