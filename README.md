## WEEK 4 
This week is about Singly and Doubly Linked Lists.

##  Key Features
Both implementations support the following core operations:
- **Dynamic Insertion:** Start, end, and specific positions.
- **Node Management:** Efficient deletion and value updates.
- **Optimized Performance:** Utilizes **Tail Pointers** and **Node Counts** to reduce complexity.

  ## 🛠️ Optimization Highlights
According to standard lab practices, these implementations include specific enhancements to overcome standard performance bottlenecks:

| Optimization | Benefit | Impact |
| :--- | :--- | :--- |
| **Tail Pointer** | Eliminates O(n) traversal for end-of-list operations. | `addAtEnd` becomes **O(1)** |
| **Node Count** | O(1) size tracking and position validation. | `getSize()` becomes **O(1)** |
| **Bidirectional (DLL)** | Direct access to the `prev` pointer. | `deleteLastNode` becomes **O(1)** |

# 🚀 Getting Started

Follow these steps to set up the project environment and execute the application on your local machine.

---

### 📋 Prerequisites

Before you begin, ensure you have a **C++ Compiler** installed. This project is optimized for modern standards.

| Component | Requirement | Check Command |
| :--- | :--- | :--- |
| **Compiler** | GCC / Clang / MSVC | `g++ --version` |
| **Standard** | C++11 or higher | `g++ -std=c++11` |
| **OS** | Windows, Linux, or macOS | `uname -a` |

> [!TIP]
> If you are on Windows, **MinGW** or **MSYS2** are great options for getting the `g++` compiler.

---

### 🛠️ Installation & Execution

Follow this sequence of commands in your terminal:

#### **1️⃣ Clone the Repository**
First, download the source code to your machine:
```bash
git clone https://github.com/manto187/Data-Structures-Algorithms.git
   ```

### 📂 Step 2: Navigate to the Task Directory
Move into your project folder to start working with the source files.

| OS Platform | Command |
| :--- | :--- |
| **Linux / macOS** | `cd task-directory` |
| **Windows (CMD/PS)** | `cd task-directory` |

> [!TIP]
> Use the `ls` (or `dir` on Windows) command to verify you are in the correct folder before proceeding.

---

### ⚙️ Step 3: Compile and Run
Convert your source code into an executable file and launch it immediately.

#### **Quick Compilation Guide**
Choose the command that matches your terminal environment:
#### **For Linus/macOS/Git Bash**
```bash
g++ main.cpp -o app && ./app
```
#### **For Windows PowerShell**
```bash
g++ main.cpp -o app; if ($?) { .\app }
```
