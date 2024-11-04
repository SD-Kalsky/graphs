#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

// 1. Реализуйте обход графа в ширину
// 2. Реализуйте обход графа в глубину
// 3. Реализуйте построение каркаса графа в процессе обхода в ширину
// 4. Реализуйте построение каркаса графа в процессе обхода в глубину
// 5. Дополнительное задание. Реализуйте визуализацию работы этих
// алгоритмов, чтобы граф отображался на экране, а процесс работы
// демонстрировался различными цветами и другими эффектами

// 6. Дополнительное задание. Реализуйте генерацию случайного
// графа, чтобы не вводить матрицу/список смежности вручную

queue<int> uniteQueue(queue<int> a, queue<int> b) {
  while (!b.empty()) {
    a.push(b.front());
    b.pop();
  }
  return a;
}
class Graph {
private:
  int size;
  int **vertices;
  void destroy() {
    int i = 0;
    while (i < size) {
      delete[] vertices[i];
      vertices[i] = nullptr;
      i++;
    }
    delete[] vertices;
    vertices = nullptr;
  }
  void destroy_vertice(int i) {
    delete vertices[i];
    vertices[i] = nullptr;
  }
  void init() {
    int i = 0;
    vertices = new int *[size];
    while (i < size) {
      vertices[i] = new int[3];
      vertices[i][0] = 3;     // Bas massiv iene
      vertices[i][1] = i + 1; // Systar bas nyomere
      vertices[i][2] = i - 1; //
      i++;
    }
  }

public:
  Graph() {
    size = 3;
    init();
    vertices[size - 1][1] = 0;
    vertices[0][2] = size - 1;
  }
  Graph(int n) {
    size = n;
    init();
    vertices[size - 1][1] = 0;
    vertices[0][2] = size - 1;
  }
  int get_size(){
    return size;
  }
  int *get_vertice(int i){
    return vertices[i];
  }
  int **get_vertices(){
    return vertices;
  }
  void print() //
  {
    int i = 0;
    while (i < size) {
      cout << i << " -> ";
      int j = 1;
      while (vertices[i][0] > j) {
        cout << vertices[i][j] << ' ';
        j++;
      }
      cout << endl;
      i++;
    }
  }
  void randomize() {
    int i = 0, j, k, s, r;
    destroy();
    srand(time(0));
    vertices = new int *[size];
    while (i < size) {
      r = rand() % (size + 1 - i);
      vertices[i] = new int[r];
      vertices[i][0] = r;
      j = 1;
      while (j < r) {
        vertices[i][j] = j + i;
        j++;
      }
      i++;
    }
    k = size - 1;
    while (k > 0) {
      stack<int> q;

      i = 0;
      while (i < size) {
        j = 1;
        while (j < vertices[i][0]) {
          if (vertices[i][j] == k) {
            q.push(i);
            break;
          }
          j++;
        }
        i++;
      }
      int *newvertices = new int[q.size() + 1];
      newvertices[0] = q.size() + 1;
      s = 0;
      while (!q.empty()) {
        s++;
        newvertices[s] = q.top();
        q.pop();
      }
      delete[] vertices[k];
      vertices[k] = newvertices;
      k--;
    }
  }
  void randomize(int n)
  {
    size=n;
    this->randomize();
  }
  void def() {
    size = 8;
    init();
    delete[] vertices;
    vertices = new int *[7];
    vertices[0] = new int[2];
    vertices[0][0] = 2;
    vertices[0][1] = 2;
    vertices[1] = new int[4];
    vertices[1][0] = 4;
    vertices[1][1] = 5;
    vertices[1][2] = 6;
    vertices[1][3] = 7;
    vertices[2] = new int[4];
    vertices[2][0] = 4;
    vertices[2][1] = 0;
    vertices[2][2] = 3;
    vertices[2][3] = 4;
    vertices[3] = new int[3];
    vertices[3][0] = 3;
    vertices[3][1] = 2;
    vertices[3][2] = 5;
    vertices[4] = new int[3];
    vertices[4][0] = 3;
    vertices[4][1] = 2;
    vertices[4][2] = 7;
    vertices[5] = new int[3];
    vertices[5][0] = 3;
    vertices[5][1] = 1;
    vertices[5][2] = 3;
    vertices[6] = new int[3];
    vertices[6][0] = 3;
    vertices[6][1] = 1;
    vertices[6][2] = 2;
    vertices[7] = new int[3];
    vertices[7][0] = 3;
    vertices[7][1] = 1;
    vertices[7][2] = 4;
  }
  void BFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1];
    queue<int> q;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
    q.push(v);
    b[v] = true;
    while (!q.empty()) {
      i = 1;
      while (i < vertices[v][0]) {
        if (!b[vertices[v][i]]) {
          a[j][0] = v;
          a[j][1] = vertices[v][i];
          q.push(vertices[v][i]);
          b[vertices[v][i]] = true;
          j++;
        }
        i++;
      }
      cout << v << ' ';
      q.pop();
      v = q.front();
    }
    i = 0;
    cout << endl << endl;
    while (i < size - 1) {
      cout << a[i][0] << ' ' << a[i][1] << endl;
      i++;
    }
  }

  int** iBFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1];
    queue<int> q;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
    q.push(v);
    b[v] = true;
    while (!q.empty()) {
      i = 1;
      while (i < vertices[v][0]) {
        if (!b[vertices[v][i]]) {
          a[j][0] = v;
          a[j][1] = vertices[v][i];
          q.push(vertices[v][i]);
          b[vertices[v][i]] = true;
          j++;
        }
        i++;
      }
      q.pop();
      v = q.front();
    }
    return a;
  }


  void DFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1];
    stack<int> q, q1;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
  q.push(v);
  q1.push(v);
  b[v]=true;
  while (!q.empty()){
    i=0;
    while (vertices[v][0]>i){
      i++;
      if(!b[vertices[v][i]]){
        a[j][0]=v;
        v=vertices[v][i];
        a[j][1]=v;
        q.push(v);
        b[v]=true;
        i=0;
        j++;
        };
      }
    q.pop();
    v=q.top();
  }
  j=0;
  while (j<size-1)
  {
    cout<<a[j][0]<<' '<<a[j][1]<<endl;
    j++;
  }
  }

  int** iDFS(int v) {
    int i = 0, j = 0, **a = new int *[size - 1];
    stack<int> q, q1;
    bool *b = new bool[size - 1];
    while (i < size - 1) {
      b[i] = false;
      a[i] = new int[2];
      i++;
    }
  q.push(v);
  q1.push(v);
  b[v]=true;
  while (!q.empty()){
    i=0;
    while (vertices[v][0]>i){
      i++;
      if(!b[vertices[v][i]]){
        a[j][0]=v;
        v=vertices[v][i];
        a[j][1]=v;
        q.push(v);
        b[v]=true;
        i=0;
        j++;
        };
      }
    q.pop();
    v=q.top();
  }

  return a;
  }


  bool isThereWay(int a, int b) // Биирис өрүт иккискэ түhүү уhунун биэрэр
  {
    bool c{false};
    int j = 1;
    while (j < vertices[a][0]) {
      if (vertices[a][j] == b) {
        c = true;
        goto exit;
      }
      j++;
    }
    j = 1;
    while (j < vertices[a][0]) {

      if (isThereWay(vertices[a][j], b)) {
        c = true;
        goto exit;
      } else
        j++;
    }
  exit:
    return c;
  }
};
