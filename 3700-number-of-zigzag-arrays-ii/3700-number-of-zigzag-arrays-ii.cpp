class Solution {
public:
    static const long long MOD = 1000000007LL;
    using Mat = vector<vector<long long>>;

    Mat multiply(const Mat& A, const Mat& B) {
        int n = A.size();
        Mat C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                if (A[i][k] == 0) continue;
                long long aik = A[i][k];
                for (int j = 0; j < n; ++j) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<long long> multiply(const Mat& A, const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 0) continue;
                sum = (sum + A[i][j] * v[j]) % MOD;
            }
            res[i] = sum;
        }
        return res;
    }

    Mat power(Mat base, long long exp) {
        int n = base.size();
        Mat result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) result[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // Length 1 is not needed for the constraints, but this keeps the code complete.
        if (n == 1) return m;

        // Initial vector for length 2:
        // up[i] = number of values smaller than i
        vector<long long> init(m, 0);
        for (int i = 0; i < m; ++i) init[i] = i;

        if (n == 2) {
            long long ans = 0;
            for (long long x : init) ans = (ans + x) % MOD;
            return (int)((2 * ans) % MOD);
        }

        // Transition matrix:
        // newUp[i] = sum of oldUp[j] for j >= m - i
        Mat T(m, vector<long long>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = m - i; j < m; ++j) {
                T[i][j] = 1;
            }
        }

        Mat P = power(T, n - 2);
        vector<long long> finalUp = multiply(P, init);

        long long sum = 0;
        for (long long x : finalUp) sum = (sum + x) % MOD;

        return (int)((2 * sum) % MOD);
    }
};