#ifndef SPRANGE_MINIMUM_QUERY_HPP
#define SPRANGE_MINIMUM_QUERY_HPP

#include <vector>
#include <memory>
#include <stdexcept>

template<typename T>
class PRangeMinimumQuery 
{ 	
        protected:
		 const std::vector<T>* pElements;

		 void check_range(size_t index_a,size_t index_b)const{
                    if(index_a >= (*pElements).size()) throw std::out_of_range("index_a out of bound");
                    if(index_b >= (*pElements).size()) throw std::out_of_range("index_b out of bound");
                    if(index_a > index_b) throw std::out_of_range("index_a > index_b");
		 }
	public:
		PRangeMinimumQuery():pElements(nullptr)
		{}
		PRangeMinimumQuery(const std::vector<T>* elements)
			:pElements(elements)
		{}
		~PRangeMinimumQuery(){
			pElements = nullptr;
		}
		virtual void preprocess(const std::vector<T>* elements)=0;
		virtual size_t find_range_minimum(size_t index_a, size_t index_b)const=0;
		size_t min(size_t i, size_t j)const{
			 size_t k = i;
			 while(i<j+1){
				 if((*pElements)[k] > (*pElements)[i])
					 k =i;
				 i++;
			 }
			 return k;
		 }
		void setElements(const std::vector<T>* elements){
			pElements = elements;
		}
};
#endif


#ifndef RANGE_MINIMUM_QUERY_HPP
#define RANGE_MINIMUM_QUERY_HPP
template<typename T>
class RangeMinimumQuery 
{ 	
        protected:
		 std::vector<T> elements;

		 void check_range(size_t index_a,size_t index_b)const{
                    if(index_a >= elements.size()) throw std::out_of_range("index_a out of bound");
                    if(index_b >= elements.size()) throw std::out_of_range("index_b out of bound");
                    if(index_a > index_b) throw std::out_of_range("index_a > index_b");
		 }
	public:
		RangeMinimumQuery(){}
		RangeMinimumQuery(const std::vector<T>& element):elements(element){}
		virtual void preprocess(const std::vector<T>& element)=0;
		virtual size_t find_range_minimum(size_t index_a, size_t index_b)const=0;
		size_t min(size_t i, size_t j)const{
			 size_t k = i;
			 while(i<j+1){
				 if(elements[k] > elements[i])
					 k =i;
				 i++;
			 }
			 return k;
		 }
		void setElements(const std::vector<T>& element){
			elements = element;
		}
};
#endif



