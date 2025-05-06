#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include <cctype>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
        int size= k.size(); //find size of string 
        unsigned long long w[5] = {0}; //make w[i]
        int index = 4; //track index 
        for (int i = size; i>0; i-=6){ //goes through the string in chunks of 6
            int start = i-6; //start will be end index -6
            if (start < 0 ){ //set to 0 if negative (short stirngs)
                start = 0;
            }
            int length = i - start; //find length of segment 
            std::string chunk = k.substr(start, length); //get the chunk 
            unsigned long long value = 0;
            unsigned long long power = 1; 
            //int count = chunk.size()-1;
            for (int j = chunk.size()-1; j>=0; j--){ //go from back to front 
                HASH_INDEX_T num = letterDigitToNumber(chunk[j]); //convert to digit 
                value += num * power; //do the power thingy 
                power*=36;
            }
          
            w[index] = value; //set the value to w[i]
            index-=1; //decrease index 
        }
        
        //h(k) stuff
        unsigned long long hash = 0;
        size_t length = sizeof(w)/sizeof(w[0]); //find length of string 
        for (size_t i = 0; i< length; i++){
            hash += rValues[i] * w[i];
          }
        return hash; 
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        char lower = std::tolower(letter);
        if (isalpha(lower)){ //if alphabet, just minus to get number 
          lower = lower - 'a';
        }
        else{
          lower = lower - '0'; //get number and then plus 26 
          lower = lower + 26;
        }
        HASH_INDEX_T number = lower; 
        return number; 
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
