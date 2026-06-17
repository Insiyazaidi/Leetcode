class Solution {
public:
    char processStr(string s, unsigned long long k) {
     

        int m = s.size();
        // len[i] = length after processing first i ops (i.e. s[0..i-1])
        vector<unsigned long long> len(m+1, 0);
        const unsigned long long LIMIT = 1000000000000000ULL; // 1e15
        
        // 2) forward pass: compute lengths
        for (int i = 0; i < m; i++) {
            char c = s[i];
            if (islower(c)) {
                len[i+1] = min(LIMIT, len[i] + 1);
            }
            else if (c == '*') {
                // pop_back if non-empty
                len[i+1] = (len[i] > 0 ? len[i] - 1 : 0);
            }
            else if (c == '#') {
                // duplicate
                len[i+1] = min(LIMIT, len[i] * 2);
            }
            else { // c == '%'
                // reverse doesn’t change length
                len[i+1] = len[i];
            }
        }
        
      // k is 0-based, so valid indices are [0 .. len[m]-1]
    if (k >= len[m]) 
        return '.';
    unsigned long long idx = k;  // <-- use k directly

    // now your existing backward loop will end up returning 'a'
    for (int i = m; i > 0; i--) {
        char c = s[i-1];
        unsigned long long prevLen = len[i-1];
        
        if (islower(c)) {
            if (idx == prevLen) 
                return c;
        }
        else if (c == '*') {
            // nothing: '*' only shrank the string
        }
        else if (c == '#') {
            if (idx >= prevLen) 
                idx -= prevLen;
        }
        else { // '%'
            idx = prevLen - 1 - idx;
        }
    }
    return '.';

    }
};