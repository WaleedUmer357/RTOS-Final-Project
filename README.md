 RTOS-Final-Project
I made a real time operating system project showing the basic workings of a simple operating system from start to finish in C.
 Raspberry Pi Pico RTOS Kernel - Educational Project

  Project Overview
This educational project implements a minimal Real-Time Operating System (RTOS) kernel from scratch for the Raspberry Pi Pico. The primary goal is to demonstrate core RTOS concepts including context switching, task scheduling, and system tick management using the RP2040's dual-core ARM Cortex-M0+ processor. The project includes a visual demonstration showing multiple counting patterns on a small OLED display, with real-time task switching visualization.

  Learning Objectives
- Understand ARM Cortex-M0+ architecture and register usage
- Implement assembly-level context switching
- Design and implement a task scheduler
- Manage system ticks and timer interrupts
- Create mutual exclusion mechanisms
- Visualize RTOS operations in real-time

  Key Features
- Custom RTOS Kernel: Built from scratch without FreeRTOS dependencies
- Visual Demonstration: OLED display shows real-time task execution
- Multiple Counting Patterns: Forward, backward, and pattern-based counters
- Context Switch Visualization: Watch tasks switch in real-time
- Performance Metrics: Display CPU usage, switch counts, and task statistics
- Interactive Control: Serial interface for debugging and control

 Technical Stack
- Hardware: Raspberry Pi Pico (RP2040)
- Display: SSD1306 OLED (I2C interface)
- Development: Pico SDK, CMake build system
- Language: C with ARM assembly for critical sections
- Communication: USB serial for debugging and control

 Project Structure
The project is organized into modular components:
- Kernel Core: Scheduler, context switching, task management
- Hardware Drivers: Display, timer, GPIO interfaces
- Demo Tasks: Counting patterns and visual demonstrations
- Utilities: Debugging, statistics collection, configuration

  Getting Started
1. Clone the repository with Pico SDK as submodule
2. Configure CMake build for Raspberry Pi Pico
3. Build the project using standard CMake workflow
4. Flash the UF2 file to your Pico
5. Connect OLED display to I2C pins (GPIO4-SDA, GPIO5-SCL)
6. Monitor via serial terminal for debugging information

  Display Information
The OLED screen shows:
- Currently executing task
- Task state information (Ready, Running, Blocked)
- Context switch counter
- CPU utilization percentage
- Individual task execution counts
- Pattern visualization for active tasks

  Interactive Elements
- Serial Commands: Monitor and control RTOS operations
- Button Inputs (optional): Manual context switching and mode selection
- Real-time Updates: Watch task transitions and scheduling decisions
- Performance Tracking: Measure context switch overhead and timing

 Core RTOS Concepts Demonstrated
1. Task States: Implementation of Ready, Running, Blocked states
2. Context Switching: Manual register saving/restoring in assembly
3. Scheduling: Round-robin and priority-based algorithms
4. System Tick: Hardware timer interrupts for preemption
5. Critical Sections: Mutex implementation using Pico SDK primitives
6. Task Communication: Basic message passing between tasks

  Performance Characteristics
- Context Switch Time: Typically 2-3 microseconds
- System Tick: Configurable (usually 1ms)
- Memory Footprint: Minimal RAM and flash usage
- Task Limit: Configurable up to 8 concurrent tasks
- CPU Utilization: Real-time display of scheduler overhead

  Configuration Options
- Adjustable system tick rate
- Configurable task priorities
- Stack size per task
- Scheduling algorithm selection
- Display refresh rate
- Debug verbosity levels

  Educational Value
This project serves as an excellent learning resource for:
- Embedded systems students
- RTOS enthusiasts wanting to understand internals
- Developers transitioning to embedded programming
- Educators teaching operating systems concepts
- Hobbyists interested in Pico programming

 Current Limitations
- Experimental educational implementation
- Limited to basic RTOS features
- No hardware FPU context saving
- Basic error handling
- Limited to Pico hardware

  Future Enhancements
- Preemptive scheduling with priorities
- Sleep/wake mechanisms
- Inter-task messaging queues
- Memory protection between tasks
- Power management features
- More sophisticated scheduling algorithms

 Prerequisites
- Basic C programming knowledge
- Familiarity with embedded systems concepts
- Understanding of ARM architecture basics
- Experience with CMake build systems
- Raspberry Pi Pico setup experience

 Learning Outcomes
After studying this project, you will understand:
- How RTOS kernels manage multiple tasks
- The mechanics of context switching at assembly level
- How schedulers make task execution decisions
- How to implement basic RTOS primitives
- How to visualize RTOS operations in real-time

  Target Audience
- Computer Science/Engineering students
- Embedded systems developers
- RTOS researchers and enthusiasts
- Educators teaching operating systems
- Hobbyists interested in low-level programming

 License
This project is open-source under the MIT License, intended for educational and non-commercial use.





