# PORTAL GUN 
Simulates the creation of portals through interactive LEDs.

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Screenshots](#screenshots)
* [Setup](#setup)
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)
* [Contact](#contact)

## General Information
This code is designed for an interactive model of a Portal Gun. 

It responds to user input through a rotary encoder to output coloured lights that simulate the Portal Gun’s in-game functions. This project aims to provide an engaging, visual experience that brings about an imagined, digital concept into the real world by applying design, coding, and electronics. 

## Technologies Used
Hardware
- Arduino UNO R4 Minima Board
- WS2812B RGB LED Strip
- Female/Male and Male/Male Jumper Wires
- Battery Snap 9v DC Lead
- 9v Battery
- USB-C to USB-C Cable
- Rotary Encoder with Pushbutton
- Black and White LEGO Bricks
- Mini Breadboard with 170 Tie Points (Optional)
  
Software 
- Arduino IDE 2.3.3
- Adafruit_Neopixel Library
- C++ Programming Language

## Features
The gun has two different portal states, blue and orange. Both portal states must be initiated before an active portal can be opened. 
An active portal, which is signified by a stable white LED, will activate as soon as both states have been triggered, otherwise, an error state will trigger and the LEDs will turn white and start blinking.

Portal States: 
-	Rotary Encoder State A: Activates the “blue portal” state and LEDs light up blue. 
-	Rotary Encoder State B: Activates the “orange portal” state and LEDs light up orange. 
-	Button Press: Opens an “active” portal and LEDs light up white.
Conditions:
-	Portal Creation Condition: Both blue and orange states must be activated to initiate an “open” portal
-	Error Condition: If the user attempts to “open” a portal without activating both blue and orange portal states, the LED turns white and starts blinking.

## Pictures

![0](https://github.com/user-attachments/assets/f9c6de7c-a74b-4a0d-b421-f01353d7a3b8)

![IMG_7912](https://github.com/user-attachments/assets/cd8ff3d4-f730-4793-b6e9-656b1c0ad8e6)


## Launch
Project Requirements/Dependencies:
- Portal Gun Code [Download Available Here: https://github.com/alecia-l/portalgun]
- Arduino IDE 2.3.3 [Download Available Here: https://www.arduino.cc/en/software]
- Adafruit_Neopixel Library [Download Available Here: https://github.com/adafruit]
  
Installation and Setup: 
- Install Arduino IDE 2.3.3 from the official Arduino website.
- Install the Adafruit_Neopixel Library from GitHub.
- Install Portal Gun code from GitHub.
- Connect the Arduino board to your computer via USB-C and port the board.
- Open Arduino IDE.
- Navigate to Sketch > Include Library > Manage Libraries.
- Search for the Adafruit_Neopixel Library installation and add it to Arduino IDE.
- Navigate to File > Open > Portal_Gun > Upload.
- Attach hardware components according to the diagram provided here: ![image](https://github.com/user-attachments/assets/052d36f1-3c2d-41b1-bdb2-ea342ffe0ed3)

Time to Play!


## Usage
Setting Portal States

  if (state == 1) {
    activatePortal(1); 
  } else if (state == 2) {
    activatePortal(2);  
  } else {
    setLEDColor(0,0,0); 
    

Triggering Portal States 

void activatePortal(int portal) {
  if (portal == 1) { 
    activatebluePortal = true; 
    activateorangePortal = false; 
    setLEDColor(0, 0, 255); 
  } else if (portal == 2) { 
    activatebluePortal = false; 
    activateorangePortal = true; 
    setLEDColor(255, 100, 0); 

    
Setting Error State

  if (digitalRead(BUTTON_PIN) == LOW) {
    if (activatebluePortal && activateorangePortal) {
      setLEDColor(255,255,255); 
    } else {
        triggerErrorState(); 
    }
  }
}


Triggering Error State

void triggerErrorState() { 
  for (int i = 0; i < 5; i++) { 
    setLEDColor(255, 255, 255); 
    delay(500); 
    setLEDColor(0, 0, 0); 
    delay(500); 
  }
}

## Project Status
Project is: _COMPLETE_ 


## Room for Improvement
While this project meets its goals of simulating the Portal Gun's functions through visual feedback, the following areas of improvement and future developments could be undertaken to improve functionality and user experience.

Areas of Improvement

Additional Engagement: The current model uses visual feedback to signify different portal states. Future iterations could include speakers to play sound effects to accompany the LEDs for additional user engagement (e.g., a victory effect when a portal activates and a loss effect when there is a portal error).

Enhanced Interactivity: The current model relies on a rotary encoder to trigger different portal states. Future iterations could include motion sensors and switches for more dynamic user interactions. 

Clean and Seamless Design: The current model uses wires for hardware connections to the Arduino board. Future iterations could include an updated model design that can hide the wires for a cleaner, more seamless look.

LED Strip Integration: The current model houses a single LED strip along the Portal Gun's inner barrel. Future iterations could include two LED strips along the inner barrel and two LED strips along the outer barrel for a more integrated and engaging user experience. 
Note: This will require access to a soldering iron.

Future Feature Developments:
- Add auditory feedback using speakers.
- Replace the rotary encoder with motion sensors and switches.
- Include more LEDs in the design.


## Acknowledgements
- My Portal Gun model was inspired by the Portal games, developed by Valve.
- This project includes a library developed by Adafruit Industries on GitHub: https://github.com/adafruit/Adafruit_NeoPixel.
- This project uses the following images as a visual reference for the model:
- https://static.wikia.nocookie.net/half-life/images/b/bb/Aperture_Science_Handheld_Portal_Device_Portal.jpg/revision/latest?cb=20110519012833&path-prefix=en;
- https://ideas.lego.com/projects/7d5b80ff-2ce5-4910-82e9-33ccdf8f41d1.

