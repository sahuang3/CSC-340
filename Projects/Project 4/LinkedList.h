//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

//
//  Updated by Ngoc Lam-Miller for CSC340.02 Spring 2022
//

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"
#include <iostream>
#include <cassert>


template<class ItemType>
class LinkedList : public ListInterface<ItemType> {

template<class friendItemType>
friend std::ostream& operator<<(std::ostream& outStream,
  const LinkedList<friendItemType>& outputList);

public:
  LinkedList();
  LinkedList(const LinkedList<ItemType>& aList);  ///TODO
  virtual ~LinkedList();

  // overloaded function
  LinkedList<ItemType>& operator=(const LinkedList<ItemType>& rhs);  ///TODO
  LinkedList<ItemType>& operator+(const LinkedList<ItemType>& rhs) const;  ///TODO
  bool operator==(const LinkedList<ItemType>& rhs) const;  ///TODO

  bool isEmpty() const;
  int getLength() const;
  bool insert(int newPosition, const ItemType& newEntry);
  bool remove(int position);
  void clear();

  /** @throw PrecondViolatedExcept if
   *    position < 1 or position > getLength(). */
  ItemType getEntry(int position) const;

  /** @throw PrecondViolatedExcept if
   *    position < 1 or position > getLength(). */
  ItemType replace(int position, const ItemType& newEntry);
    

private:
  Node<ItemType>* headPtr; // Pointer to first node in the chain;
                           // (contains the first entry in the list)
  int itemCount;           // Current count of list items

  // Locates a specified node in this linked list.
  // @pre  position is the number of the desired node;
  //       position >= 1 and position <= itemCount.
  // @post  The node is found and a pointer to it is returned.
  // @param position  The number of the node to locate.
  // @return  A pointer to the node at the given position.
  Node<ItemType>* getNodeAt(int position) const;

}; // end LinkedList

#endif


//-------------------------------------------------------------------
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor


///TODO: your implementation of copy constructor
template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
  Node<ItemType>* origPtr = aList.headPtr;
  if(origPtr == nullptr){
    headPtr = nullptr;
  } else{
    headPtr = new Node<ItemType>();
    headPtr->setItem(origPtr->getItem());
    Node<ItemType>* newPtr = headPtr;
    
    while(origPtr != nullptr){
      origPtr = origPtr->getNext();
      if(origPtr == nullptr){
        newPtr->setNext(nullptr);
        break;
      }
      ItemType next = origPtr->getItem();
      Node<ItemType>* newNodePtr = new Node<ItemType>(next);
      newPtr->setNext(newNodePtr);
      newPtr = newPtr->getNext();
    }
    newPtr->setNext(nullptr);
  }
}

///TODO: your implementation of assignment operator
template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& rhs){
  if(this != &rhs){
    if(headPtr != NULL){
      headPtr = NULL;
    }
    Node<ItemType>* copyPtr = NULL;
    Node<ItemType>* origPtr = rhs.headPtr;
    while(origPtr != NULL){
      if(headPtr == NULL){
        headPtr = copyPtr = new Node<ItemType>(origPtr->getItem());
      } else{
        copyPtr->setNext(new Node<ItemType>(origPtr->getItem()));
        copyPtr = copyPtr->getNext();
      }
      origPtr = origPtr->getNext();
    }
  }
  return *this;
}

///TODO: your implementation of operator+
template<class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator+(const LinkedList<ItemType>& rhs) const{
  
  LinkedList<ItemType> temp;
  Node<ItemType>* ptr = this->headPtr;
  Node<ItemType>* ptr2 = rhs.headPtr;
  Node<ItemType>* next = ptr->getNext();
  int count = 0;
  while(ptr != nullptr){
    temp.insert(count, ptr->getItem());
    count++;
    ptr = ptr->getNext();
  }
  while(ptr2 != nullptr){
    temp.insert(count, ptr2->getItem());
    count++;
    ptr2 = ptr2->getNext();
  }
 return temp;
 
}

///TODO: your implementation of operator==
template<class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rhs) const{
  if(itemCount != rhs.itemCount){
    return false;
  }
  if(headPtr == nullptr && rhs.headPtr == nullptr){
    return true;
  }
  Node<ItemType>* temp = headPtr;
  Node<ItemType>* temp2 = rhs.headPtr;
  while(temp != nullptr){
    if(temp->item != temp2->item){
      return false;
    }
    temp = temp->next;
    temp2 = temp2->next;
  }
  return true;
}

///TODO: your implementation of replace function
template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
  Node<ItemType> temp;
  Node<ItemType>* ptr = headPtr;
  Node<ItemType>* next;
  if(position > itemCount){
    throw(PrecondViolatedExcept());
  }
  for(int i=1; i<position; i++){
    ptr = ptr->getNext();
    next = ptr->getNext();
  }
  ptr->setItem(newEntry);
  ptr->setNext(next);
  temp.setItem(ptr->getItem());
  temp.setNext(NULL);
  return temp.getItem();
}



template<class friendItemType>
std::ostream& operator<<(std::ostream& outStream,
  const LinkedList<friendItemType>& outputList)
{
  int position = 1;
  Node<friendItemType>* curPtr = outputList.headPtr;
  while (curPtr != nullptr) {
    outStream << curPtr->getItem() << "(" << position << ") -> ";
    curPtr = curPtr->getNext();
    position++;
  }
  outStream << "nullptr";
  return outStream;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
} // end destructor

//---------------------------------------------------


template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
  return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
  return (itemCount == 0);
}


//--------------------------
template<class ItemType>
void LinkedList<ItemType>::clear()
{
  while (!isEmpty())
    remove(1);
} // end clear


template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
  bool ableToRemove = (position >= 1) && (position <= itemCount);
  if (ableToRemove) {
     Node<ItemType>* curPtr = nullptr;
     if (position == 1) {
       // Remove the first node in the chain
       curPtr = headPtr; // Save pointer to node
       headPtr = headPtr->getNext();
     }
     else {
       // Find node that is before the one to remove
       Node<ItemType>* prevPtr = getNodeAt(position - 1);

       // Point to node to remove
       curPtr = prevPtr->getNext();

       // Disconnect indicated node from chain by connecting the
       // prior node with the one after
       prevPtr->setNext(curPtr->getNext());
     }

     // Return node to system
     curPtr->setNext(nullptr);
     delete curPtr;
     curPtr = nullptr;
     itemCount--; // Decrease count of entries
  }

  return ableToRemove;
} // end remove



template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const

{
  // Enforce precondition
  bool ableToGet = (position >= 1) && (position <= itemCount);
  if (ableToGet) {
     Node<ItemType>* nodePtr = getNodeAt(position);
     return nodePtr->getItem();
  }
  else {
     std::string message = "getEntry() called with an empty list or ";
     message = message + "invalid position.";
     throw(PrecondViolatedExcept(message));
  }
} // end getEntry


template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
  // Debugging check of precondition
  assert( (position >= 1) && (position <= itemCount) );

  // Count from the beginning of the chain
  Node<ItemType>* curPtr = headPtr;
  for (int skip = 1; skip < position; skip++)
    curPtr = curPtr->getNext();

  return curPtr;
}  // end getNodeAt


template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }

      itemCount++;
      }

   return ableToInsert;
}  // end insert
