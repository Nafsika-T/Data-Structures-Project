
#ifndef HashTable_H
#define HashTable_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <iterator>

using namespace std;

//Αυτό το struct αναπαριστά ένα στοιχείο του πίνακα που αποτελείται από μια λέξη και το πλήθος εμφανήσεων αυτής της λέξης

struct WordCount2
{
  int count_;
  string word;
};

//Η κλάση HashTable αναπαριστά τη δομή του πίνακα κατακερματισμού και τις λειτουργίες του

class HashTable
{
  protected:
    WordCount2 *data; //ο πίνακας data από στοιχεία WordCount αναπαριστά τον πίνακα κατακερματισμού
    int words;  //η μεταβλητή words αποθηκεύει το συνολικό πλήθος των λέξεων
    int size_;  //η μεταβλητη size_ αναπαριστά το μέγεθος της μνήμης που καταλαμβάνει ο πίνακας 
    int found;  //η μεταβλητή found χρησιμοποιείται για την αποθήκευση της θέσης του στοιχείου που βρίσκεται από την λειτουργία της αναζήτησης

    long hashCode(string word);  //μέθοδος που επιστρέφει τη θέση κατακερματισμού της λέξης που δίνεται σαν όρισμα
    void hashing(string word);   //μέθοδος που κατακερματίζει την λέξη που δίνεται σαν όρισμα
    void moreMemory();    //μέθοδος για την αύξηση της μνήμης

  public:
    HashTable();   
    void insert_(string);   //μέθοδος για την εισαγωγή λέξης στον πίνακα
    void print();           //μέθοδος για την εμφάνιση όλων των στοιχείων του πίνακα
    bool search_(string);    //μέθοδος για την αναζήτηση λέξης στον πίνακα
    void searchHowTimes(string);   //μέθοδος για την αναζήτηση λέξης στον πίνακα και εμφάνισης της λέξης αυτής και του πλήθους της 
    long getSize()     //μέθοδος που επιστρέφει το μέγεθος του πίνακα
    {
      return size_;
    }

    string operator[](int pos)       //υπερφόρτωση του τελεστή [] για την εμφάνιση ενός στοιχείου του πίνακα 
    {
      string s=data[pos].word+"-"+to_string(data[pos].count_);
      return s;
    }
};

#endif
