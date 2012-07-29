/*
  AdkStream.cpp - Streaming ADK (Android accessory)
  Copyright (c) 2012 Anton Smirnov (dev@antonsmirnov.name)
*/

/******************************************************************************
 * Includes
 ******************************************************************************/

#include <AdkStream.h>
#include <Arduino.h>
#include <HardwareSerial.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/
AdkStream::AdkStream()
{
	len = sizeof(msg);
	adk = new ADK(&usb,
			 "Anetto Software", // Manufacturer Name
			 "ArduinoCommander arduino client", // Model Name
			 "ArduinoCommander ADK sketch", // Description (user-visible string)
			 "1.0", // Version
			 "http://anettosoftware.co.uk/ac.php", // URL (web page to visit if no installed apps support the accessory)
			 "1234567890");
} 
 
bool AdkStream::begin()
{
	return (usb.Init() != -1);  
}

void AdkStream::end()
{
	adk->Release();
  delete adk;
}

int AdkStream::available()
{
		usb.Task();
		if (!adk->isReady())
			return 0;
			
		rcode = adk->RcvData(&len, msg);
		if (!rcode || rcode == hrNAK)
			return 0;
			
		return len;
}

int AdkStream::read()
{
		return msg[0];
}

void AdkStream::flush() {
    // not implemented
}

int AdkStream::peek() {
    // not implemented
}

size_t AdkStream::write(uint8_t outcomingByte) {	
		outByte = outcomingByte;
		adk->SndData(1, &outByte);
}