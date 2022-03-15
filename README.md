# Mediantor-cpp
Mediantor is a container that stores a collection of integers and provides only two operations:

* `Insert(x)` - adds _x_ to collection;
* `Take()` - returns the value of the median element in the collection and removes this element.

This project provides three implementations of Mediantor:

1. As a sorted list, with complexity _O(N)_ for each operation;
2. As SQR-decomposition, with complexity _O(sqrt(N))_ for each operation;
3. As two heaps, with complexity _O(log(N))_ for each operation.

## Building

This project has submodules, so after cloning it, don't forget to run

`$ git submolude update --init --recursive`

Use CMake and any compiler to build the project. No additional input is required.

## Running

Run demo.exe (or just "demo", if you are not using Windows) to manually test the project. See the section below about the structure of a test input.

Run test.exe to get results of automated testing.

## Structure of a test input

The first line of input should contain one single integer _n_ (1 ≤ _n_ ≤ 10<sup>5</sup>) - a number of operations with Mediantor.

The following _n_ lines should contain descriptions of these operations. If the line reads like

`1 x`,

it means that `Insert(x)` will be performed (-10<sup>9</sup> ≤ _x_ ≤ 10<sup>9</sup>). If the line contains one single zero, it means that `Take()` performed.

It is granted that `Take()` will not be called when Mediantor is empty.

Manual tests should follow the same rules.

## Structure of a test output

For each called `Take()`, output will contain a line with a returned number.

## Example

| Input       | Output      |
| ----------- | ----------- |
| 10          | 3           |
| 1 1         | 2           |
| 1 2         | 5           |
| 1 5         | 1           |
| 1 3         |             |
| 1 9         |             |
| 0           |             |
| 0           |             |
| 0           |             |
| 1 -3        |             |
| 0           |             |
