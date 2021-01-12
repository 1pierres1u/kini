
template<typename T>
RangeMinimumQuerySparse<T>::RangeMinimumQuerySparse()
{
}
template<typename T>
RangeMinimumQuerySparse<T>::RangeMinimumQuerySparse(const vector<T>& V)
{build(V);
}
template<typename T>
void RangeMinimumQuerySparse<T>::build(const vector<T>& V)
{ 
  elements = V;
  sparseTable.clear();
  //
  //size restriction on building the sparse table
  if(elements.size()<MIN_SIZE_VECTOR)
      return;
  //
  size_t N = elements.size();
  //add vectors
   for(size_t i=0; i < N; i++)
	sparseTable.push_back(vector<size_t>(floor(log2(N-i))+1));
  //fill first column
  for(size_t i=0; i<N; i++)
  {	sparseTable[i][0] = i;
  }
  //fill remaining 
  size_t L = sparseTable[0].size(); 
  size_t k = 1;
  for(size_t j=1; j < L; j++)
  { for(size_t i=0; sparseTable[i].size()>j; i++)
    { size_t a = sparseTable[i][j-1];
      size_t b = sparseTable[i+k][j-1];
      
      if(elements[a] > elements[b])
      { sparseTable[i][j] = sparseTable[i+k][j-1];
      }
      else
      { sparseTable[i][j] = sparseTable[i][j-1];
      }
    }
    k*=2;
  }
}
template<typename T>
T RangeMinimumQuerySparse<T>::range_minimum(size_t index_a, size_t index_b)const
{ check_range(elements, index_a, index_b);

  if(index_a != index_b )
  { if(elements.size()>=MIN_SIZE_VECTOR)
    {  
	    size_t k = floor(log2(index_b-index_a+1));
	    size_t L = (1 << k);
	    index_a = sparseTable[index_a][k];
	    index_b = sparseTable[index_b - L + 1][k];
	    index_a = (elements[index_a]>elements[index_b]?index_b:index_a);
    }
    else
    { index_a = min_(elements,index_a,index_b);
    }
  }
  return elements[index_a];
}

