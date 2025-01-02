#include <vector>

using std::vector;
class solution {
public:
    int sum(const vector<int>& vec, int i) {
        return (vec[i-1]||vec[i-2] == 10) ? 2 * vec[i] : vec[i];
    }
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1,s2; s1 = s2 = 0;

        for (int i = 0; i < static_cast<int>(player1.size()); i++)  {
            s1+=sum(player1, i); s2+=(sum(player2,i));
        }
        if (s1 != s2)
            return (s1 > s2) ? s1 : s2;
        else
            return 0;
    }
};

