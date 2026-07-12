class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        for(int i =0; i<indegree.size(); i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
       
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count==n){ // saare process hogai .. topological sort work -> cycle nhi h -> course krste h 
            return true;
        }
        return false;
     
    }
};