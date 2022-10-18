/*
 * queue.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Pavel Starovoitov
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdint.h>

namespace container
{
  class queue {
  public:
    queue(uint16_t size);
    ~queue();
    void push(char element);
    char pop(void);
    void flush(void);
    bool empty(void);
    uint16_t size(void);
  private:
    uint16_t _size;
    uint16_t _count_elements;
    char* _buffer;
    char* _begin;
    char* _end;
  };
} /* namespace container */

#endif /* QUEUE_H_ */
