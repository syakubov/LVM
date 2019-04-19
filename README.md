# LVM: The Lil' Virtual Machine&trade;

Silly, stackless, register-based virtual machine capable of basic arithmetic operations and printing to the console. Written in C, like a Real Virtual Machine&reg; should be.

## Getting Started

### Prerequisites

You need to have a recent version of Clang.
### Installing

In a directory of your choice, run the following commands in the terminal:
<br>

```
git clone link
make
```
And that's it! The program compiles with some warnings, but it works fine. 
### Running

Programming this machine is done by editing the program.c file, and compiling involves simply running make in the terminal again.
<br>

After following the installation instructions, and/or remaking after editing the program.c file, run:
<br>


```
./lvm
```
In the directory where you called make.
## User Guide

### Registers

The LVM has five registers:

```
AR
```

All arithmetic operations that are implemented so far affect this register only.Instructions that affect other registers (besides MOV and RMOV) will be implemented soon.

```
AX
BX
CX
```
These are general registers. They can be written to and used as arguments for arithmetic operations on AR.
```
IP
```
This is the instruction pointer register. It is used solely to fetch the next instruction. Strict error checking will be implemented to ensure that it is not written to (MOV and RMOV currently work on IP and can easily be used to break the program).
### Instruction Set

These are the instructions that you may use to program the LVM (in its own language, of course).

<br>
```
EXIT
```

Once the program gets to this instruction, it halts execution.
<br>

```
MOV
```
Usage:

```
MOV, (AR|AX|BX|CX), <integer literal>
```

Sets the value of the register to the integer literal specified.
<br>

```
RMOV
```
Usage:

```
RMOV, (AR|AX|BX|CX), (AR|AX|BX|BX|CX)
```

Sets the value of the register to the integer literal specified.
<br>

```
ADD
```
Usage:

```
ADD, <integer literal>
```
Adds the value of the register to the accumulator (AR).
<br>

```
RADD
```

Usage:

```
RADD, (AR|AX|BX|CX)
```

Adds the value of the register to the accumulator (AR).
<br>

```
SUB
```
Usage:

```
SUB, <integer literal>
```
Subtracts the value of the integer literal from the accumulator (AR).
<br>

```
RSUB
```

Usage:

```
RSUB, (AR|AX|BX|CX)
```
Subtracts the value of the register from the accumulator (AR).
<br>

```
MUL
```

Usage:

```
MUL, <integer literal>
```
Multiplies the value of the accumulator (AR) by the integer literal.
<br>

```
RMUL
```

Usage:

```
RMUL, (AR|AX|BX|CX)
```
Multiplies the value of the accumulator (AR) by the value of the register.
<br>

```
DIV
```

Usage:

```
DIV, <integer literal>
```
Integer-divides AR by the integer literal.
<br>

```
RDIV
```

Usage:

```
RDIV, (AR|AX|BX|CX)
```
Integer-divides AR by the value of the register.
<br>

```
PRINTLIT
```

Usage:

```
PRINTLIT, <integer literal>
```
Prints the integer literal to the console.
<br>

Usage:

```
PRINTR, (AR|AX|BX|CX)
```
Prints the value of the specified register to the console.
<br>

### Programming

In order to program the LVM, open the program.c file with a text editor of your choice. Notice that the inital "loaded" program is an empty program, which does... well, nothing. There are also commented out sample programs for you to try out. Note that the syntax of the LVM language is quite simple, and is basically an array of tokens. The order of the tokens is specified above in the instruction set section. Note that every instruction should be followed by a comma, until the final instruction EXIT, which is the end of the program array. The EXIT instruction should only be put at the end of your program, but technically it doesn't have to be. If it isn't, the program will just terminate prematurely. Feel free to comment out/in any of the same programs to see how they work. The basic program looks like this:

```
const int program[] =
{
 INSTRUCTION, ARGUMENT, [OPTIONAL SECOND ARGUMENT],
 INSTRUCTION, ARGUMENT, [OPTIONAL SECOND ARGUMENT],
 ....,
 EXIT
};
```

## Contributing

Opening to contributions soon, and another guide will be written. Feel free to try adding functions yourself as the machine is rather simple (all function definitions are in lvmhelper.c). Hopefull we will have some control flow functions and jumps soon.

## Authors

 **Solomon Yakubov** - [syakubov](https://github.com/syakubov)

## License

This project is licensed under the GPL License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

* This project was inspired by Felix Angell's [mac](https://github.com/felixangell/mac), although it is a completely different architecture. Tutorial for mac can be found here: https://blog.felixangell.com/virtual-machine-in-c/

* The [build-your-own-x](https://github.com/danistefanovic/build-your-own-x) repository, which directed me to Felix's example.

