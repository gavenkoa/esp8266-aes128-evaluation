#include <Arduino.h>

#include <Crypto.h>
#include <AES.h>
#include <string.h>

//key[16] cotain 16 byte key(128 bit) for encryption
byte key[16]={0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};
//plaintext[16] contain the text we need to encrypt
byte plaintext[16]={0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
//cypher[16] stores the encrypted text
byte cypher[16];
//decryptedtext[16] stores decrypted text after decryption
byte decryptedtext[16];
//creating an object of AES128 class
AESTiny128 aes128;

byte block0[16]={0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
byte block1[16];
byte *pin, *pout;
#define CHUNK_SIZE 100*1024
#define CHUNK_CNT (CHUNK_SIZE / sizeof(block0))

void setup() {
    Serial.begin(9600);

    aes128.setKey(key,16);// Setting Key for AES
}

void loop() {
//    delay(1000);

    pin = block0, pout = block1;
    unsigned long start = micros();
    for (uint i = 0; i < CHUNK_CNT; i++) {
        aes128.encryptBlock(pout, pin);
        byte *tmp = pin;
        pin = pout, pout = tmp;
    }
    unsigned long stop = micros();
    Serial.printf("AES performance: %lu us per %d bytes\n", stop-start, CHUNK_SIZE);

    // Serial.print("Before Encryption:");
    // for(uint i=0; i<sizeof(plaintext); i++){
    //     Serial.write(plaintext[i]);
    // }
    // aes128.encryptBlock(cypher,plaintext);
    // Serial.print("After Encryption:");
    // for(uint i=0; i<sizeof(plaintext); i++){
    //     Serial.write(cypher[i]);
    // }
    // aes128.decryptBlock(decryptedtext,cypher);
    // Serial.println();
    // Serial.print("After Dencryption:");
    // for(int i=0; i<sizeof(decryptedtext); i++){
    //     Serial.write(decryptedtext[i]);
    // }
}

