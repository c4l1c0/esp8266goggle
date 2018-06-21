import ddf.minim.analysis.*;
import ddf.minim.*;
import websockets.*;
 
Minim minim;
WebsocketClient wsc;
AudioInput in;
FFT fft;
float[] peaks;

int peak_hold_time = 1;
int[] peak_age;

int binsperband = 5;
int peaksize;

int buffer_size = 1024;
float sample_rate = 44100;

int spectrum_height = 176;

int[] freq_array = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int i,g;
float f;


float[] freq_height = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup()
{
  size(200, 200);

  minim = new Minim(this);
 
  in = minim.getLineIn(Minim.MONO,buffer_size,sample_rate);
  fft = new FFT(in.bufferSize(), in.sampleRate());
  fft.window(FFT.HAMMING);
  peaksize = 1+Math.round(fft.specSize()/binsperband);
  peaks = new float[peaksize];
  peak_age = new int[peaksize];

  wsc=new WebsocketClient(this, "ws://192.168.0.1:81");
}
String fftData;
String fftCopy;

void draw()
{
for(int k=0; k<16; k++){
freq_array[k] = 0;
}

  fft.forward(in.mix);
  freq_height[0] = fft.calcAvg((float) 0, (float) 50);
  freq_height[1] = fft.calcAvg((float) 51, (float) 69);
  freq_height[2] = fft.calcAvg((float) 70, (float) 94);
  freq_height[3] = fft.calcAvg((float) 95, (float) 129);
  freq_height[4] = fft.calcAvg((float) 130, (float) 176);
  freq_height[5] = fft.calcAvg((float) 177, (float) 241);
  freq_height[6] = fft.calcAvg((float) 242, (float) 331);
  freq_height[7] = fft.calcAvg((float) 332, (float) 453);
  freq_height[8] = fft.calcAvg((float) 454, (float) 620);
  freq_height[9] = fft.calcAvg((float) 621, (float) 850);
  freq_height[10] = fft.calcAvg((float) 851, (float) 1241);
  freq_height[11] = fft.calcAvg((float) 1242, (float) 1600);
  freq_height[12] = fft.calcAvg((float) 1601, (float) 2200);
  freq_height[13] = fft.calcAvg((float) 2201, (float) 3000);
  freq_height[14] = fft.calcAvg((float) 3001, (float) 4100);
  freq_height[15] = fft.calcAvg((float) 4101, (float) 5600);
   

  for(int j=0; j<16; j++){    
    if (freq_height[j] < 200000 && freq_height[j] > 150){freq_array[j] = 8;}
    else{ if (freq_height[j] <= 250 && freq_height[j] > 100){freq_array[j] = 7;}
    else{ if (freq_height[j] <= 160 && freq_height[j] > 75){freq_array[j] = 6;}
    else{ if (freq_height[j] <= 140 && freq_height[j] > 50){freq_array[j] = 5;}
    else{ if (freq_height[j] <= 50 && freq_height[j] > 40){freq_array[j] = 4;}
    else{ if (freq_height[j] <= 40 && freq_height[j] > 30){freq_array[j] = 3;}
    else{ if (freq_height[j] <= 30 && freq_height[j] > 10){freq_array[j] = 2;}
    else{ if (freq_height[j] <= 10 && freq_height[j] >= 1 ){freq_array[j] = 1;}
    else{ if (freq_height[j] < 1 ){freq_array[j] = 0;}
  }}}}}}}}}

  fftData="!";
  for(i=0; i<16; i++){
    fftData+=freq_array[i];
  }
  if(fftData != fftCopy){
    wsc.sendMessage(fftData);
    fftCopy=fftData;
  }
  delay(15)
}
 
 
void stop()
{
  in.close();
  minim.stop();
  super.stop();
}
