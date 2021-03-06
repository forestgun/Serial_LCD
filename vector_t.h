// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
// May 01, 2012 release 102
// See README.txt
//
// © Rei VILO, 2010-2012
//   CC = BY NC SA
//   http://embeddedcomputing.weebly.com/serial-lcd.html
//   http://github.com/rei-vilo/Serial_LCD
//
// For 
//   4D Systems Goldelox and Picaso SGC Command Set
//   http://www.4dsystems.com.au/
//
// Based on
//   Container for objects like C++ vector
//   http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1289151491
//
//

#ifndef _VECTOR_T_H
#define _VECTOR_T_H

// Minimal class to replace std::vector
template<typename Data>
class Vector_t {
    size_t d_size; // Stores number of actually stored objects
    size_t d_capacity; // Stores allocated capacity
    Data *d_data; // Stores data
    
public:
    Vector_t() : 
    d_size(0), d_capacity(0), d_data(0) {
    }; // Default constructor
    
    Vector_t(Vector_t const &other) : 
    d_size(other.d_size), d_capacity(other.d_capacity), d_data(0) { 
        d_data = (Data *)malloc(d_capacity*sizeof(Data)); 
        memcpy(d_data, other.d_data, d_size*sizeof(Data)); 
    }; // Copy constuctor
    
    ~Vector_t() { 
        free(d_data); 
    }; // Destructor
    
    Vector_t &operator=(Vector_t const &other) { 
        free(d_data); 
        d_size = other.d_size; 
        d_capacity = other.d_capacity; 
        d_data = (Data *)malloc(d_capacity*sizeof(Data)); 
        memcpy(d_data, other.d_data, d_size*sizeof(Data)); 
        return *this; 
    }; // Needed for memory management
    
    void push_back(Data const &x) { 
        if (d_capacity == d_size) resize(); 
        d_data[d_size++] = x; 
    }; // Adds new value. If needed, allocates more space
    
    size_t size() const { 
        return d_size; 
    }; // Size getter
    
    Data const &operator[](size_t idx) const { 
        return d_data[idx]; 
    }; // Const getter
    
    Data &operator[](size_t idx) { 
        return d_data[idx]; 
    }; // Changeable getter
    
private:
    void resize() { 
        d_capacity = d_capacity ? d_capacity*2 : 1; 
        Data *newdata = (Data *)malloc(d_capacity*sizeof(Data)); 
        memcpy(newdata, d_data, d_size * sizeof(Data)); 
        free(d_data); 
        d_data = newdata; 
    }; // Allocates double the old space
}; 


#endif                          // _VECTOR_T_H not defined


