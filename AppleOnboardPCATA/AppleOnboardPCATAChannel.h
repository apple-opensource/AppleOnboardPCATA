/*
 * Copyright (c) 2004 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 2.0 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _APPLEONBOARDPCATACHANNEL_H
#define _APPLEONBOARDPCATACHANNEL_H

#include <IOKit/IOService.h>

class AppleOnboardPCATARoot;

class AppleOnboardPCATAChannel : public IOService
{
    OSDeclareDefaultStructors( AppleOnboardPCATAChannel )

protected:
    AppleOnboardPCATARoot * fProvider;

    virtual bool         mergeProperties(
                                 OSDictionary * properties );

    virtual UInt32       getNumberPropertyValue(
                                 const char * propKey ) const;

public:
    virtual bool         init(   IOService *       provider,
                                 OSDictionary *    properties,
                                 IORegistryEntry * dtEntry = 0 );

    virtual UInt32       getCommandBlockAddress( void ) const;

    virtual UInt32       getControlBlockAddress( void ) const;

    virtual UInt32       getInterruptVector( void ) const;

    virtual UInt32       getChannelNumber( void ) const;

    virtual const char * getHardwareVendorName( void ) const;

    virtual const char * getHardwareDeviceName( void ) const;

    virtual bool         handleOpen(
                                 IOService *  client,
                                 IOOptionBits options,
                                 void *       arg );

    virtual void         handleClose(
                                 IOService *  client,
                                 IOOptionBits options );

    virtual void         pciConfigWrite8(
                                 UInt8 offset,
                                 UInt8 data,
                                 UInt8 mask = 0xff );

    virtual void         pciConfigWrite16(
                                 UInt8  offset,
                                 UInt16 data,
                                 UInt16 mask = 0xffff );

    virtual void         pciConfigWrite32(
                                 UInt8  offset,
                                 UInt32 data,
                                 UInt32 mask = 0xffffffff );

    virtual UInt8        pciConfigRead8( UInt8 offset );

    virtual UInt16       pciConfigRead16( UInt8 offset );

    virtual UInt32       pciConfigRead32( UInt8 offset );

    virtual bool         matchPropertyTable(
                                 OSDictionary * table,
                                 SInt32 *       score );
};

#endif /* !_APPLEONBOARDPCATACHANNEL_H */
