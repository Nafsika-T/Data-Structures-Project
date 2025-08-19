
#ifndef Sorted_H
#define Sorted_H

#include "UnSorted.h"
#include <cstring>


//Η κλάση Sorted αναπαριστά τον ταξινομημένο πίνακα και τις λειτουργίες του και κληρονονεί την UnSorted

class Sorted : public UnSorted    
{
  protected:
    bool search_(int,int,string);  //βοηθητική μέθοδος που πραγματοποιεί δυαδική αναζήτηση
  public:
    Sorted();
    void insert_(string);   //μέθοδος για την εισαγωγή λέξης στον πίνακα
    bool search_(string);   //μέθοδος για την διαγραφή λέξης από τον πίνακα
    void delete_(string);   //μέθοδος για την αναζήτηση λέξης στον πίνακα (χρησιμοποιεί την search_(int,int,string))
};

#endif
