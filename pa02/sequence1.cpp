//Shuangyu Li
//07/27/2017
//


#include  <iostream>
#include "sequence1.h"
#include <cstdlib>
#include <cassert>

namespace main_savitch_3
{
    static const sequence::size_type CAPACITY =30;
    
    sequence::sequence()
    {
        used = 0;
        current_index =0;//no need of data type for initializor
    }
    sequence::size_type sequence::size() const
    {
        return used-1;
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return data[current_index];
    }
    void sequence::start()
    {   if (used>0)
            current_index = 0;
        else
            std::cout<<"empty sequence"<<std::endl;
    }
    void sequence::advance()
    {
        assert(is_item());
        current_index++;
    }
    bool sequence::is_item() const 
    {
        if(used == 0||current_index>used)
        {
            return false;
        }
        else {return true;}
    
    }
    void sequence::insert(const value_type& entry)
    {
        if(used == 0)//emptry 
        {
            data[current_index] = entry;
            used++;
        }
        if(is_item())
        {
            for (int i = used;i>current_index;i--)
            {
                data[i]=data[i-1];
            }
            data[current_index] = entry;
            used++;
        }
        else
        {
            for (int i = used;i>current_index;i--)
            {
                data[i]=data[i-1];
            }
            current_index = 0;
            data[current_index] = entry;
            used++;
        }
    }
    void sequence::attach(const value_type& entry)
    {
        if(used==0)
        {
            data[used++]=entry;
        }
        if(is_item())
        {
            for(int i = used;i>current_index+1;i--)
            {
                data[i]=data[i-1];
            }
            data[++current_index] = entry;
            used++;
        }
        else
        {
            data[used++] = entry;
            current_index = used-1;
            
        }
    }
    void sequence::remove_current()
    {
        assert(is_item());
        for (int i = current_index;i<used-1;i++)
        {
            data[i] = data[i+1];
        }
        used--;
    }
}
