import serial

#configure serial port
button = serial.Serial(
    port='COM7',                             #TODO: universal port 
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)

#button.open()  #prevent bugs

while(True):

    data = button.readline()
    print("Port name: ", data)