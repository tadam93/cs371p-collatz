// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------
// Length estimate  15 hours
// Dates:
//      Jan 27 - 1 hour
//      Feb 1 - 3 hours
// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    //cout << "I:" << i << "\tJ:" << j << endl;
    assert(i > 0);
    assert(i < 1000000);
    assert(j > 0);
    assert(j < 1000000);
    if(i > j){
        int temp = i;
        i = j;
        j = temp;
    }
    int max_cycle = 1;
    while(i <= j){
        //cout << "I: " << i << endl;
        int curr_cycle = collatz_cycle_length(i);
        if(curr_cycle > max_cycle){
            max_cycle = curr_cycle;
        }
        i++;
    }
    assert (max_cycle > 0);
    return max_cycle;
}


// -------------
// collatz_cycle_length
//  Takes in a number and finds the cycle length based on the collatz formula
// int i: the number whose cycle length is desired
// return int: the cycle length
// -------------
int collatz_cycle_length(int i){
    //cout << "I:" << i << endl;
    assert(i > 0);
    assert(i < 1000000);
    int count = 1;
    while (i > 1){
        if ((i % 2) == 0){
            i = (int)(i / 2);
        }else{
            i = (3 * i) + 1;
        }
        count++;
    }
    assert(count > 0);
    return count;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);
    }
}