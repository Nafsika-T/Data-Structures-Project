#include "UnSorted.h"
#include <cstring>
#include <iterator>
#include <iostream>
#include <array>
#include "clean.h"
using namespace std;


UnSorted::UnSorted()
{
  size_=1024;  
  data=new WordCount[size_];  
  pointer=0;
  found=0; 
}


//Αυτή η μέθοδος δέχεται ως όρισμα μια συμβολοσειρά και την εισάγει στο πίνακα

void UnSorted::insert_(string word)
{
  clean(word);  

  if (search_(word)) //αρχικά αναζητείται η λέξη με τη βοήθεια της μεθόδου search και εάν υπάρχει ήδη
  {
    data[found].count_++;  //τότε αυξάνεται κατά 1 το πλήθος του στοιχείου στο οποίο βρέθηκε η λέξη
  }else                   //αλλιώς
  {
    data[pointer].w=word;   //εισάγεται η λέξη στην επόμενη κενή θέση του πίνακα
    data[pointer].count_=1;  //μόλις εισαχθεί η λέξη θα έχει πλήθος 1
    pointer++;              //αυξάνεται ο pointer για να δείχνει στην επόμενη κενή θέση του πίνακα
    if (pointer==size_)      //αν το pointer είναι ίσο με το size τότε
      moreMemory();         //χρησιμοποιείται η μέθοδος moreMemory() για την αύξηση της μνήμης
  }
  return;
}


//Αυτή η μέθοδος δέχεται ως όρισμα μια συμβολοσειρά, την αναζητά στο πίνακα και επιστρέφει true αν υπάρχει στο πίνακα και false αν δεν υπάρχει

bool UnSorted::search_(string word)
{
  clean(word);
  for (int j=0; j<pointer; j++) //Για κάθε στοιχείο του πίνακα ελέγχεται
  {
    if (data[j].w==word)   //εάν η λέξη του στοιχείου είναι η ίδια με αυτή που αναζητείται
    {
      found=j;       //εάν είναι τότε κρατείται η θέση του στοιχείου αυτού στη μεταβλητή found
      return true;         //και επιστρέφεται true
    }
  }
  return false;        //εάν δεν βρεθεί η λέξη επιστρέφεται false
}


//Αυτή η μέθοδος παίρνει ως όρισμα μια συμβολοσειρά, την αναζητά και σε κάθε περίπτωση εμφανίζει κατάλληλο μύνημα.

void UnSorted::searchHowTimes(string word)
{
  clean(word);
  if (search_(word))
    cout<<"the word "<<word<<" exists "<<data[found].count_<<" times"<<endl;
  else
    cout<<"the word "<<word<<"not exist"<<endl;

}


//Αυτή η μέθοδος δέχεται σαν όρισμα μια συμβολοσειρά και την διαγράφει από τον πίνακα

void UnSorted::delete_(string word)
{
  if (search_(word))  //αρχικά αναζητείται η λέξη με τη βοήθεια της μεθόδου search και εάν υπάρχει τότε
  {
    if (data[found].count_>1)    //εάν το πλήθος της λέξης είναι μεγαλύτερο από 1 τότε
       data[found].count_--;     //απλά μειώνεται κατά 1
    else
    {
      data[found]=data[pointer-1];  //αλλιώς στη θέση του στοιχείου που πρέπει να διαγραφεί αντιγράφεται το στοιχείο της τελευταίας θέσης του πίνακα
      data[pointer-1].w="";        //και διαγράφεται το τελευταίο στοιχείο
      data[pointer-1].count_=0;
      lessMemory();     //χρησιμοποιείται η μέθοδος lessMemory() για την μείωση της μνήμης
    }
  }
  else
  {
    cout<<"this word not exist"<<endl;   //εάν η λέξη δεν υπάρχει τότε εμφανίζεται κατάλληλο μύνημα
  }
}


//Αυτή η μέθοδος διπλασιάζει την μνήμη που καταλαμβάνει ο πίνακας data

bool UnSorted::moreMemory()
{
  int n=size_*2;
  WordCount *temp=new WordCount[n]; //Δημιουργείται ένας βοηθητικός πίνακας temp με μέγεθος δυο φορές το μέγεθος του πίνακα data
	for (int i=0; i<size_; i++)  //Αντιγράφονται τα στοιχεία του πίνακα data στο πίνακα temp
	{
    temp[i]=data[i];
  }
	delete[] data; //Απελευθερώνεται η μνήμη που καταλαμβάνει ο πίνακας data
  data=temp;     //Ο πίνακας data θα δείχνει πλέον στο πίνακα temp
  size_=n;        //και το size θα είναι δυο φορές το προηγούμενο size
  return true;
}


//Αυτή η μέθοδος λειτουργεί όπως η μέθοδος moreMemory() με τη διαφορά ότι δεν διπλασιάζει το μέγεθος αλλά το μειώνει κατά 1

bool UnSorted::lessMemory()
{
  int n=size_-1;
  WordCount *temp;
	temp = new WordCount[n];
	if (temp == NULL)
	   return false;

	for (int i=0; i<pointer; i++)
	{
    temp[i]=data[i];
  }
	delete[] data;
  data=temp;
  size_=n;
  pointer--;
  return true;
}


//Αυτή η μέθοδος επιστρέφει το μέγεθος του πίνακα
int UnSorted::getSize()
{
  return pointer;
}
