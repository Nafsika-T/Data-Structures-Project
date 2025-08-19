
#include "UnSorted.h"
#include "Sorted.h"
#include "HashTable.h"
#include "BST.h"
#include "AVL.h"
#include "clean.h"

#include <string.h>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {

  int words=0;     //το πλήθος οων των λέξεων του αρχείου

  int sizeQ=10000;   //το σύνολο Q αποτελείται από 10000 λέξεις
  string *Q=new string[sizeQ];  

  string filename, word;
  filename="gutenberg.txt";
  ifstream myfile (filename.c_str());

  if (!myfile.is_open()) {       //Εάν το αρχείο δεν μπορεί να ανοίξει
    cout << "Unable to open file " << filename;    //τότε εμφανίζεται κατάλληλο μήνυμα
    return -1;                //και το πρόγραμμα τερματίζει
  }

  UnSorted usArray;    
  Sorted sArray;
  HashTable hashT;
  BST bst;
  AVL avl;
  while (!myfile.eof())
  {
    myfile >> word;           //διαβάζονται μία μία οι λέξεις από το αρχείο
    clean(word);              //μετατρέπονται τοι πεζοί χαρακτήρες σε κεφαλαίους και αφαιρούνται τα σημεία στίξης μέσω της μεθόδου clean 
    if (!word.empty())        //Αν η λέξη δεν είναι κενή (υπάχει περίπτωση να είναι κενή αν πριν περάσει από την clean αποτελούνταν μόνο απο σημεία στίξης )
    {                         //τότε η λέξη εισάγεται σε κάθε μία από τις δομές
      hashT.insert_(word);
      avl.insertNode(word);
      bst.insertNode(word);
      sArray.insert_(word);
      usArray.insert_(word);
    }
    words++;
  }
  myfile.close();

  //το αρχείο ξανανοίγει για διάβασμα και οι λέξεις του συνόλου Q πέρνονται αμοιόμορφα από το αρχείο

  filename="gutenberg.txt";
  ifstream myfile1 (filename.c_str());

  int takeWord=words/sizeQ;
  int k=0;
  int i=0;
  int j=0;
  while (!myfile1.eof() && j<sizeQ)
  {
    myfile1 >> word;
    if (i==k)
    {
      Q[j]=word;
      k+=takeWord;
      j++;
    }
    i++;
  }

  //ανζητείται κάθε λέξη του πίνακα Q και καταγράφεται ο συνολικός χρόνος σε δευτερόλεπτα

  auto startSearch = high_resolution_clock::now();
  for (i=0; i<sizeQ; i++ )
  {
    hashT.searchHowTimes(Q[i]);
    avl.searchHowTime(Q[i]);
    bst.searchHowTime(Q[i]);
    usArray.searchHowTimes(Q[i]);
    sArray.searchHowTimes(Q[i]);
  }
  auto stopSearch = high_resolution_clock::now();
  duration<double> searchTime=stopSearch-startSearch;

  cout <<"Search time: "<< searchTime.count() <<" s"<< endl;

  myfile1.close();
}
