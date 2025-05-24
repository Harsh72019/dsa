#include<bits/stdc++.h>
using namespace std;


char firstNonRepeatingCharacter(string str) {
  unordered_map<char , int> um;
  for(auto i : str)
  {
    um[i]++;
  }

  for(auto i : str)
  {
    if(um[i] == 1)
      return i;
  }
  return str[0];
}