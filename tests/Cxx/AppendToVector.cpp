
#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <compare>

using namespace std;
int main() {
   vector<int> v1 = { 1, 2, 3 };
   vector<int> v2 = { 4, 5 };
   v2.insert(v2.begin(), v1.begin(), v1.end());
   return 0;
}