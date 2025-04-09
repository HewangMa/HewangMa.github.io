#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int testSize = 100;
int s[8] = {1, 1, 2, 3, 4, 6, 8};
class Poly
{
private:
    long co[101];
    // co[i] means the coefficient of x^i

public:
    Poly(int mul = 1)
    {
        for (int i = 0; i < 101; i++)
            if (i % mul == 0)
                co[i] = 1;
            else
                co[i] = 0;
    }
    Poly(int *p)
    {
        for (int i = 0; i < 101; i++)
            co[i] = p[i];
    }
    void multiply(Poly p)
    {
        long ret[101];
        for (int i = 0; i < 101; i++)
            ret[i] = 0;
        for (int i = 0; i < 101; i++)
            for (int j = 0; j < 101 && i + j < 101; j++)
                ret[i + j] += this->co[i] * p.co[j];

        for (int i = 0; i < 101; i++)
            this->co[i] = ret[i];
    }
    void print()
    {
        for (int i = 0; i < 101; i++)
            cout << co[i] << ' ';
        cout << endl;
    }
    long get(int index)
    {
        return co[index];
    }
};

void solve1()
{
    long S[102][102];
    // S[i][j] means the ways to write j numbers sum to i
    // Stirling numbers of the second kind
    for (int i = 0; i < 101; i++)
    {
        S[i][0] = 0;
        S[i][i] = 1;
    }
    for (int i = 2; i < 101; i++)
        for (int j = 1; j < i; j++)
            S[i][j] = S[i - 1][j] * j + S[i - 1][j - 1];

    long ans = 0;
    for (int j = 2; j <= testSize; j++)
        ans += S[testSize][j];
    cout << ans << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << S[i][j] << ' ';
        cout << endl;
    }
}
void solve2()
{
    long S[102][102];
    long Fac[102];
    Fac[0] = 1;
    for (int i = 1; i <= testSize; i++)
        Fac[i] = i * Fac[i - 1];
    // S[i][j] means the ways to write j numbers sum to i
    // Stirling numbers of the second kind
    for (int i = 0; i < 101; i++)
    {
        S[i][0] = 0;
        S[i][i] = 1;
    }
    for (int i = 2; i <= testSize; i++)
        for (int j = 1; j < i; j++)
            S[i][j] = (S[i - 1][j] * j + S[i - 1][j - 1]);
    for (int i = 0; i <= testSize; i++)
        for (int j = 1; j <= testSize; j++)
            S[i][j] *= Fac[j];

    for (int i = 0; i < 10 && i <= testSize; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << S[i][j] << ' ';
        cout << endl;
    }

    long ans[102];
    for (int i = 2; i <= testSize; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
            sum += S[i][j];
        sum /= Fac[i];
        ans[i] = sum;
    }
    for (int i = 2; i <= testSize; i++)
        cout << i << ": " << ans[i] << endl;
}
void solve3()
{
    Poly p = Poly();
    for (int i = 2; i <= testSize; i++)
    {
        Poly pi = Poly(i);
        p.multiply(pi);
    }
    cout << p.get(testSize) - 1 << endl;
}
int main()
{
    solve3();
}