/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 * https://en.wikipedia.org/wiki/Doubly_linked_list
 */

// Constructor
template <class T>
List<T>::List():head_(NULL),tail_(NULL),length_(0)
{}
// List<T>::List() { 
//   // @TODO: graded in MP3.1
//   ListNode* head_ = NULL;
//   ListNode* tail_ = NULL;
//   length_ = 0; 
// }

// Destructor ~List() is given in List-given.hpp and it calls _destroy()

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  // The _destroy() function should free all memory allocated for ListNode objects

  int len = this->length_; // get the length of the whole linked list

  ListNode *current = NULL;
  ListNode *next = NULL;

  current = this->head_;   // get the head_ of the linked list

  while(len > 1){ // need to free ListNode
    next = current->next; // store next node info
    delete current;
    current = next;       // update current
    len = len - 1;
  }

  if(len == 1){ // reach the tail node
    current = this->tail_;
    delete current;
  }

  current = NULL;
  next = NULL;
  this->head_ = NULL;
  this->tail_ = NULL;
  this->length_ = 0;

}


/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(this->head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {

  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata); 

  // List<T>::ListNode::ListNode(const T& ndata) : next(NULL), prev(NULL), data(ndata)
  // newNode->next and newNode->prev will be initialized to NULL

  // the linked list is empty, add only one node to the linked list
  if(this->head_ == NULL){

    this->head_ = newNode; 
    this->tail_ = newNode; 

  } else {
    // the linked list at least has one node
    this->head_-> prev = newNode;
    newNode->next = this->head_;
    this->head_ = newNode;
  }

  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {

  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata); 

  // List<T>::ListNode::ListNode(const T& ndata) : next(NULL), prev(NULL), data(ndata)
  // newNode->next and newNode->prev will be initialized to NULL

  // the linked list is empty, add only one node to the linked list
  if(this->head_ == NULL){

    this->head_ = newNode; 
    this->tail_ = newNode; 

  } else {

    // the linked list at least has one node
    this->tail_-> next = newNode;
    newNode->prev = this->tail_;
    this->tail_ = newNode;

  }

  length_++;

}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */

// template <typename T>
// List<T> List<T>::split(int splitPoint) {
    
//     if (splitPoint > length_)
//         return List<T>();

//     if (splitPoint < 0)
//         splitPoint = 0;

//     ListNode * secondHead = split(head_, splitPoint);

//     int oldLength = length_;
//     if (secondHead == head_) {
//         // current list is going to be empty
//         head_ = NULL;
//         tail_ = NULL;
//         length_ = 0;
//     } else {
//         // set up current list
//         tail_ = head_;
//         while (tail_ -> next != NULL)
//             tail_ = tail_->next;
//         length_ = splitPoint;
//     }

//     // set up the returned list
//     List<T> ret;
//     ret.head_ = secondHead;
//     ret.tail_ = secondHead;
//     if (ret.tail_ != NULL) {
//         while (ret.tail_->next != NULL)
//             ret.tail_ = ret.tail_->next;
//     }
//     ret.length_ = oldLength - splitPoint;
//     return ret;
// }

template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {

  /// @todo Graded in MP3.1
  ListNode * curr = start;

  if(curr == NULL){
    return NULL;
  }

  if(splitPoint == 0){
    return curr;
  }

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
      curr = curr->next;
  }

  if(curr != NULL) {
    curr->prev->next = NULL;
    curr->prev = NULL;
  }

  return curr;

}



/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1

  // Empty linked list
  if(this->head_ == NULL){
    return;
  }

  // The linked list has only one node
  if(this->length_ == 1){
    return;
  }

  // The linked list has more than two nodes
  ListNode* curr = head_->next;     // the second node
  ListNode* next_hold = NULL;

  while(curr != NULL && curr->next != NULL){

    // Delete the current node and link its prenode with its next node
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;

    // Hold the node's which to remove next
    next_hold = curr->next->next; 

    // Move current node to tail
    curr->prev = this->tail_;
    this->tail_->next = curr;
    curr->next = NULL;

    // Update the tail pointer
    this->tail_ = curr; 

    if(next_hold != NULL){
      curr = next_hold;
    }

  }

}



