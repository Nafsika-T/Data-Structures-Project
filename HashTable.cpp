
#include "HashTable.h"
#include <cstring>
#include <iterator>
#include <iostream>
#include <array>
#include "clean.h"
#include <math.h>

using namespace std;

HashTable::HashTable()
{
  words=0;
  size_=100000;
  data=new WordCount2[size_];
}


//Αυτή η μέθοδος δέχεται ως όρισμα μια συμβολοσειρά και την εισάγει στο πίνακα

void HashTable::insert_(string word)
{
  clean(word);
  if (search_(word))        //αρχικά αναζητείται η λέξη με τη βοήθεια της μεθόδου search και εάν υπάρχει ήδη
  {
    data[found].count_++;   //τότε αυξάνεται κατά 1 το πλήθος του στοιχείου στο οποίο βρέθηκε η λέξη
  }
  else
  {
    hashing(word);     // αλλιώς η λέξη κατακερματίζεται
    words++;        //το πλήθος των λέξεων αυξάνεται κατά 1
    if (words==size_/2)   //Αν το πλήθος των λέξεων είναι ίσο με το μέγεθος τότε
    {
      moreMemory();  //χρησιμοποιείται η μέθοδος moreMemory() για την αύξηση της μνήμης
    }
  }
  return;
}


//Αυτή η μέθοδος δέχεται ως όρισμα μια συμβολοσειρά, την αναζητά στο πίνακα και αν τη βρει επιστρέφει true ενώ αν δεν την βρει επιστρέφει false

bool HashTable::search_(string word)
{
  clean(word);
  long h=hashCode(word);     //Αρχικά υπολογίζεται το hashCode της δοσμένης λέξης
  int i=0;                    //το i είναι μετρητής για τον αριθμό των στοιχείων που ελέγχθηκαν
  while(i<size_ && !data[h].word.empty())  // όσο δεν έχουν ελεγχθεί όλα τα στοιχεία και η θέση h δεν είναι κενή
  {
    if (h==size_) {h=0;}  //Αν το h ξεπεράσει το μέγεθος του πίνακα τότε το h γίνεται 0 για να συνεχιστεί η αναζήτηση από εκεί

    if (word.compare(data[h].word)==0)   //Αν η λέξη βρεθεί τότε
    {
      found=h;             //καταχωρείται στη μεταβλητή found η θέση την οποία βρέθηκε
      return true;         //και επιστρέφεται true
    }
    h++;      //όσο δε βρίσκεται η λέξη ο δείκτης h αυξάνεται για να συνεχιστεί η αναζήτηση στο επόμενο στοιχείο
    i++;      //αυξάνεται ο δείκτης i αφου μόλις ελέγχθηκε μια ακόμα λέξη
  }
  return false;           //Αν η λέξη δεν υπάρχει επιστρέφεται false
}

//Αυτή η μέθοδος παίρνει ως όρισμα μια συμβολοσειρά, την αναζητά και σε κάθε περίπτωση εμφανίζει κατάλληλο μύνημα

void HashTable::searchHowTimes(string word)
{
  clean(word);
  if (search_(word))
     cout<<"the word "<<data[found].word<<" exists "<<data[found].count_<<" times"<<endl;
  else
     cout<<"the word "<<word<<" not exist"<<endl;
}


//Αυτή η μέθοδος δέχεται μια συμβολοσειρά και βρίσκει το hashCode της

long HashTable::hashCode(string word)
{

  long p = 31;
  long hash_value = 0;
  long p_pow = 1;
  for (char c : word) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % size_;
    p_pow = (p_pow * p) % size_;
  }
  return fabs(hash_value);
}



//Αυτή η μέθοδος δέχεται μια συμβολοσειρά και την κατακερματίζει

void HashTable::hashing(string word)
{
  long h=hashCode(word);       //Αρχικά υπολογίζεται το hashCode της δοσμένης λέξης
  for(int i=0; i<size_; i++)  //θα χρειαστεί να ελεγχθούν το πολύ τόσα στοιχεία όσα έχει και ο πίνακας, ξεκινώντας από το h αναζητείται μια κενή θέση
  {
    if (h==size_)  //Αν το h ξεπεράσει το μέγεθος του πίνακα τότε το h γίνεται 0 για να συνεχιστεί η αναζήτηση κενής θέσης από εκεί
      h=0; 
    if (data[h].word.empty())  //Εάν βρεθεί κενή θέση
    {
      data[h].word=word;       //τότε η λέξη εισάγεται σ'αυτή τη θέση
      data[h].count_=1;
      return;               //και η μέθοδος τερματίζει
    }
    h++;      //όσο δε βρίσκεται κενή θέση ο h δείκτης αυξάνεται
  }
}


//Αυτή η μέθοδος τυπώνει όλα τα στοιχεία του πίνακα

void HashTable::print()
{
  for (int i=0; i<size_; i++)
  {
    if (!data[i].word.empty())
    {
      cout<<data[i].word<<"-"<<data[i].count_<<endl;
    }
  }
}


//Αυτή η μέθοδος διπλασιάζει την μνήμη που καταλαμβάνει ο πίνακας data

void HashTable::moreMemory()
{

  int n=size_;
  size_=size_*2;
	WordCount2 *temp = new WordCount2[size_]; //Δημιουργείται ένας βοηθητικός πίνακας temp με μέγεθος δυο φορές το μέγεθος του πίνακα data
  for(int i=0; i<n; i++)    //Kάθε στοιχείο του πίνακα data κατακερματίζεται στο πίνακα temp:
  {
    if (!data[i].word.empty())
    {
    long h=hashCode(data[i].word);   //Αρχικά υπολογίζεται το hashCode της λέξης του τρέχοντος στοιχείου
    for (int j=0; j<size_; j++)    //Ξεκινώντας από το h αναζητείται μια κενή θέση (θα χρειαστεί να ελεγχθούν το πολύ τόσα στοιχεία όσα το πίνακας ξεκινώντας από τη θέση h)
    {
      if (h==size_) h=0; //Αν το h ξεπεράσει το μέγεθος του πίνακα τότε το h γίνεται 0 για να συνεχιστεί η αναζήτηση κενής θέσης από εκεί
      if (temp[h].word.empty())    //Εάν βρεθεί κενή θέση
      {
       temp[h].word=data[i].word;     //τότε η λέξη εισάγεται σ'αυτή τη θέση
       temp[h].count_=data[i].count_;
       break;                   //χρησιμοποιείται το break για να σταματίσει η αναζήτηση κενής θέσης
      }
      h++;                      //όσο δε βρίσκεται κενή θέση ο h δείκτης αυξάνεται
    }
    }
  }

  delete[] data;    //Απελευθερώνεται η μνήμη που καταλαμβάνει ο πίνακας data
  data=temp;        //Ο πίνακας data θα δείχνει πλέον στο πίνακα temp
  return;
}
