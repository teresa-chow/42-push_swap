# Push_swap
[![42 School: Rank 2](https://img.shields.io/badge/42%20School-Rank%202-%2315bbbb)](https://www.42network.org/)

_Push_swap is a project about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. Its goal is reaching an optimized data sorting solution._

___


### Table of contents
[Subject notes](#subject-notes) · [Usage](#usage) · [License](#license)

___

</br>

# Subject notes

Notes on the subject and further reading : [here](https://github.com/teresa-chow/42-push_swap/wiki).

___

</br>

# Usage
## Setup and compilation

1. Clone repository
    ```bash
    git clone git@github.com:teresa-chow/42-push_swap.git push_swap
    ```

2. Go inside project directory and run `make`
    ```bash
    cd push_swap
    make
    ```

3. Execute `push_swap` program
    ```bash
    ./push_swap "<random set of integers>"
    ```
    or
   ```bash
   ./push_swap 0 5 -1 3
   ```
   
4. To check if the program is sorting different sets of numbers correctly, export the variable `ARG` and test the program (repeat as needed)
   ```bash
   export ARG="<random set of integers>"
   make test
   ```

___

</br>

## Approach

For stacks of up to 5 elements, a brute force approach is used.
Otherwise, for bigger sets, steps taken are the following:

#### I. Find key values: median and 5 higher values
- Find the median of the data set. Here, if the given data set has an even number of observations, we have considered the upper middle value to be the "median".
- Find the 5 bigger values in the given data set.

#### II. Push median to stack b
- According to the position of the median value in the stack, rotate it (if in the top half of the stack) or reverse rotate it (if in the bottom half).
- Push it to stack b.

#### III. Push other elements to stack b
- Push other elements to stack b, leaving the 5 higher values in stack a.
- Check if the element is above or below median. If above, rotate stack b after pushing, to have values above median in the bottom half of stack b.
- Sort the 5 remaining values in stack a.

#### IV. Evaluate operation cost and move elements accordingly
- Find the next higher value in stack a to every node in stack b and calculate movement cost (higher number of necessary operations = higher cost).
- Choose to move the element with an associated lower cost.
- Repeat this step until stack b is empty again.

___

</br>

### License
This work is published under the terms of [42 Unlicense](./LICENSE).

</br>

[⬆ back to top](#push_swap)
