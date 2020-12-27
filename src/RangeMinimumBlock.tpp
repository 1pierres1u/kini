template<class T>
void RangeMinimumBlock<T>::build_block_of_minima()
{return T();
}
template<class T>
RangeMinimumBlock<T>::RangeMinimumBlock()
{
}
template<class T>
RangeMinimumBlock<T>::RangeMinimumBlock(const RangeMinimumBlock& r):elements(r.elements),
                      blockSize(r.blockSize),blockOfMinima(r.blockOfMinima)
{
}
template<class T>
RangeMinimumBlock<T>::RangeMinimumBlock(RangeMinimumBlock&& r):elements(std::move(r.elements)),
                      blockOfMinima(std::move(r.blockOfMinima)),blockSize(std::move(blockSize))
{
}
template<class T>
RangeMinimumBlock<T>::RangeMinimumBlock(const vector<T>& vElements)
{
}
template<class T>
RangeMinimumBlock<T>::RangeMinimumBlock(size_t sBlockSize, const vector<T>& vElements)
{
}
template<class T>
void RangeMinimumBlock<T>::build(const vector<T>& vElements)
{
}
template<class T>
void RangeMinimumBlock<T>::build(size_t sBlockSize, const vector<T>& vElements)
{
}
template<class T>
T RangeMinimumBlock<T>::range_minimum(size_t index_a,size_t index_b)const
{return T();
}
template<class T>
size_t RangeMinimumBlock<T>::blockSize_()const noexcept
{return 0;
}
template<class T>
vector<T> RangeMinimumBlock<T>::blockOfMinima_()const noexcept
{return vector<T>();
}

