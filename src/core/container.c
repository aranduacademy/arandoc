#include <ad/core.h>

uint16_t
ad_container_get_n_children(ADContainer* container){
  return container->n_children;
}

ADBlock*
ad_container_get(ADContainer* container, uint16_t index){
  return container->children[index];
}
