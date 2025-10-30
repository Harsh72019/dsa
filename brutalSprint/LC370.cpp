#include<bits/stdc++.h>
using namespace std;

vector<int> rangeAddition(int n , vector<vector<int>> & queries)
{
   vector<int> ans (n , 0);

   for(auto it : queries)
   {
       ans[it[0]] += it[2];
       if(it[1] + 1 < n)
       {
           ans[it[1] + 1] -= it[2];
       }
   }
   int sum = 0;
   for(int i = 0; i < n ; i++)
   {
       sum += ans[i];
       ans[i] = sum;
   }
   return ans;
}

int main()
{
    vector<vector<int>> queries = {{1, 2, 2}, {2, 4, 3}};
    vector<int> ans = rangeAddition(5 , queries);
    for(auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}