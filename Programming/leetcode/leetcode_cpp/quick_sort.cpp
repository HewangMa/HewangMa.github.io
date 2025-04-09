#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    while (left < right) {
        while (left < right && nums[right] >= pivot)
            right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void quick_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int pos = partition(nums, left, right);
        quick_sort(nums, left, pos - 1);
        quick_sort(nums, pos + 1, right);
    }
}
int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    quick_sort(nums, 0, nums.size());
    for (int n : nums)
        cout << n << ' ';
    return 0;
}