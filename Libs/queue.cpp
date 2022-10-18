/*
 * queue.cpp
 *
 *  Created on: Oct 16, 2022
 *      Author: Pavel Starovoitov
 */

#include <queue.h>

namespace container
{
  queue::queue(uint16_t size) : _size(size){
    _buffer = new char[_size];
    flush();
  }

  queue::~queue()
  {
    delete[] _buffer;
  }

  void queue::push(char element)
  {
    if (_count_elements < _size)
    {
      _count_elements++;

      *_end = element;
      _end++;

      if (_end >= _buffer + _size) _end = _buffer;
    }
  }

  char queue::pop(void)
  {
    char result = '\0';

    if (_count_elements > 0)
    {
      _count_elements--;
      result = *_begin;
      _begin++;
      if (_begin >= _buffer + _size) _begin = _buffer;
    }

    return result;
  }

  void queue::flush(void)
  {
    _count_elements = 0;
    _begin = _end = _buffer;
  }

  bool queue::empty(void)
  {
    return (_count_elements == 0);
  }

  uint16_t queue::size(void)
  {
    return _count_elements;
  }


} /* namespace container */
