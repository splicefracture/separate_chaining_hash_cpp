#ifndef SEPARATECHAINING_CPP
#define SEPARATECHAINING_CPP

#include "SeparateChaining.h"
#include "SeparateChainingAux.h"
#include <iostream>

using namespace std;

template <class HashedObj>
HashTable<HashedObj>::HashTable()
{

}


/**
 * Construct the hash table.
 */
template <class HashedObj>
HashTable<HashedObj>::HashTable( const HashedObj & notFound, int size )
  : ITEM_NOT_FOUND( notFound ), theLists( nextPrime( size ) )
{
}

/**
 * Construct the hash table.
 */
template <class HashedObj>
HashTable<HashedObj>::HashTable( const HashedObj & notFound)
   : ITEM_NOT_FOUND( notFound ), theLists( nextPrime( 101) )
{
}

/**
 * Insert item x into the hash table. If the item is
 * already present, then do nothing.
 */
template <class HashedObj>
void HashTable<HashedObj>::insert( const HashedObj & x )
{
  List<HashedObj> & whichList = theLists[ x.getKey(theLists.size( ) ) ];
  ListItr<HashedObj> itr = whichList.find( x );
  
  if( itr.isPastEnd( ) )
    whichList.insert( x, whichList.zeroth( ) );
}

/**
 * Remove item x from the hash table.
 */
template <class HashedObj>
void HashTable<HashedObj>::remove( const HashedObj & x )
{
  theLists[ x.getKey( theLists.size()) ].remove( x );
}

/**
 * Find item x in the hash table.
 * Return the matching item or ITEM_NOT_FOUND if not found
 */
template <class HashedObj>
HashedObj & HashTable<HashedObj>::find( const HashedObj & x )
{
  ListItr<HashedObj> itr;
  itr = theLists[ x.getKey( theLists.size( ) )].find( x );
  if( itr.isPastEnd( ) )
  {
     return ITEM_NOT_FOUND;
  }
  else
    return itr.retrieve( );
}

/**
 * Find item x in the hash table.
 * Return the matching item or ITEM_NOT_FOUND if not found
 */
template <class HashedObj>
HashedObj & find(int x )
{
   HashedObj temp(x);
   ListItr<HashedObj> itr;
   itr = theLists[x].find( temp );
   if( itr.isPastEnd( ) )
   {
      return ITEM_NOT_FOUND;
   }
   else
      return itr.retrieve( );
}


/**
 * Make the hash table logically empty.
 */
template <class HashedObj>
void HashTable<HashedObj>::makeEmpty( )
{
  for( int i = 0; i < theLists.size( ); i++ )
    theLists[ i ].makeEmpty( );
}

/**
 * Deep copy.
 */
template <class HashedObj>
const HashTable<HashedObj> &
HashTable<HashedObj>::operator=( const HashTable<HashedObj> & rhs )
{
  if( this != &rhs )
    theLists = rhs.theLists;
  return *this;
}

#endif
