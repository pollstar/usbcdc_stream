/*
 * ostream.cpp
 *
 *  Created on: 16 oct 2022
 *      Author: Pavel Starovoitov
 */

#include "ostream.h"
#include "usbd_cdc_if.h"

namespace com{
  ostream cout;

  void ostream::transmit(const char* str) const
  {
    uint8_t rc = USBD_OK;
    do {
      CDC_Transmit_FS((uint8_t*)str, strlen(str));
    } while (rc == USBD_BUSY);

    HAL_Delay(1);
  }


  ostream& ostream::operator <<( const char * str)
  {
    transmit(str);

    return *this;
  }

  ostream& ostream::operator <<(const char ch)
  {
    char buf[2] = {ch, 0};

    transmit(buf);

    return *this;
  }

  ostream& ostream::operator <<(const int n)
  {
    char buf[10] {0};

    sprintf(buf, "%d", n);
    transmit(buf);

    return *this;
  }
}

