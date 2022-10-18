/*
 * ostream.h
 *
 *  Created on: 16 oct 2022
 *      Author: Pavel Starovoitov
 */

#ifndef OSTREAM_H_
#define OSTREAM_H_

namespace com {

  class ostream
  {
  private:
      void transmit(const char* str) const;

  public:
      ostream& operator <<(const char ch);
      ostream& operator <<(const char * str);
      ostream& operator <<(const int n);
  };
} // namespace com


#endif /* OSTREAM_H_ */
