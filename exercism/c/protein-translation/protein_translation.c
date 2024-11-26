#include "protein_translation.h"
#include <string.h>
#include <stdbool.h>

int translate_codon(const char *codon) {
   if (strcmp(codon, "AUG") == 0)
      return Methionine;
   else if (strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0)
      return Phenylalanine;
   else if (strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0)
      return Leucine;
   else if (strcmp(codon, "UCU") == 0 || strcmp(codon, "UCC") == 0 
         || strcmp(codon, "UCA") == 0 || strcmp(codon, "UCG") == 0)
      return Serine;
   else if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0)
      return Tyrosine;
   else if (strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0)
      return Cysteine;
   else if (strcmp(codon, "UGG") == 0)
      return Tryptophan;
   else if (strcmp(codon, "UAA") == 0 || strcmp(codon, "UAG") == 0 || strcmp(codon, "UGA") == 0)
      return STOP;
   else return INVALID;
}


proteins_t proteins(const char *const rna)
{
   proteins_t p;
   int len = strlen(rna);
   char rna_cpy[len];

   strncpy(rna_cpy, rna, len);
   for (int i = 0; i < len; i += 3) {
      char codon[3] = { rna_cpy[i], rna_cpy[i + 1], rna_cpy[i + 2] };
      int translation_result = translate_codon(codon);
      bool stop_procedure = 0;
      
      if (translation_result == INVALID) {
         p.count = 0;
         p.valid = 0;
      }
      else if (p.count == MAX_PROTEINS || translation_result == STOP) break;

      switch (protein_val)
      {
         case Methionine:
            ++p.count;
            p.proteins[i] = Methionine;
            break;
         case Phenylalanine:
            ++p.count;
            p.proteins[i] = Phenylalanine;
            break;
         case Leucine:
            ++p.count;
            p.proteins[i] = Leucine;
            break;
         case Serine:
            ++p.count;
            p.proteins[i] = Serine;
            break;
         case Tyrosine:
            ++p.count;
            p.proteins[i] = Tyrosine;
            break;
         case Cysteine:
            ++p.count;
            p.proteins[i] = Cysteine;
            break;
         case Tryptophan:
            ++p.count;
            p.proteins[i] = Tyrosine;
            break;
      }
   }
}
