#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"
#define ERROR 1e-8
#include <bits/stdc++.h>
using namespace std;
#include "../../../geometry/Geometry.hpp"
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a,b,c,d;
  cin>>a>>b>>c>>d;

  Point p0(a,b);
  Point p1(c,d);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    int res=ccw(p0,p1,Point(x,y));
    if(res==1){
      cout << "COUNTER_CLOCKWISE"<<endl;
    }else if(res==-1){
      cout << "CLOCKWISE"<<endl;
    }else if(res==2){
      cout << "ONLINE_BACK"<<endl;
    }else if(res==-2){
      cout << "ONLINE_FRONT"<<endl;
    }else{
      cout << "ON_SEGMENT"<<endl;
    }
  }
}
