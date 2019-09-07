title: Software Tutorial - Introduction
output: tutorial1.html
controls: true
style: style.css

--

# Software Tutorial
## 1-Introduction

--

### Main Duties

* Embedded
    * Maintain core library, which contains reusable modules and hardware drivers.
    * Help mechanical engineers to design and test the robot prototype.
    * Design and refine keymaps for operators.
* Algorithm
    * Computer vision and gimbal control algorithm for aimbot development.
    * Task planning using ROS for sentry robot.
    * Power control algorithms to maximize utilization of the available power.

--

### Technical Stack

* Language: C/C++
* Version Control: Git
* Embedded:
  * RoboMaster Development Board A
  * MCU: STM32F427IIH6
  * MPU: ARM Cortex M4
  * RTOS: ChibiOS
  * Debugger: J-Link EDU mini
  * Compiler: GNU ARM Embedded Toolchain 2017 Q2
* Algorithm:
  * Intel NUC mini computer
  * Libraries: ROS, OpenCV
  * OS: Ubuntu 18

--

# Computer Language Basics
```c
#include <stdio.h>
int main()
{
    /* Traditional Hello World program */
    printf("Hello World");
    return 0;
}
```

--

### Motivation
* Computer executes simple instructions sequentially. Consider the pseudo-code below:
  ```
  SET A = 1
  SET B = 2
  ADD B to A
  //Finally: A = 3, B = 2
  ```

* This is ***hardware dependent***, and ***verbose*** for some more complex programs.
* Programmers developed ***high level*** programming languages to deal with this problem, they are:
  * More abstract, thus more concise and less machine dependent (you can care less about the low level implementation).
  * More restricted, which can prevent programmers from doing something stupid, and also improve code readability and maintainability.

--

### Motivation (cont.)

* Abstractions: neglecting implementation details.
  * Low level: working with hardware.
  * High level: neglecting the hardware details.
* C language is a high level programming language. It provides some abstractions which enables us to write larger programs. However, it still provides ways for us to do low level work, which is needed in embedded programming.

> Note: C++ is a superset of C, which provides more abstractions than C language while being compatible with C. We use both C and C++ in our team. As C++ is more complicated and not really needed in the internal competition, we would not talk about C++ now.

--

### Compile

* High level languages cannot be executed by computers directly. It has to be translated into machine code before execution, this translation is called ***compile*** and is done by a ***compiler*** (compiler toolchain, basically a set of tools).
* When compiling programs for another kind of machine having different set of instruction set, a ***cross-compiler*** would be needed, and the translation would be called ***cross-compile***. In short, the compiler used in our embedded programming is different from what we use normally.
* Apart from compiling C files, we may have to include assembly code files or library files to generate the entire executable program. The process of generating the executable program is called ***building***, and due to the complexity of the build process we often make use of build tools such as **GNU Make** to automate the build process.

--

### Comments

* Comments are texts that are intended for human read only, and will be ignored by the compiler.

* Single line comments starts with `//` and continue to the end of the line.
* Multi-line comments starts with `/*` and ends with `*/`. Note that it is not required to be multi-line.

```c
// a comment using the entire line
printf("foo"); // a comment using only the end of a line
/* comment spanning
   multiple lines   */
printf(/*a comment in the middle of a line*/  "bar");
```

--

### Types

* Data in programs have ***types***, such as integer, floating point (represented using scientific notation), string (text) etc, with the following usages:
  * Memory layout. Data are stored in memory as bits and bytes, which on their own has no meaning. Type defines the interpretation of the memory.

    For example `1000 0000` can represent 128 for integer, but it can also represent -128 for another type of integer (`int8_t`).
  * Operations. For example the addition of integer is different than that of floating point.
  * Checking. Different types may be incompatible from each other, or the conversion may cause loss of information that requires programmer's attention.

    Compiler performs ***type checking*** to make sure that the programmer uses the right type on the right place. For example, not putting a text into a math function.

> Note: The memory layout for the same type in different architecture may be different. Search ***memory alignment*** and ***endianness*** for more details.

--

### Primary Types

* ***Integers***: with ***signed*** and ***unsigned***, and various sizes which determines the range of the type. It would ***overflow/underflow*** when the actual data is beyond the the range of the data type. For example, if the range of a signed `int8_t` is -128 to 127, when you add 1 to 127, it would overflow to -128.  
  Different size of integers can be denoted using the combination of `int` `long` `short`, and `unsigned` for unsigned integers. However, the standard only specified the minimum size of the integers, the actual size is implementation dependent. For ***fixed size integers*** which are mainly used in embedded development, use `stdint.h`.
* ***Floating point***: represents numbers in ***scientific notation***, with sign, exponent and significant field. It can represent real numbers with a wide range, but with limited precision (indeed the number is nearly never exact). `float` for single-precision, `double` for double-precision and `long double` for even higher precision.
* ***Characters***: 8 bit integer primarily used to store ***ASCII*** characters. The reserved word is `char`.
* ***Boolean***: 1 bit integer used to denote true and false. The reserved word is `bool`.

--

### Expressions and Statements

* Statements are similar to instructions, are executed sequentially, together with expressions are building blocks of complicated programs.
* Expressions can be evaluated to a single value:
  ```c
  1 + 1       // 2
  sin(PI/4)   // sqrt(2)/2
  2 + 2 >= 4  // true
  ```
* Expressions become statements by appending a semicolon (`;`) after them:

  ```c
  1 + 1;
  sin(PI/4);
  2 + 2 >= 4;
  ```
* Statements can be combined into a ***compound statement*** using a pair of braces (`{}`):

  ```c
  {
      1 + 1;
      sin(PI/4);
      2 + 2 >= 4;
  }
  ```
  

--

### Variables




