#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ARC4.h"
#include <iostream>

using namespace std;

void  ARC4::prga(unsigned char * plaintext,unsigned char * cipher,int size){
    for(int k=0;k<size;k++){
        prgaIndexA=(prgaIndexA+1)%256;
        prgaIndexB=(prgaIndexB+sbox[prgaIndexA])%256;
        swap(sbox,prgaIndexA,prgaIndexB);
        cipher[k]=sbox[(sbox[prgaIndexA]+sbox[prgaIndexB])%256]^plaintext[k];
    }
}

void  ARC4::prga_char( char * plaintext, char * cipher,int size){
    for(int k=0;k<size;k++){
        prgaIndexA=(prgaIndexA+1)%256;
        prgaIndexB=(prgaIndexB+sbox[prgaIndexA])%256;
        swap(sbox,prgaIndexA,prgaIndexB);
        cipher[k]=sbox[(sbox[prgaIndexA]+sbox[prgaIndexB])%256]^plaintext[k];
    }
}

void ARC4::encrypt_char( char * plaintext, char * ciphertext,int size){
    prga_char(plaintext,ciphertext,size);
}
void ARC4::encrypt(unsigned char * plaintext,unsigned char * ciphertext,int size){
    prga(plaintext,ciphertext,size);
}
ARC4::ARC4(){
}
void ARC4::swap(unsigned char data[],int i ,int j){
    unsigned char temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}
void ARC4::ksa(){
    int j=0;
    for(int i=0;i<256;i++){
        j=(j+sbox[i]+key[i% sizeKey])%256;
        swap(sbox,i,j);
    }
}
void ARC4::set_key(unsigned char  k[],int size){
    key=k;
    prgaIndexA=0;
    prgaIndexB=0;
    sizeKey=size;
    for(int i=0;i<256;i++){
        sbox[i]=(unsigned char)i;
    }
    ksa();
}
