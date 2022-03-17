class Solution {
private:
      vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
          
        //right ele is always not have smaller element than that 
        s.push(-1);
        vector<int> ans(n);
    
        //iterate over all heights to find small ele
        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            //arr[s.top] will give value on top instead of prev value at stack top here they gives index at stacks top
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            //pushed smallest value index 
            s.push(i);
        }
        return ans; 
    }    
public:
    
    int largestRectangleArea(vector<int>& heights) {
        //total width 
        int n= heights.size();
        
        //next smaller element index this will specify how much we can utilized on right
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
           
        //prev smaller element index this will specify how much we can utilized on left
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        //store area as min
        int area = INT_MIN;
        
        //iterate over all heights to find max
        for(int i=0; i<n; i++) {
            //get height as length 
            int l = heights[i];
            
            //if next is -1 it means we dont get smaller element so take n as it utilize all space
            if(next[i] == -1) {
                next[i] = n;
            }
            
            //prev handled in function
            //calculate area using formula
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};