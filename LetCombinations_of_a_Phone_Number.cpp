class Solution {
public:
    vector<string> s = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void func( vector<string> &sol , string &x , int len , string ar , int l){
        if (len == l){
            sol.push_back(x);
            return;
        }
        for(int i = 0;i<s[((ar[len])%48)-2].size();i++){
            x[len] = s[((ar[len])%48)-2][i];
            func(sol , x,len+1,ar,l);
        }
    }
    vector<string> letterCombinations(string digits) {
         string str(digits.size(), '-');
         vector<string> sol;
        if(digits.size() == 0)
            return sol;
         func(sol,str,0,digits,digits.size());
         return sol;
    }
};
