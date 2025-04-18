class Solution {
public:
    void solve(int count, string& str, int n){  // Pass str by reference
        // base case
        if(count == n){
            return;
        }

        string store = "";

        int i = 0;
        while(i < str.length()) {
            char current = str[i];
            int cnt = 1;

            // Count consecutive characters
            while(i + 1 < str.length() && str[i] == str[i + 1]) {
                cnt++;
                i++;
            }

            store += to_string(cnt) + current;
            i++;
        }

        str = store;
        solve(count + 1, str, n);  // Recursive call with updated str
    }

    string countAndSay(int n) {
        int count = 1;
        string str = "1";

        solve(count, str, n);  // str is updated via reference now
        return str;
    }
};
