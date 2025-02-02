class Solution {
public:
    string addBinary(string a, string b) {
        std::string out;

        int size = (a.length() > b.length()) ? a.length() : b.length();
        int carry = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0; --i, --j) {

            int x = (i >= 0) ? a[i] - '0' : 0;
            int y = (j >= 0) ? b[j] - '0' : 0;

            int z = x + y + carry; 

            if (z == 3)  {
                z = 1;
                carry = 1;
            }
            else if (z == 2) { 
                z = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }

            out.push_back(z + '0');
        }
        if (carry) out.push_back(carry + '0');


        std::reverse(out.begin(),out.end());
        return out;
    }
};