class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
            n = -(long)n;
        }
        return powHelper(x, n);
    }

private:
    double powHelper(double x, long n) {
        if (n == 0) return 1;
        double half = powHelper(x, n / 2);
        return (n % 2 == 0) ? half * half : half * half * x;
    }
};