/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {

  /// @todo Graded in MP3.2

  // reverse a chain of linked memory beginning at startPoint and ending at endPoint.
  // startPoint and endPoint pointers should point at the new start and end of the chain of linked memory.

  // the next member of the ListNode before the sequence should point at the new start
  // the prev member of the ListNode after the sequence should point to the new end

  // it may be called to reverse only parts of a given 
  // write this function iteratively

  if(startPoint == endPoint){
    return;
  }

  if(startPoint == NULL || endPoint == NULL){
    return;
  }

  ListNode *curr = startPoint;
  ListNode *curr_next = endPoint->next;

  // startPoint is not the head of the list
  if(startPoint->prev != NULL){
    // store the location of the endNode
    startPoint->prev->next = endPoint;
  }

  // endPoint is not the tail of the list
  if(endPoint->next != NULL){
    // store the location of the startNode
    endPoint->next->prev = startPoint;
  } 

  endPoint->prev = startPoint->prev;

  while(curr != endPoint){
    curr->prev = curr->next;
    curr->next = curr_next;
    curr_next = curr;
    curr = curr->prev;
  }

  curr->next = curr_next;
  endPoint = startPoint;
  startPoint = curr;

}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {

  /// @todo Graded in MP3.2

  if(this->length_ == 0){
    return;
  }

  if(n >= this->length_){

    ListNode* startPoint = this->head_;
    ListNode* endPoint = this->tail_;

    reverse(startPoint , endPoint);

    this->head_ = startPoint;
    this->tail_ = endPoint;

  } else {

    // 1 < n < this->length_

    int iters = this->length_/n;
    int iters_left = this->length_%n;

    ListNode* startPoint = this->head_;
    ListNode* endPoint = this->head_;

    int count = 0;

    while (count < iters){

      endPoint = startPoint;

      for(int i = 0; i < n-1; i++){
          endPoint = endPoint->next;
      }
      
      if(count == 0){
        reverse(this->head_, endPoint);
      } else {
        reverse(startPoint, endPoint);
      }

      startPoint = endPoint->next;
      count += 1;
    
    }

    if(iters_left != 0){
      endPoint = this->tail_;
      reverse(startPoint, endPoint);
      this->tail_ = endPoint;
    } else {
      this->tail_ = endPoint;
    }

  }
    
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {

    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }

    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {

  /// @todo Graded in MP3.2

  if(first == NULL && second == NULL){
    return NULL;
  }

  if(first != NULL && second == NULL){
    return first;
  }

  if(first == NULL && second != NULL){
    first = second;
    second = NULL;
    return first;
  }

  if(first != NULL && second != NULL && first == second){
    second = NULL;
    return first;
  }

  // first != second != NULL
  // first and second are both sorted

  ListNode* curr_first = first;
  ListNode* curr_second = second;
  ListNode* curr_second_next = NULL;

  bool finished = false;

  while (curr_second != NULL) {

    curr_second_next = curr_second->next;

    while (curr_first != NULL) {

      if (curr_second->data < curr_first->data) {

        // Initial compare, first node of first linked linked and second node of second linked list
        if (first == curr_first && second == curr_second){

          first = curr_second;
          curr_second->next = curr_first;
          curr_first->prev = curr_second;
          curr_second = curr_second_next;

        } else{

          curr_second->next = curr_first;
          curr_first->prev->next = curr_second;
          curr_second->prev = curr_first->prev;
          curr_first->prev = curr_second;
        }

        if (curr_second_next!=NULL) {
            curr_second_next->prev = NULL;
        }

        break;

      } else {

        if (curr_first->next == NULL) {

          finished = true;

          if(curr_second != NULL){
            curr_first->next = curr_second;
            curr_second->prev = curr_first;
          }
          
          break;

        } else {

          curr_first = curr_first->next;

        }
          
      }

    }

    if (finished == true) {

      return first;

    } else {

      curr_second = curr_second_next;

    }

  }

  return first;

}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {

  /// @todo Graded in MP3.2


  if (start == NULL || chainLength == 1){

    return start;

  } else {

    // chainLength > 1

    int splitPoint = chainLength/2;
    int toTailPoint = chainLength-splitPoint;

    ListNode* start_2 = split(start, splitPoint);
    start = mergesort(start, splitPoint); 
    start_2  = mergesort(start_2, toTailPoint);

    return merge(start, start_2);

  }

}
