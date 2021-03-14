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

    bool merge(myList chains[],myList anti_chain[],int k)
    {
        set<int> ac;//a set of indices indicating those input queues whose heads are known to form an antichain.
        int bigger[k];
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