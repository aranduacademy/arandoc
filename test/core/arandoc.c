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

static void
test_parse(){
  char* texto          = "# oi\nTudo bom?";
  ADDocument* document = ad_document_new_from_text(texto, 14);

  // Range tests
  g_assert_cmpuint(ad_block_get_start  (AD_BLOCK(document)),==, 0);
  g_assert_cmpuint(ad_block_get_end    (AD_BLOCK(document)),==,14);
  g_assert_cmpuint(ad_block_get_start_x(AD_BLOCK(document)),==, 0);
  g_assert_cmpuint(ad_block_get_start_y(AD_BLOCK(document)),==, 0);
  g_assert_cmpuint(ad_block_get_end_x  (AD_BLOCK(document)),==, 8);
  g_assert_cmpuint(ad_block_get_end_y  (AD_BLOCK(document)),==, 1);

  // Children tests
  g_assert_cmpuint(ad_container_get_n_children(document),==, 2);
  g_assert_cmpuint(ad_container_get(document,0)->type,==, AD_TYPE_HEADER);
  g_assert_cmpuint(ad_container_get(document,1)->type,==, AD_TYPE_PARAGRAPH);

  // # oi
  ADHeader* header = ad_container_get(document,0);
  g_assert_cmpuint(header->depth,==,1);
  g_assert_cmpuint(header->n_children,==,1);
  // oi
  g_assert_cmpuint(header->children[0].type,==,AD_TYPE_TEXT);
  ADText* text = header->children[0];
  g_assert_cmpuint(text->range.start, ==, 2);
  g_assert_cmpuint(text->range.end  , ==, 4);
  g_assert_cmpuint(text->loc.start.x, ==, 2);
  g_assert_cmpuint(text->loc.start.y, ==, 0);
  g_assert_cmpuint(text->loc.end.x  , ==, 4);
  g_assert_cmpuint(text->loc.end.y  , ==, 0);

  // Tudo bom? (paragraph)
  ADParagraph* paragraph = document->children[1];
  g_assert_cmpuint(paragraph->n_children, ==, 1);
  // Tudo bom? (text)
  g_assert_cmpuint(paragraph->children[0].type,==,AD_TYPE_TEXT);
  ADText* text = paragraph->children[0];
  g_assert_cmpuint(text->range.start, ==,  5);
  g_assert_cmpuint(text->range.end  , ==, 14);
  g_assert_cmpuint(text->loc.start.x, ==,  0);
  g_assert_cmpuint(text->loc.start.y, ==,  1);
  g_assert_cmpuint(text->loc.end.x  , ==,  8);
  g_assert_cmpuint(text->loc.end.y  , ==,  1);

}

int
main(int argc, char* argv[]){
  setlocale (LC_ALL, "");
  g_test_init(&argc, &argv, NULL);
  g_test_bug_base("https://github.com/aranduacademy/arandoc/issues/");
  g_test_add_func("/arandoc/test_parse", test_parse);
}
