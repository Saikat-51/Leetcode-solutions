class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int st=0;
        int end=height.size()-1;

        while(st<end){
            int line_height=min(height[st],height[end]);
            int length=end - st;
            ans=max(ans,(line_height*length));
            if(height[st]>height[end]) end--;
            else 
            st++;
        }
        return ans;
    }
};