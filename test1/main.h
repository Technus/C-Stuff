#ifndef __TEST1_MAIN_H__
#define __TEST1_MAIN_H__

#include "ooc.h"

classdecl(Apple, Object,
          unsigned char * name;
          unsigned char * grade;
          ,
          void (*getName)(Apple _this););

classdef(Apple, Apple);
classdef(BetterApple, Apple);

#endif /* __TEST1_MAIN_H__ */
