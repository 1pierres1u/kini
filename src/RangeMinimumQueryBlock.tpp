template<typename T>
RangeMinimumQueryBlock<T>::RangeMinimumQueryBlock():block_size(0)
{
}
template<typename T>
RangeMinimumQueryBlock<T>::RangeMinimumQueryBlock(const vector<T>& V)
{ if(V.size()>3)
   build(V);
  else {
   this->elements = V;
   block_size = 0; 
  }
}
template<typename T>
void RangeMinimumQueryBlock<T>::build(const vector<T>& V)
{ this->elements = V;
  block_size = 0;
  size_t N = V.size();
  block_minimum.clear();    
  if(V.size()>3)
  { block_size = sqrt(N);
    size_t num_blocks = N/block_size + (N%block_size==0?0:1);
    block_minimum = vector<size_t>(num_blocks);
    size_t i =0;
    while(i < N)
    { size_t j = i/block_size;
      j =  minr(N-1,(j+1)*block_size-1); 
      block_minimum[i/block_size] = min_(this->elements,i,j);
      i = j + 1;
    }  
  }
}
template<typename T>
size_t RangeMinimumQueryBlock<T>::range_minimum_position(size_t index_a, size_t index_b) const
{ check_range(this->elements,index_a,index_b); 

  size_t min_i=index_a;
  if(block_size==0 || (index_b-index_a+1<block_size))
  { min_i = min_(this->elements, index_a, index_b);
  }
  else
  {
    while(index_a < index_b+1)
    { size_t k = index_a/block_size;
      k = minr(index_b, (k+1)*block_size-1);
      if(is_a_block(index_a,k,block_size))
      { min_i = minu(min_i,block_minimum[index_a/block_size],this->elements);
      }
      else
      { min_i = minu(min_i,min_(this->elements,index_a,k),this->elements);
      }
      index_a = k + 1;
    }
  }
 return min_i;
}
