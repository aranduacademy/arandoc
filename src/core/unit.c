#include <ad/core.h>

uint64_t
ad_unit_get_start(ADUnit* unit){
  return unit->super.range.start;
}

uint64_t
ad_unit_get_end(ADUnit* unit){
  return unit->super.range.end;
}

uint32_t
ad_unit_get_start_x(ADUnit* unit){
  return unit->super.loc.start.x;
}

uint32_t
ad_unit_get_start_y(ADUnit* unit){
  return unit->super.loc.start.y;
}

uint32_t
ad_unit_get_end_x(ADUnit* unit){
  return unit->super.loc.end.y;
}

uint32_t
ad_unit_get_end_y(ADUnit* unit){
  return unit->super.loc.end.y;
}

ADUnitType
ad_unit_get_type(ADUnit* unit){
  return unit->type;
}
