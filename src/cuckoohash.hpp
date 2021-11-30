#ifndef CUCKOO_HASH_HPP
#define CUCKOO_HASH_HPP

#include <vector>

class CuckooHash{
	private:
		size_t slot
		std::vector<int> table;
	public:
		CuckooHash(size_t slotx):slot(slotx),table(std::vector<int>(slotx,-1)){
		}
		void insert(int kx){}
		bool search(int kx){
			return false;
		}
};
#endif
