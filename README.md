# AT_LineFollower

### Overview
Line Follower based on ATmega88 microcontroller. 
It is autonomous robot which detects and follows black line in white area.

Visual outlook: https://ibb.co/fnGMsa

### Description
Core that manage line follower work is ATmega88 microcontroller. For proper working it uses implementation of PD algorithm (initially PID was used but during tests it worked a bit worse than just PD so we decided to use the second one in final version). Line detection is handled by 8 reflection sensors in front, while motors are controlled by H-bridge and PWM signals.
Board is made manually from light wood to cut down weight and size as much as possible 
(design is also directed for that purpose).

Parts used:
- ATmega88 microcontroller, “the brain”
- QTR-8RC, sensors list
- 2 * 18650 acumulator, power suply
- Pololu TB6612FNG, used for motors control>
- 2 * 5V motor together with wheel (65x26mm)
- other minor components like resistors or step-down transformer (all included in schema below)

Schema link: https://easyeda.com/agedee34/LineFollower_PTM-ebb706302d924e61a77a70f42d5fbbeb

### Tools
Program was written with usage of MkClipse IDE, which is very nice tool for writing programs designed for ATmega microcontrollers (it takes care of flashing program to controller too).

### How to compile and run
No specific IDE/compiler is required - just make sure that your choice have libraries for Atmega88 included.

### Future improvements
One of ideas for improvements would be adding some additonal sensors in front of robot to detect obstacles (like small books especially placed on road) and implement method to avoid them. Also, motors could be replaced with more powerful versions.

### Attributions
Special thanks for our math lecturer dr. Piotr Rejmenciak, who after seeing our robot gave
us pen for no reason stating that he would like to give us some kind of support :)

### License
Distributed under MIT license

### Credits
Damian Michalski, Michał Mikołajczak, Piotr Zimny
Computer Science Sudents, Faculty of Electical Engineering, Poznan University of Technology.

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology. Supervisor: Adam Bondyra
