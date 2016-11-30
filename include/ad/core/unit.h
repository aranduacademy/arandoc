/** The MIT License (MIT)
 ** This file is part of the arandoc project.
 ** Copyright 2016 Anderson Tavares <acmt@outlook.com>.
 **
 ** Permission is hereby granted, free of charge, to any person obtaining a
 ** copy of this software and associated documentation files (the "Software"),
 ** to deal in the Software without restriction, including without limitation
 ** the rights to use, copy, modify, merge, publish, distribute, sublicense,
 ** and/or sell copies of the Software, and to permit persons to whom the
 ** Software is furnished to do so, subject to the following conditions:
 **
 ** The above copyright notice and this permission notice shall be included in
 ** all copies or substantial portions of the Software.
 **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 ** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 ** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 ** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 ** DEALINGS IN THE SOFTWARE.
 **/

#if !defined(AD_CORE_H_INSIDE)
#error "Only <ad/core.h> can be included directly."
#endif

#ifndef AD_UNIT_H
#define AD_UNIT_H

#include <ad/core.h>

#define AD_UNIT(x) ((ADUnit*)x)

typedef enum{
  AD_TYPE_PARAGRAPH,
  AD_TYPE_HEADER,
  AD_TYPE_TEXT,
  AD_TYPE_LIST,
  AD_TYPE_LIST_ITEM,
  AD_TYPE_EMPHASIS,
  AD_TYPE_STRONG,
  AD_TYPE_QUOTE,
  AD_TYPE_FIGURE,
  AD_TYPE_SUBFIGURE,
  AD_TYPE_EQUATION,
  AD_TYPE_EQUATION_INLINE,
  AD_TYPE_CODE_SPAN,
  AD_TYPE_CODE,
  AD_TYPE_DOCUMENT,
  AD_TYPE_MATH_INLINE,
  AD_TYPE_MATH,
  AD_TYPE_LINK_DEF,
  AD_TYPE_LINK,
} ADUnitType;

typedef struct{
  ADRange super;
  ADUnitType type;
}ADUnit;

uint64_t
ad_unit_get_start(ADUnit* unit);

uint64_t
ad_unit_get_end(ADUnit* unit);

uint32_t
ad_unit_get_start_x(ADUnit* unit);

uint32_t
ad_unit_get_start_y(ADUnit* unit);

uint32_t
ad_unit_get_end_x(ADUnit* unit);

uint32_t
ad_unit_get_end_y(ADUnit* unit);

ADUnitType
ad_unit_get_type(ADUnit* unit);

uint64_t
ad_unit_set_start(ADUnit* unit, uint64_t value);

uint64_t
ad_unit_set_end(ADUnit* unit, uint64_t value);

uint32_t
ad_unit_set_start_x(ADUnit* unit, uint32_t value);

uint32_t
ad_unit_set_start_y(ADUnit* unit, uint32_t value);

uint32_t
ad_unit_set_end_x(ADUnit* unit, uint32_t value);

uint32_t
ad_unit_set_end_y(ADUnit* unit, uint32_t value);

ADUnitType
ad_unit_set_type(ADUnit* unit, ADUnitType type);



#endif
