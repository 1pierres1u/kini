template<class T>
RangeMinimumNaive<T>::RangeMinimumNaive() 
{
}
template<class T>
RangeMinimumNaive<T>::RangeMinimumNaive(const RangeMinimumNaive& r):elements(r.elements)
{
}
template<class T>
RangeMinimumNaive<T>::RangeMinimumNaive(RangeMinimumNaive&& r):elements(std::move(r.elements))
{
}
template<class T>
RangeMinimumNaive<T>::RangeMinimumNaive(const vector<T>& vElements):elements(vElements) 
{
}
template<class T>
void RangeMinimumNaive<T>::build(const vector<T>& vElements)
{ elements = vElements;
}
template<class T>
T RangeMinimumNaive<T>::range_minimum(size_t index_a, size_t index_b)const 
{ if(index_a > index_b) throw std::out_of_range("index_a > index_b");
  if(index_a >= elements.size()) throw std::out_of_range("index_a >= size of vector");
  if(index_b >= elements.size()) throw std::out_of_range("index_b >= size of vector");
  T m;
  m=elements[index_a];
  while(++index_a<=index_b)
  { if(m>elements[index_a])
	    m = elements[index_a];
  }
  return m;
}
