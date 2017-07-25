// stats.cxx - implements statistician class as defined in stats.h
// XIAOLE XI  April 15 2017

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

namespace main_savitch_2C
{
  statistician::statistician(){
    count = 0;
    total = 0.0;
  }
  void statistician::next(double r){
    count += 1;
    total += r;
    if (count < 2){
      tiniest = r;
      largest = r;
    }
    else {
      if (tiniest > r){
	tiniest = r;
      }
      if (largest < r){
	  largest = r;
	}
    }
  }
  void statistician::reset(){
    count = 0;
    total = 0.0;

  }
  double statistician::mean() const{
    assert (length() > 0);
    return (total/count);
  }
  double statistician::minimum() const{
    assert (length() > 0);
    return tiniest;
  }
  double statistician::maximum() const{
    assert (length() > 0);
    return largest;
  }
  statistician operator + (const statistician& s1, const statistician& s2){
    statistician s3;
    if (s1.length() == 0 && s2.length() == 0){
      return s3;
    }
    else{
      if (s1.length() == 0){
	s3.count = s2.count;
	s3.total = s2.total;
	s3.tiniest = s2.tiniest;
	s3.largest = s2.largest;
      }
      else if (s2.length() == 0){
	s3.count = s1.count;
	s3.total = s1.total;
	s3.tiniest = s1.tiniest;
	s3.largest = s1.largest;
      }
      else {
	s3.count = s1.count + s2.count;
	s3.total = s1.total + s2.total;
	if (s1.tiniest < s2.tiniest){
	  s3.tiniest = s1.tiniest;
	}
	else {
	  s3.tiniest = s2.tiniest;
	}
	if (s1.largest > s2.largest){
	  s3.largest = s1.largest;
	}
	else {
	  s3.largest = s2.largest;
	}
      }
      return s3;
    }
  }
  statistician operator * (double scale, const statistician& s){
    statistician s1;
    if (s.length() == 0){
      return s1;
    }
    else{
      if (scale < 0 ){
	s1.count = s.count;
	s1.total = s.total * scale;
	s1.tiniest = s.largest * scale;
	s1.largest = s.tiniest * scale;
      }
      else {
	s1.count = s.count;
	s1.total = s.total * scale;
	s1.tiniest = s.tiniest * scale;
	s1.largest = s.largest * scale;
      }
      return s1;
    }
  }
  bool operator == (const statistician& s1, const statistician& s2){
    if (s1.length() == 0 && s2.length() == 0){
      return true;
    }
    else {
      if (s1.length() == s2.length() && s1.sum() == s2.sum()
	  && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()){
	return true;
      }
      else {
	return false;
      }
    }
  }     
}
