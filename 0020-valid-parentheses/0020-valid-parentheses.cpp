// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
//                 st.push(s[i]);

//             }
//             else{
//                 if(st.empty())
//                     return false;
//             }
//                 char ch=st.top();
//                 st.pop();
        
            
            
//                 if((s[i]==')' && ch=='(') || 
//                 (s[i]==']' && s[i]=='[') || 
//                 (s[i]=='}' && s[i]=='{')){
//                     continue;
//                 }
//                 else{
//                     return false;
//                 }
//             }        
//         }
//         return st.empty();

//     }
    
    
// };


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int n = s.size();

        for (int i = 0; i < n; i++) {

            // If opening bracket, push into stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            // Otherwise it is a closing bracket
            else {

                // If stack is empty, no opening bracket exists
                if (st.empty()) {
                    return false;
                }

                // Get the top opening bracket
                char ch = st.top();
                st.pop();

                // Check whether brackets match
                if ((s[i] == ')' && ch == '(') ||
                    (s[i] == ']' && ch == '[') ||
                    (s[i] == '}' && ch == '{')) {

                    continue;
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty if all brackets are matched
        return st.empty();
    }
};