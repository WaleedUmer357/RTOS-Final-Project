<h3>🖥️ Operating Systems & Software</h3>

- <b><a href="https://github.com/WaleedUmer357/RTOS-Final-Project">Raspberry Pi Pico RTOS Kernel - Educational Project</a></b>
  - Real-Time Operating System built from scratch for Raspberry Pi Pico
  - <a href="https://github.com/WaleedUmer357/RTOS-Final-Project/tree/main/src">Source Code</a> | <a href="https://youtube.com/shorts/ePrvbYPfnaA">Demo Video</a>
  <details>
  <summary>⚙️ Click to view Project Details</summary>
  <br>
  
  <h4>🚀 Project Overview</h4>
  <p>This educational project implements a minimal Real-Time Operating System (RTOS) kernel from scratch for the Raspberry Pi Pico. The primary goal is to demonstrate core RTOS concepts including context switching, task scheduling, and system tick management using the RP2040's dual-core ARM Cortex-M0+ processor. The project includes a visual demonstration showing multiple counting patterns on a small OLED display, with real-time task switching visualization.</p>
  
  <h4>🎯 Learning Objectives</h4>
  <ul>
    <li>Understand ARM Cortex-M0+ architecture and register usage</li>
    <li>Implement assembly-level context switching</li>
    <li>Design and implement a task scheduler</li>
    <li>Manage system ticks and timer interrupts</li>
    <li>Create mutual exclusion mechanisms</li>
    <li>Visualize RTOS operations in real-time</li>
  </ul>
  
  <h4>✨ Key Features</h4>
  <ul>
    <li><b>Custom RTOS Kernel:</b> Built from scratch without FreeRTOS dependencies</li>
    <li><b>Visual Demonstration:</b> OLED display shows real-time task execution</li>
    <li><b>Multiple Counting Patterns:</b> Forward, backward, and pattern-based counters</li>
    <li><b>Context Switch Visualization:</b> Watch tasks switch in real-time</li>
    <li><b>Performance Metrics:</b> Display CPU usage, switch counts, and task statistics</li>
    <li><b>Interactive Control:</b> Serial interface for debugging and control</li>
  </ul>
  
  <h4>🛠️ Technical Stack</h4>
  <table>
    <tr>
      <td><b>Hardware</b></td>
      <td>Raspberry Pi Pico (RP2040)</td>
    </tr>
    <tr>
      <td><b>Display</b></td>
      <td>SSD1306 OLED (I2C interface)</td>
    </tr>
    <tr>
      <td><b>Development</b></td>
      <td>Pico SDK, CMake build system</td>
    </tr>
    <tr>
      <td><b>Language</b></td>
      <td>C with ARM assembly for critical sections</td>
    </tr>
    <tr>
      <td><b>Communication</b></td>
      <td>USB serial for debugging and control</td>
    </tr>
  </table>
  
  <h4>📁 Project Structure</h4>
  <p>The project is organized into modular components:</p>
  <ul>
    <li><b>Kernel Core:</b> Scheduler, context switching, task management</li>
    <li><b>Hardware Drivers:</b> Display, timer, GPIO interfaces</li>
    <li><b>Demo Tasks:</b> Counting patterns and visual demonstrations</li>
    <li><b>Utilities:</b> Debugging, statistics collection, configuration</li>
  </ul>
  
  <h4>🖼️ RTOS Implementation Code Gallery</h4>
  
  <p><b>💾 Task Management - Remove Task Implementation</b></p>
  <p>Core function for removing tasks from the scheduler, including critical section handling and task list updates.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.07.22 AM (1).jpeg" alt="Remove Task Function" width="800"/>
  
  <p><b>📋 Task Interface - User Interaction Code</b></p>
  <p>Implementation of Task6 showing user input handling for task removal with validation and error handling via serial interface.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.07.22 AM.jpeg" alt="Task Interface Code" width="800"/>
  
  <p><b>⏰ System Tick Configuration</b></p>
  <p>SysTick timer configuration for RTOS timing (125MHz = 125000 cycles/ms). This critical code sets up the hardware timer for task preemption.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.07.23 AM (1).jpeg" alt="SysTick Configuration" width="800"/>
  
  <p><b>🔄 Scheduler Implementation - Core Algorithm</b></p>
  <p>Round-robin scheduler implementation showing task selection logic, quantum management, and context switching decisions.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.07.23 AM (3).jpeg" alt="Scheduler Implementation" width="800"/>
  
  <p><b>📥 Load Task Function - Task Creation</b></p>
  <p>Complete implementation of task loading including TCB initialization, stack frame setup, and linked list management.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.07.23 AM.jpeg" alt="Load Task Function" width="800"/>
  
  <p><b>🎬 Initialization Scheduler Setup</b></p>
  <p>RTOS initialization code showing task list setup, TCB initialization, and system startup sequence.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.07.24 AM.jpeg" alt="Initialize Scheduler" width="800"/>
  
    <p><b>🖥️ Serial Monitor - Runtime Debugging</b></p>
  <p>Real-time serial monitor output showing task interactions, user commands, and system responses during RTOS execution.</p>
  <img src="Images/WhatsApp Image 2026-01-22 at 12.08.12 AM (1).jpeg" alt="Serial Monitor Output" width="800"/>
  
  <h4>🚀 Getting Started</h4>
  <ol>
    <li>Clone the repository with Pico SDK as submodule</li>
    <li>Configure CMake build for Raspberry Pi Pico</li>
    <li>Build the project using standard CMake workflow</li>
    <li>Flash the UF2 file to your Pico</li>
    <li>Connect OLED display to I2C pins (GPIO4-SDA, GPIO5-SCL)</li>
    <li>Monitor via serial terminal for debugging information</li>
  </ol>
  
  <h4>🧠 Core RTOS Concepts Demonstrated</h4>
  <ol>
    <li><b>Task States:</b> Implementation of Ready, Running, Blocked states</li>
    <li><b>Context Switching:</b> Manual register saving/restoring in assembly</li>
    <li><b>Scheduling:</b> Round-robin and priority-based algorithms</li>
    <li><b>System Tick:</b> Hardware timer interrupts for preemption</li>
    <li><b>Critical Sections:</b> Mutex implementation using Pico SDK primitives</li>
    <li><b>Task Communication:</b> Basic message passing between tasks</li>
  </ol>
  
  <h4>⚡ Performance Characteristics</h4>
  <table>
    <tr>
      <td><b>Context Switch Time</b></td>
      <td>2-3 microseconds</td>
    </tr>
    <tr>
      <td><b>System Tick</b></td>
      <td>Configurable (typically 1ms)</td>
    </tr>
    <tr>
      <td><b>Memory Footprint</b></td>
      <td>Minimal RAM and flash usage</td>
    </tr>
    <tr>
      <td><b>Task Limit</b></td>
      <td>Up to 8 concurrent tasks</td>
    </tr>
    <tr>
      <td><b>Scheduler Overhead</b></td>
      <td>Real-time CPU utilization display</td>
    </tr>
  </table>
  
  <h4>💻 Code Highlights</h4>
  <ul>
    <li><b>Task Control Block (TCB):</b> Custom structure for storing task state, stack pointer, and priority</li>
    <li><b>Context Switching:</b> Low-level assembly code for saving/restoring ARM Cortex-M0+ registers</li>
    <li><b>Round-Robin Scheduling:</b> Fair time-slicing algorithm with configurable quantum</li>
    <li><b>SysTick Handler:</b> Interrupt-driven preemptive multitasking</li>
    <li><b>Critical Sections:</b> Interrupt disable/enable for atomic operations</li>
    <li><b>Stack Management:</b> Individual stack allocation per task with overflow detection</li>
  </ul>
  
  <h4>🎮 Interactive Elements</h4>
  <ul>
    <li><b>Serial Commands:</b> Monitor and control RTOS operations</li>
    <li><b>Task Creation/Deletion:</b> Dynamic task management at runtime</li>
    <li><b>Real-time Updates:</b> Watch task transitions and scheduling decisions</li>
    <li><b>Performance Tracking:</b> Measure context switch overhead and timing</li>
  </ul>
  
  <h4>📚 Educational Value</h4>
  <p>This project serves as an excellent learning resource for:</p>
  <ul>
    <li>Embedded systems students</li>
    <li>RTOS enthusiasts wanting to understand internals</li>
    <li>Developers transitioning to embedded programming</li>
    <li>Educators teaching operating systems concepts</li>
    <li>Hobbyists interested in Pico programming</li>
  </ul>
  
  <h4>⚠️ Current Limitations</h4>
  <ul>
    <li>Experimental educational implementation</li>
    <li>Limited to basic RTOS features</li>
    <li>No hardware FPU context saving</li>
    <li>Basic error handling</li>
    <li>Limited to Pico hardware</li>
  </ul>
  
  <h4>🔮 Future Enhancements</h4>
  <ul>
    <li>Preemptive scheduling with priorities</li>
    <li>Sleep/wake mechanisms</li>
    <li>Inter-task messaging queues</li>
    <li>Memory protection between tasks</li>
    <li>Power management features</li>
    <li>More sophisticated scheduling algorithms</li>
  </ul>
  
  <h4>🎓 Learning Outcomes</h4>
  <p>After studying this project, you will understand:</p>
  <ul>
    <li>How RTOS kernels manage multiple tasks</li>
    <li>The mechanics of context switching at assembly level</li>
    <li>How schedulers make task execution decisions</li>
    <li>How to implement basic RTOS primitives</li>
    <li>How to debug embedded systems via serial interface</li>
  </ul>
  
  <h4>📖 You Tube Demonstration Videos </h4>
  <ul>
    <li><a href="https://youtube.com/shorts/ePrvbYPfnaA">Raspberry Pi Pico Demo</a></li>
  </ul>
  
  <h4>📜 License</h4>
  <p>This project is open-source under the MIT License, intended for educational and non-commercial use.</p>
  
  <p><b>Author:</b> Waleed Umer | Griffith University</p>
  <p><b>Project Type:</b> Educational RTOS Implementation</p>
  <p><b>Hardware Platform:</b> Raspberry Pi Pico (RP2040)</p>
  
  </details>
