class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> mp;

        mp[1000] = "M";
        mp[900] = "CM";
        mp[500] = "D";
        mp[400] = "CD";
        mp[100] = "C";
        mp[90] = "XC";
        mp[50] = "L";
        mp[40] = "XL";
        mp[10] = "X";
        mp[9] = "IX";
        mp[5] = "V";
        mp[4] = "IV";
        mp[1] = "I";

        string ans = "";

        for (auto &it : mp) {
            while (num >= it.first) {
                num -= it.first;
                ans += it.second;
            }
        }

        return ans;
    }
};