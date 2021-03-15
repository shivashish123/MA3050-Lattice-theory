/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 100005
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
class chains{
    private:
    set<vector<int>> allChains;
    int n;

    public:
    chains(int n){
        this->n = n;
    }
    vector < vector<vector<int>>> generateChains(){
        vector < vector<vector<int>>> totalChains;
        for(int i=0;i<n;i++){
            totalChains.pb(generateChain());
        }
        return totalChains;
    }
    vector<vector<int>> generateChain(){
        vector<vector<int>> chains;
        vector<int>seed = getSeed();
        chains.pb(seed);
        int chainSize = rand(1,10);
        for(int i=2;i<=chainSize;i++){
            vector<int>nextChain = getChain(chains.back());
            chains.pb(nextChain);
        }
        return chains;
        
    }
    vector<int> getSeed(){
        vector<int> seed;
        while(1){
            for(int i=1;i<=n;i++){
                seed.pb(rand(1,n));
            }
            if(allChains.find(seed)!=allChains.end()){
                seed.clear();
                continue;
            }
            else{
                allChains.insert(seed);
                return seed;
            }
        }
    }
    vector<int> getChain(vector<int> ch){
        vector<int>newChain;
        while(1){
            for(auto k:ch){
                newChain.pb(k+rand(1,n));
            }
            if(allChains.find(newChain)!=allChains.end()){
                newChain.clear();
                continue;
            }
            else{
                allChains.insert(newChain);
                return newChain;
            }
        }
    }
};


int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
	IOS;
	int n=rand(3,3); // total process
	cout<<n<<endl;
    chains chain(n);
    
    vector < vector<vector<int>>> allChains = chain.generateChains();
    for(auto k:allChains){
        cout<<k.size()<<" ";
    }
    cout<<endl;
    for(auto k:allChains){
        for(auto l:k){
            for(auto p:l){
                cout<<p<<" ";
            }
            cout<<endl;
        }
    }

}
