# Automated-ChessBoard

# Techievince 8.0, Electronics Club IITG Project

# Overview
- Designed a chessboard, with a AI opponent and capable of moving the chess pieces on its own. Major Tech used are Arduino, Embedded C and for AI Micro Max chess program is used based on Minimax and Alpha-Beta algorithms. The AI played the role of computer and it could move the pieces on its own, it could also detect our moves and make a sound if invalid move is played. Human to human mode was also present.

# Introduction
- The idea of the project is to create a hardware computerized chess game which can be played without any screen and reduces our screen time.
- Chess is a game of intelligence and strategy, but playing it always on screen makes it boring.
- The objective  of this project is to maintain the same thrill of offline chess with the advantage of a computer player.

# Methodology
- All the chess pieces were magnetized and a electromagnet is used to move the pieces. The electromagnet is placed on a XY trolley which uses two stepper motors, one for X direction and other for Y direction.
![20220415_183719_mfnr 1](https://user-images.githubusercontent.com/90093681/177321888-e152768e-4c89-42ea-b307-b357a2c30bd2.jpg)
- The magnet motorization is based on core XY concept. Two motors along with belts are used to move following the X and Y axes. The main advantage of the Core XY concept compared to cartesian kinematics is to avoid having a motoron board the trolley beam. Thus the horizoontal beam is more compact and allow to have a bigger working envelope.
- The trolley is assembled on the XY table. It is equipped with an electromagnet. The electromagnet can generate a magnetic field which creates the link between the trolley and the chess pieces. So, when the trolley moves the chess pieces follow it.
- The Arduino cannot directly power the electromagnet with its output pins because they cannot deliver enough power. So, the electromagnet must be connected to an independent electric current. The advantage of the power transistor is that a low amperage is enough to control it, so it can be piloted by the Arduino.
- **Localization of chess pieces** : Magnetic sensors are placed below each chess piece square. So, when the magnet of the chess piece is above the sensor, the sensor will be activated. By comparing the activated sensors before and after the move, the chess piece displacement can be determined.
- The magnetic sensor or Reed switch is composed of a hermetic glass envelope with two flexible metal contacts inside. The contact is normally open when there is no magnetic field and close if a magnetic field is present. Multiplexers are used to connect the 64 sensors to arduino.
![20220417_091514](https://user-images.githubusercontent.com/90093681/179518228-a9dd4117-88eb-42df-b426-e506d23a51d8.jpg)
- **Special Moves** : To avoid any contact between the chess pieces, the displacement path imposes to move between two squares and not to the middle. Same for the capturing, a captured piece is pushed out of the chessboard first.

# Materials list
- Rod system(preferring this)
	- Rod 10mm -length 2000mm
	- 4 X Rod slider  8mm 
-Transmission (ROD) :
	- 2 x GT2 Pulley, 20 teeth, 5mm bore 
	- 2m x GT2 Belt
- PLYWOOD-depends:
	- Box :
		- 1 x Foamboard - 462 x 462 x 5 mm
		- 1 x Foamboard - 462 x 462 x 10 mm
		- 2 x Foamboard - 462 x 80 x 10 mm
		- 2 x Foamboard - 442 x 80 x 10 mm
- Chess : {magnetic pieces are preferred}
	- 1 x Chess pieces set - Staunton 3
	- 1 x Chessboard Sticker - Squares size : 37 x 37 mm-{printing }
	- 32 x Magnet, Dia 8 x 3 mm
- Electronics :
	- 1 x aurdino mega
	- 2 x Buy 28BYJ-4Stepper Motor with ULN2003 Motor Driver Online (robu.in)
	- 2 x Stepper Motor Driver Carrier - Pololu - A4988
	- 2 x Arcade button - Bore hole 23.5 mm
	- 1 x Electromagnet - Adafruit - 3Kg Holding Force - P25/20
	- 1 x  diode
	- 1 x MOSFET - TIP 120
	- 2x Rollers
	- 64 x Reed Switch - Dia 2 x 14.5 mm robu
	- 1 x Resistor - 1K ohm
	- 4 x MUX breakout - SparkFun - CD74HC4067
	- Female Headers
	- 10 x Screw Terminal
	- 3 x Prototyping Board - 50 x 100 mm
	- 4 x HE10 Connectors
	- 8 x Ribbon Cable - 8
	- Bluetooth module HC-05

# Conclusion
- Playing the chess in offline is a real thrill, adding a computer opponent. The AI opponent is capable of moving on its own giving the benifits of both online and offline chess games.
