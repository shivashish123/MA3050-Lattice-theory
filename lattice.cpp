#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > myList;

class Poset{
    int n;
    myList* chains;
    public:
    Poset(int n , myList chains[]){
        this->n = n;
        this->chains = new myList[n];
        for(int i=0;i<n;i++){
            this->chains[i] = chains[i];
        }
    }
    void printInput(){
        for(int i=0;i<n;i++){
            auto ch = chains[i];
            for(auto ch2 : ch){
                for(auto el: ch2){
                    cout<<el<<" ";
                }
                cout<<endl;
            }
        }
    }
    void findAntiChain(int k)
    {
        
    }    
};


int main()
{
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