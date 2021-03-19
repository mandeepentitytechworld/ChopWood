 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef priority_queue<int> pq;

int main(void) {
  int n;
  cin >> n;
  vi code(n);
  for (int i = 0; i < n; ++i) cin >> code[i];
  if (code.back() != ++n) {
    cout << "Error\n";
    return 0;
  }
  vi freq(n, 0);
  pq leaves;
  for (vi::iterator i = code.begin(); i != code.end(); ++i)
    ++freq[*i-1];
  for (int i = 0; i < n; ++i)
    if (!freq[i]) 
      leaves.push(-i);
  for (vi::iterator i = code.begin(); i != code.end(); ++i) {
    cout << -leaves.top()+1 << "\n";
    leaves.pop();
    if (!--freq[*i-1])
      leaves.push(1-*i);
  }
  return 0;
}
