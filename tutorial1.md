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

# C Language Basics
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

### What is C and Why C?
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

### What is C and Why C? (cont.)

* Abstractions: neglecting implementation details.
  * Low level: working with hardware. 
  * High level: neglecting the hardware details. 
* C language is a high level programming language. It provides some abstractions which enables us to write larger programs. However, it still provides ways for us to do low level work, which is needed in embedded programming.

> Note: C++ is a superset of C, which provides more abstractions than C language while being compatible with C. We use both C and C++ in our team. As C++ is more complicated and not really needed in the internal competition, we would not talk about C++ now.

--

### Compiling

* High level languages cannot be executed by computers directly. It has to be translated into machine code before execution, this translation is called ***compile*** and is done by a ***compiler*** (compiler toolchain, basically a set of tools).
* When compiling programs for another kind of machine having different set of instruction set, a ***cross-compiler*** would be needed, and the translation would be called ***cross-compile***. In short, the compiler used in our embedded programming is different from what we use normally.
* Apart from compiling C files, we may have to include assembly code files or library files to generate the entire executable program. The process of generating the executable program is called ***building***, and due to the complexity of the build process we often make use of build tools such as **GNU Make** to automate the build process.

--

