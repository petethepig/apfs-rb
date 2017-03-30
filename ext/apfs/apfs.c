// Include the Ruby headers and goodies
#include "ruby.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>

#include <copyfile.h>      /* for copyfile(3)    */
#include <sys/clonefile.h> /* for clonefileat(2) */

void Init_apfs();

VALUE method_copyfile(VALUE self, VALUE src, VALUE dest);

void Init_apfs() {
  VALUE c = rb_cObject;
  c = rb_const_get(c, rb_intern("Apfs"));
  rb_define_singleton_method(c, "copyfile", (VALUE(*)(ANYARGS))method_copyfile, 2);
}

VALUE method_copyfile(VALUE self, VALUE src, VALUE dest) {
  int error;
  copyfile_state_t s;

  s = copyfile_state_alloc();
  error = copyfile(StringValueCStr(src), StringValueCStr(dest), s, COPYFILE_CLONE);

  return INT2NUM(error);
}
