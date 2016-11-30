#include <ad/core.h>

uint16_t
ad_container_get_n_blocks(ADContainer* container){
  return container->n_blocks;
}

ADBlock*
ad_container_get(ADContainer* container, uint16_t index){
  ADBlockList* item = container->list;
  uint16_t i = 0;
  while(i < index && item != NULL){
    item = item->next;
    i++;
  }
  return item->block;
}

ADBlockList*
ad_container_get_list(ADContainer* container){
  return container->list;
}
