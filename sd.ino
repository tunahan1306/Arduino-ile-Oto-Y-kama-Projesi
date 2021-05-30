/*
  TUNAHAN ÇAKIR 
  190201031
*/
#include <SPI.h>
#include <SD.h>

File myFile;

int besbutondurum = 0;
int onbutondurum = 0;
int yirmibutondurum = 0;
int ellibutondurum = 0;
int yuzbutondurum = 0;
int pbbutondurum = 0;

int kopbutondurum = 0;
int yikbutondurum = 0;
int kurbutondurum = 0;
int cilbutondurum = 0;
int hbbutondurum = 0;

int beslik = 0, onluk = 0, yirmilik = 0 , ellilik = 0, yuzluk = 0;
int toplam = 0, borc = 0;

String hizmet[4] = {"Kopukleme", "Yikama", "Kurulama", "Cilalama"};
int hizmetID[4] = {1, 2, 3, 4};
int hizmetAdet[4] = {3, 50, 100, 20};
int hizmetFiyat[4] = {15, 10, 5, 50};
int kasa[5] = {0, 0, 0, 0, 0};

int kasatoplam = kasa[0] * 5 + kasa[1] * 10 + kasa[2] * 20 + kasa[3] * 50 + kasa[4] * 100;
int kopsym = 0, yiksym = 0, kursym = 0, cilsym = 0;

const int besbuton = A0;
const int onbuton = A1;
const int yirmibuton = A2;
const int ellibuton = A3;
const int yuzbuton = A4;
const int pbbuton = A5;

const int kopbuton = 6;
const int yikbuton = 5;
const int kurbuton = 4;
const int cilbuton = 3;
const int hbbuton = 2;

boolean parasayim = true;
boolean hizmetsayim = true;
boolean parateslim = true;

