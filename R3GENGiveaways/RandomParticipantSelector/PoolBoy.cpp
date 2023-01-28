#include "PoolBoy.h"

PoolBoy::PoolBoy(std::fstream& file, RNGenerator& randGen)
	: contests_(nullptr), randGen_(randGen), numOfContests_(0) {
	std::string contestInfo;
	DLinkedList<Entry>* list = new DLinkedList<Entry>();

	while (file >> contestInfo) {
		if (contestInfo != "ContestTitle:") {	
			file >> contestInfo;
			int i;
			file >> i;
			for (int j = 0; j < i; j++) {
			Entry* entry = new Entry(contestInfo, randGen_.get_float());
			Iterator itr = Iterator(list->get_first());
			bool append = true;
			if (itr.ptr_ != nullptr) {
				while (itr.ptr_ != nullptr) {
					if (*itr.ptr_->data_ > *entry) {
						append = false;
						break;
					}
					itr.move_right();
				}
			}
			!append
				? list->add_entry(new Node(entry), itr)
				: list->add_entry(new Node(entry));
			}
		}
		else {
			const int SIZE = 25;
			char* title = new char[SIZE];
			file.ignore(1);
			file.getline(title, SIZE, '\n');
			if (contests_ != nullptr) {
				EntryPool* ptr = contests_;
				while (ptr->get_next() != nullptr) {
					ptr = ptr->get_next();
				}
				ptr->assign_next(new EntryPool(title, list));
			}
			else {
				contests_ = new EntryPool(title, list);
			}
			delete[] title;
			numOfContests_++;
			list = new DLinkedList<Entry>();
		}
	}
	delete list;
}

EntryPool* PoolBoy::get_pool() { return contests_; }

Entry* PoolBoy::get_winners() {
	EntryPool* currentPool = contests_;
	Entry* entry = nullptr;
	while (currentPool != nullptr) {
		Entry* nextWinner = currentPool->pick_winner(
			randGen_.get_int(
				currentPool->get_entries()->count() - 1));
		if (entry != nullptr) {
			Entry* itr = entry;
			while (itr->get_next() != nullptr) {
				itr = itr->get_next();
			}
			itr->set_ptr(nextWinner);
		}
		else { entry = nextWinner; }
		currentPool = currentPool->get_next();
	}
	return entry;
}

PoolBoy::~PoolBoy() {
	while (contests_ != nullptr) {
		EntryPool* deleteMe = contests_;
		contests_ = contests_->get_next();
		delete deleteMe;
	}
	delete contests_;
}