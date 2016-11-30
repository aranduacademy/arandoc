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

#include <glib.h>
#include <locale.h>
#include <stdint.h>
#include <ad/core.h>

void
test_unit(ADUnit* unit, ADUnit *gt){
  g_assert_cmpuint(ad_unit_get_start  (unit),==,ad_unit_get_start(gt));
  g_assert_cmpuint(ad_unit_get_end    (unit),==,ad_unit_get_end(gt));
  g_assert_cmpuint(ad_unit_get_start_x(unit),==,ad_unit_get_start_x(gt));
  g_assert_cmpuint(ad_unit_get_start_y(unit),==,ad_unit_get_start_y(gt));
  g_assert_cmpuint(ad_unit_get_end_x  (unit),==,ad_unit_get_end_x(gt));
  g_assert_cmpuint(ad_unit_get_end_y  (unit),==,ad_unit_get_end_y(gt));
}

static void
test_parse(){
  char texto[]          = "# oi\nTudo bom?";
  ADDocument* document  = ad_document_new_from_text(texto, 14);
  ADUnit document_unit  = {0,14,0,0,8,1};
  ADUnit header_unit    = {2,4,2,0,4,0};
  ADUnit paragraph_unit = {5,14,0,1,8,1};


  // This document is a block with 14 chars, 2 lines, from (0,0) to (1,8)
  test_unit(AD_UNIT(document), &document_unit);

  // ... and it's a container block with two leaf blocks (a header and a paragraph)
  g_assert_cmpuint(ad_container_get_n_blocks(AD_CONTAINER(document)),==, 2);
  g_assert_cmpuint(ad_unit_get_type(AD_UNIT(ad_container_get(AD_CONTAINER(document),0))),==, AD_TYPE_HEADER);
  g_assert_cmpuint(ad_unit_get_type(AD_UNIT(ad_container_get(AD_CONTAINER(document),1))),==, AD_TYPE_PARAGRAPH);

  // We test the header # oi which has 1 inline (the text 'oi')
  ADHeader* header = AD_HEADER(ad_container_get(AD_CONTAINER(document),0));
  g_assert_cmpuint(ad_header_get_depth(header)             ,==,1);
  g_assert_cmpuint(ad_block_get_n_inlines(AD_BLOCK(header)),==,1);
  // Testing the text inline 'oi'
  g_assert_cmpuint(ad_unit_get_type(AD_UNIT(ad_block_get(AD_BLOCK(header),0))),==,AD_TYPE_TEXT);
  ADText* text = AD_TEXT(ad_block_get(AD_BLOCK(header),0));
  test_unit(AD_UNIT(text),&header_unit);

  // Tudo bom? (paragraph)
  ADParagraph* paragraph = AD_PARAGRAPH(ad_container_get(AD_CONTAINER(document),1));
  g_assert_cmpuint(ad_block_get_n_inlines(AD_BLOCK(paragraph)), ==, 1);
  // Tudo bom? (text)
  g_assert_cmpuint(ad_unit_get_type(AD_UNIT(ad_block_get(AD_BLOCK(paragraph),0))),==,AD_TYPE_TEXT);
  text = AD_TEXT(ad_block_get(AD_BLOCK(paragraph),0));
  test_unit(AD_UNIT(text),&paragraph_unit);
}

int
main(int argc, char* argv[]){
  setlocale (LC_ALL, "");
  g_test_init(&argc, &argv, NULL);
  g_test_bug_base("https://github.com/aranduacademy/arandoc/issues/");
  g_test_add_func("/arandoc/test_parse", test_parse);
  return g_test_run();
}
