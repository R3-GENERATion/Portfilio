#include "Node.h"
#include <crtdbg.h>

template <typename data_t>
Node<data_t>::Node(data_t* data) :
	data_(data), left_(nullptr), right(nullptr) {};

Node<data_t>::~Node() {
	free(node_->left);
}