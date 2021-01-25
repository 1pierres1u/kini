template<typename T>
RangeMinimumQueryHybrid<T>::RangeMinimumQueryHybrid():block_size(0),no_elem(0)
{
}
template<typename T>
RangeMinimumQueryHybrid<T>::RangeMinimumQueryHybrid(const vector<T>& V)
{ build(V);
}
template<typename T>
void RangeMinimumQueryHybrid<T>::build(const vector<T>& V)
{  no_elem = V.size();
   elements = V;
   rmq_blocks.clear();
   summary_position.clear();
   block_size=0;
   if(no_elem >= MIN_SIZE_VECTOR)
   {  
     find_block_size();
    
     rmq_blocks = vector<unique_ptr<RangeMinimumQuery<T>>>(no_elem/block_size+1+(no_elem%block_size==0?0:1)); 
     size_t M = rmq_blocks.size()-1; //minus room for summary block 
     
     vector<T> summary(M);		
     summary_position = vector<size_t>(M);
     size_t S = 0,L; 
     vector<T> tmp;
     while(S<M)
     {  L = minr(no_elem-1,(S+1)*block_size-1);
        tmp = vector<T>(V.begin()+S*block_size,V.begin()+L+1);
        rmq_blocks[S] = make_unique<RangeMinimumQuerySparse<T>>(tmp);
        size_t pos = min_(tmp,0,tmp.size()-1);
        summary_position[S] = pos;
        summary[S]=tmp[pos];
        S++;
     }
     rmq_blocks[S] = make_unique<RangeMinimumQuerySparse<T>>(summary);  
   }
}
template<typename T>
T RangeMinimumQueryHybrid<T>::range_minimum(size_t index_a, size_t index_b)const
{ return elements[range_minimum_position(index_a,index_b)]; 
}
template<typename T>
void RangeMinimumQueryHybrid<T>::find_block_size()
{ size_t lg = log2(no_elem)/4;
  block_size = (lg>5?lg:lg*4); 
}
template<typename T>
size_t RangeMinimumQueryHybrid<T>::range_minimum_position(size_t index_a, size_t index_b)const
{ if(index_a >= no_elem) throw std::out_of_range("index_a out of bound");
  if(index_b >= no_elem) throw std::out_of_range("index_b out of bound");
  if(index_a > index_b) throw std::out_of_range("index_a > index_b");

  size_t minp;
  if(no_elem >= MIN_SIZE_VECTOR)
  { size_t block_a = index_a/block_size;
    size_t end_a = minr(no_elem-1,(block_a+1)*block_size-1);
    size_t block_b = index_b/block_size;
    size_t start_b = block_b*block_size;

    if(block_a == block_b)
    {
      minp = block_a*block_size + rmq_blocks[block_a]->range_minimum_position(index_a%block_size,index_b%block_size);
    }
    else
    { size_t ba = block_a*block_size + rmq_blocks[block_a]->range_minimum_position(index_a%block_size,end_a%block_size);
      size_t bb = block_b*block_size + rmq_blocks[block_b]->range_minimum_position(start_b%block_size,index_b%block_size);
      minp = minu(ba,bb,elements);

      if(block_b-block_a>1)
      { size_t Q =  rmq_blocks[rmq_blocks.size()-1]->range_minimum_position(block_a+1,block_b-1);
        Q = Q*block_size + summary_position[Q];
        minp = minu(minp, Q,elements);
      } 
    }
  }
  else
  { minp = min_(elements,index_a,index_b);
  }
  return minp;
}
