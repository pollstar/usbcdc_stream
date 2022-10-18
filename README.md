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

The project was created using STM32CubeMX, for STM32CubeIDE.

For to make the project:

mkdir usbcdc_stream  
cd usbcdc_stream  
git init  
git remote add root https://github.com/pollstar/usbcdc_stream.git  
git branch -M master  
git pull root master  
