#ifndef __TEST1_OOC_H__
#define __TEST1_OOC_H__

typedef struct vClass vClass;
typedef struct oClass oClass;

typedef struct vObject vObject;
typedef struct oObject oObject;

struct oObject // The object data
{
  struct vClass * class; // this instance class Class
};

struct oClass // The class object data
{
  struct oObject; // extends object
  struct vClass * super;
  unsigned char * name;
};

struct vClass // The Class class
{
  struct oClass;
};

struct vObject // The Object class
{
  struct vClass; // extends class Class
};

vObject cObject;
vClass  cClass;

typedef oClass  Class;
typedef oObject Object;

typedef unsigned int bool;

#define classdecl(_name, _super, fields, methods) \
  typedef struct o##_name                         \
  {                                               \
    struct o##_super;                             \
    fields                                        \
  } o##_name;                                     \
                                                  \
  typedef o##_name _name;                         \
                                                  \
  typedef struct v##_name                         \
  {                                               \
    struct v##_super;                             \
    methods                                       \
  } v##_name;

#define classdef(_name, _super) v##_super c##_name;

#define getClass(_class, _this) ((v##_class *)(_this.class))

#define withClass(_class) .class = (vClass *)&c##_class
#define withSuper(_super) .super = (vClass *)&c##_super
#define withName(_name)   .name = #_name

#define classimpl(_name, _super) \
  typedef o##_super _name;       \
  v##_super         c##_name = { \
      withClass(_name),  \
      withSuper(_super), \
      withName(_name)

#define newObject(_class) \
  {                       \
    withClass(_class)

#define invoke(_class, _method, _this) (getClass(_class, _this)->_method(_this
#define invokeStatic(_class, _method) (c##_class->_method(

#endif /* __TEST1_OOC_H__ */
