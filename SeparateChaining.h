#ifndef SEPARATE_CHAINING_H_
#define SEPARATE_CHAINING_H_

#include <vector>
#include <string>
#include "LinkedList.h"
#include "SeparateChainingAux.h"

using namespace std;

// SeparateChaining Hash table class
//
// CONSTRUCTION: an initialization for ITEM_NOT_FOUND
//               and an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Hashable find( x )     --> Return item that matches x
// void makeEmpty( )      --> Remove all items
// int hash( string str, int tableSize )
//                        --> Global method to hash strings

template <class HashedObj>
class HashTable
{
  public:
   
   HashTable();
   
   explicit HashTable( const HashedObj & notFound, int size);
   
   HashTable( const HashedObj & notFound);
   
   HashedObj & find( const HashedObj & x );
   
   HashedObj & find(int x );
   
   void makeEmpty( );
   void insert( const HashedObj & x );
   void remove( const HashedObj & x );
   
   const HashTable & operator=( const HashTable & rhs );
   
  private:
   HashedObj ITEM_NOT_FOUND;
   vector<List<HashedObj> > theLists;   // The array of Lists
};

#include "SeparateChaining.cpp"
#endif
