

/*
 * Program for filtering the X-axis values of accel and transmitting it serially
 * Programmed by B.Aswinth Raj
 * Dated: 21-08-206
 */

#define AccelPin      A0         // A0 is connected to X-axis of Accel
#define Samplesize   13         // filterSample number
int Array1 [Samplesize];           // array for holding raw sensor values for sensor

int rawData1, smoothData1;      // variables for sensor data

int toSend;

void setup(){
  Serial.begin(9600);
//  Serial.begin(38400);
}

void loop()
{     
  rawData1 = analogRead(AccelPin);                              // read X-axis of accelerometer
  smoothData1 = digitalSmooth(rawData1, Array1);  

  toSend = map (smoothData1, 193, 280, 0, 255);             // the data from accelerometer mapped to form a byte
  Serial.write (toSend);
  delay(100);
}

  int digitalSmooth(int rawIn, int *sensSmoothArray){         // "int *sensSmoothArray" passes an array to the function - the asterisk indicates the array name is a pointer
  int j, k, temp, top, bottom;
  long total;
  static int i;
  static int sorted[Samplesize];
  boolean done;

  i = (i + 1) % Samplesize;                  // increment counter and roll over if necc. -  % (modulo operator) rolls over variable
  sensSmoothArray[i] = rawIn;           // input new data into the oldest slot

  for (j=0; j<Samplesize; j++){           // transfer data array into anther array for sorting and averaging
    sorted[j] = sensSmoothArray[j];
  }

  done = 0;                    // flag to know when we're done sorting              
  while(done != 1){        // simple swap sort, sorts numbers from lowest to highest
    done = 1;
    for (j = 0; j < (Samplesize - 1); j++){
      if (sorted[j] > sorted[j + 1]){        // numbers are out of order - swap
        temp = sorted[j + 1];
        sorted [j+1] =  sorted[j] ;
        sorted [j] = temp;
        done = 0;
      }
    }
  }

  bottom = max(((Samplesize * 15)  / 100), 1); 
  top = min((((Samplesize * 85) / 100) + 1  ), (Samplesize - 1));   // the + 1 is to make up for asymmetry caused by integer rounding
  k = 0;
  total = 0;
  for ( j = bottom; j< top; j++){
    total += sorted[j];         // total remaining indices
    k++; 

  }

  return total / k;            // divide by number of samples
}
