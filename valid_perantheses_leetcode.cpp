class Solution {
public:
    stack<char> st;
    void validate(string s){
        for(int i = 0;i<s.length();i++){
            if(st.size() == 0 || s[i] == '('){
                st.push(s[i]);
            }
            else if ((s[i] == ')') and (st.top() == '('))
                st.pop();
        }
    }
    void genp(vector<string> &x,int len,int i,string &s){
        if(len == i){
            validate(s);
            if(st.size() == 0)
                 x.push_back(s);
            else{
                while (!st.empty()) {
                st.pop();
            }
            }
            return;
        }
        s[i] = '(';
        i += 1;
        genp(x,len,i,s);
        i -= 1;
        s[i] = ')';
        i += 1;
        genp(x,len,i,s);
    }
    vector<string> generateParenthesis(int n) {
         vector<string> s;
         string x;
         x.assign(n*2,'-');
         genp(s,n*2,0,x);
         return s;
    }
};
