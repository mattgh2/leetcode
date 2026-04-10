#include <iostream>
#include <vector>

auto fn(std::vector<int> &nums) -> int {
    int n = nums.size();

    int max = 0, run = nums[0];
    int l = 0;
    for (int i = 1; i < n; ++i) {
        if ((run & nums[i]) == 0) {
            ++run;
            run |= nums[i];
        }
        else {
            while (run & nums[i]) {
                run-=nums[l];
                ++l;
            }
            run |= nums[i];
        }
        max = std::max(max, i-l+1);
    }
    return max;
}

int main(int argc, char **argv){

    std::vector<int> v = {1,3,8,48,10};
    std::vector<int> v2 = {3,1,5,11,13};
    std::vector<int> v3 = {84139415,693324769,614626365,497710833,615598711,264,65552,50331652,1,1048576,16384,544,270532608,151813349,221976871,678178917,845710321,751376227,331656525,739558112,267703680};
    
    std::cout << fn(v3);


    return 0;
}
