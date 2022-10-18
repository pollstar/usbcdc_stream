/*
 * istream.cpp
 *
 *  Created on: Oct 16, 2022
 *      Author: Pavel Starovoitov
 */

#include "stream.h"
#include "usbd_cdc_if.h"
#include "queue.h"

int8_t (* old_receive)(uint8_t *Buf, uint32_t *Len);
const uint8_t MAX_CIN_BUFFER = 64;

container::queue buffer(MAX_CIN_BUFFER);

static int8_t receive(uint8_t* Buf, uint32_t *Len)
{
  if (old_receive == nullptr)
    return USBD_FAIL;

  int rc = old_receive(Buf, Len);

  for (uint32_t i = 0; i < *Len; i++)
  {
      buffer.push((char)Buf[i]);
  }

  return rc;
}

namespace com
{
  istream cin;

  istream::istream()
  {
    old_receive = USBD_Interface_fops_FS.Receive;
    USBD_Interface_fops_FS.Receive = receive;
  }

  istream::~istream()
  {
    USBD_Interface_fops_FS.Receive = old_receive;
  }

  istream& istream::operator >>(char &ch)
  {
    while(buffer.empty());
    ch = buffer.pop();

    return *this;
  }

  istream& istream::operator >>(int &n)
  {
    int result = 0;
    char ch = '\0';
    bool err_ch = false;
    bool first_ch = true;
    int negative = 1;

    do
    {
      while(buffer.empty());
      ch = buffer.pop();
      com::cout << ch;

      if (!err_ch)
      {
	if (ch >= '0' && ch <= '9')
	{
	  result *= 10;
	  result += ch - '0';
	}
	else if (ch == '-' && first_ch)
	{
	  negative = -1;
	}
	else
	  err_ch = true;

	first_ch = false;
      }
    }
    while(ch != 13);

    n = result * negative;

    return *this;
  }
} /* namespace com */
