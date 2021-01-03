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
{ if(index_a >= elements.size()) throw std::out_of_range("index_a out of bound");
  if(index_b >= elements.size()) throw std::out_of_range("index_b out of bound");
  if(index_a > index_b) throw std::out_of_range("index_a > index_b");
  
  size_t mi=index_a;
  while(++index_a <= index_b)
  { if(elements[mi] > elements[index_a])
      mi = index_a;
  }
  return elements[mi];
}
