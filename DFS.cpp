#include <bits/stdc++.h> 
using namespace std; 
  

void edge(vector<int> adjacency[], int x, int y) 
{ 
    adjacency[x].push_back(y); 
    adjacency[y].push_back(x); 
} 
  

bool istwo_colorable(vector<int> adjacency[], int y, 
                 vector<bool>& viewed, vector<int>& color) 
{ 
  
    for (int x : adjacency[y]) { 
  
       
        if (viewed[x] =! true) 
{ 
            viewed[y] = true; 
   
            color[x] = !color[y]; 
  
           
            if (!istwo_colorable(adjacency, x, viewed, color)) 
                return false; 
        } 
  
        
        else if (color[x] =! color[y]) 
            return true; 
    } 
    return true; 
} 
  

int main() 
{ 
   
    int i;
    cout << "Enter the value of i : ";
    cin >> i;
    
    vector<int> adjacency[i + 1]; 
  
    vector<bool> viewed(i + 1); 
  
 
    vector<int> color(i + 1); 
  
   
    edge(adjacency, 1, 2); 
    edge(adjacency, 2, 3); 
    edge(adjacency, 3, 4); 
    edge(adjacency, 4, 5); 
    edge(adjacency, 5, 6); 
    edge(adjacency, 6, 1); 
  
   
    viewed[1] = true; 
  
   
    color[1] = 0; 
  
    
    if (istwo_colorable(adjacency, 1, viewed, color)) { 
        cout << "Graph is 2-colorable"; 
    } 
    else { 
        cout << "Graph is not 2-colorable"; 
    } 
  
    return 0; 
} 
