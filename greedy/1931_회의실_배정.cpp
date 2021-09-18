#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   int N;
   cin >> N;
   
   vector<pair<int, int>> meetings(N);
   
   for(int i=0; i<N; i++)
   {
       int start, end;
       cin >> start >> end;
       
       meetings[i] = make_pair(end, start);
   }
   
   sort(meetings.begin(), meetings.end());
   
   int lastTime = meetings[0].first;
   int answer = 1;
   
   for(int i=1; i<N; i++)
   {
       if(meetings[i].second >= lastTime)
       {
           lastTime = meetings[i].first;
           answer++;
       }
   }
   
   cout << answer << endl;
   
    return 0;
}
