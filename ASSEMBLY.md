# Assembly Instructions

## Tools Needed
- 3D Printer
- Hot glue gun
- Super glue

## Cost and Materials
- OLED 0.96 inch (64x128 px) = ~$2
- Arduino Nano = ~$2
- 4 Male to Female Jumper Wires = ~$0.30
- Printed Body (23g) = ~$0.53

Total: ~$4.83

## Procedure
1. Apply super glue to the open face on the front of the larger rectangular body piece and put the OLED screen in with the male terminals going into the hole at the top of the open face.
2. Connect 4 jumper wires to the male terminals on the OLED screen.
3. Put the male end of the jumper wires through the appropriate pin hole in the Arduino Nano and use hot glue on the tips of the terminals to stop them from falling off. Soldering the wires works just as well, though I use hot glue as it is easier to adjust in case I decide to change a wire. Follow this wiring pattern: SDA to A4, SCL to A5, VCC to 3.3V, and GND to GND.
4. Place any small adjustable item on the bottom of the inside of the body. Foam, cotton, and even hot glue work good. Use your material to position the Nano's USB port to match the small hole in the back of the body. Once it is positioned, mount it with a small amount of hot glue.
5. Hot glue the lid onto the top of the main body to close it.
6. Connect a USB to your computer and Bit. Then open Arduino IDE.
7. Download the libraries: Adafruit_SSD1306 and Adafruit_GFX
8. Upload the code.ino file into the Arduino Nano.

Note: The Arduino Nano has a red light in it so you will be able to see that while it is powered. If you want to block some of that light, try painting the inside black before starting.
