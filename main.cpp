#include <bits/stdc++.h>
using namespace std;


// Initializing number of customers as n, blocked roads length &  x,y to represent a customer in Coordinates
// Coordinates & locked_Roads 
int n, bl, x, y;
vector<vector<int>> coordinates, blocked_Roads;

// Initializing Distance Grid & efficient Route Distance
int effRouteDist = INT_MAX;
vector<vector<int>> Distance;



// CalculateDistance Method will Initializes the Distance Grid to store the distances between any two customers 
// & also keeps track for Blocked Roads
void CalculateDistance(){
    Distance.resize(n+1, vector<int>(n+1));
    for(int x = 0; x <= n; x++){
        for(int y = x; y <= n; y++){
            Distance[x][y] = Distance[y][x] = abs(coordinates[x][0] - coordinates[y][0]) + abs(coordinates[x][1] - coordinates[y][1]);
        }
    }

    // Marking the Blocked_Roads with Distance as Infinity/INT_MAX as per Assumption 
    for(auto cords : blocked_Roads){
        Distance[cords[0]][cords[1]] = Distance[cords[1]][cords[0]] = INT_MAX;
    }
}



// ShortestPath Method will Calculate the Shortest Distance Path with efficiency as highest 
void ShortestPath(int customer, int efficiency, unordered_set <int> visited){
    visited.insert(customer);
    
    // using priority queue as min Heap to get the shortest unvisited customer at a particular instant 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    
    for(int i=0; i<=n; i++){
        // Considering the customers who aren't visited yet 
        if(visited.find(i) == visited.end() && Distance[customer][i] != INT_MAX){
            pq.push({Distance[customer][i], i});
        }
    }
    
    // Iterating through priority queue
    while(!pq.empty()){
        auto [steps, node] = pq.top();
        pq.pop();
        ShortestPath(node, efficiency + steps, visited);
    } 

    // updates the effRouteDist only if our visited customers will be equal to the number to customers considering delivery agent too.  
    if(visited.size() == n+1){
        effRouteDist = min(effRouteDist, efficiency);
    }

    // Backtrack for any next adjacent node possible 
    visited.erase(customer);
}



//  Main method to start the execution of program
int main()
{
    // Inputs for n i.e number of Customers and bl i.e number of Blocked Roads
    cin >> n >> bl;

    // Consideration :- pizza shop/ delivery person initially to be at the center which we assume as (0,0) for calculations 
    coordinates.push_back({0,0});

    // Taking inputs as Coordinates of Customers for delivery
    for(int i=0; i<n; i++){
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    // Taking inputs for Blocked_Roads between customers
    for(int i = 0; i<bl; i++){
        cin >> x >> y;
        blocked_Roads.push_back({x, y});
    }

    CalculateDistance();
    unordered_set <int> visited ;
    ShortestPath(0, 0, visited);

    cout<< effRouteDist << endl;
    return 0;
}