class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        int n = s.size();
        int cycleLen = 2 * numRows - 2;
        string result(n, '\0'); // allocate final size
        int pos = 0;

        for (int row = 0; row < numRows; ++row) {
            for (int j = row; j < n; j += cycleLen) {
                result[pos++] = s[j];

                int secondJ = j + cycleLen - 2 * row;
                if (row != 0 && row != numRows - 1 && secondJ < n) {
                    result[pos++] = s[secondJ];
                }
            }
        }

        return result;
    }
};
