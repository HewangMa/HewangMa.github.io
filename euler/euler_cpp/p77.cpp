#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
const int testSize = 150;
class Poly
{
private:
    long co[201];
    // co[i] means the coefficient of x^i

public:
    Poly(int mul = 1)
    {
        for (int i = 0; i < 201; i++)
            if (i % mul == 0)
                co[i] = 1;
            else
                co[i] = 0;
    }
    Poly(int *p)
    {
        for (int i = 0; i < 201; i++)
            co[i] = p[i];
    }
    void multiply(Poly p)
    {
        long ret[201];
        for (int i = 0; i < 201; i++)
            ret[i] = 0;
        for (int i = 0; i < 201; i++)
            for (int j = 0; j < 201 && i + j < 201; j++)
                ret[i + j] += this->co[i] * p.co[j];

        for (int i = 0; i < 201; i++)
            this->co[i] = ret[i];
    }
    void print()
    {
        for (int i = 0; i < 201; i++)
            cout << co[i] << ' ';
        cout << endl;
    }
    long get(int index)
    {
        return co[index];
    }
};
vector<int> primes;
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
void solve1()
{
    // primes.push_back(2);
    // primes.push_back(3);
    // for (int i = 4; i <= 100; i++)
    // {
    //     bool prime_tag = true;
    //     for (int j = 2; j <= sqrt(i); j++)
    //         if (i % j == 0)
    //         {
    //             prime_tag = false;
    //             break;
    //         }
    //     if (prime_tag == true)
    //         primes.push_back(i);
    // }
    // int largest_prime = 2;
    // int index = 0;
    Poly p = Poly(2);
    for (int num = 3; num <= testSize; num++)
    {
        if (is_prime(num))
        {
            Poly ppi = Poly(num);
            cout << "multiplied " << num << endl;
            p.multiply(ppi);
            // p.print();
        }
        int ans = (is_prime(num)) ? (p.get(num) - 1) : (p.get(num));
        cout << num << ": " << ans << endl;
    }
}
int main()
{
    solve1();
}