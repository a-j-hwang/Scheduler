# Scheduler

This C/C++ program is a simple simulation of two scheduler algorithm, FIFO and Round Robin. Each process has 4 values attached to them: R1, B1, R2, B2. 
R1 is the first run time before B1, the first blocked time. R2 is how long it should be executed after B1, and B2 follows it as time to be blocked before termination process. The termination process lasts 1ms, and treated the same way as other regular running time.
All processes have the same creation time, and when priority is in tie, one that comes alphabetically first is executed. 

Input values are to be set as following, with a single spacing in between them.

n SA q R1₁ B1₁ R2₁ B2₁, ..., R1ₙ B1ₙ R2ₙ B2ₙ

n is the number of processes.
SA The scheduling algorithm to use. 1 signifies FIFO; 2 signifies RR with quantum q. q The quantum for RR scheduling. q is present only if SA=2.
R1₁ B1₁ R2₁ B2₁, ..., R1ₙ B1ₙ R2ₙ B2ₙ are the four running and blocking times for each process. Since that last run is always for 1 time unit, no input is needed for its specification.

Instructions:

Complie and run it as regular c++ file on Linux machine using command

g++ Lab2.c

followed by

./a.out

input should be as provided in the lab sheet,
2+4*n / 3+4*n integers with a space in between them

ex) 
2 2 2 3 2 3 2 3 2 3 2
2 1 3 2 3 2 3 2 3 2

Author- Alicia Hwang
