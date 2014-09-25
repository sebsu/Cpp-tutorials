#pragma GCC push_options
#pragma GCC optimize ("O2")
 
#include <iostream>
#include <vector>
#include <iterator>
#include <time.h>
 
//#define int unsigned long long
 
int main()
{
  std::ios::sync_with_stdio(false);
  std::ios_base::sync_with_stdio (false);
 
  int sizeN = 0;
  int sizeM = 0;
  double begin = (double)clock()*1000;
  while(std::cin >> sizeN >> sizeM)
    {
      if((sizeN == 0) && (sizeM == 0))
        {
	  double end = (double)clock()*1000;
	  std::cout << (end-begin)/CLOCKS_PER_SEC;
	  return 0;
        }
      else if((sizeN == 0) || (sizeM == 0))
        {
	  int t = sizeN + sizeM;
	  int dump;
	  for(int i = 0; i < t; ++i)
	    std::cin >> dump;
 
	  int ret = 0;
	  std::cout << ret << "\n";
	  continue;
        }
 
      std::vector<int> vec;
      vec.reserve(sizeN);
 
      for(int n = 0; n < sizeN; ++n)
        {
	  int val;
	  std::cin >> val;
	  vec.push_back(val);
        }
 
      std::vector<int>::iterator it = vec.begin();
      std::vector<int>::iterator eit = vec.end();
      int duplicates = 0;
 
      for(int m = 0; m < sizeM; ++m)
        {
	  int mVal;
	  std::cin >> mVal;
 
	  while((it != eit) && (*it < mVal))
	    ++it;
 
	  if(mVal == *it)
	    ++duplicates;
        }
 
      // read away two terminating zeros
      //std::cin >> sizeN >> sizeM;
 
      std::cout << duplicates << "\n";
    }
  return 0;
}
 
#pragma GCC pop_options
