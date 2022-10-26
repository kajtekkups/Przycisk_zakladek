import serial
import webbrowser

#configure serial port
button = serial.Serial(
    port='COM7',                             #TODO: universal port 
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)

def choose_the_link(transfered_number):
    options = {
        1: 'https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab_channel=RickAstley',
        2: 'https://pl.wikipedia.org/wiki/Paradoks_Monty%E2%80%99ego_Halla#:~:text=Paradoks%20polega%20na%20tym%2C%20%C5%BCe,przecie%C5%BC%20%E2%80%9Enic%20nie%20wiadomo%E2%80%9D.',
        3: 'https://en.wikipedia.org/wiki/Embedded_system'
    }
    return options.get(transfered_number)

while(True):

    #reads signal send by atmega via COM port and converts it to more friendly format
    transfer_data = list(button.readline())

    link = choose_the_link(transfer_data[0])
    webbrowser.open(link)
