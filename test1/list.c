#include "list.h"

static unsigned int size(List _this)
{
  return _this.size;
}

static bool isEmpty(List _this)
{
  return _this.size == 0;
}

static void clear(List _this)
{
  return _this.size = 0;
}

classimpl(List, List),
    .size    = &size,
    .isEmpty = &isEmpty,
    .clear   = &clear,
}
;
