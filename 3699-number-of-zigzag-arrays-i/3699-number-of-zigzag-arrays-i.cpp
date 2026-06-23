#include <vector>

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        long long MOD = 1e9 + 7;
        
        // U[v] represents the number of valid alternating sequences 
        // currently ending at value 'v' where the last step was an UP step.
        std::vector<long long> U(m + 1, 0);
        
        // Base case: For length 2, any sequence a_0 < a_1 is valid.
        // If it ends in v, a_0 can be any value from 1 to v-1.
        for (int v = 1; v <= m; ++v) {
            U[v] = v - 1;
        }
        
        // Build the sequence up to length n
        for (int i = 3; i <= n; ++i) {
            std::vector<long long> U_new(m + 1, 0);
            std::vector<long long> P(m + 1, 0);
            
            // P[u] acts as the prefix sum of DOWN ending sequences.
            // A DOWN sequence ending in 'u' is symmetric to an UP sequence ending in 'm - u + 1'
            for (int u = 1; u <= m; ++u) {
                P[u] = (P[u - 1] + U[m - u + 1]) % MOD;
            }
            
            // The new UP sequences ending in 'v' can be preceded by any DOWN sequence ending in 'u' < 'v'.
            for (int v = 1; v <= m; ++v) {
                U_new[v] = P[v - 1];
            }
            
            U = U_new;
        }
        
        long long ans = 0;
        for (int v = 1; v <= m; ++v) {
            ans = (ans + U[v]) % MOD;
        }
        
        // Because for every UP-ending pattern there is a mirror DOWN-ending pattern, multiply by 2.
        ans = (ans * 2) % MOD;
        
        return static_cast<int>(ans);
    }
};