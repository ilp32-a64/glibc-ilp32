# glibc for AArch64 ILP32

The C library for AArch64 ILP32: 64-bit Arm code with 32-bit `long` and
pointers, which uses less memory and keeps the full AArch64 instruction set
([performance](https://github.com/ilp32-a64/llvm-ilp32/blob/main/docs/benchmarks.md)).

Upstream glibc never merged AArch64 ILP32; its last ports are the sourceware
branches `arm/ilp32` (glibc 2.30, 2019) and `schwab/ilp32` (glibc 2.33, 2021),
both with a 32-bit `time_t`. This is a new port to glibc 2.41.

This default branch only holds this file. The library is in the branches below.

## Branches

| Branch | Base | Status |
|---|---|---|
| `ilp32-2.41` | glibc 2.41 | current, 64-bit `time_t` |
| `ilp32-2.30` | upstream `arm/ilp32` (glibc 2.30) | deprecated, 32-bit `time_t` |

## Use

Build the toolchain (GCC 14.3 with this glibc) with
[test-ilp32](https://github.com/ilp32-a64/test-ilp32), then:

```
glibc/rebuild-all.sh                       # in test-ilp32, once
export PATH=~/work/ilp32-glibc/toolchain/out/bin:$PATH   # $GLIBC_WORK/toolchain/out/bin
aarch64-linux-gnu_ilp32-gcc -O2 hello.c -o hello
```

The programs run on a kernel with the ILP32 ABI, such as
[linux-ilp32](https://github.com/ilp32-a64/linux-ilp32) branch `ilp32-6.12.y`;
test-ilp32 runs its tests on that kernel in QEMU (`qemu/run.sh`).

## ilp32-2.41

- **Data model**: `long`, pointers and `size_t` are 4 bytes; `time_t` and `off_t` are 8 bytes.
- **Year 2038 safe**: only the time64 system calls are used.
- **ABI starts at `GLIBC_2.41`**: binaries built for 2.30 do not run with it.
- **Kernel 5.10 or newer** with the ILP32 ABI.
- **Install paths**: libraries in `/libilp32` and `/usr/libilp32`, dynamic linker
  `/lib/ld-linux-aarch64_ilp32.so.1`, next to the system's 64-bit libraries.
- **LP64 unchanged**: LP64 builds of this tree are the same as upstream.
- **Big endian** (`ld-linux-aarch64_be_ilp32.so.1`) is configured but not tested.
- **Testing**: the test-ilp32 programs and `check-abi` pass in QEMU; the full
  glibc test suite has not been run yet.

## License

LGPL-2.1-or-later, see `COPYING.LIB` in the `ilp32-2.41` branch (and `LICENSES`
there for the few parts under other terms).
