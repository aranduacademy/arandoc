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

#ifndef AD_CONTAINER_H
#define AD_CONTAINER_H

#include <stdint.h>
#include <ad/core.h>

#define AD_CONTAINER(x) ((ADContainer*)x)

typedef struct ADContainer{
  ADBlock   parent;
  ADBlock*  children;
  uint16_t  n_children;
}ADContainer;

/**
 * @brief ad_container_get_n_children
 * @param container
 * @return
 */
uint16_t
ad_container_get_n_children(ADContainer* container);

/**
 * @brief ad_container_get
 * @param container
 * @param index
 * @return
 */
ADBlock*
ad_container_get(ADContainer* container, uint16_t index);

#endif
