class Solution {
public:
    string removeOuterParentheses(string s) {
        string fin = "";
        int opened = 0;
        for(auto i : s){
            if (i == '('){
                opened++;
                if (opened > 1){
                    fin.push_back(i);
                }
            }
            else{
                opened--;
                if (opened > 0){
                    fin.push_back(i);
                }
            }
        }
        return fin;
    }
    
};