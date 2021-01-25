template<typename T>
RangeMinimumQueryFischer<T>::RangeMinimumQueryFischer()
{
}
template<typename T>
RangeMinimumQueryFischer<T>::RangeMinimumQueryFischer(const vector<T>& V)
{build(V);
}
template<typename T>
void RangeMinimumQueryFischer<T>::build(const vector<T>& V)
{ 
  this->no_elem = V.size();
  this->elements = V;
  this->rmq_blocks.clear();
  this->summary_position.clear();
  this->block_size = 0;
  block_structures.clear();
  if(this->no_elem >= this->MIN_SIZE_VECTOR)
  {
    this->find_block_size();
    size_t M = this->no_elem/this->block_size + (this->no_elem%this->block_size==0?0:1);
    this->block_structures = vector<size_t>(M);
    this->summary_position = vector<size_t>(M);
    vector<T> summary(M);
    vector<T> tmp;
    size_t S=0,L;
    string cartesian_number="";
    map<string,int> map_cn;
    while(S<M)
    { L = minr(this->no_elem-1,(S+1)*this->block_size-1);
      tmp = vector<T>(V.begin()+S*this->block_size,V.begin()+L+1);
      find_cartesian_number(cartesian_number,S);
      if(map_cn.find(cartesian_number)==map_cn.end())
      { 
        this->rmq_blocks.push_back(make_unique<RangeMinimumQuerySparse<T>>(tmp));
        block_structures[S]=this->rmq_blocks.size()-1;  
        map_cn.emplace(cartesian_number,this->rmq_blocks.size()-1);
      }
      else
      {
        block_structures[S]=map_cn[cartesian_number];
      }
      size_t pos = min_(tmp,0,tmp.size()-1);
      this->summary_position[S]=pos;
      summary[S]=tmp[pos]; 
      S++;
    }
    this->rmq_blocks.push_back(make_unique<RangeMinimumQuerySparse<T>>(summary)); 
  }
}
template<typename T>
void RangeMinimumQueryFischer<T>::find_cartesian_number(string& cartesian_number,size_t index_block)
{ stack<T> S;
  size_t L = minr((index_block+1)*this->block_size-1,this->no_elem-1);
  cartesian_number="1";
  S.push(this->elements[index_block*this->block_size]);
  size_t i = index_block*this->block_size+1;
  while(i<=L)
  { while(!S.empty() && this->elements[i]<S.top())
    { S.pop();
      cartesian_number+="0";
    }
    S.push(this->elements[i]);
    cartesian_number+="1";
    i++;
  }  
  while(!S.empty())
  {cartesian_number+="0";
   S.pop();
  }
}
template<typename T>
size_t RangeMinimumQueryFischer<T>::range_minimum_position(size_t index_a, size_t index_b)const
{ if(index_a >= this->no_elem) throw std::out_of_range("index_a out of bound");
  if(index_b >= this->no_elem) throw std::out_of_range("index_b out of bound");
  if(index_a > index_b) throw std::out_of_range("index_a > index_b");
  size_t minp;
  if(this->no_elem >= this->MIN_SIZE_VECTOR)
  { size_t block_a = index_a/this->block_size;
    size_t end_a = minr(this->no_elem-1,(block_a+1)*this->block_size-1);
    size_t block_b = index_b/this->block_size;
    size_t start_b = block_b*this->block_size;

    if(block_a == block_b)
    {
      minp = block_a*this->block_size + this->rmq_blocks[block_structures[block_a]]->range_minimum_position(index_a%this->block_size,
                                                                                               index_b%this->block_size);
    }
    else
    { size_t ba = block_a*this->block_size + this->rmq_blocks[block_structures[block_a]]->range_minimum_position(index_a%this->block_size,
                                                                                               end_a%this->block_size);
      size_t bb = block_b*this->block_size + this->rmq_blocks[block_structures[block_b]]->range_minimum_position(start_b%this->block_size,
                                                                                                     index_b%this->block_size);
      minp = minu(ba,bb,this->elements);

      if(block_b-block_a>1)
      { size_t Q =  this->rmq_blocks[this->rmq_blocks.size()-1]->range_minimum_position(block_a+1,block_b-1);
        Q = Q*this->block_size + this->summary_position[Q];
        minp = minu(minp, Q,this->elements);
      } 
    }
  }
  else
  { minp = min_(this->elements,index_a,index_b);
  }
  return minp;
}
