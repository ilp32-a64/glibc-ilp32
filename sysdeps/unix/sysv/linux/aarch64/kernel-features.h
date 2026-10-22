/* Set flags signalling availability of kernel features based on given
   kernel version number.  AArch64 version.
   Copyright (C) 2018-2025 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include_next <kernel-features.h>

#undef __ASSUME_CLONE_DEFAULT
#define __ASSUME_CLONE_BACKWARDS 1

#ifndef __LP64__
/* ILP32 uses the AArch32 (compat) handlers of the kernel for the system
   calls with 64-bit arguments and for SysV IPC, as ARM does.  */

/* fadvise64_64 takes the advice before the offset and length.  */
# define __ASSUME_FADVISE64_64_6ARG	1

/* 64-bit arguments are register pairs starting with an even-numbered
   register.  */
# define __ASSUME_ALIGNED_REGISTER_PAIRS	1

/* The compat struct ipc64_perm has a 16-bit mode.  */
# include <endian.h>
# if __BYTE_ORDER == __BIG_ENDIAN
#  define __ASSUME_SYSVIPC_BROKEN_MODE_T
# endif

/* The compat IPC control calls need IPC_64.  */
# undef __ASSUME_SYSVIPC_DEFAULT_IPC_64
#endif
