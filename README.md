# EdenPURE-500XL---Mods
EdenPURE 500XL is a nice quiet heater, but has annoying issues that caused me to want to improve it.

  # Problems
  - No onboard EEPROM, on powerup the unit defaults to max heat
  - Temperature ranges are unusable (anything below 4 is cold, 5 is way too hot)
  - Unnnecessary powerup noise

  # Hardware Specifications
  - Single Layer PCB
  - 1 output relay for heating (fan is automatically on anytime thermal switch is triggered)
  - 1 input thermistor for room temp located at back plastic grille
  - Capicitive dropper power supply (this unit is not insulated!) - Produces a -11.5V, 5.6V and 5V rail. These three rails are created by zener diodes
  - SN8P2602BPB - P-DIP 18 pin, external clock
  - 5k NTC Thermistor (first guess is B25/100 is 3988K)

  # Reverse Engineering
  - EasyEDA schematic https://oshwlab.com/johnsoncolb/edenpure-500xl
  - LED's and buttons are multiplexed
  - Migrating to the PIC16F1827 elimiantes the external clock circuitry
  - State logic will be used to display LED's and read button presses
  - Remap 5 modes to more practical temperatures
