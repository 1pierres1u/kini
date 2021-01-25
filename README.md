# KINI
A C++ templated data structure library.

# Table Of Contents
The data structures implemented are:
* Range Minimum Query
  * Naive
  * Blocking
  * Sparse Table
  * Hybrid
  * Fischer

## Usage
```cpp
  #include "../include/RangeMinimumQueryHybrid.hpp"
  using namespace std;
  int main()
  { size_t N,start,end;
    cout << "vector size: ";
    cin  >> N;
    vector<int> V(N);
    cout << "Enter elements\n";
    for(auto& x:V)
     cin >> x;
    RangeMinimumQueryHybrid<int> rmq;
    rmq.build(V);
  
    cout << "Enter\nrange start: ";
    cin >> start;
    cout << "range end: ";
    cin >> end;
    cout << "minimum is: " << rmq.range_minimum(start,end) << endl;
    return 0;
  }
```


