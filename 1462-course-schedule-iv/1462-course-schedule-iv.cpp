class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> gr(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (const auto& edge : prerequisites) {
            gr[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<unordered_set<int>> nodePrerequisites(numCourses);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int adj : gr[node]) {
                nodePrerequisites[adj].insert(node);
                for (int prereq : nodePrerequisites[node]) {
                    nodePrerequisites[adj].insert(prereq);
                }
                if (--indegree[adj] == 0) q.push(adj);
            }
        }
        
        vector<bool> answer;
        for (const auto& query : queries) {
            answer.push_back(nodePrerequisites[query[1]].count(query[0]));
        }
        
        return answer;
    }
};