#include <ad/core.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ADDocument*
ad_document_new(){
  return malloc(sizeof(ADDocument));
}

void
ad_document_fill(ADDocument* document,char* text, uint64_t max_length){
  document->text = text;
  char* pch = strtok(text,"\n");
  while(pch != NULL){
    printf("%s\n", pch);
    pch = strtok(NULL, "\n");
  }
}

ADDocument*
ad_document_new_from_text(char *text, uint64_t max_length){
  ADDocument* document = ad_document_new();
  ad_document_fill(document, text, max_length);
  return document;
}
