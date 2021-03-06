/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/utils/z/sbe_link.H $                                */
/*                                                                        */
/* OpenPOWER sbe Project                                                  */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __SBE_LINK_H
#define __SBE_LINK_H

// $Id:  Exp $

/// \file sbe_link.H
/// \brief Constants required for linking SBE code images
///
/// This header contains those cpp manifest constants required for processing
/// the linker scripts used to generate SBE code images.  They may also be
/// useful for PPE assembler programming so they are included in sbe.H as
/// well.
///
/// The link address of OTPROM code as a byte-address
///
/// The OTPROM can be addressed both as an I2C slave and as a direct PIB
/// slave.  The I2C slave is at PIB local address 0x0 and the PIB memory
/// interface is at local address 0x8000.  SBE/IPL uses the PIB addressing
/// mode, so the OTPROM image is linked at 0x40000 (the byte-address
/// equivalent of 0x8000).
#define OTPROM_ORIGIN 0xC0000

/// The amount of memory contained in each OTPROM macro
#define OTPROM_BLOCK_SIZE 1024

/// The amount of memory reserved for OTPROM code
///
/// This amount is exclusive of physical OTPROM memory reserved for compressed
/// scan ring images.
#define OTPROM_CODE_SIZE (1 * OTPROM_BLOCK_SIZE)

/// The link address of the P9 SBE Base image
#define SBE_BASE_ORIGIN 0xFFFE8000
/// SBE base image length ( 96 KB - 512 bytes for loader)
#define SBE_BASE_LENGTH 0x17DFF

///This Index depends upon XIP HEADER File
// Start offset of sectionTable in XIP header. There are 8 entries
// of 8 byte each.
#define SBE_XIP_TOC_OFFSET 8*8

/// The link address of the P9 SBE Base image
#define SBE_SEEPROM_BASE_ORIGIN 0xFF800000
#define OTPROM_SEEPROM_HIGHER_NIBBLE 0xFF80

///  This Index depends upon XIP HEADER File
///  Each section table entry is 12 bytes(SIZE_OF_SBE_XIP_SECTION) size,
//   Base Loader is 10 th (P9_XIP_SECTION_BASELOADER) section
#define SBE_LOADER_BASE_SECTION  SBE_SEEPROM_BASE_ORIGIN + SBE_XIP_TOC_OFFSET \
                                  + 120
// Base Loader start address
#define SBE_LOADER_BASE_ORIGIN 0xFFFFE400
// Base Loader length
#define SBE_LOADER_BASE_LENGTH 0x1C00

// Base Loader entry function offset in header
#define SBE_LOADER_ENTRY_HEADER_OFFSET 20
// PK boot offset in header
#define SBE_KERNEL_ENTRY_HEADER_OFFSET 28

/// The physical address offset where SBE-SEEPROM code is loaded
///
/// This address *must* be a constant known to the OTPROM code.
#define SBE_SEEPROM_LOAD_ADDRESS 0x2000

/// The offset (in bytes) of the .fixed section in P9 SBE-XIP images
#define SBE_XIP_FIXED_OFFSET 512

/// The link address of the PIBMEM image
#define PIBMEM_ORIGIN 0

/// The amount of space available in the PIBMEM, in bytes (96KB)
#define PIBMEM_SIZE (96 * 1024)

/// The fixed section of Otprom
#define OTPROM_FIXED_SIZE (OTPROM_ORIGIN + 0x340)

/// Sbe fixed sction for the pibmem repair
#define SBE_FIXED_SECTION (SBE_SEEPROM_BASE_ORIGIN + SBE_XIP_TOC_OFFSET + 12)

// Macros to use in assembly code in OTPROM/SEEPROM
// This will be updated in last two bits of messaging register.
// This will help in debugging sbe boot failures
//
// Code reached to OTPROM
#define SBE_CODE_OTPROM_START_MSG 0x01
// Code reached to SEEPROM loader
#define SBE_CODE_SEEPROM_START_MSG 0x02
// Code reached to PIBMEM Loader ( pibmem c loader )
#define SBE_CODE_PIBMEM_START_MSG 0x03

#endif  // __SBE_LINK_H

