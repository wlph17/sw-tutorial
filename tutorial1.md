title: Software Tutorial - Basic C Language
output: tutorial1.html
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
* Computer executes simple instructions sequentially. Consider the assembly below:
  ```assembly
  MOV r0, #1        /* save 1 in register 0            */
  MOV r1, #1        /* save 1 in register 1            */
  ADD r0, r0, r1    /* add r0 and r1 and save it in r0 */
  ```
  
* This is ***hardware dependent***, and ***verbose*** for some more complex programs.
* Programmers developed ***high level*** programming languages to deal with this problem, they are:
  * More abstract<span class="hidden">, thus more concise and less machine dependent (you can care less about the low level implementation).</span>
  * More restricted<span class="hidden">, which can prevent programmers from doing something stupid, and also improve code readability and maintainability.</span>

--

### Motivation (cont.)

* Abstractions: neglecting implementation details.
  * Low level: working with hardware.
  * High level: neglecting the hardware details.
* C language is a high level programming language. <span class="hidden">It provides some abstractions which enables us to write larger programs. However, it still provides ways for us to do low level work, which is needed in embedded programming.</span>

--

### Compiler

* High level languages cannot be executed by computers directly. It has to be translated into machine code before execution, this translation is called ***compiling*** and is done by a ***compiler*** (or compiler toolchain, basically a set of tools).
* When compiling programs for another kind of machine having different set of instruction set, a ***cross-compiler*** would be needed, and the translation would be called ***cross-compile***. <span class="hidden">In short, the compiler used in our embedded programming is different from what we use normally.</span>
* <span class="hidden">Apart from compiling C files, we may have to include assembly code files or library files to generate the entire executable program. </span>The process of generating the executable program is called ***building***, <span class="hidden">and due to the complexity of the build process</span> we often make use of build tools such as **GNU Make** to automate the build process.

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
  * Memory layout<span class="hidden">. Data are stored in memory as bits and bytes, which on their own has no meaning. Type defines the interpretation of the memory.</span>

    <span class="hidden">For example `1000 0000` can represent 128 for integer, but it can also represent -128 for another type of integer (`int8_t`).</span>
  * Operations<span class="hidden">. For example the addition of integer is different than that of floating point.</span>
  * Checking.<span class="hidden"> Different types may be incompatible from each other, or the conversion may cause loss of information that requires programmer's attention.</span>

    <span class="hidden">Compiler performs ***type checking*** to make sure that the programmer uses the right type on the right place. For example, not putting a text into a math function.</span>

> Note: The memory layout for the same type in different architecture may be different. Search ***memory alignment*** and ***endianness*** for more details.

--

### Primary Types

* ***Integers***<span class="hidden">: with ***signed*** and ***unsigned***, and various sizes which determines the range of the type. It would ***overflow/underflow*** when the actual data is beyond the the range of the data type. For example, if the range of a signed `int8_t` is -128 to 127, when you add 1 to 127, it would overflow to -128. (assuming two's complement is used)</span>  
  <span class="hidden">Different size of integers can be denoted using the combination of `int` `long` `short`, and `unsigned` for unsigned integers. However, the standard only specified the minimum size of the integers, the actual size is implementation dependent. For ***fixed size integers*** which are mainly used in embedded development, use `stdint.h`.</span>
* ***Floating point***<span class="hidden">: represents numbers in ***scientific notation***, with sign, exponent and significant field. It can represent real numbers with a wide range, but with limited precision (indeed the number is nearly never exact). `float` for single-precision, `double` for double-precision and `long double` for even higher precision.</span>
* ***Characters***<span class="hidden">: 8 bit integer primarily used to store ***ASCII*** characters. The reserved word is `char`.</span>
* ***Boolean***<span class="hidden">: 1 bit integer used to denote true and false. The reserved word is `bool`.</span>

--

### Basic Operations

* Integers and floating point numbers support basic arithmetic operations<span class="hidden">, including `+` (addition), `-` (subtraction), `*` (multiplication), `/` (division), `%` (mod).</span>

* Integers and numbers support comparison which would return boolean<span class="hidden">, including `==` (equal), `>` (larger than), `<` (smaller than), `>=` (larger than or equal to), `<=` (larger than or equal to), `!=` (not equal).</span>

* Integers also support bitwise operations<span class="hidden">, including `&` (bitwise and), `|` (bitwise or), `~` (bitwise not), `^` (bitwise xor), `<<` (left shift), `>>` (right shift).</span>

* Booleans support logical operations<span class="hidden">, including `&&` (logical and), `||` (logical or), `!` (logical not). *Logical and* and *logical or* would have a *short-circuiting* behavior, as the second operand (the right one) will not be evaluated if the result can be deduced from the first operand, thus may reduce processing time if used wisely.</span>

* Operators have different precedence, parenthesis (`()`) can be used to change the precedence like in ordinary arithmetic.

  ```c
  5 * (1 + 1)
  ```

--

### Function Call
* Functions are subprograms that can be executed to perform certain task, may take inputs and may evaluate to a certain value. They will be discussed in depth later in the tutorial.


* Inputs to the program are called ***parameters***, and evaluated value of the function is called the ***return value***. Format of function call is `<name>(<param1>, <param2>, ...)`: 
  ```c
  sin(1)
  printf("1 + 1 = %d", 1 + 1)
  exit()
  ```
  
* <span class="hidden">Functions that can be defined entirely by its input and output mapping are called </span>***pure functions***<span class="hidden">. Effects of the function apart from returning the return value are called `side effects`. For example, `printf` is not a pure function, and its side effect is printing to stdout of the terminal. Note that side effects may be desired feature of a function.</span>

--

### Statements & Expressions

- ***Expression*** would evaluate to a single value.

- Statements are similar to instructions, are executed sequentially, together with expressions are building blocks of complicated programs.

- Expressions become statements by appending a semicolon (`;`) after them:

  ```c
  1 + 1;
  sin(PI/4);
  2 + 2 >= 4;
  ```

- Statements can be combined into a ***compound statement*** (also called blocks) using a pair of braces (`{}`):

  ```c
  {
      1 + 1;
      sin(PI/4);
      2 + 2 >= 4;
  }
  ```

--

### Variables

* Computer programs store data in variables. 

* Declaration of variable: angle brackets denote terms that should be replaced, square brackets denote optional component, note that this is not the complete format)

  ```
  <type> <name> [= <value>];
  ```

  Examples:

  ```c
  int a;          // declare an integer called a with random value (not initialized)
  bool b = true;  // declare a boolean called b assigned with value true
  ```

