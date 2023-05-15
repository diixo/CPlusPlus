// https://linuxhint.com/std-transform-function-cpp/

#include <iostream>
#include <algorithm>

using namespace std;

int square(int m) {
   return m*m;
}

int main(int lmn, char **pqr) {

   int array[12] = {4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26};
   int result[12];

   transform(array, array+12, result, square);
}

///////////////////////////////////////

int operator_increment (int k, int l) {
  return k+l;
}

int main () {

  int a = 8;    

  int inp_arr1[] = {4, 7, 12, 36, 75, 23, 48, 69};
  int inp_arr2[] = {2, 15, 6, 95, 8, 73, 4, 80};
  int otp_arr[a];

  std::transform (inp_arr1, inp_arr1+a, inp_arr2, otp_arr, operator_increment);

  std::cout <<"Resultant array:";

  for(int k=0; k<8; k++){
    cout <<' ' << otp_arr[k];
  }

  cout <<'\n';
  return 0;
}

/////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>  

int op_increase (int j) { return ++j; }

int main () {
  std::vector<int>abc;
  std::vector<int>xyz;

  for (int j = 1; j < 8; j++)
    abc.push_back (j * 20);  
                     
  xyz.resize(abc.size());

  // 1.
  std::transform (abc.begin(), abc.end(), xyz.begin(), [](int x) { return ++x; });

  // 2.
  std::transform (abc.begin(), abc.end(), xyz.begin(), op_increase);

  // 3.
  std::transform (abc.begin(), abc.end(), xyz.begin(), abc.begin(), std::plus<int>());

  std::cout <<"Output";

  for (std::vector<int>::iterator it=abc.begin(); it!=abc.end(); ++it)
    std::cout <<' ' <<*it;

  std::cout <<'\n';
  return 0;
}
