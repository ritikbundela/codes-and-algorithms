// Last updated: 26/11/2025, 22:31:42
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> st;

      for(int mag: asteroids) {
        if(mag > 0){
            st.push(mag);
        }else{
            while(!st.empty() && st.top() > 0 && st.top() < -mag){
                st.pop();
            }

            if(st.empty() || st.top() < 0){
                st.push(mag);
            }

            if(!st.empty() && st.top() == -mag){
                st.pop();
            }
        }
      }
      
      vector<int> res(st.size());
      int i = st.size()-1;

      while(!st.empty()){
        res[i--] = st.top();
        st.pop();
      }
      return res;
    }
};