#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
// using namespace std;

// template<typename T>
// std::ostream& operator<<(std::ostream& s, const std::vector<T>& v)
// {
//     s.put('[');
//     char comma[3] = {'\0', ' ', '\0'};
//     for (const auto& e : v) {
//         s << comma << e;
//         comma[0] = ',';
//     }
//     return s << ']';
// }

int main(int argc, const char * argv[]){
  // std::cout << "Hello atom!" << "\n";
  // std::string alpha(27, '0');
  // alpha[10] = 100;
  // std::cout << alpha << std::endl;
  std::vector<int> vec(100, 0);
  std::vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};

  std::stringstream ss;
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(ss, ""));

  std::string alpha_s = ss.str();

  // copy( v.begin(), v.end(), ostream_iterator<int>(ss, " "));
  // string s = ss.str();
  std::cout << alpha_s << std::endl;

  return 0;
}
