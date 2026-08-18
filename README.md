
PC-LISP
=======

Forked by Ralf Elberskirch (elberskirch01).

Main master by Peter Ashwood-Smith

PC-LISP is a portable Franz Lisp dialect interpreter and compiler,
written in C, that is portable to 32 & 64 bit Linux, Mac, and Windows.

The main home for this system is:  https://github.com/blakemcbride/PC-LISP

Porting and updating done by Blake McBride (blake@mcbridemail.com)

Adaption to 64bit pointers and 64bit fixnum.
============================================

The home of this fork is
https://github.com/elberskirch01/PC-LISP

By Ralf Elberskirch

Compilation with mingw provided by msys2 with
msys2-x86_64_2026_03_22.exe for Windows using ucrt64 with gcc
required some adaptions.
Same holds for compilation under Ubuntu 24.04.2 LTS (WSL2 X86_64) also with gcc.

See also: build.txt

The following issues were conwsidered while porting to 64bit:

Mingw64 is used, because it provides unistd.h.
Preprocessor defines for Mingw relay often on code provided for MSC (_MSC_VER).
The field atom in fixcell is extended to long long int
(lifix64_t), because in lithrow.c 64bit pointer value is stored
in fixcell. Hence also the whole fixnum arithmetic is extended 
to 64bit. It considers also 64bit time_t in butimest.c.

It was tried to keep the compatibility to other platgforms untouched.

When retrieving integer value out of fixcell via GetFix() in 
most places still GetFix32() is in use restricting retrieved value to 32bit with range check. This keeps many files untouched.

The byte code FX8 is introduced to store and retrieve signed 
64bit integer (long long int).
Byte code FX is renamed to FX4 (long int).
FX4 is used, if FX1 (1 byte) is not applicable and fixnum value 
is in range of 32bit.
This enables byte compatibility with PC-LISP V6.00.
FX8 took value of U1.
The usage of regular expression library (regex.h) required by 
bustrfnd.c may be excluded by processor define LINOREGEX.
