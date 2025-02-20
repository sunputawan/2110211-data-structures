#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};

auto Comp1 = [](Song &S1, Song &S2) {
  return (S1.artist != S2.artist) ? S1.artist > S2.artist : ((S1.title != S2.title) ? S1.title > S2.title : S1.count > S2.count);
};

auto Comp2 = [](Song &S1, Song &S2) {
  return (S1.count != S2.count) ? S1.count < S2.count : ((S1.artist != S2.artist) ? S1.artist > S2.artist : S1.title > S2.title);
};

//  you have to write something below this line 
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song, decltype(Comp1)> pq1(Comp1);
CP::priority_queue<Song, decltype(Comp2)> pq2(Comp2);

#endif
