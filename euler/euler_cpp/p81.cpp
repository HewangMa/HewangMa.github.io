#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;
// vector<int> parseVec(string line)
// {
//     return vector<int>(){};
// }
void solve()
{
    ifstream file("./0081_matrix.txt");
    cout << file.is_open() << endl;
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
        cout << "!!";
    }
}
int main()
{
    solve();
    return 0;
}