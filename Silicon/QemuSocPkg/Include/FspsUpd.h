/** @file

Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.

  This file is automatically generated. Please do NOT modify !!!

**/

#ifndef __FSPSUPD_H__
#define __FSPSUPD_H__

#include <FspUpd.h>

#pragma pack(1)


/** Fsp S Configuration
**/
typedef struct {

/** Offset 0x0040 - BMP Logo Data Size
  BMP logo data buffer size. 0x00000000(Default).
**/
  UINT32                      LogoSize;

/** Offset 0x0044 - BMP Logo Data Pointer
  BMP logo data pointer to a BMP format buffer. 0x00000000(Default).
**/
  UINT32                      LogoPtr;

/** Offset 0x0048 - Graphics Configuration Data Pointer
  Graphics configuration data used for initialization. 0x00000000(Default).
**/
  UINT32                      GraphicsConfigPtr;

/** Offset 0x004C - PCI Temporary MMIO Base
  PCI Temporary MMIO Base used before full PCI enumeration. 0x80000000(Default).
**/
  UINT32                      PciTempResourceBase;

/** Offset 0x0050
**/
  UINT8                       UnusedUpdSpace1[32];

/** Offset 0x0070
**/
  UINT8                       ReservedFspsUpd;
} FSP_S_CONFIG;

/** Fsp S UPD Configuration
**/
typedef struct {

/** Offset 0x0000
**/
  FSP_UPD_HEADER              FspUpdHeader;

/** Offset 0x0020
**/
  UINT8                       UnusedUpdSpace0[32];

/** Offset 0x0040
**/
  FSP_S_CONFIG                FspsConfig;

/** Offset 0x0071
**/
  UINT8                       UnusedUpdSpace2[13];

/** Offset 0x007E
**/
  UINT16                      UpdTerminator;
} FSPS_UPD;

#pragma pack()

#endif
