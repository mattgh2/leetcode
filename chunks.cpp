#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    static int maxChunksToSorted(vector<int>& arr) {
        auto r = [&](auto &&f, int start, int end) {
            int count{};
            if (start >= end) return 1;
            int mid = start + (end - start) / 2;
            if (arr[mid+1] < arr[mid]) return 1;

            count += f(f,start, mid);
            count += f(f,mid+1, end);
            return count;
        };

        int count = r(r,0, arr.size()-1);
        return count; 
    }
};
int main(int argc, char **argv){

    std::vector<int> arr = {1,0,2,3,4};

    std::cout << Solution::maxChunksToSorted(arr);


    return 0;
}
