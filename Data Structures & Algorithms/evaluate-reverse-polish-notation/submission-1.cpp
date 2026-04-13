class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        std::stack<int> stack;
        int a,b;

        for (const string& s : tokens){
            if(s == "+"){
                a = stack.top(); stack.pop();
                b = stack.top(); stack.pop();
                stack.push(b + a);
            }else if (s == "-"){
                a = stack.top(); stack.pop();
                b = stack.top(); stack.pop();
                stack.push(b - a);
            }else if (s == "*"){
                a = stack.top(); stack.pop();
                b = stack.top(); stack.pop();
                stack.push(b * a);
            } else if (s == "/"){
                a = stack.top(); stack.pop();
                b = stack.top(); stack.pop();
                stack.push(b / a);
            } else {
                stack.push(stoi(s));
            }
        }

        return stack.top();
        
    }
};
