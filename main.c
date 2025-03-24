#include<stdio.h>
#include<stdlib.h>
#define MEM_SIZE (4 * 1024 * 1024)

typedef struct {
  uint32_t regs[32];
  uint32_t pc;
  uint32_t hi, lo;
} CPU;

typedef struct {
  uint8_t opcode;
  uint8_t rs;
  uint8_t rt;
  uint8_t rd;
  uint8_t shamt;
  uint8_t funct;
  uint16_t imm;
  uint32_t target;
  int32_t imm_se;
} DecodeInstruction;

uint8_t memory[MEM_SIZE];

uint32_t mem_read_word(uint32_t add) {
  if(add%4 != 0) {
     printf("Unaligned memory access at 0x%08x\n", add);
     exit(1);
  }

  uint8_t b0 = memory[add];
  uint8_t b1 = memory[add + 1];
  uint8_t b2 = memory[add + 2];
  uint8_t b3 = memory[add + 3];

  return uint32_t value = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;

}

DecodeInstruction decode_instruction(uint32_t instr) {
  DecodedInstruction dec;
  
  dec.opcode = (instr >> 26) & 0x3F;
  

  switch(dec.opcode) {
    case 0x00:
      dec.rs = (instr >> 21) & 0x1F;
      dec.rt = (instr >> 16) & 0x1F;
      dec.rd = (instr >> 11) & 0x1F;
      dec.shamt = (instr >> 6) & 0x1F;
      dec.funct = instr & 0x3F;
      break;

  
}
