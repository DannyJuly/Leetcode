  
//iteration preorder using stack  208ms
  vector<int> preorder(Node* root) {
        vector<int> ret ;
        if(!root) return ret;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            
            auto node = st.top();
            st.pop();
            ret.push_back(node->val);
            vector<int>::reverse_iterator rit;
            for(auto rit = (node->children).rbegin(); rit != (node->children).rend(); rit++) {
                st.push(*rit);
            }
        }
        return ret;
    }



// resursion   192ms
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        f(root);
        return ans;
    }
    
    void f(Node* root) {
        if(!root) return;
        ans.push_back(root->val);
        for(auto ch : root->children)
            f(ch);
    }
};