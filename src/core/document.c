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
  document->text   = text;
  ad_unit_set_start(document,0);
  ad_unit_set_end(document,max_length-1);
  document->length = max_length;
  ad_document_get_structure(document);
  ad_document_parse_structure(document);

  char* pch = strtok(text,"\n");
  while(pch != NULL){
    if(ad_is_header(pch)){
      ad_header_new();
    }
    switch (pch[0]) {
    case '#':
      ad_header_new();
      ad_container_append();
      break;
    default:
      break;
    }
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
