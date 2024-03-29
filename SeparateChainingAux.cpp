#include "SeparateChaining.h"
#include "SeparateChainingAux.h"


/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
  if( n == 2 || n == 3 )
    return true;
  
  if( n == 1 || n % 2 == 0 )
    return false;
  
  for( int i = 3; i * i <= n; i += 2 )
    if( n % i == 0 )
      return false;
  
  return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
  if( n % 2 == 0 )
    n++;
  
  for( ; !isPrime( n ); n += 2 )
    ;
  
  return n;
}

/**
 * A hash routine for string objects.
 */
int hash( const string & key, int tableSize )
{
  int hashVal = 0;
  
  for( int i = 0; i < (int)key.length( ); i++ )
    hashVal = 37 * hashVal + key[ i ];
  
  hashVal %= tableSize;
  if( hashVal < 0 )
    hashVal += tableSize;
  
  return hashVal;
}


/**
 * A hash routine for ints.
 */
int hash( int key, int tableSize )
{
  if( key < 0 ) key = -key;
  return key % tableSize;
}
