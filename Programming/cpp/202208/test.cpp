#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, int> mp;
    mp[0] = 9;
    cout << mp[0] << endl;
    vector<int> vec;
    cout << vec.size() << endl;
    printf("hello world1\n");
    cout << "hello world2" << endl;
    printf("hello world3\n");
    return 0;
}