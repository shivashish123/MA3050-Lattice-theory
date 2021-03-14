#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > myList;
void findAntiChain(int k,myList chains[])
{
    cout<<"HELLO"<<endl;
}
int main()
{
    int n,m; //n is number of processes and m is number of chains/queues 
    cin>>n>>m;
    int size_queue[m];
    for(int i=0;i<m;i++)
    {
        cin>>size_queue[i];
    }
    myList chains[m];
    for(int i=0;i<m;i++)
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
    int k;      // find if there exists an antichain of size k
    cin>>k;
    findAntiChain(k,chains);
}