#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

int32_t lw(uint32_t address, int32_t kte) {
    int32_t byteAddress = address + kte;
    if (byteAddress % 4 != 0) {
        printf("O endereço fornecido não é válido");
        return 0;
    }
    byteAddress /= 4;
    return mem[byteAddress];
}

int32_t lb(uint32_t address, int32_t kte) {
    int32_t byteAddress = address + kte;
    int8_t *byte = (int8_t *) mem;
    byte += byteAddress;
    return *byte;
}

int32_t lbu(uint32_t address, int32_t kte) {
    int32_t byteAddress = address + kte;
    int8_t *byte = (int8_t *) mem;
    byte += byteAddress;
    int32_t value = (*byte & 0x000000FF);
    return value;
}

void sw(uint32_t address, int32_t kte, int32_t dado) {
    int32_t byteAddress = address + kte;
    if (byteAddress % 4 != 0) {
        printf("O endereço fornecido não é válido");
    }
    byteAddress /= 4;
    mem[byteAddress] = dado;
}

void sb(uint32_t address, int32_t kte, int8_t dado) {
    int32_t byteAddress = address + kte;
    int8_t *byte = (int8_t *) mem;
    byte += byteAddress;
    *byte = dado;
}

int main() {
    // 1.Ler 4 bytes do teclado(0,1,2,3).
    for (uint32_t i = 0; i < 4; i++) {
        char comma;
        int32_t value;
        scanf("%x%c", &value, &comma);
        sb(i, 0, value);
    }

//    // 2.Ler mais 4 bytes do teclado(4,5,6,7).
    for (int i = 4; i < 8; i++) {
        char comma;
        int32_t value;
        scanf("%x%c", &value, &comma);
        sb(i, 0, value);
    }

    // 3. Ler 4 palavras do teclado.
    for(int i = 8; i <= 20 ; i += 4){
        int32_t value;
        scanf("%x", &value);
        sw(i,0,value);
    }

    // 4. Imprimir 6 primeiras palavras do vetor memoria.
    for(int i = 0; i < 6;i++){
        int32_t value = mem[i];
        printf("%08x\n",value);
    }

    // 5. Teste de funções de leitura.
    printf("%08x\n", lb(4,0));
    printf("%08x\n", lbu(4,0));

    for(int i = 12; i <= 20 ; i += 4){
        int32_t data = lw(i,0);
        printf("%08x\n", data);
    }
//
//    // 6. Imprimir o conteúdo total da memória em hexa
//    for(int i = 0; i < 7; i++){
//        int32_t value = mem[i];
//        printf("%08x\n",value);
//    }

    return 0;
}