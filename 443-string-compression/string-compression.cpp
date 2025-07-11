class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        char prev = chars[0];
        int count = 1;

        for (int i = 1; i < chars.size(); i++) {
            if (prev == chars[i]) {
                count++;
            } else {
                // equal nahi hai
                chars[index++] = prev;
                if (count > 1) {
                    int st = index;
                    while (count) {
                        chars[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(chars.begin() + st, chars.begin() + index);
                }
                prev = chars[i];
                count = 1;
            }
        }
        chars[index++] = prev;
        if (count > 1) {
            int st = index;
            while (count) {
                chars[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin() + st, chars.begin() + index);
        }
        return index;
    }
};