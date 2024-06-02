class Solution {
public:
     void all_ans(string digit, string op, vector<string> &ans) {
        if (digit.length() == 0) {
            ans.push_back(op);
            return;
        }
        char first = digit[0];
        digit.erase(digit.begin());
        
        vector<string> letters;
        if (first == '2') letters = {"a", "b", "c"};
        else if (first == '3') letters = {"d", "e", "f"};
        else if (first == '4') letters = {"g", "h", "i"};
        else if (first == '5') letters = {"j", "k", "l"};
        else if (first == '6') letters = {"m", "n", "o"};
        else if (first == '7') letters = {"p", "q", "r", "s"};
        else if (first == '8') letters = {"t", "u", "v"};
        else if (first == '9') letters = {"w", "x", "y", "z"};
        
        for (string letter : letters) {
            all_ans(digit, op + letter, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        all_ans(digits,"",ans);
        return ans;


    }
};