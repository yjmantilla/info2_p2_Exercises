int array_to_int(char *array);
char incomingBytes[100];   // for incoming serial data
int convertednumber=0;




void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 4) {
                // read the incoming byte:
                Serial.readBytesUntil(char(13),incomingBytes,100);

                // say what you got:
                     array_to_int(incomingBytes);
        }
}

int array_to_int(char * array)
{
  for(int i=0;array[i]!=char(0);i++)
{
  Serial.println(array[i]);
Serial.println((int) (array[i]-48)*pow(10,(4-i)));
  convertednumber=convertednumber+ (array[i]-48)*pow(10,(4-i));
}
}

/*
se pueden usar delimitadores para comenzar y terminar de leer
*/
