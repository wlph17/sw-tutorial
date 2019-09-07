title: Software Tutorial - Basic C Language
output: basic_c.html
controls: true
style: style.css

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

### Expressions & Statements

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
* Statements can be combined into a ***compound statement*** (also called blocks) using a pair of braces (`{}`):

  ```c
  {
      1 + 1;
      sin(PI/4);
      2 + 2 >= 4;
  }
  ```
  

--

### Arithmetic Operations & Function Call

--

### Logical Operations & Bitwise Operations

--

### Variables

* Computer programs store data in variables. 

* Declaration of variable: (angle brackets denote terms that should be replaced, square brackets denote optional component, note that this is not the complete format)

  ```
  <type> <name> [= <value>];
  ```

  Examples:

  ```c
  int a;          // declare an integer called a with random value (not initialized)
  bool b = true;  // declare a boolean called b assigned with value true
  ```

* Variables have ***scope***, ***global*** (the entire program) if not declared inside any function, or ***local*** to the block of code it is in. Variable names should be unique within its scope, and only the code within the scope of the variable have access to the variable.

  ```c
  int globalVariableA;   // global
  void someFunction() {
      int localVariable; // local to the function
      {
          int localVariable2; // local to this block only
      }
      // has no access to localVariable2 and knows nothing about it
  }
  ```

--

### Variables (cont.)

* Variables can be modified by assigning it with another value:

  ```c
  int a = 0; // originally a is 0
  a = 5;     // it is 5 now
  ```
  
  but cannot do so if declared as constant:
  
  ```c
  const int a = 0;
  a = 5; // this would not compile as it is not allowed
  ```
  
  
  
* Variables not initialized should not be read, as the value is undefined (it can be anything).

  ```c
  int a;
  printf("%d", a); // does not make sense, it can be anything
  ```
  
  
  
* Variables declared in a block would ***shadow*** the variable outside with the same name. 

  ```c
  int a = 0;
  {
      int a;
      a = 5;             // you are changing the variable a inside this block, 
                         // instead of the one outside
      printf("%d\n", a); // 5
  }
  printf("%d\n", a);     // 0
  ```

--

### Conditional Statement

--

### Iterative Statement

--

### Functions

- Function is a set of statements together to perform a task, may take ***parameters*** (input data, same as variables), and may evaluate to a value (called ***return value***). For example, `sin` function takes a double, computes the sine value and returns a double.

- ***Function Declaration***: tells the compiler the name, parameters and the return type of a function.

  ```
  <type> <name>(<type> <parameter name>, ...);
  ```

  ```c
  double sin(double rad);
  ```

- ***Function Definition***: defines how the function run, basically the declaration with the function body. (statements to be run, with a ***return statement*** to return the evaluated value)

  ```
  <type> <name>(<type> <parameter name>, ...)
  {
      <statements>
      return <value>;
  }
  ```

--

### Functions (cont.)

* Functions can have no return value, the type of this kind of functions are `void`.

  ```c
  void printSine(double rad)
  {
      printf("%lf", sin(rad));
  }
  ```
  
* Return statements would stop the execution of the function, yielding the control back to the caller.
  
  ```c
  int foo()
  {
      if (true)
          return 1;     // the function basically terminates here
      printf("foobar"); // this will never be run (dead code)
  }
  ```
  
* Void functions can use return statement to yield the control back to the caller also.
  
  ```c
  void bar()
  {
      if (true)
          return;       // the function basically terminates here
      printf("foobar"); // this will never be run
  }
  ```
  
  

--

### Type Conversion & Casting

