/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the size of given input array.
*/

#include <bits/stdc++.h>
using namespace std;

int ZeroPairSum(int n, vector<int> arr){
    
    // Variable to store the count of pairs.
    int count=0;
    
    // Hash-map to store frequency of each element
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    
    // Iterating the hash-map
    for(auto it = mp.begin(); it != mp.end(); it++){
        
        int curKey = it->first;
        
        // Checking if curKey is not equal to 0
        // Also checking if -curKey exists in the hash-map
        if(curKey!=0 && mp.find(-curKey)!=mp.end()){
            
            // Multiplying frequencies and adding them to count
            count+=(mp[curKey]*mp[-curKey]);
        }
    }
    
    // Handling the border case when array element is equal to 0
    if(mp.find(0)!=mp.end()){
        int f = mp[0];
        // Multiplying f and f-1 and adding it to count
        count+=(f * (f-1));
    }
    
    return count/2;

}

int main(){ // WA huhuhuhuhu 
    int n; cin >> n;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        arr.push_back(temp);
    }

    cout<< ZeroPairSum(n, arr) << "\n";
}