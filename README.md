# Parallel Sortings: A Comparative Project in Serial and Parallel Programming

Welcome to the **Parallel Sortings** repository! This project explores the power of parallel programming through serial and parallel sorting algorithms implemented in **Java** (current) and **C++** (coming soon). Our aim is to illustrate how task parallelism can significantly optimize performance, particularly for large datasets.

## Project Overview

This repository is part of a college project that introduces and demonstrates the effectiveness of parallel programming. By breaking down sorting tasks and processing them simultaneously, we aim to achieve faster results than traditional serial approaches.

This project showcases:
- **Serial sorting algorithms** for baseline comparisons.
- **Parallel sorting algorithms** to highlight performance gains via task division.
- **Performance metrics** across varying dataset sizes to illustrate scalability.

## Implementations

### Java Implementation

Our Java solution implements and benchmarks various serial and parallel sorting algorithms with different array sizes to compare execution times.

#### Sorting Algorithms Included
1. **Serial Sorting Algorithms:**
   - Merge Sort
   - Bubble Sort
   - Quick Sort
   - Selection Sort
   - Insertion Sort
   - Counting Sort

2. **Parallel Sorting Algorithms:**
   - Parallel Merge Sort
   - Parallel Bubble Sort
   - Parallel Quick Sort
   - Parallel Selection Sort
   - Parallel Insertion Sort
   - Parallel Counting Sort

#### Sample Benchmark Results

Below are sample timings for each algorithm based on array sizes of **10**, **100**, **1,000**, and **10,000** elements. Results illustrate the benefits of parallel sorting as array sizes increase.

<details>
<summary>Click to expand benchmark results</summary>

##### Array Size: 10
- **Parallel Sorts**:
  - Parallel Merge Sort Time: 11,970,428 ns
  - Parallel Bubble Sort Time: 8,507,228 ns
  - Parallel Quick Sort Time: 1,919,143 ns
  - Parallel Selection Sort Time: 2,754,165 ns
  - Parallel Insertion Sort Time: 7,078,392 ns
  - Parallel Counting Sort Time: 6,335,696 ns
- **Serial Sorts**:
  - Serial Merge Sort Time: 649,523 ns
  - Serial Bubble Sort Time: 6,842 ns
  - Serial Quick Sort Time: 241,581 ns
  - Serial Selection Sort Time: 5,233 ns
  - Serial Insertion Sort Time: 7,125 ns
  - Serial Counting Sort Time: 35,799 ns

... *(and so forth for larger array sizes)*

</details>

### C++ Implementation *(Coming Soon)*

The C++ version of the sorting algorithms will be introduced to further explore performance optimizations in parallel programming. This version will:
- Use **XMake** as the build system.
- Include similar serial and parallel sorting algorithms for direct comparison with the Java implementation.
- Measure performance across varying data sizes to compare the efficiency of C++ vs. Java in parallel sorting tasks.

### Future Directions

1. **Cross-Language Comparison**: After the C++ implementation, we’ll analyze and compare performance results across Java and C++. This will provide insights into how language and runtime differences affect parallel algorithm performance.
2. **Scalability Testing**: With larger data sets, we aim to observe how the algorithms perform under increasing workloads and determine the break-even points for parallelization benefits.

## Running the Java Code

To run the Java implementation:
1. **Compile** the Java files: `javac *.java`
2. **Run the main class**: `java MainClass`
3. View the benchmark output in the console, as shown in the sample results above.

## Running the C++ Code *(Planned)*

For the upcoming C++ code:
1. Clone the repository and install **XMake** if necessary.
2. Compile and execute the program using:
   ```bash
   xmake
   xmake run
