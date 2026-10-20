# glibc for AArch64 ILP32

The C library for the AArch64 ILP32 ABI. Upstream glibc never merged AArch64 ILP32; the newest port is the
sourceware branch `arm/ilp32` (glibc 2.30, 2019).

This default branch only holds this file. The library is in the branches below.

## Branches

| Branch | Base | Content |
|---|---|---|
| `ilp32-2.30` | sourceware `arm/ilp32` (`b3454f4a`, glibc 2.30) | + fixes |

## Fixes

| Fix | Effect without it |
|---|---|
| look up the ILP32 vDSO with version `LINUX_4.12` (the version every ILP32 kernel series exports) instead of `LINUX_4.9`, also for the `gettimeofday` IFUNC | no vDSO symbol is found; `clock_gettime` and `gettimeofday` always use the system call |

## Build

[ilp32-a64/ilp32-test](https://github.com/ilp32-a64/ilp32-test) (`toolchain/build-toolchain.sh`) builds the
`aarch64-linux-gnu_ilp32` cross toolchain with this branch: binutils 2.35.2, GCC 10.5, kernel headers from
[ilp32-a64/linux](https://github.com/ilp32-a64/linux).

Data model: `long`, pointers, `size_t`, `time_t` 4 bytes; `off_t` 8 bytes; `long double` 16 bytes.
Libraries in `/libilp32` and `/usr/libilp32`, dynamic linker `/lib/ld-linux-aarch64_ilp32.so.1`.
