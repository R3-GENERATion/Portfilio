#include "EntryPool.h"

EntryPool::EntryPool() : entries_(), nextPool_(nullptr) {}

EntryPool::EntryPool(std::string name, DLinkedList<Entry>* list)
	: contestName_(name), nextPool_(nullptr) { entries_ = list; };

std::string EntryPool::get_name() { return contestName_; };

DLinkedList<Entry>* EntryPool::get_entries() { return entries_; };

Entry* EntryPool::pick_winner(int pos) {
	Iterator itr = Iterator(entries_->get_first());
	for (int i = 0; i < pos; i++) {
		itr.move_right();
	}
	return winner_ = itr.ptr_->data_;
}

Entry* EntryPool::get_winner() { return winner_; }

EntryPool* EntryPool::get_next() { return nextPool_; }

void EntryPool::assign_next(EntryPool* pool) { nextPool_ = pool; }

std::ostream& operator<<(std::ostream& os, EntryPool& pool) {
	return os << pool.get_name() << "    " << *pool.get_winner();
};