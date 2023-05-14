//ಥ_ಥ
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <deque>

using namespace std;
const long long inf = 1e10;


int rec2(int n) {

  if (n < 4) {

    return n + 3;

  }
  if (rec2(n - 1) % 2) {
      
    return rec2(n - 2) + 2 * n;

  }
  else {

    return rec2(n - 2) + n;
      
  }

}

int rec3(int n) {

  if (n == 0) {

    return 0;

  }
  else if (1 <= n && n < 3) {

    return 1;

  }
  else {

    return rec3(n - 2) + rec3(n - 1);

  }

}

int rec4(int n) {

  if (n == 0) {

    return 0;

  }
  else if (n % 2) {

    return 2 * rec4(n - 1) + 1;

  }
  else {

    return rec4(n / 2) + 3;

  }

}

int rec5(int n){

  if (n == 1) {

    return 1;

  }
  else {

    return n * rec5(n - 1);

  }

}

int main() {
  //cout << rec(15) << endl;
  //return 0;
  int co = 0;
  int co1 = 0;
  for (int i = 40; i < 51; i++) {

    co += rec2(i);

  }
  cout << co << endl;
  for (int i = 0; i < 1000; i++){

    if (rec4(i) == 18) {

      co1++;

    }

  }
  cout << co << rec3(47) << co1 << rec5(2023) / rec5(2020) << endl;
  
}