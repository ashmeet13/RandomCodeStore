class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        int i=0;
        int array_sum = accumulate(array.begin(), array.end(), 0);
        int expected_sum = (n*(n+1))/2;
        return expected_sum - array_sum;
    }
};