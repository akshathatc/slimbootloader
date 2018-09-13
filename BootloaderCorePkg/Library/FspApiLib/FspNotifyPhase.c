/** @file

  Copyright (c) 2017, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <FspApiLibInternal.h>

/**
  This FSP API is used to notify the FSP about the different phases in the boot process.
  This allows the FSP to take appropriate actions as needed during different initialization
  phases. The phases will be platform dependent and will be documented with the FSP
  release. The current FSP supports following notify phases:
    Post PCI enumeration
    Ready To Boot
    End of firmware

  @param[in] Phase              Phase parameter for FspNotifyPhase

  @retval EFI_SUCCESS           The notification was handled successfully.
  @retval EFI_UNSUPPORTED       The notification was not called in the proper order.
  @retval EFI_INVALID_PARAMETER The notification code is invalid.
**/
EFI_STATUS
EFIAPI
CallFspNotifyPhase (
  FSP_INIT_PHASE  Phase
  )
{
  FSP_INFO_HEADER            *FspHeader;
  FSP_NOTIFY_PHASE            NotifyPhase;
  NOTIFY_PHASE_PARAMS         NotifyPhaseParams;
  EFI_STATUS                  Status;

  FspHeader = (FSP_INFO_HEADER *) (PcdGet32 (PcdFSPSBase) + FSP_INFO_HEADER_OFF);

  ASSERT (FspHeader->Signature == FSP_INFO_HEADER_SIGNATURE);
  ASSERT (FspHeader->ImageBase == PcdGet32 (PcdFSPSBase));

  if (FspHeader->NotifyPhaseEntryOffset == 0) {
    return EFI_UNSUPPORTED;
  }

  NotifyPhase = (FSP_NOTIFY_PHASE) (FspHeader->ImageBase +
                                    FspHeader->NotifyPhaseEntryOffset);

  NotifyPhaseParams.Phase = Phase;

  DEBUG ((DEBUG_INFO, "Call FspNotifyPhase(%02X) ... ", Phase));
  Status = NotifyPhase (&NotifyPhaseParams);
  DEBUG ((DEBUG_INFO, "%r\n", Status));

  return Status;
}

