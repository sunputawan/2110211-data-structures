#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> s;
  for(auto x:v) {
    if(x.first == 1) {
      s.push(x.second);
    }
    else {
      int a = s.top(); s.pop();
      int b = s.top(); s.pop();
      int ans;
      switch (x.second) {
        case 0:
          ans = a+b;
          break;
        case 1:
          ans = b-a;
          break;
        case 2:
          ans = a*b;
          break;
        case 3:
          ans = b/a;
          break;
        default:
          break;
      }
      s.push(ans);
      //cout<<s.top()<<'\n';
    }
  }

  return s.top();
}

#endif
