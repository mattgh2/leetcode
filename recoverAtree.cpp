#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

auto build_tree(std::vector<int> &vals) -> TreeNode * {
    std::queue<TreeNode *> q;

    int i = 0;
    TreeNode * root = new TreeNode(vals[i++]);
    q.push(root);

    while (i < static_cast<int>(vals.size())) {
        TreeNode * c = q.front(); q.pop();

        if (i < static_cast<int>(vals.size())) {
            c->left = new TreeNode(vals[i++]);
            q.push(c->left);
        }
        if (i < static_cast<int>(vals.size())) {
            c->right = new TreeNode(vals[i++]);
            q.push(c->right);
        }
    }
    return root;
}

int MAX_D;

auto parse(std::string traversal) -> TreeNode * {
    int n = traversal.length();
    auto to_num = [&traversal, &n](int &i) -> int {
        int num = 0;
            for (; i < n && traversal[i] != '-'; ++i) {
                num = num * 10 + traversal[i]-48;
            }
            return num;
    };
    std::unordered_map<int, std::vector<TreeNode *>> mp;

    int i = 0;
    TreeNode * root = new TreeNode(to_num(i));
    mp[0].emplace_back(root);

    int dash_count = 0;
    for (; i < n; ++i) {
        if (traversal[i]=='-') {
            ++dash_count;
        }
        else {
            // Get the whole number not just the first digit.

            TreeNode * current = new TreeNode(to_num(i)); --i;
            TreeNode * current_parent = mp[dash_count-1].back();

            if (current_parent->left) {
                current_parent->right = current;
            } else {
                current_parent->left = current;
            }
            mp[dash_count].emplace_back(current);

            dash_count = 0;
        }
    }
    return mp[0].back();
}

auto print_tree(TreeNode * root) -> void {
    if (!root)
        return;

    std::cout << root->val << '\n';

    print_tree(root->left);
    print_tree(root->right);
}

int main(int argc, char **argv) { 

    // std::vector<int> v = {1,2,5,3,4,6,7};
    // TreeNode *  root = build_tree(v);
    // print_tree(root);


    std::string s = "1-2--3---4-5--6---7";
    std::string s2 = "1-2--3---4-5--6---7";
    std::string s3 = "1-401--349---90--88";


    TreeNode * root = parse(s3);
    print_tree(root);
    
    return 0; 
} 
