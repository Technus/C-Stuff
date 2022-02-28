#include "ooc.h"

vObject cObject = {
    .class = (vClass *)&cClass,
    .super = (vClass *)0,
    .name  = "Object"};

vClass cClass = {
    .class = (vClass *)&cClass,
    .super = (vClass *)&cObject,
    .name  = "Class"};