class Solution {
public:
    long long ncr(int a, int r) {
        long long ans = 1;
        for (int i = 1; i <= r; ++i) {
            ans = ans * (a - r + i) / (i);
        }
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        return ncr(m + n - 2, n - 1);
    }
};
