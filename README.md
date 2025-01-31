# CPU_SCHEDULING_SIMULATOR-OS
The problem involves developing a program for process scheduling in an operating system. The program solicits user input for the number of processes, their burst times, and, in the case of Round Robin scheduling, the time quantum. It allows the user to select one of several scheduling algorithms: FCFS, SJF, Round Robin, or Priority Disk Scheduling. After this selection, the program calculates and presents the waiting time and turnaround time for each process. It also provides the average waiting time and average turnaround time for the chosen scheduling algorithm. Users have the option to implement another scheduling algorithm or exit the program. In essence, this program automates and facilitates process scheduling simulations for users.

# PROBLEM STATEMENT
To develop a program that prompts the user to input the number of processes, their burst times, and for Round Robin scheduling, the time quantum. It then allows the user to choose one of the mentioned scheduling algorithms(FCFS ,SJF, Round Robin, and Priority Disk Scheduling) . The program calculates and displays the waiting time and turnaround time for each process. Additionally, it provides the average waiting time and average turnaround time for the selected scheduling algorithm. The user is also given the option to implement another scheduling algorithm or to exit the program.

# OBJECTIVE
1. The primary objective of this project is to create a software tool that can simulate the execution of processes in a CPU using different scheduling algorithms and then evaluate their performance based on two key metrics:
a. Average Waiting Time: This metric measures the average amount of time a process spends waiting in the ready queue before getting CPU time.
b. Average Turnaround Time: It calculates the average time taken for a process to complete execution, from arrival in the ready queue to termination.

2. Simulation:
The heart of this project is the simulation component, where the software emulates the behavior of different scheduling algorithms on a set of processes. Here's how it works:
a. Input Parameters: The program prompts the user to input various parameters:
- Number of processes: The quantity of processes to be scheduled.
- Burst times: The execution time required for each process.
- Time quantum (for Round Robin scheduling): The maximum amount of CPU time each process can have in a single turn.
- Priority levels (for Priority Disk Scheduling): A priority associated with each process, which dictates the order of execution.
b. Scheduling Algorithms: The user selects one of the available scheduling algorithms (FCFS, SJF, Round Robin, or Priority Disk Scheduling).
c. Simulation Execution: The simulator runs the chosen scheduling algorithm on the provided processes and records data for each process, such as waiting time, turnaround time, and completion order.
d. Performance Metrics Calculation: After simulating all processes, the simulator calculates the average waiting time and average turnaround time based on the data recorded during execution.

3. Performance Evaluation:
Once the simulation is complete, the program provides the following valuable information:
- Waiting Time and Turnaround Time for each individual process, which allows users to assess the efficiency of the selected algorithm for each process.
- Average Waiting Time: This metric provides insight into how efficiently the selected algorithm utilizes CPU time, as a lower average waiting time indicates better performance.
- Average Turnaround Time: This metric reflects how quickly processes are completed, making it another critical performance indicator.
  
4. Comparative Analysis:
This project is valuable for conducting comparative analyses of different scheduling algorithms. Users can assess how each algorithm performs on the same set of processes, making it easier to choose the most suitable algorithm for specific scenarios.

5. User Interaction:
The program should be user-friendly, allowing users to select scheduling algorithms, input process data, and view the results. Additionally, the option to choose different scheduling algorithms or exit the program should be provided for versatility.

6. Educational and Research Use:
Such a simulator is crucial for educational purposes in teaching operating systems concepts and for conducting research on process scheduling algorithms. It allows students, researchers, and practitioners to gain a better understanding of how scheduling decisions impact system performance.

# Scheduling Algorithms:
- Depending on the user's choice, the program should execute the selected scheduling algorithm.
Here's a brief overview of how each algorithm works:
- First-Come-First-Serve (FCFS): The processes are executed in the order they arrive.
- Shortest Job First (SJF): The process with the shortest burst time is executed first.
- Round Robin: Each process gets a fixed time quantum to execute in a cyclic manner. If a process doesn't complete in the time quantum, it's moved to the end of the queue.
- Priority Disk Scheduling: Processes are executed based on their priority levels. The process with the highest priority goes first.
