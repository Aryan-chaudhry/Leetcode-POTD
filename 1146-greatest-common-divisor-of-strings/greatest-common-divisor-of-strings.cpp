class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";
        int length1 = str1.length();
        int length2 = str2.length();
        int gcdLength = gcd(length1,length2);
        return str1.substr(0, gcdLength);
    }
};