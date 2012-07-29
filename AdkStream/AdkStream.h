/*
  AdkStream.h - Streaming ADK (Android accessory)
  Copyright (c) 2012 Anton Smirnov (dev@antonsmirnov.name)
*/

#ifndef ADK_STREAM
#define ADK_STREAM

#include <inttypes.h>
#include <Stream.h>
#include <adk.h>

class AdkStream : public Stream
{
	private:
		uint8_t msg[1];
		uint8_t outByte;
		uint16_t len;
		uint8_t rcode;
		
		USB usb;
		ADK *adk;
  	
  public:
		  AdkStream();
			
		  bool begin();						
      void end();
		
			// overriden Stream class functions
			virtual size_t write(uint8_t byte);
			virtual int read();
			virtual int available();
			virtual void flush(); // not implemented
			virtual int peek();	// not implemented
};

#endif

