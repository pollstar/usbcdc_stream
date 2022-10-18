CDC USB of STM32 on C++

Here is an example of the implementation of the transmission/reception of data through the USB CDC for the STM32 microcontroller.

To emulate stream I/O methods through the STL library in C++, the following classes are used:
    - ostream
    - istream
These classes are described and implemented in the /Libs directory.
Output and input are organized by overloading the >> and << operators, respectively.

The ostream class uses the CDC_Transmit_FS USB library function.
The istream class uses the callback library function CDC_Receive_FS

In structure USBD_Interface_fops_FS field Receive to contain a pointer to the function CDC_Receiver_FS. 

