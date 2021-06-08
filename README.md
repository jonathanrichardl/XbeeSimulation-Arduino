Written by Jonathan Richard

Department of Electrical Engineering, Universitas Indonesia

# XbeeSimulationProteus
Codes to demonstrate RF communication with XBEE simulated in proteus, some codes are written in pure c (by manually manipulating the registers) to maximize performance. 

# Simulation files and Libraries
https://drive.google.com/drive/folders/1XGEHeAsKerrETIPeHEtcSmYXzOPMelAV 

# How this works
The arduino on the left will decode the data from the GPS Module. Then will transmit the decoded data with the Xbee module into the arduino on the right. Where the arduino will log the gps data into the SDCard. You can also press the button on the receiver arduino to trigger interrupt, that will also trigger the LED on transmitter arduino (with some delays because of the Serial Communication of GPS Data may be still ongoing) 
