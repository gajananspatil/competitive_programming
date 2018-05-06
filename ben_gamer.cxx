#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;
int mincost(vector<int> vec,int w);

int poponecount(unsigned no);
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string str;
        getline(cin,str);
        stringstream ss(str);
        int l,w;
        ss>>l;
        ss>>w;
        //cout<<l<<","<<w<<"\n";
        vector<int> set;
        set.reserve(l);
        for(int i=0;i<l;++i)
        {       cin>>str;
                set.push_back(bitset<32>(str).to_ulong());

        }
//      for(auto i : set)
//              cout<<i<<",";
//      cout<<"\n";
        mincost(set,w);

}
int poponecount(unsigned no)
{
#ifdef __GNUC__
//      cout<<"builtin"<<"\n";
        return __builtin_popcount(no);
#endif
//      cout<<"bitset"<<"\n";
        bitset<32>bno(no);
        return bno.count();
}

int mincost(vector<int> vec,int w)
{
        unsigned maxmasks=pow(2,w);
        vector<unsigned> costs;
        costs.reserve(maxmasks);
        costs.resize(maxmasks);
        fill(costs.begin()+1,costs.end(),0x3f3f3f3f);
        costs[0]=0;
        int curCost=0;
        int cur1Count=0;
        for(int mask=0;mask<maxmasks;++mask)
        {
                curCost=costs[mask];
                cur1Count=poponecount(mask);
                for(int j=0;j<vec.size();++j)
                {
                        int newMask=mask|vec[j];
                        unsigned newCost=curCost+pow(poponecount(newMask)-cur1Count,2);
                        costs[newMask]=std::min(costs[newMask],newCost);
                }

        }

//      for(auto n:costs)
//              if(n !=0x3f3f3f3f)
//              cout<<n<<"\n";
        int index=0;
        for(auto v:vec)
                index=index|v;
        cout<<costs[index]<<"\n";

}
