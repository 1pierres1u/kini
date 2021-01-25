template<typename T>
RangeMinimumQueryNaive<T>::RangeMinimumQueryNaive()
{
}
template<typename T>
RangeMinimumQueryNaive<T>::RangeMinimumQueryNaive(const vector<T>& V)
{this->elements=V;
}
template<typename T>
void RangeMinimumQueryNaive<T>::build(const vector<T>& V)
{ this->elements = V;
}
template<typename T>
size_t RangeMinimumQueryNaive<T>::range_minimum_position(size_t index_a, size_t index_b)const
{ check_range(this->elements,index_a,index_b);
  size_t mi=index_a;
  while(++index_a <= index_b)
  { if(this->elements[mi] > this->elements[index_a])
      mi = index_a;
  }
  return mi;
}
