#ifndef __TEST1_LIST_H__
#define __TEST1_LIST_H__

#include "ooc.h"

classdecl(List, Object,
          unsigned int size;
          ,
          unsigned int (*size)(List _this);
          bool (*isEmpty)(List _this);
          void (*clear)(List _this););

classdef(List, List);

#define ListClassDecl(_type, _note, _pointer)                                                         \
  classdecl(ListOf##_type##_note, List,                                                               \
            _type##_pointer##* content;                                                               \
            ,                                                                                         \
            void (*add)(ListOf##_type##_note _this, _type##_pointer object);                          \
            bool (*contains)(ListOf##_type##_note _this, _type##_pointer object);                     \
            void (*forEach)(ListOf##_type##_note _this, void (*forEach)(_type##_pointer /*object*/)); \
            bool (*remove)(ListOf##_type##_note _this, _type##_pointer object);                       \
            _type##_pointer(*get)(ListOf##_type##_note _this, unsigned int index);                    \
            _type##_pointer(*set)(ListOf##_type##_note _this, unsigned int index, _type##_pointer object););

#define ListClassDef(_type, _note) vList cListOf##_type##_note;

#define ListClassExt(_type, _note) \
  classext(ListOf##_type##_note, List)

ListClassDecl(Object, s, );
ListClassDef(Object, s);

#endif /* __TEST1_LIST_H__ */
