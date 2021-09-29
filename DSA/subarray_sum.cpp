/*
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

Logic - We maintain a sum variable and two index pointers start and end.
We iterate over the array, keep adding a number to the sum variable move the end pointer ahead.
Everytime the sum exceeds the target value we start a while loop to 
get rid of the inital values added and move the start pointer ahead. 

We match the sum varaible with the desired value and if there is a match
we return the indexes

Time Complexity - O(n) [We loop through the array once]
Space Complexity - O(1) [We are not using any datastructure]

*/


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        // Your code here
        int start = 0, end = 0;
        int sum = 0;
        vector<int> vect;
        for(int i=0; i<n; i++){
            sum += arr[end];
            end+=1;
            while (sum>s){
                sum = sum-arr[start];
                start += 1;
            }
            if (sum==s){
                vect.push_back(start+1);
                vect.push_back(end);
                return vect;
            }
        }
        vect.push_back(-1);
        return vect;
    }
};