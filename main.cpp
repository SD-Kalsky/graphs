#include "classes.h"
#include "graph.h"
#include <iostream>
using namespace std;

int main() {
  Graph g;
  g.def();
  int **a;
  a=g.iBFS(3);
  int i=0;
  while(i<g.get_size()-1)
  {
    cout<<a[i][0]<<' '<<a[i][1]<<endl;
    i++;
  }
  cout<<endl;
  a=g.iDFS(3);
  i=0;
  while(i<g.get_size()-1)
  {
    cout<<a[i][0]<<' '<<a[i][1]<<endl;
    i++;
  }


  return 0;
}
