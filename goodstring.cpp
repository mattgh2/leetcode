#include <numeric>
#include <unordered_map>
#include <iostream>


int main(int argc, char **argv){

    std::unordered_map<int,int> mp;
    

    mp[0] = 1;
    mp[1] = 1;
    mp[2] = 1;

    std::cout << std::accumulate(mp.begin(),mp.end(), 0,[](const auto &acc, const auto &pair)  {
                return pair.first + acc; 
            });




    return 0;
}
