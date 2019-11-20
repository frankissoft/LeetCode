#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]){
  std::cout << "Hello atom!" << std::endl;
  // std::string alpha(27, '0');
  // alpha[10] = 100;
  // std::cout << alpha << std::endl;
  std::vector<int> alpha(100, 0);
  std::stringstream ss;
  copy(alpha.begin(), alpha.end(), std::ostream_iterator<int>(ss, ""));
  std::string alpha_s = ss.str();
  std::cout << alpha_s << std::endl;

  return 0;
}
