class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i =0;i<nums1.size();i++){
            int position=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    position=j;
                    break;
                } 
                
            }

            int nextGreater=-1;
            for(int j=position+1;j<nums2.size();j++){
                if(nums1[i]<nums2[j]){
                    nextGreater=nums2[j];
                    break;
                }

            }  
            ans.push_back(nextGreater);  
        }
        return ans;        
        
        
    }

};