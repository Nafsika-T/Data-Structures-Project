#ifndef UnSorted_H
#define UnSorted_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <iterator>

using namespace std;


//Αυτό το struct αναπαριστά ένα στοιχείο του πίνακα που αποτελείται από μια λέξη και το πλήθος εμφανήσεων αυτής της λέξης
struct WordCount
{
  int count_;
  string w;
};

//Η κλάση UnSorted αναπαριστά την δομή του αταξινόμητου πίνακα και τις λειτουργίες του
class UnSorted
{
  protected:
    WordCount *data; //ο πίνακας data από στοιχεία WordCount αναπαριστά τον αταξινόμητου πίνακα
    int size_;    //η μεταβλητη size_ αναπαριστά το μέγεθος της μνήμης που καταλαμβάνει ο πίνακας    
    int found;    //η μεταβλητή found χρησιμοποιείται για την αποθήκευση της θέσης του στοιχείου που βρίσκεται από την λειτουργία της αναζήτησης
    int pointer;   //στην μεταβλητή pointer αοθηκεύεται η επόμενη άδεια θέση του πίνακα στην οποία μπορεί να εισαχθεί στοιχείο
    bool moreMemory();   //μέθοδος για την αύξηση της μνήμης
    bool lessMemory();   //μέθοδος για την μείωση της μνήμης

  public:
    UnSorted();       
    int getSize();   //μέθοδος που επιστρέφει το μέγεθος (αριθμό στοιχείων) του πίνακα

    virtual void insert_(string);   //μέθοδος για την εισαγωγή λέξης στον πίνακα
    virtual void delete_(string);   //μέθοδος για την διαγραφή λέξης από τον πίνακα
    virtual bool search_(string);   //μέθοδος για την αναζήτηση λέξης στον πίνακα
    void searchHowTimes(string);  //μέθοδος για την αναζήτηση λέξης στον πίνακα και εμφάνισης της λέξης αυτής και του πλήθους της 

    string operator[](int pos)     //υπερφόρτωση του τελεστή [] για την εμφάνιση ενός στοιχείου του πίνακα 
    {
      if (pos<getSize())
      {
       string s=data[pos].w+"-"+to_string(data[pos].count_);
       return s;
      }
      return "bound of array";
    }
};

#endif
