#include <ad/core.h>

uint64_t
ad_block_get_start(ADBlock* block){
  return block->range.start;
}

uint64_t
ad_block_get_end(ADBlock* block){
  return block->range.end;
}

uint32_t
ad_block_get_start_x(ADBlock* block){
  return block->loc.start.x;
}

uint32_t
ad_block_get_start_y(ADBlock* block){
  return block->loc.start.y;
}

uint32_t
ad_block_get_end_x(ADBlock* block){
  return block->loc.end.x;
}

uint32_t
ad_block_get_end_y(ADBlock* block){
  return block->loc.end.y;
}
