namespace utility
{
  template<class T>
  size_t minimum(vector<T>& V, size_t i, size_t j)
  { size_t m = i; 
    for(size_t k=i; k<j+1; k++)
	    if(V[k]<V[m])
		    m = k;
    return m;
  }
}
