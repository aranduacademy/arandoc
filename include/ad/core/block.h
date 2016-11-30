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

#ifndef AD_BLOCK_H
#define AD_BLOCK_H

#include <stdint.h>

#define AD_BLOCK(x) ((ADBlock*)x)

typedef enum{
  AD_TYPE_PARAGRAPH,
  AD_TYPE_HEADER,
  AD_TYPE_TEXT,
  AD_TYPE_ENUMERATE,
  AD_TYPE
} ADBlockType;

typedef struct{
  uint64_t start;
  uint64_t end;
}ADRange;

typedef struct{
  uint32_t x;
  uint32_t y;
}ADCoord;

typedef struct{
  ADCoord start;
  ADCoord end;
}ADRangeCoord;

typedef struct ADBlock{
  ADRange      range;
  ADRangeCoord loc;
  ADBlock*     next;
  ADBlock*     prev;
}ADBlock;

uint64_t
ad_block_get_start(ADBlock* block);

uint64_t
ad_block_get_end(ADBlock* block);

uint32_t
ad_block_get_start_x(ADBlock* block);

uint32_t
ad_block_get_start_y(ADBlock* block);

uint32_t
ad_block_get_end_x(ADBlock* block);

uint32_t
ad_block_get_end_y(ADBlock* block);


#endif
