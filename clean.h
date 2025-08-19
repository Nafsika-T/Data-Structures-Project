//Αυτό το αρχείο περιέχει τη μέθοδο clean η οποία χρησιμοποιείται από όλες τις κλάσεις

#ifndef CLEAN_H
#define CLEAN_H

#include <algorithm> //αυτή η βιβλιοθήκη χρησιμοποιείται αποκλειστικά και μόνο για την μετατροπή των πεζών χαρακτήρων σε κεφαλαία 

//Αυτή η μέθοδος δέχεται ως όρισμα μια συμβολοσειρά και μετατρέπει τους πεζούς χαρακτήρες σε κεφαλαίους, αφαιρεί τα σημεία στίξης 

static void clean(string &word)
{
  for(size_t j=0; j<word.length(); ++j)
  {
    if(ispunct(word[j]))
    {
      word.erase(j--, 1);
    }
  }
  transform(word.begin(), word.end(),word.begin(), ::toupper);
}

#endif