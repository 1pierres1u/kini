template<typename T>
RangeMinimumQueryNaive<T>::RangeMinimumQueryNaive()
{
}
template<typename T>
RangeMinimumQueryNaive<T>::RangeMinimumQueryNaive(const vector<T>& V):elements(V)
{
}
template<typename T>
void RangeMinimumQueryNaive<T>::build(const vector<T>& V)
{ elements = V;
}
template<typename T>
T RangeMinimumQueryNaive<T>::range_minimum(size_t index_a, size_t index_b)const
{ check_range(elements,index_a,index_b);
  size_t mi=index_a;
  while(++index_a <= index_b)
  { if(elements[mi] > elements[index_a])
      mi = index_a;
  }
  return elements[mi];
}
