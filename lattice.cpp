#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
typedef vector< vector<int> > myList;
class Helper{
    public:
    static int getRandomNumber(int a, int b) {
        return a + rand() % (b - a + 1);
    }
};
class Graph{
    int k;
    set<pii> *adj;
    public:
    Graph(int k){
        this->k = k;
        adj = new set<pii>[k+1];
    }
    void generateGraph(){
        for(int i = 1; i < k; ++i) {
            int u = Helper::getRandomNumber(1, i - 1);
            int v = i;
            adj[u].insert({v,i-1});
            adj[v].insert({u,i-1});
        }
    }
    void dfs(int u,int par,bool visited[],set<pii>adj[]){
        visited[u] = true;
        for(auto k:adj[u]){
            if(k.ff == par ) continue;
            dfs(k.ff,u,visited,adj);
        }
    }
    int getLabel(int i,int j){
        bool visited[k+1];
        memset(visited,false,sizeof(visited));
        int label;
        for(auto child:adj[i]){
            auto childCopy = child;
            dfs(child.first,i,visited,adj);
            if(visited[j] == true){
                adj[i].erase(childCopy);
                label =  childCopy.second;
                break;
            }
        }
        adj[i].insert({j,label});
        return label;
    }    
};
class Chains{
    vector<pair<int,vector<vector<int>>>> chains;

    public:
    Chains(){

    }
    Chains(vector<pair<int,vector<vector<int>>>> chains){
        this->chains = chains;
    }
    void addChain(vector<vector<int>> ch){
        chains.pb({ch.size(),ch});
    }
    vector<vector<int>> getChain(int index){
        return chains[index].ss;
    }

    vector<vector<int>>* getLeastElementChains(int k){
        vector<vector<int>>* leastChains = new vector<vector<int>>[k];
        for(int i=0;i<k;i++){
            leastChains[i] = chains[i].second;                        
        }               
        return leastChains;
    }
    void updateChains(vector<vector<int>>* newChains,int k){
        chains.erase(chains.begin(),chains.begin()+k);
        for(int i=0;i<k-1;i++){
            chains.pb({newChains[k].size(),newChains[k]});
        }
        sort(chains.begin(),chains.end());
    }
};
class Poset{
    int n;
    Chains pChains;
    int totalChains;
    public:
    Poset(int n , myList chains[]){
        this->n = n;
        this->totalChains = n;
        for(int i=0;i<n;i++){
            this->pChains.addChain(chains[i]);
        }
    }
    
    
    void printInput(){
        for(int i=0;i<n;i++){
            auto ch = pChains.getChain(i);
            for(auto ch2 : ch){
                for(auto el: ch2){
                    cout<<el<<" ";
                }
                cout<<endl;
            }
        }
    }
    /*
    * Returns true if all the chains in the given list of chains is non-empty
    */
    bool allChainsNonEmpty(myList chains[],int k) 
    {
        for(int i=0;i<k;i++)
        {
            if(chains[i].size()==0)
                return false;
        }
        return true;
    }

    /*
    * Returns true if first vector clock is less than second vector clock 
    */
    bool less_than(vector<int> clock1, vector<int> clock2)
    {
        //clock1 < clock2 if in all positions clock1[i] <= clock2[i] and there is atleast one position in which clock1[i] < clock2[i]
        for(int i=0;i<n;i++)
        {
            if(clock1[i]>clock2[i])
                return false;
        }
        for(int i=0;i<n;i++)
        {
            if(clock1[i]<clock2[i])
                return true;
        }
        return false;
    }

    bool merge(myList chains[],myList merged_chain[],int k)
    {
        set<int> ac;//a set of indices indicating those input queues whose heads are known to form an antichain.
        int bigger[k];
        Graph graph(k);
        while(ac.size()!=k && allChainsNonEmpty(chains,k))
        {
            set<int> move; //records which elements will be moved from an input queue to an output queue.
            for(int i=0;i<k;i++)
            {
                if(ac.find(i)==ac.end()) //check if i does not belong to 'ac' and then proceed
                {
                    for(int j=0;j<k;j++)
                    {
                        if(less_than(chains[i][0],chains[j][0]))
                        {
                            move.insert(i);
                            bigger[i]=j;
                        }
                        if(less_than(chains[j][0],chains[i][0]))
                        {
                            move.insert(j);
                            bigger[j]=i;
                        }
                    }
                }
            }
            for (auto it = move.begin(); it != move.end(); ++it)
            {
                //dest = findQ()
                // pass i , j to getLabel
                int dest = graph.getLabel(*it,bigger[*it]);
                vector<int> head_element = chains[it][0];
                merged_chain[dest].push_back(head_element);
                chains[it].erase(chains[it].begin()); 

            }
            for(int i=0;i<k;i++) //  ac = all - move
            {
                if(move.find(i)==move.end())
                {
                    ac.insert(i);
                }
            }
        }
        if(allChainsNonEmpty(chains,k))
            return false; 
        return true;
    }

    vector<vector<int>>* findAntiChain(int k)
    {
        while(totalChains > k-1){
            vector<vector<int>>* toMergeChains = pChains.getLeastElementChains(k);
            vector<vector<int>>* mergedChains = new vector<vector<int>>[k-1];
            bool res = merge(toMergeChains,mergedChains, k);
            if(res)
                pChains.updateChains(mergedChains,k);
            else
            {     
                vector<vector<int>>* antichain = new vector<vector<int>>[k];
                for(int i=0;i<k;i++)
                {
                    antichain[i]=toMergeChains[i][0];
                }
                return antichain;
            }
        }
        return NULL;
    }  
   
};


int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n; //n is number of processes 
    cin>>n;
    int size_queue[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>size_queue[i];        
    }
    myList chains[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<size_queue[i];j++)
        {
            vector<int> vector_clock;
            int entry;
            for(int k=0;k<n;k++)
            {
                cin>>entry;
                vector_clock.push_back(entry);
            }
            chains[i].push_back(vector_clock);
        }
    }
    Poset p(n,chains);
    p.printInput();

    //   int k;      // find if there exists an antichain of size k
    // cin>>k;
}