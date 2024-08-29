# The Ultimate Pizza Delivery Route

## Overview 
Welcome to Pizza Town! Your challenge is to deliver pizzas to all customers in record time, navigating through blocked roads and ensuring each customer is satisfied. The goal is to find the shortest and most efficient route that visits each customer exactly once, traverses each street exactly once, and avoids any roadblocks.

## Problem Statement
Given a map of Pizza Town:
    n: The number of customers.
    Coordinates: A list of (x, y) coordinates representing the location of each customer.
    Blocked roads: A list of pairs representing the blocked roads between customers.

Objective: Calculate the minimum distance required to deliver a pizza to each customer, considering blocked roads and maximizing delivery speed.

## Solution 
Approach :- The problem is approached using graph traversal algorithms like Dijkstra’s Algorithm to find the shortest path while considering the blocked roads. The code dynamically builds the graph from the input coordinates and blocked roads, then computes the optimal delivery route.

Intitution :- 
Step 1: Define Distance matrix/Grid to store the distance between any two customers. 
Step 2: Now we'll be using Dijkshtra's Algorithm to select the Shortest Path between any two points or customers in our case. 
Step 3: Using Greedy Approach, we will find the shortest distance between any two customer's Coordinates.

## How to Run the Code 
run the main.cpp file in any c++ compiler. 
Inputs Format are
n -  number of customers including (0, 0)
bl - length of blocked road vector

Next Line contains list of Customer Coordinates in the form of vector
Ex - 
1 4 
2 3  
5 2  
3 1


Next Line contains list of BLocked Roads in the form of vector 
1 3



Dry Run :- 


                    

                                
                    .A(1, 4)
                                .B(2, 3)
                                                            .C(5, 2)
                                           .D(3, 1)
            . Shop(0,0) 


Distance Matrix as
/// Consider A B C D as 1, 2, 3, 4 customers respectively & 0 as the shop location 
    -1 represents a block road between the customers

     0  1  2  3  4
  0 [0, 5, 5, 7, 4]
  1 [5, 0, 2,-1, 2]
  2 [5, 2, 0, 4, 3]
  3 [7,-1, 4, 0, 3]
  4 [4, 5, 3, 3, 0]


  Here Distance[x][y] -> represent distance from x customer to y customer

For this testCase / Inputs

Execution steps 
main() -> invokes
Inputs are readed from Users
CalculateDistance() ->  will define our distance matrix 
ShortestPath() -> will be called on shop to start calculating efficient route 

 