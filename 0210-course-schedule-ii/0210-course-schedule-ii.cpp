class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           int n = numCourses;
        unordered_map<int , vector<int>>adj;
        vector<int>indegree(n ,0);
        for(int u = 0 ; u<prerequisites.size(); u++){
        int a = prerequisites[u][0];
        int b = prerequisites[u][1];
        adj[b].push_back(a);
        indegree[a]++;
          
        }
        queue<int>q;
         int count = 0 ;
         vector<int>path;
        for(int i =0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
                // count++;  -- removing as per kahn algo node is process when pop from queue so do whatevr u want when popping 
                // path.push_back(i);
            }
        }
       
        while(!q.empty()){
            int u = q.front();
            q.pop();
                 count++;
            path.push_back(u);
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                   
                }
            }
        }
      if(count==n){ // cycle nhi h sb thek h 
return path;
      }
      return {};
       
    }
};