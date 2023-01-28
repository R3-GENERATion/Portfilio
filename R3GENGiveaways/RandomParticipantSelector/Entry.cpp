#include "Entry.h"

Entry::Entry(std::string name, float seed)
	: name_(name), seed_(seed), ptr_(nullptr) {}

std::string Entry::get_name() { return name_; }

void Entry::set_name(std::string name) { name_ = name; }

Entry* Entry::get_next() { return ptr_; }

void Entry::set_ptr(Entry* ptr) { ptr_ = ptr; }

bool Entry::operator>(Entry& entry) { return seed_ > entry.seed_; };

bool Entry::operator<(Entry& entry) { return seed_ < entry.seed_; };

std::ostream& operator<<(std::ostream& os, Entry& entry) {
	return os << entry.get_name();
}
