/*
 * istream.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Pavel Starovoitov
 */

#ifndef ISTREAM_H_
#define ISTREAM_H_

namespace com
{
  class istream
  {
  public:
    istream ();
    ~istream ();

    bool isOk();

    istream& operator >> (int &n);
    istream& operator >> (char &ch);
  };
} /* namespace com */

#endif /* ISTREAM_H_ */


