//Juleljus-programmet

//Det här är en exempel-kommentar. Kommentarer börjar med // eller /* och är kod som datorn inte läser, utan bara programmeraren



//Här beskrivs både gradient paletts och 16-färgspaletter.


/* Vi vill att arduinon kollar i biblioteket för vissa funktioner så att vi
slipper förklara allt från början. Alla bibliotek slutar på .h. Det finns massvis med bibliotek online*/
#include <FastLED.h>



/*Nu skriver vi ner variabler som vi kan använda i många olika delar av vårt program 
Först några variabler som är konstanta, alltså inte kommer ändras.*/
const int antal_LEDs = 5;
const int pin_kopplad_till_LEDstrip = 2;

/*Här skriver vi ner lite fler variabler. Dessa kan ändras innuti programmet*/
//En lista av våra LED-lampor
CRGB LEDs[antal_LEDs]; 

//Vilken position i paletten vi börjar på
int startdel_i_paletten = 0; 

//Mellan 0 och 255
int ljusstyrka = 100; 

//Paletten är större än vår LEDstrip, så vi tar små steg
float antal_LEDS_att_hoppa = 255/antal_LEDs;

//Först skapar vi en palett som en gradient, alltså där färgen skiftar fint från ena till andra änden
DEFINE_GRADIENT_PALETTE(palette_1) {
  0, 255,   0,   0,   //På plats 0 har vi färgen (255,0,0) som är röd
  255, 255, 0,  0   //På plats 255 har vi färgen (255,0,0) igen
};

//Här skapar vi en 16-färgspalette där du väljer vad varje sextondel ska ha för färg.
CRGBPalette16 palette_2 = CRGBPalette16(
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Blue,
    
    CRGB::Blue,
    CRGB::Red,
    CRGB::Blue,
    CRGB::Blue,
    
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Blue,

    CRGB::Blue,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Blue
);


//Välj vilken palett som används denna gång:

CRGBPalette16 palette = palette_1;
//CRGBPalette16 palette = palette_2;

void setup() {
  //Kod som kör vid uppstarten:
  FastLED.addLeds<WS2812B,pin_kopplad_till_LEDstrip, GRB>(LEDs,antal_LEDs);
  FastLED.setBrightness(ljusstyrka);
}

void loop() {
  //Kod som kör om och om igen

  //Skicka paletten du gjort till LED-strippen!
  fill_palette(
  LEDs, 
  antal_LEDs,
  startdel_i_paletten,
  antal_LEDS_att_hoppa,
  palette,
  ljusstyrka,
  LINEARBLEND);

  //Här kör vi lite kod var 10e millisekund (var 100-dels sekund)
  EVERY_N_MILLISECONDS(10) {
    //Vi ökar variabeln "startdel_i_paletten" med 1 varje gång, det är vad ++ betyder.
    startdel_i_paletten++;

    //Om vi kommer till palettens sista del så börjar vi om från början
    if (startdel_i_paletten == 255){
        startdel_i_paletten = 0;
    }

  };

  FastLED.show();
}





