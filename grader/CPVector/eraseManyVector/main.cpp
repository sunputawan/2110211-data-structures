#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "vector.h"
#include "student.h"

using namespace std;



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  CP::vector<int> v;
  char c;
  scanf("%c", &c);
  while (c != 'q') {
    if (c == 'a') {
      // add data
      int n;
      scanf("%d", &n);
      for (int i = 0;i < n;i++) {
        int value;
        scanf("%d", &value);
        v.push_back(value);
      }
    } else if (c == 'e') {
      // call erase
      std::vector<int> pos;

      int n;
      scanf("%d", &n);
      for (int i = 0;i < n;i++) {
        int value;
        scanf("%d", &value);
        pos.push_back(value);
      }
      v.erase_many(pos);
    } else if (c == 'p') {
      cout<<'\n';
      for (auto &x : v) {
        printf("%d ",x);
      }
      printf("\n");
    }
    scanf("%c", &c);
  }
  return 0;
}