void setup() {
  Serial.begin(9600);

  pinMode(besbuton, INPUT);
  pinMode(onbuton, INPUT);
  pinMode(yirmibuton, INPUT);
  pinMode(ellibuton, INPUT);
  pinMode(yuzbuton, INPUT);
  pinMode(pbbuton, INPUT);

  pinMode(kopbuton, INPUT);
  pinMode(yikbuton, INPUT);
  pinMode(kurbuton, INPUT);
  pinMode(cilbuton, INPUT);
  pinMode(hbbuton, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.println("------------------------------");
  Serial.println("Para Miktarini Giriniz : ");
  delay(250);
}

void loop() {
  besbutondurum = digitalRead(besbuton);
  onbutondurum = digitalRead(onbuton);
  yirmibutondurum = digitalRead(yirmibuton);
  ellibutondurum = digitalRead(ellibuton);
  yuzbutondurum = digitalRead(yuzbuton);
  pbbutondurum = digitalRead(pbbuton);

  kopbutondurum = digitalRead(kopbuton);
  yikbutondurum = digitalRead(yikbuton);
  kurbutondurum = digitalRead(kurbuton);
  cilbutondurum = digitalRead(cilbuton);
  hbbutondurum = digitalRead(hbbuton);

  paraOlusturma();
  hizmetOlusturma();
}


void paraOlusturma() {
  if (pbbutondurum == HIGH) {
    parasayim = false;
    Serial.println("------------------------------");
    Serial.print("\nToplam Paraniz = ");
    Serial.println(toplam);
    delay(250);
    Serial.println("------------------------------");
    Serial.println("Hizmet Giriniz ");
    delay(250);
  }
  if (parasayim) {
    if (besbutondurum == HIGH) {
      if (beslik < 99)
        beslik++;
      toplam = beslik * 5 + onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100;
      kasa[0]++;
      Serial.print("\nToplam Beslik Sayisi = ");
      Serial.println(beslik);
      delay(300);
    }
    if (onbutondurum == HIGH) {
      if (onluk < 99)
        onluk++;
      toplam = beslik * 5 + onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100;
      kasa[1]++;
      Serial.print("\nToplam Onluk Sayisi = ");
      Serial.println(onluk);
      delay(300);
    }
    if (yirmibutondurum == HIGH) {
      if (yirmilik < 99)
        yirmilik++;
      toplam = beslik * 5 + onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100;
      kasa[2]++;
      Serial.print("\nToplam Yirmilik Sayisi = ");
      Serial.println(yirmilik);
      delay(300);
    }
    if (ellibutondurum == HIGH) {
      if (ellilik < 99)
        ellilik++;
      toplam = beslik * 5 + onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100;
      kasa[3]++;
      Serial.print("\nToplam Ellilik Sayisi = ");
      Serial.println(ellilik);
      delay(300);
    }
    if (yuzbutondurum == HIGH) {
      if (yuzluk < 99)
        yuzluk++;
      toplam = beslik * 5 + onluk * 10 + yirmilik * 20 + ellilik * 50 + yuzluk * 100;
      kasa[4]++;
      Serial.print("\nToplam Yuzluk Sayisi = ");
      Serial.println(yuzluk);
      delay(300);
    }
  }
}

void hizmetOlusturma() {
  if (hbbutondurum == HIGH) {
    hizmetsayim = false;
    Serial.println("------------------------------");
    Serial.print("\nToplam Borcunuz = ");
    Serial.println(borc);
    delay(250);
    Serial.println("------------------------------");
    Serial.print("\nKalan Paraniz = ");
    Serial.println(toplam - borc);
    delay(250);
    paraUstu();
    delay(250);
    if(parateslim){
      parateslim=false;
      paraTeslim();
    }
  }
  if (hizmetsayim) {
    if (kopbutondurum == HIGH) {
      if (kopsym < hizmetAdet[0])
        kopsym++;
      else
        Serial.println("Yeterli hizmet Bulunmamaktadir...");
      borc = hizmetFiyat[0] * kopsym + hizmetFiyat[1] * yiksym + hizmetFiyat[2] * kursym + hizmetFiyat[3] * cilsym;
      Serial.print("\nToplam Kopukleme Sayisi = ");
      Serial.println(kopsym);
      delay(300);
    }
    if (yikbutondurum == HIGH) {
      if (yiksym < hizmetAdet[1])
        yiksym++;
      else
        Serial.println("Yeterli hizmet Bulunmamaktadir...");
      borc = hizmetFiyat[0] * kopsym + hizmetFiyat[1] * yiksym + hizmetFiyat[2] * kursym + hizmetFiyat[3] * cilsym;
      Serial.print("\nToplam Yikama Sayisi = ");
      Serial.println(yiksym);
      delay(300);
    } if (kurbutondurum == HIGH) {
      if (kursym < hizmetAdet[2])
        kursym++;
      else
        Serial.println("Yeterli hizmet Bulunmamaktadir...");
      borc = hizmetFiyat[0] * kopsym + hizmetFiyat[1] * yiksym + hizmetFiyat[2] * kursym + hizmetFiyat[3] * cilsym;
      Serial.print("\nToplam Kurulama Sayisi = ");
      Serial.println(kursym);
      delay(300);
    } if (cilbutondurum == HIGH) {
      if (cilsym < hizmetAdet[3])
        cilsym++;
      else
        Serial.println("Yeterli hizmet Bulunmamaktadir...");
      borc = hizmetFiyat[0] * kopsym + hizmetFiyat[1] * yiksym + hizmetFiyat[2] * kursym + hizmetFiyat[3] * cilsym;
      Serial.print("\nToplam Cilalama Sayisi = ");
      Serial.println(cilsym);
      delay(300);
    }
  }
}

boolean yeterli = true;
void paraUstu() {
  toplam = toplam - borc;
  int yuz = toplam / 100;
  if (yuz > kasa[4])
    yuz = kasa[4];
  toplam = toplam - yuz * 100;
  int elli = toplam / 50;
  if (elli > kasa[3])
    elli = kasa[3];
  toplam = toplam - elli * 50;
  int yirmi = toplam / 20;
  if (yirmi > kasa[2])
    yirmi = kasa[2];
  toplam = toplam - yirmi * 20;
  int on = toplam / 10;
  if (on > kasa[1])
    on = kasa[1];
  toplam = toplam - on * 10;
  int bes = toplam / 5;
  if (bes > kasa[0])
    bes = kasa[0];
  toplam = toplam - bes * 5;

  if(toplam==0){
    Serial.println("-------------------------------------------");
  Serial.println("*************PARA USTUNUZ********");
  Serial.print("\nYuzluk Sayisi = ");
  Serial.println(yuz);
  Serial.print("\nEllilik Sayisi = ");
  Serial.println(elli);
  Serial.print("\nYirmilik Sayisi = ");
  Serial.println(yirmi);
  Serial.print("\nOnluk Sayisi = ");
  Serial.println(on);
  Serial.print("\nBeslik Sayisi = ");
  Serial.println(bes);
  Serial.println("----------------------------------------");
  }else{
    yeterli = false;
    Serial.println("-----------------------------");
    Serial.println("Kasada Yeteri Kadar Para Bulunmamaktadir");
  }



}

void paraTeslim(){
  int degisken =2;
  if(yeterli == false){
    digitalWrite(8,HIGH);
    Serial.println("--------------------------------");
    Serial.println("Paraniz Teslim Edilemedi");
  }
  else if(degisken==2){
    digitalWrite(8,HIGH);
    Serial.println("PARA SIKISTI !!!............... ");
    Serial.println("PARANIZ TESLİM EDİLEMEDİ");
  }else{
    digitalWrite(9,HIGH);
    Serial.println("PARANIZ TESLIM EDILDI :)");
  }
}
