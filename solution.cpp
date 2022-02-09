#include "solution.h"
#include <queue>

using namespace sol1167;
using namespace std;

/*takeaways
  - use min-heap to sort the sticks
    by their length with the shortest
    one on top of the queue
  - the price is compounding so that's
    why you need to start with the less
    pricy ones
    - let's use testfixture as an example
    - we connect the sticks from the pricy
      ones
      - (4+3) -> first new stick cost
      - (4+3) + 2 -> second new stick cost
      - total cost: (4+3)+(4+3)+2
      - you can see you are compounding
        the higher price (4+3) every time
        you connect two sticks

*/

int Solution::minCost(vector<int> &input)
{
  /* C++ notes
     - by default priority_queue is a max-heap
     - we are turning it to a min-heap
       - it's just how the queue is designed if
         the use of greater<int> confuses
         you
  */
  auto q = priority_queue<int, vector<int>, greater<int>>();

  for (auto i : input)
    q.push(i);

  int totalCost = 0;
  /*
    - make sure you have more
      than one stick before
      continue
  */
  while (q.size() > 1)
  {
    auto s1 = q.top();
    q.pop();
    auto s2 = q.top();
    q.pop();
    /* put the connected stick back */
    q.push(s1 + s2);
    totalCost += (s1 + s2);
  }

  return totalCost;
}