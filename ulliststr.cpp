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
  tail_->val[tail_->first] = val;
  tail_->last += 1;
  size_ += 1; 
}
void ULListStr::pop_back()
{
  if (head_ == nullptr & tail_==nullptr) //if it is an empty list
    return;
  else if (tail_->last == 1) //deallocate tail if there is only one string
  {
    Item* Item = new ULListStr::Item();
  }
}
// WRITE YOUR CODE HERE
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
