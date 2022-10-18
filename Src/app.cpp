/*
 * app.cpp
 *
 *  Created on: Oct 16, 2022
 *      Author: Pavel Starovoitov
 */

#include "app.h"
#include "stream.h"
#include "stm32f0xx_hal.h"

void app()
{

  int i = 1;
  char ch = 'A';

  HAL_Delay(3000);
  com::cout << "Test UART over USB CDC\r\n";

  while(1)
  {
      com::cout << "Press key: \r\n";
      com::cin >> ch;
      i = ch;
      com::cout << "You pressed: " << ch << " code is " << i << "\r\n";

      com::cout << "Enter number: \r\n";
      com::cin >> i;
      com::cout << "You entered: " << i << "\r\n";
  }
}


