// Shuangyu Li
// 07/26/2017
#include <cassert>
#include <string>
#include "words2.h"

using std::string;

namespace lab03_2
{
    Words::Words(unsigned int initial_capacity) {
        used = 0;
        capacity = initial_capacity;
        data = new string[capacity];
        
    }
    
    Words::Words(const Words &source){
        used = source.used;
        capacity = source.capacity;
        data = new string[capacity];
        copy(source.data, source.data + used, data);
        
    }
    
    Words::~Words(){
        delete [] data;
        
    }
    
    void Words::append(string word) {
        if (used == capacity){
            string *data1 = new string[used * 2];
            copy(data, data + used, data1);
            delete [] data;
            data = data1;
            capacity = used * 2;
            
        }
        data[used] = word;
        ++used;
        
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
        
    }
    
    Words& Words::operator = (const Words &source){
        if (this == &source){
            return *this;
            
        }
        if (capacity != source.capacity){
            string *data1 = new string[source.capacity];
            delete [] data;
            data = data1;
            capacity = source.capacity;
            
        }
        used = source.used;
        copy(source.data, source.data + used, data);
        return *this;
        
    }
    
    unsigned int Words::size() const {
        return used;
        
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
        
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
        
    }
    
    
}
