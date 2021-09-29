/*
https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1

Logic - We sort the array first, O(nlog(n))

For a given arrary [1,2,3,5]

There are two ways of checking a triplet - 
1+2 = 3 and check if 3 exists in the array
or,
3-2 = 1 and check if 1 exists in the array

We use the latter - We start iterating backwards and keep calculating
the difference. We maintain an index at the start [0]. If the value at
the start is less than what the differnce has come to be we increment this
index. Finally this index would either be greater than or equal to the difference

If the difference is equal we add to the count.

How does this logic work?

Essentially everytime you calculate a difference from right to left -
keeping a varaible constant while the other variable decreases  
the value of the difference would increase. This enables us to maintain
an index against that fixed varaible and check if the differnce is present.

Time Complexity - O(n^3)
Space Complexity - O(1)

*/


class Solution{
public:	
	int countTriplet(int arr[], int n)
	{
	    int count=0;
	    int i,j,k;
	    sort(arr, arr + n);
	    
	    for(i=n-1;i>=0;i--){
	        k = 0;
	        for(j=n-1;j>=0;j--){
	            while(arr[k]<arr[i]-arr[j]){
	                k+=1;
	            }
	            if((arr[k]==arr[i]-arr[j]) && (i!=j && j!=k && i!=k)){
	                count+=1;
	            }
	        }
	    }
	    return count/2;
	}
};


/*
The correct solution

We sort the array once again. 
We iterate backwards on the array - checking if the number (say: i) is the sum
of one or multiple combinations in the array.

We maintain two pointers for every i. One from the start of the array
one just before i. We add the numbers at this point. Now there are three possibilities - 

1. The sum ends up being more than i - we need to reduce the sum hence we decrement
the second from behind

2. The sum ends up being less than i - we need to increase the sum hence we
increment the first pointer from ahead

3. The sum is equal to i - we incremet the count and also increment the ahead pointer
to force the algo to continue search for other combinations if any.

Time Complexity - O(n^2)
Space Complexity - O(1)
*/


class Solution{
public:	
	int countTriplet(int arr[], int n)
	{
	    int count=0;
	    int i,j,k;
	    sort(arr, arr + n);
	    
	    for (i=n-1;i>=0;i--){
	        j=0;
	        k=i-1;
	        while(j<k){
	            if(arr[j]+arr[k] == arr[i]){
	                count+=1;
	                j+=1;
	            }
	            else if(arr[j]+arr[k] > arr[i])
	                k=k-1;
	            else if(arr[j]+arr[k] < arr[i])
	                j=j+1;
	        }
	    }
	    return count;
	}
};