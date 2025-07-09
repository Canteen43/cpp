# 42 C++ Piscine Projects (Modules 00–09)

A collection of ten C++ modules (Module 00 → 09) from the 42 School C++ Piscine, written in **C++98**. Each module builds upon the previous to teach core C++ and OOP concepts.

---

## 📘 Module Overview

| Module  | Title / Focus                                   | Description                                                                 |
|--------:|--------------------------------------------------|-----------------------------------------------------------------------------|
| **00**  | **C Basics & I/O**                               | Learn namespaces, classes, iostream, member functions, initialization lists, `static` & `const` qualifiers, and class foundations. |
| **01**  | **Memory Management**                            | Practice dynamic allocation (`new`/`delete`), pointers, references, and `switch` statements. |
| **02**  | **Operator Overloading & Canonical Form**        | Implement operators, adhere to the Orthodox Canonical Class (copy constructor, assignment operator, destructor). |
| **03**  | **Inheritance**                                  | Create class hierarchies with single inheritance, base vs. derived classes, and constructor/destructor chaining. |
| **04**  | **Polymorphism & Abstraction**                   | Define virtual functions, abstract base classes (interfaces), and enable runtime polymorphism. |
| **05**  | **Loops & Exception Handling**                   | Use loops (`for`, `while`), handle errors with `try` / `throw` / `catch`, and define your own exceptions. |
| **06**  | **C++ Casting**                                  | Explore safe casts: `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast`. |
| **07**  | **Templates**                                    | Write generic reusable code using function and class templates. |
| **08**  | **Containers & Iterators**                       | Build templated containers, custom iterators, and implement algorithm patterns (e.g. sort, filter). |
| **09**  | **Standard Template Library (STL)**              | Apply STL containers (`vector`, `map`, `set`, etc.) and algorithms (`std::sort`, `find`, `for_each`, ...). |

---

## ✅ Getting Started

### Prerequisites
- A C++98-compatible compiler (e.g., `g++`, version ≥ 4.8).
- Make (if using provided `Makefile`s or shell scripts).

### Build & Run
Each module is self-contained:

```bash
cd cpp-module-03/          # prefix = module folder (00–09)
make                        # or `g++ -std=c++98 *.cpp -o module`
./module                    # run compiled executable
