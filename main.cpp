#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1167;

tuple<vector<int>, int> testFixture1()
{
  vector<int> input{2, 4, 3};
  return make_tuple(input, 14);
}

tuple<vector<int>, int> testFixture2()
{
  vector<int> input{1, 8, 3, 5};
  return make_tuple(input, 30);
}

void test1()
{
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<1>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minCost(get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto fixture = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<1>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minCost(get<0>(fixture));

  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}