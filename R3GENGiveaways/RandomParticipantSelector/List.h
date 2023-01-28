
template <typename data_t>
class DLinkedList {
public:
	/**
	 * Struct:		Node
	 * Purpose:		Structure to hold data for the list and maintains a reference to the
	 *				prior and next list
	 */
	struct Node {
		Node* left_;
		Node* right_;
		data_t* data_;

		Node(data_t* data)
			: left_(nullptr), right_(nullptr), data_(data) {};
	};
	/**
	 * Struct:		Iterator
	 * Purpose:		Structure to iterate and access data within the list
	 */
	struct Iterator {
		Node* ptr_;
		Iterator(Node* node) : ptr_(node) {};
		void move_left() { ptr_ = ptr_->left_; };
		void move_right() { ptr_ = ptr_->right_; };
		Node* next() { return ptr_ != nullptr ? ptr_->right_ : nullptr; };
		Node* prev() { return ptr_ != nullptr ? ptr_->left_ : nullptr; };
		data_t* left_entry() { return ptr_->left_->data_; };
		data_t* right_entry() { return ptr_->right_->data_; };
	};
	/**
	 * Default Constructor:
	 * Provides a list with two null pointers and a count of 0
	 */
	DLinkedList()
		: firstNode_(nullptr), lastNode_(nullptr), count_(0) {};
	/**
	 * Constructor:
	 * Provides a list with a single node and a count of 1
	 */
	DLinkedList(Node* data)
		: firstNode_(data), lastNode_(nullptr), count_(1) {
		firstNode_->right_ = lastNode_;
	};
	/**
	 * Copy Constructor:
	 * Provides a list from a list
	 */
	DLinkedList(DLinkedList& list) : count_(0) {
		firstNode_ = list.get_first();
		lastNode_ = list.get_last();
		Iterator itr = Iterator(firstNode_);
		while (itr.ptr_ != nullptr) {
			count++;
			itr.move_right();
		}
	}
	/**
	 * Function:	count()
	 * Returns:		unsigned integer value that represents the size of the list
	 */
	unsigned count() { return count_; }
	/**
	 * Function:	add_entry()
	 * Parameters:	Node*
	 * Purpose:		Add's node either to the first unassigned node.
	 */
	void add_entry(Node* node) {
		if (firstNode_ != nullptr) {
			if (lastNode_ != nullptr) {
				Iterator itr = Iterator(lastNode_);
				lastNode_ = node;
				lastNode_->left_ = itr.ptr_;
				itr.ptr_->right_ = lastNode_;
			}
			else {
				lastNode_ = node;
				lastNode_->left_ = firstNode_;
				firstNode_->right_ = lastNode_;
			}
		}
		else { 
			firstNode_ = node;
			firstNode_->right_ = lastNode_;
		}
		count_++;
	};
	/**
	 * Function:	add_entry()
	 * Parameters:	Node*, Iterator&
	 * Purpose:		Add's a node at the location of the iterator
	 */
	void add_entry(Node* node, Iterator& itr) {
		if (firstNode_ != nullptr) {
			if (lastNode_ != nullptr) {
				Node* glass = itr.prev();
				node->left_ = glass;
				node->right_ = itr.ptr_;
				
				itr.ptr_->left_ = node;
				if(glass != nullptr)
					glass->right_ = node;
				else
					firstNode_ = node;
			}
			else {
				lastNode_ = firstNode_;
				firstNode_ = node;
				lastNode_->left_ = firstNode_;
				lastNode_->right_ = nullptr;
				firstNode_->right_ = lastNode_;
				firstNode_->left_ = nullptr;
			}
		}
		else {
			firstNode_ = node;
			firstNode_->right_ = lastNode_;
		}
		count_++;
	};
	//void remove_entry(data_t*);
	/**
	 * Function:	get_first()
	 * Returns:		The node at the front of the list.
	 */
	Node* get_first() { return firstNode_; }
	/**
	 * Function:	get_last()
	 * Returns:		The node at the end of the list.
	 */
	Node* get_last() { return lastNode_; }

	~DLinkedList() {
		Iterator itr = Iterator(firstNode_);
		if(itr.ptr_ != nullptr){
			while (itr.next() != nullptr) {
				delete itr.ptr_->left_;
				itr.move_right();
				delete itr.left_entry();
			}
			delete itr.prev();
			delete itr.ptr_->data_;
			delete itr.ptr_;
		}
		else {
			free(firstNode_);
			free(lastNode_);
		}
	};

private:

	Node* firstNode_;

	Node* lastNode_;

	unsigned count_;
};