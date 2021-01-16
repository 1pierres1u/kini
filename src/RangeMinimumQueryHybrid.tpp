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
   if(no_elem >= MIN_SIZE_VECTOR)
   { rmq_blocks.clear();
      
     find_block_size();
    
     rmq_blocks = vector<unique_ptr<RangeMinimumQuery<T>>>(no_elem/block_size+1+(no_elem%block_size==0?0:1)); 
     size_t M = rmq_blocks.size()-1; //minus room for summary block 
     
     vector<T> summary(M);		
     size_t S = 0,L; 
     vector<T> tmp;
     while(S<M)
     {  L = minr(no_elem-1,(S+1)*block_size-1);
        tmp = vector<T>(V.begin()+S*block_size,V.begin()+L+1);
        rmq_blocks[S] = make_unique<RangeMinimumQuerySparse<T>>(tmp);
        summary[S]=tmp[min_(tmp,0,tmp.size()-1)];
        S++;
     }
     rmq_blocks[S] = make_unique<RangeMinimumQuerySparse<T>>(summary);  
   }
   else
   { elements = V;
   } 
}
template<typename T>
T RangeMinimumQueryHybrid<T>::range_minimum(size_t index_a, size_t index_b)const
{ if(index_a >= no_elem) throw std::out_of_range("index_a out of bound");
  if(index_b >= no_elem) throw std::out_of_range("index_b out of bound");
  if(index_a > index_b) throw std::out_of_range("index_a > index_b");

  T minv;
  if(no_elem >= MIN_SIZE_VECTOR)
  { size_t block_a = index_a/block_size;
    size_t end_a = minr(no_elem-1,(block_a+1)*block_size-1);
    size_t block_b = index_b/block_size;
    size_t start_b = block_b*block_size;

    if(block_a == block_b)
    {
      minv = rmq_blocks[block_a]->range_minimum(index_a%block_size,index_b%block_size);
    }
    else
    { minv = minr( rmq_blocks[block_a]->range_minimum(index_a%block_size,end_a%block_size),
                   rmq_blocks[block_b]->range_minimum(start_b%block_size,index_b%block_size)
                 );
      if(block_b-block_a>1)
      { minv = minr(minv, rmq_blocks[rmq_blocks.size()-1]->range_minimum(block_a+1,block_b-1));
      } 
    }
  }
  else
  { minv = elements[min_(elements,index_a,index_b)];
  }

  return minv;
}
template<typename T>
void RangeMinimumQueryHybrid<T>::find_block_size()
{ size_t lg = log2(no_elem)/4;
  block_size = (lg>5?lg:lg*4); 
}



