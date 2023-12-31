# File Search Program

## Overview

This is a simple file search program implemented in C. The program uses various algorithms, including the Breadth-First Search (BFS) algorithm for directory traversal and the Knuth-Morris-Pratt (KMP) algorithm for pattern matching within files. The search results are organized using a custom data structure called `SearchResult`.

## Algorithms

### Breadth-First Search (BFS)

The BFS algorithm is employed to traverse the directory structure in a breadth-first manner. It starts from the provided starting directory and explores all its immediate subdirectories before moving on to their subdirectories. This ensures that files at shallower levels are found before those at deeper levels.

### Knuth-Morris-Pratt (KMP)

The KMP algorithm is used for efficient pattern matching within files. It allows the program to search for a specific pattern (e.g., a target file name) in a file by avoiding unnecessary backtracking, resulting in faster and more efficient searches.

### Path Construction

When constructing paths during BFS traversal, the program takes care to concatenate paths correctly to avoid issues such as double slashes in the resulting paths. Proper path concatenation ensures that the paths are well-formed and readable.

## Data Structures

### Queue

The BFS algorithm relies on a queue data structure for managing the order of directory exploration. A linked list-based queue is implemented to efficiently enqueue and dequeue directories during traversal.

```c
typedef struct Node {
    char* path;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;
```

### SearchResult

The program uses a custom `SearchResult` struct to organize and store the paths of the found files. The struct contains an array of paths (`char**`) and the number of paths (`int num_paths`).

```c
typedef struct {
    char** paths;
    int num_paths;
} SearchResult;
```

## Usage

To use the program, provide the starting path and target file as command-line arguments:

```bash
make
./file_search /path/to/search example.txt
```
