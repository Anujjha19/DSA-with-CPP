#include<bits/stdc++.h>
using namespace std;

public:
        void leftPart(Node *root , vector<int> &ans){
            //Base Case
            if( (root==NULL) || (root -> left ==NULL && root ->right ==NULL)){
                return;
            }
            
            ans.push_back(root->data);
            
            if(root->left){
                leftPart(root ->left , ans);
            }
            else {
                //(root->right)
                leftPart(root ->right ,ans);
            }
        }
        
        void leavesPart(Node *root , vector<int> &ans){
            
            //Base Case
            if(root == NULL ) return;
            if(root -> left ==NULL && root -> right ==NULL) {
                ans.push_back(root -> data);
                return;
            }
            /*
            if(root->left){
                leavesPart(root ->left ,ans);
            }
            if(root->right){
                leavesPart(root ->right , ans);
            } */
            leavesPart(root ->left ,ans);
            leavesPart(root ->right ,ans);
        }
        
        void rightPart(Node *root , vector<int> &ans){
            
            //Base Case
            if( (root==NULL) || (root -> left ==NULL && root ->right ==NULL)){
                return;
            }
            if(root -> right){
                rightPart(root ->right ,ans);
            }else{
                rightPart(root -> left , ans);
            }
            ans.push_back(root -> data);
        }

//Main FUNCTION
    vector <int> boundary(Node *root)
    {
        //Make ans To Store 
        vector<int>ans;
        if(root ==NULL) return ans; //Base Case
        ans.push_back(root -> data);
        
        //Traverse Left Part
        leftPart(root ->left  , ans);
        
         //Traverse Leaves-> LEFT  Part
        leavesPart(root -> left , ans  );
         //Traverse Leaves-> RIGHT  Part
        leavesPart(root -> right , ans );
         //Traverse Right Part
        rightPart( root -> right , ans);
        
        return ans;
    }

Time Complexity: O(N).
Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)
Space Complexity: O(N)

// Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).