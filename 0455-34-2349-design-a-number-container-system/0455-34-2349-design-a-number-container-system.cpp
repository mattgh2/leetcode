class NumberContainers {
public:
    std::unordered_map<int, int> indices;
    std::unordered_map<int, int> min_index;
    std::unordered_map<int, int> counts;

    NumberContainers() = default;

    void change(int index, int number) {

        int old_number = indices[index];
        --counts[old_number];

        if (counts[old_number] == 0) {
            min_index[old_number] = 0;
        }

        else if (min_index[old_number] == index) { 
            int min = INT_MAX;
            for (const auto& [idx, num] : indices) {
                if (num == old_number && idx != index) {
                    min = std::min(idx, min);
                }
            }
            
            min_index[old_number] = min;
        }

        indices[index] = number;

        if (index < min_index[number] || counts[number] == 0) {
            min_index[number] = index;
        }

        ++counts[number];
    }

    int find(int number) {
        if (counts[number] < 1)
            return -1;
        return min_index[number];
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */