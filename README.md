# abstract-VM

## The project

AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

### II.1 The assembly language

#### II.1.1 Example

As an example is still better that all the possible explanations in the world, this is an
example of an assembly program that your machine will be able to compute:

```
; -------------
; exemple.avm -
; -------------

push int32(42)
push int32(33)

add

push float(44.55)

mul

push double(42.42)
push int32(42)

dump

pop

assert double(42.42)

exit

```

#### II.1.2 Description

As for any assembly language, the language of AbstractVM is composed of a series of
instructions, with one instruction per line. However, AbstractVM’s assembly language
has a limited type system, which is a major difference from other real world assembly
languages.

<table>
   <tr>
     <td>Comments</td>
     <td>Comments start with a ’;’ and finish with a newline. A comment can
       be either at the start of a line, or after an instruction.</td>
  </tr>
  <tr>
    <td>push v</td>
    <td>Pushes the value v at the top of the stack. The value v must have one of
        the following form:
  
          ◦ int8(n) : Creates an 8-bit integer with value n.
          ◦ int16(n) : Creates a 16-bit integer with value n.
          ◦ int32(n) : Creates a 32-bit integer with value n.
          ◦ float(z) : Creates a float with value z.
          ◦ double(z) : Creates a double with value z.</td>
  </tr>
  <tr>
    <td>pop</td>
    <td>Unstacks the value from the top of the stack. If the stack is empty, the
        program execution must stop with an error.</td>
  </tr>
  <tr>
    <td>dump</td>
    <td>Displays each value of the stack, from the most recent one to the oldest
        one WITHOUT CHANGING the stack. Each value is separated from the next one
        by a newline.</td>
  </tr>
  <tr>
    <td>assert v</td>
    <td>Asserts that the value at the top of the stack is equal to the one passed
        as parameter for this instruction. If it is not the case, the program execution must
        stop with an error. The value v has the same form that those passed as parameters
        to the instruction push.</td>
  </tr>
  <tr>
    <td>add</td>
    <td>Unstacks the first two values on the stack, adds them together and stacks the
        result. If the number of values on the stack is strictly inferior to 2, the program
        execution must stop with an error.</td>
  </tr>
  <tr>
    <td>sub</td>
    <td>Unstacks the first two values on the stack, subtracts them, then stacks the
        result. If the number of values on the stack is strictly inferior to 2, the program
        execution must stop with an error.</td>
  </tr>
  <tr>
    <td>mul</td>
    <td>Unstacks the first two values on the stack, multiplies them, then stacks the
        result. If the number of values on the stack is strictly inferior to 2, the program
        execution must stop with an error.</td>
  </tr>
  <tr>
    <td>div</td>
    <td>Unstacks the first two values on the stack, divides them, then stacks the result.
        If the number of values on the stack is strictly inferior to 2, the program execution
        must stop with an error. Moreover, if the divisor is equal to 0, the program execution
        must stop with an error too. Chatting about floating point values is relevant a this
        point. If you don’t understand why, some will understand. The linked question is
        an open one, there’s no definitive answer.</td>
  </tr>
  <tr>
    <td>mod</td>
    <td>Unstacks the first two values on the stack, calculates the modulus, then
        stacks the result. If the number of values on the stack is strictly inferior to 2, the
        program execution must stop with an error. Moreover, if the divisor is equal to 0,
        the program execution must stop with an error too. Same note as above about fp
        values.</td>
  </tr>
  <tr>
    <td>print</td>
    <td>Asserts that the value at the top of the stack is an 8-bit integer. (If not,
        see the instruction assert), then interprets it as an ASCII value and displays the
        corresponding character on the standard output.</td>
  </tr>
  <tr>
    <td>exit</td>
    <td>Terminate the execution of the current program. If this instruction does not
        appears while all others instruction has been processed, the execution must stop
        with an error.</td>
  </tr>
</table>
