/** @file
  The platform hook library.

  Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiPei.h>
#include <Library/IoLib.h>
#include <RegAccess.h>

/**
  Enables the execution by writing to the MSR.
**/
VOID
EnableCodeExecution (
  VOID
)
{
  AsmWriteMsr32 (0x120, 0x100);
}
