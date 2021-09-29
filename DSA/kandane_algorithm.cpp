/*
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

Logic - We maintaing two varaibles and we iterate left to right.
max_so_far is the maximum sum of the subarrays seen till now.
max_till_here is the one that adds the elements.

max_so_for is initalized to MIN_INT
max_till_here is zero

In order, every time we iterate on a element, we - 
1. Add the element to max_till_here
2. Check if max_till_here is greater than max_so_far, if so update max_so_far
3. Check if max_till_here is less than 0, update it back to 0 if it is

How does this work?

We iterate over the array, every element is added to max_till_here.
max_so_far will only be updated if the max_til_here is greater than it.
And the last step to check for less tan 0 max_till_here makes sure we don't add
multiple negative values to it.
*/


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long max_so_far = LLONG_MIN, max_till_here = 0;
        
        int i;
        
        for(i=0;i<n;i++){
            max_till_here = max_till_here+arr[i];
            max_so_far =  max(max_so_far,max_till_here);
            if(max_till_here<0){
                max_till_here = 0;
            }
        }
        
        return max_so_far;
        
    }
};