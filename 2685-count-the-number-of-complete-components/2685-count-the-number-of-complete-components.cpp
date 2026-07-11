class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>>& adjList,unordered_map<int,bool>&vis,int &nodes,int &edgesCount){
        vis[node]=true;
        nodes++;
        edgesCount+=adjList[node].size();

        for(int i:adjList[node]){
            if(!vis[i]){
                dfs(i,adjList,vis,nodes,edgesCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>>adjList;
        for(auto edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        unordered_map<int,bool>vis;

        int count=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int nodes=0;
                int edgesCount=0;
                dfs(i,adjList,vis,nodes,edgesCount);
                edgesCount/=2;
                if(edgesCount==nodes*(nodes-1)/2)
                count++;
            }
        }
        return count;
    }
};