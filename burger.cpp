#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
using std::vector, std::string;

std::unordered_map<std::string, bool> vis;

auto go(std::unordered_map<std::string,std::vector<std::string>> &mp, std::unordered_map<std::string, std::unordered_set<std::string>>  &req, const std::string &current, const std::string &prev, std::vector<std::string> &ans) -> void {

    for (const auto & i : mp[current]) {
        req[i].erase(current);
        go(mp,req,i,current,ans);
    }
    if (req[current].empty()) {
            ans.push_back(current);
    }

}

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    int n = recipes.size(), m = ingredients.size(), s = supplies.size();
    std::unordered_map<std::string,std::vector<std::string>> mp;
    std::unordered_map<std::string,std::unordered_set<std::string>> req;

    for (int i = 0; i < s; ++i) {
        mp.insert({supplies[i],{}});
    }
    for (int i = 0; i < n; ++i) {
        mp.insert({recipes[i], {}});
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < ingredients[i].size(); ++j) {
            req[recipes[i]].insert(ingredients[i][j]);
            if (mp.find(ingredients[i][j]) != mp.end()) {
                mp[ingredients[i][j]].push_back(recipes[i]);
            }
        }
    }
    std::vector<std::string> ans;
    for (const auto & [name, stuff] : mp) {
        go(mp,req,name, name, ans);

    }
    return ans;

}
int main(int argc, char **argv){

    
    std::vector<std::string> v1 = {"bread","sandwich"};
    std::vector<std::vector<std::string>> v2 = {{"yeast","flour"}, {"bread","meat"}};
    std::vector<std::string> v3 = {"yeast","flour","meat"};
    findAllRecipes(v1,v2,v3);



    return 0;
}
