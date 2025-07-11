# 📘 Compiler Design Lab – Session-wise Learning Repository

Welcome to the **Compiler Design Lab** repository. This repo contains all lab work, C/C++ codes, and notes organized session by session. Each session focuses on a specific part of the compiler construction process, such as lexical analysis, syntax checking, parsing, and symbol table construction.

---

## 📚 Sessions Covered

### ✅ SESSION 1: Scanning and Filtering a Source Program
- Reading source files line by line  
- Removing unnecessary symbols, comments, or whitespace  
- Extracting meaningful parts (e.g., header files, keywords) using file I/O in C/C++

### ✅ SESSION 2: Lexical Analysis
- Building a simple lexical analyzer (tokenizer)  
- Identifying and categorizing tokens: keywords, identifiers, numbers, symbols  
- Working with strings and characters in C++

### ✅ SESSION 3: Symbol Table Construction and Management
- Creating a basic symbol table using arrays or structures  
- Storing variable names, types, and scopes  
- Supporting lookup and redeclaration checks

### ✅ SESSION 4: Detecting Simple Syntax Errors
- Identifying common syntax issues like:
  - Missing semicolons  
  - Unmatched braces or parentheses  
- Providing line-based error messages

### ✅ SESSION 5: Use of CFGs for Parsing
- Introduction to **Context-Free Grammars (CFGs)**  
- Writing grammar rules for simple programming constructs  
- Manual or partial automation of parse tree generation

### ✅ SESSION 6: Predictive Parsing
- Building a basic **LL(1)** parser using recursive descent  
- Understanding and applying **FIRST** and **FOLLOW** sets  
- Parsing simple expressions using custom grammar rules

### ✅ SESSION 7: Lab Final Examination and Final Assignment Submission
- Final practical exam  
- Final project submission covering multiple compiler phases  
- Cleaned and commented code for evaluation

---

## 🧰 Technologies Used

- **Languages**: C, C++  
- **Tools**: GCC/G++, Visual Studio Code, Git & GitHub  
- **Concepts**: Lexical analysis, syntax analysis, parsing, symbol table management

---

## 📁 Folder Structure

/CompilerDesignLab
│
├── Session01_Scanning/
├── Session02_LexicalAnalysis/
├── Session03_SymbolTable/
├── Session04_SyntaxErrors/
├── Session05_CFGs/
├── Session06_PredictiveParsing/
├── Session07_FinalProject/
└── README.md


---

## 🚀 How to Use

1. Clone the repository:
   git clone https://github.com/your-username/CompilerDesignLab.git
   cd CompilerDesignLab
2. Navigate into the session folder and compile the file(s):
    cd Session02_LexicalAnalysis
    g++ lexer.cpp -o lexer
    ./lexer
