#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
vector<int> pivotArray(vector<int>& nums, int pivot) {
        auto it = std::stable_partition(nums.begin(), nums.end(), [&pivot](int a) { return a < pivot; });


        std::stable_partition(it, nums.end(), [&pivot](int a) { return a == pivot; });

        return nums;
    }

int main(int argc, char **argv){

    int pivot = 2;
    std::vector<int> v = {-3,4,3,2};

    int n = v.size();
    std::vector<int> ans(n);
    std::vector<int> cache;

    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] < pivot){
            ans[j++] = v[i];
        }
        else {
            cache.push_back(v[i]);
        }
    }
    std::ranges::stable_partition(cache, [&pivot](int a) { return a == pivot; });
    for (int i = 0; i < (int)cache.size(); ++i) {
        ans[j++] = cache[i]; 
    }

    std::vector<int> v2 = {9,12,5,10,14,3,10};
    auto v3 = pivotArray(v2, 10);
    std::vector<int> v4 = {-3,2,4,3};
    auto v5 = pivotArray(v4, 2);

    std::vector<int> v6 = {4,0,4,5,-11};
    auto v7 = pivotArray(v6, 5);

    for (int i = 0; i < (int)v3.size(); ++i) {
        std::cout << v3[i] << ' ';
    }

    std::cout << '\n';

    for (int i = 0; i < (int)v5.size(); ++i) {
        std::cout << v5[i] << ' ';
    }

    std::cout << '\n';

    for (int i = 0; i < (int)v7.size(); ++i) {
        std::cout << v7[i] << ' ';
    }



    return 0;
}
