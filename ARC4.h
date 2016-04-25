/*
 * ARC4.h
 *
 *  Created on: Nov 9, 2011
 *      Author: fabio
 */
#ifndef ARC4_H_
    #define ARC4_H_
    class ARC4{
        public:
            void set_key(unsigned char * k,int size);
            void encrypt(unsigned char * in,unsigned char * out,int size);
            void encrypt(char * in,char * out,int size);
            void ksa();
            static void hello();
            ARC4();
        protected:
            void swap(unsigned char data[],int i ,int j);
            void prga(unsigned char * plaintext,unsigned char * cipher,int size);
            void prga(char * plaintext,char * cipher,int size);
            unsigned char * key;
            unsigned char sbox[256];
            int sizeKey,prgaIndexA,prgaIndexB;
    };



#endif /* ARC4_H_ */