* Variables have ***scope***<span class="hidden">, ***global*** (the entire program) if not declared inside any function, or ***local*** to the block of code it is in. Variable names should be unique within its scope, and only the code within the scope of the variable have access to the variable.</span>

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

### Special Operators

* Compound assignment operators: `a += b` means `a = a + b`. Similar operators: `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`.

* Increment and decrement: `a++` evaluates to `a`, and then add 1 to `a`. `++a` add 1 to `a`, and then evaluate to `a`.  The same goes to decrement `--` operator.

  ```c
  int a = 0;
  printf("%d\n", a++); // 0, a = 1 now
  printf("%d\n", ++a); // 2, a = 2 now
  ```

--

### Conditional Statement & Operator

* We may want to execute statements conditionally, i.e. do something only when certain condition is met. We would use `if` block to do so.

  ```
  if (<condition boolean>)
      <statement>
  else if (<condition boolean>)
      <statement>
  ...
  else
      <statement>
  ```
  ```c
  if (1 + 1 > 2)
      printf("1 + 1 > 2");
  else if (1 + 1 == 2)
      printf("1 + 1 = 2");
  else
      printf("1 + 1 < 2");
  ```
* Condition operator is an operator that would evaluate to 2 different values depending on the condition. `<condition> ? <value when true> : <value when false>`.

  ```c
  (1 + 1 == 2)? 1 : 0 // 1
  (1 + 1 > 2)? 1 : 0 // 0
  ```

--

### Loops

* Programs may do repetitive task via loops, which repeat certain statements.

* while loop: check the condition, execute statement and repeat if condition is true.

  ```c
  while (<condition>)
      <statement>
  ```

* do-while loop: execute statement, check the condition and repeat if true.

  ```c
  do
     <statement>
  while (<condition>);
  ```

* for-loop: syntactic sugar for while loop.
  ```c
  for (<initial>; <condition>; <action>)
      <statement>
  ```
  Run the initial statement once, check condition, run statement, action and repeat if condition is true. Example:
  
  ```c
  for (int i = 0; i < 10; i++)
      printf("%d\n", i);
  ```

--

### Functions

- Function is a set of statements together to perform a task, may take ***parameters*** (input data, same as variables), and may evaluate to a value (called ***return value***). <span class="hidden">For example, `sin` function takes a double, computes the sine value and returns a double.</span>

- ***Function Declaration***<span class="hidden">: tells the compiler the name, parameters and the return type of a function.</span>

  ```
  <type> <name>(<type> <parameter name>, ...);
  ```

  ```c
  double sin(double rad);
  ```

- ***Function Definition***<span class="hidden">: defines how the function run, basically the declaration with the function body. (statements to be run, with a ***return statement*** to return the evaluated value)</span>

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

* Different types have different representation in memory, so we may need to convert data to do operations between 2 data of different type.

  ```c
  1 + 1.0 // int + double, int will be converted into double
  ```

* Type conversion<span class="hidden"> take place during assignment to different variable of different type, or when operation involves two data of different types. Type with smaller range will be converted to the type with larger range. For example integers will be converted to float, but float will not be converted to integers *normally*.</span>

* When we want to force type conversion, we would use type casting.<span class="hidden"> For example, converting from float to integer which may cause loss of information.</span>

  ```c
  int a = (int)1.234;
  ```
  
* Operators would return the same type as the operands. For example, integer division would give integer. So we may cast integer to float explicitly to get a float result:

  ```c
  double a = 1 / 2;         // 0
  double b = (double)1 / 2; // 0.5
  ```

  




