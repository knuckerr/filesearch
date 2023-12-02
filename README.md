# File Search Program

## Overview

This is a simple file search program implemented in C. The program uses the Breadth-First Search (BFS) algorithm to search for a specific file in a given directory and its subdirectories. The search results are organized using a custom data structure called `SearchResult`.

## Algorithms

### Breadth-First Search (BFS)

The BFS algorithm is employed to traverse the directory structure in a breadth-first manner. It starts from the provided starting directory and explores all its immediate subdirectories before moving on to their subdirectories. This ensures that files at shallower levels are found before those at deeper levels.

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
./file_search /path/to/search example.txt
```

The program will then perform a BFS search and display the paths of the found files.
