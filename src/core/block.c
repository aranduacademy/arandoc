#include <ad/core.h>

/* ----------------------------------------------------------------------------
 * PUBLIC FUNCTIONS
 * --------------------------------------------------------------------------*/
uint16_t
ad_block_get_n_inlines(ADBlock* block){
  return block->n_inlines;
}

ADInline*
ad_block_get(ADBlock* block, uint16_t index){
  uint16_t i = 0;
  ADInlineList* listitem = block->inlines;
  while(i < index && listitem != NULL){
    listitem = listitem->next;
  }
  return listitem->item;
}

ADInlineList*
ad_block_get_list(ADBlock* block){
  return block->inlines;
}
