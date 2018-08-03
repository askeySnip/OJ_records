class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> dirs(256, 0);
        int res = 0;
        input.push_back('\n');

        for (int i = 0, level = 0, len = 0, isFile = 0; i < input.size(); i++) {
            switch (input[i]) {
                case '\n': level = 0; len = 0; isFile = 0; break;
                case '\t': level++; break;
                case '.' : isFile = 1;
                default:
                    len++;
                    dirs[level] = len;
                    if (isFile) res = max(res, accumulate(dirs.begin(), dirs.begin() + level + 1, 0) + level);
            }
        }

        return res;
    }

};