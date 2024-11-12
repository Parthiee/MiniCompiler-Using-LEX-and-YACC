# Mini compiler

This project provides a workflow for compiling a C source file (`source.c`) into assembly code (`assembly.s`). The process includes:
1. **Lexical Analysis** (using `lex.l`)
2. **Parsing** (using `yacc.y`)
3. **Intermediate Code Generation and Optimization** (output as `intermediate.i`)
4. **Assembly Code Generation** (output as `assembly.s`)

## Files

- **`lex.l`**: Lexical analyzer code, written using Lex. Defines tokens for the source code.
- **`yacc.y`**: Parser code, written using Yacc. Defines grammar and syntax rules, generating a parser.
- **`source.c`**: The input C source file, which will be compiled to generate intermediate and assembly code.
- **`intermediate.i`**: Output file containing optimized 3-address intermediate code.
- **`assembly.s`**: Output file containing the final assembly code.
- **`build.sh`**: Shell script to automate the build process for generating intermediate and assembly code.

## Prerequisites

Ensure you have the following installed:
- **Lex**: A lexical analyzer generator.
- **Yacc**: A parser generator.
- **GCC**: The GNU Compiler Collection, for compiling generated code.

## How to Run

1. Place all files (`lex.l`, `yacc.y`, `source.c`, and `build.sh`) in the same directory.
2. Open a terminal in that directory.
3. Run the following command to start the build process:
   ```sh build.sh ```

