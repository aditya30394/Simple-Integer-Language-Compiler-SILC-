# Simple Integer Language Compiler (SILC)
A compiler developed for SIL (Simple Integer Language) in C using tools Lex and Yacc. SIL is a two pass compiler for a hypothetical machine SIM (Simple Integer Machine). SIL has support for basic and user defined data types, functions and conditional and iterative statements, arithmetic and logical expressions and I/O.

The roadmap for the project can be found [here](http://silcnitc.github.io/).

**Specifications**

1. *The specification of the source programming language*: The source language for this compiler is called the Experimental Language (ExpL),
which is designed solely for instructional purposes. An informal specification of the source language is given [here](http://silcnitc.github.io/expl.html).
The specification for an extension of the basic ExpL language with support for object oriented programming is given [here](http://silcnitc.github.io/oexpl-specification.html).

2. *Application Binary Interface of the target platform*: A compiler must generate a binary executable file that can be loaded and executed
by an operating system running on a target machine. Normally, an OS system installation comes with an interface specification, explaining 
how binary executable files must be formatted to run on the system. This interface is called the Application Binary Interface (ABI). 
The ABI is dependent on both the OS and the machine architecture. The ABI for this project is that of the Experimental Operating System 
(ExpOS) running on the Experimental String Machine. [XSM]. The ABI specification is given [here](http://silcnitc.github.io/abi.html). (The simulator allows the target program to contain machine instructions in mnemonic form, avoiding translation to binary format).

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
