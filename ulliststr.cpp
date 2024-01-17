#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if (head_ == nullptr & tail_==nullptr) //if it is an empty list
  {
    Item* Item = new ULListStr::Item();
    head_ = Item;
    tail_ = Item;
  }
  else if (tail_->last == ARRSIZE) //initialize a new Item if there is no room
  {
    Item* Item = new ULListStr::Item();
    tail_->next = Item;
    Item->prev = tail_;
    tail_ = Item;
  }
  tail_->last += 1;
  tail_->val[tail_->last-1] = val;
  size_ ++; 
}

void ULListStr::pop_back()
{
  if (head_ == nullptr && tail_==nullptr) //if it is an empty list
    return;
  
  // Case where the tail node has only one element
  if (tail_->last - tail_->first <= 1) 
  {
    Item* prev = tail_->prev;
    delete tail_;
    if (prev != nullptr)
    {
      prev->next = nullptr;
      tail_ = prev;
    }
    else // The list had only one node
    {
      head_ = nullptr;
      tail_ = nullptr;
    }
  }
  else //stop maintaining the last element
  {
    tail_->last--;
  }
  size_--;
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise, 
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string& val)
{
  if(head_ == nullptr && tail_ == nullptr) //empty list
  {
    Item* newItem = new ULListStr::Item();
    head_ = newItem;
    tail_ = newItem;
    head_->last = 1; // Since this is a new node, set last to 1
  }
  else if(head_->first == 0) //full head node
  {
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    head_->last = 1; // Since this is a new node, set last to 1
  }
  else //space before first
  {
    head_->first --;
  }
  head_->val[head_->first] = val;
  size_++;
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front()
{
  if (head_ == nullptr && tail_ == nullptr) //empty list
    return;
  
  if (head_->last - head_->first <= 1) //a head with only element
  {
    Item* next = head_->next;
    delete head_;
    head_ = next;
    if (head_ != nullptr)
    {
      head_->prev = nullptr;
    }
    else //head == tail
    {
      tail_ = nullptr;
    }
  }
  else
  {
    head_->first++;
  }
  size_ --;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_) {
    return nullptr; // loc is out of bounds
  }
  Item* cur = head_;
  while (cur != nullptr)
  {
    size_t numElementsInCurItem = cur->last - cur->first;
    if (loc < numElementsInCurItem)
    {
      return &(cur->val[cur->first + loc]);
    }
    loc -= numElementsInCurItem;
    cur = cur->next;
  }

  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
