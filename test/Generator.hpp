#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <map>
#include <vector>


enum Vector_Type{increasing,decreasing,shuffled};

template<typename T>
class Generator{
	private:
		//[1 - 999]: increasing vectors
		//[1000 - 1999]: decreasing vectors
		//[2000 - 2999]: shuffled vectors
		std::map<size_t,std::vector<T>> vectors;
		size_t last_inc_vect;
		size_t last_dec_vect;
		size_t last_shu_vect;
		const size_t MAX_NO_VECTORS=1000;


		//[1 - 2999]: ranges are associated with a given vector
		//[3000 - ...]: random ranges 
		std::map<size_t,std::vector<std::pair<size_t,size_t>>> ranges;
		size_t last_range_idx;
	public:
		//GENERATE VECTORS
		
		Generator():last_inc_vect(0),last_dec_vect(1000),
			last_shu_vect(2000)
		{
		}
		const std::vector<T>& generate_vector(size_t vector_size,Vector_Type vt=0){
			return std::vector<T>();
		}
		void generate_vector(size_t how_many,std::vector<size_t> sizes, Vector_Type vt=0){
			if(vt==0){//increasing
			}
			else if(vt==1){//decreasing
			}
			else{//shuffled
			}
		}
		void generate_vector(size_t how_many,size_t size,Vector_Type vt=0){
		
		}
		const std::vector<T>& get_vector(size_t idx)const{
			return std::vector<T>();
		}
		//0 is returned if no (inc,dec,shuf) vector was generated
		void clear_vector(Vector_Type vt){
		}
		void clear_vector(size_t idx){
		}
	        size_t  get_last_inc_vect(){
			return 0;
		}
		size_t  get_last_dec_vect(){
			return 0;
		}
		size_t  get_last_shu_vect(){
			return 0;
		}

		//GENERATE RANGES
		
		//generate a set of ranges associate to a vector generated
		void generate_range(size_t vector_idx,size_t length,size_t how_many){ //fixed-length range
		}
		void generate_range(size_t vector_idx,size_t how_many){ //random size range for a vector
		}
		void generate_range(size_t vector_idx, const std::vector<size_t> V){
		}
		void clear_range(size_t idx){
		}
		void clear_range(){
		}
		size_t get_last_range_idx(){
			return 0;
		}
};
#endif
