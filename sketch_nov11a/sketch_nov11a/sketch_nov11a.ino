#include <Servo.h> //Servo kütüphanesi
 
// Saniye

Servo YATAY;
int servo_yatay = 180;
int servo_yatay_ust_limit = 180;
int servo_yatay_alt_limit = 25;

Servo DIKEY;
int servo_dikey = 45;
int servo_dikey_ust_limit= 80;
int servo_dikey_alt_limit= 15;

int sol_ust = 0; //LDR sol üst
int sag_ust = 1; //LDR sağ üst
int sol_alt = 2; //LDR sol alt
int sag_alt = 3; //LDR sağ alt
 
void setup()
{
Serial.begin(9600);
// Servo bağlantısı
// Pin bağlantısı
YATAY.attach(9);
DIKEY.attach(10);
YATAY.write(90);
delay(1000);
DIKEY.write(45);
delay(5000);
}
 
void loop()
{
int sol_ust_dijital = analogRead(sol_ust); // sol üst
int sag_ust_dijital = analogRead(sag_ust); // sağ üst
int sol_alt_dijital = analogRead(sol_alt); // sol alt
int sag_alt_dijital = analogRead(sag_alt); // sağ alt
 

int zaman = 10;  // Milisaniye
int deger = 50;  // Ldr deger farkları
 
int ortalama_ust = (sol_ust_dijital + sag_ust_dijital) / 2;
int ortalama_alt = (sol_alt_dijital + sag_alt_dijital) / 2; 
int ortalama_sol = (sol_ust_dijital + sol_alt_dijital) / 2; 
int ortalama_sag = (sag_ust_dijital + sag_alt_dijital) / 2; 
 
int fark_ust_alt = ortalama_ust - ortalama_alt; 
int fark_sol_sag = ortalama_sol - ortalama_sag;
 
 
Serial.print(ortalama_ust);
Serial.print(" ");
Serial.print(ortalama_alt);
Serial.print(" ");
Serial.print(ortalama_sol);
Serial.print(" ");
Serial.print(ortalama_sag);
Serial.print(" ");
Serial.print(zaman);
Serial.print(" ");
Serial.print(deger);
Serial.println(" ");
 
 
if (-1*deger > fark_ust_alt || fark_ust_alt > deger) // aralıktaki fark değer ile karşılaştırılıyor
{
if (ortalama_ust > ortalama_alt)
{
servo_dikey = ++servo_dikey;
if (servo_dikey > servo_dikey_ust_limit)
{
servo_dikey = servo_dikey_ust_limit;
}
}
else if (ortalama_ust < ortalama_alt)
{
servo_dikey= --servo_dikey;
if (servo_dikey < servo_dikey_alt_limit) { servo_dikey = servo_dikey_alt_limit; } } DIKEY.write(servo_dikey); } 

////////////////////////////////////////////////////////////////////////////////////////

if (-1*deger > fark_sol_sag || fark_sol_sag > deger)  // aralıktaki fark değer ile karşılaştırılıyor
{
{
if (ortalama_sol > ortalama_sag)
{
servo_yatay = --servo_yatay;
if (servo_yatay < servo_yatay_alt_limit)
{
servo_yatay = servo_yatay_alt_limit;
}
}
else if (ortalama_sol < ortalama_sag) { servo_yatay = ++servo_yatay; if (servo_yatay > servo_yatay_ust_limit)
{
servo_yatay = servo_yatay_ust_limit;
}
}
else if (ortalama_sol = ortalama_sag)
{
// bişi yapmaz
}
YATAY.write(servo_yatay);
}
delay(zaman);
 
}
}
