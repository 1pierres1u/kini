template<class T>
RangeMinimumNaive<T>::RangeMinimumNaive()
{
}
template<class T>
RangeMinimumNaive<T>::RangeMinimumNaive(const std::vector<T>& vElements):elements(vElements)
{
}
template<class T>
void RangeMinimumNaive<T>::build(const std::vector<T>& vElements)
{ elements = vElements;
}
template<class T>
T RangeMinimumNaive<T>::range_minimum(size_t index_a, size_t index_b)const 
{ T m;
  if(elements.size()>0 && index_a<=index_b && elements.size()>index_b)
  { m=elements[index_a];
    while(++index_a<=index_b)
    { if(m>elements[index_a])
	    m = elements[index_a];
    }
  }
  return m;
}
