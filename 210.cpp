class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        learned = 0;
        queue<int> q;
   graph = vector<vector<int>>(numCourses,vector<int>());
   vector<int> indegree = vector<int>(numCourses,0);
    for(auto &p : prerequisites){
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }
    for(int i = 0; i < numCourses; i++){
       if(indegree[i] == 0){
           q.push(i);
           ans.push_back(i);
           learned++;
         //  cout<<"a"<<endl;
       }
    }
       while(!q.empty()){
           int temp = q.front();
           q.pop();
           for(auto & cur : graph[temp]){
               indegree[cur]--;
               if(indegree[cur] == 0){
                   q.push(cur);
                   ans.push_back(cur);
                   learned++;
                 //  cout<<"b"<<endl;
               }
           }
       }
      
    if(learned == numCourses)
     return ans;
     else{
         return {};
     }
      
    }
    private:
    vector<vector<int>> graph;
    vector<int> ans;
    int learned;
};
