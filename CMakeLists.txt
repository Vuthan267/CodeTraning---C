cmake_minimum_required(VERSION 4.4)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C
        # "divide & conquer/main.c"
        "divide & conquer/mergesort.c"
        "divide & conquer/mergesort.h"
        "divide & conquer/quicksort.c"
        "divide & conquer/quicksort.h"
        "divide & conquer/binarysearch.c"
        "divide & conquer/binarysearch.h"
        "divide & conquer/power.c"
        "divide & conquer/power.h"
        "divide & conquer/karatsuba.c"
        "divide & conquer/karatsuba.h"
        "divide & conquer/closest2points.c"
        "divide & conquer/closest2points.h"
        # greedy/main.c
        greedy/atm.c
        greedy/atm.h
        greedy/fracknap.c
        greedy/fracknap.h
        greedy/tsp.c
        greedy/tsp.h
        greedy/cookie.c
        greedy/cookie.h
        greedy/stock.c
        greedy/stock.h
        greedy/activity.c
        greedy/activity.h
        greedy/jump.c
        greedy/jump.h
        greedy/jobsequencing.c
        greedy/jobsequencing.h
        # "dynamic programming/main.c"
        "dynamic programming/rodcutting.c"
        "dynamic programming/rodcutting.h"
        "dynamic programming/fibonacci.c"
        "dynamic programming/fibonacci.h"
        "dynamic programming/climbstairs.c"
        "dynamic programming/climbstairs.h"
        "dynamic programming/robber.c"
        "dynamic programming/robber.h"
        "dynamic programming/coinchange.c"
        "dynamic programming/coinchange.h"
        "dynamic programming/mincostpath.c"
        "dynamic programming/mincostpath.h"
        "dynamic programming/decode.c"
        "dynamic programming/decode.h"
        "dynamic programming/knapsackdynamic.c"
        "dynamic programming/knapsackdynamic.h"
        "dynamic programming/lcs.c"
        "dynamic programming/lcs.h"
        "dynamic programming/minpathtriangle.c"
        "dynamic programming/minpathtriangle.h"
        # backtracking/main.c
        backtracking/nqueen.c
        backtracking/nqueen.h
        backtracking/permutationstring.c
        backtracking/permutationstring.h
        backtracking/subsetsum.c
        backtracking/subsetsum.h
        backtracking/mazerat.c
        backtracking/mazerat.h
        backtracking/allsubset.c
        backtracking/allsubset.h
        backtracking/combinationalsum.c
        backtracking/combinationalsum.h
        backtracking/hamiltoniancycle.c
        backtracking/hamiltoniancycle.h
        branchandbound/main.c
        branchandbound/atm.c
        branchandbound/atm.h
        # sorting/main.c
        sorting/bubblesort.c
        sorting/bubblesort.h
        sorting/insertionsort.c
        sorting/insertionsort.h
        sorting/selectionsort.c
        sorting/selectionsort.h
        sorting/heapsort.c
        sorting/heapsort.h
        branchandbound/atmSetup.c
        branchandbound/knapBnB.c
        branchandbound/knapBnB.h
        branchandbound/tspBnB.c
        branchandbound/tspBnB.h
)

target_link_libraries(C m)